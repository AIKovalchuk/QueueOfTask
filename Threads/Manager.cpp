#include "pch.h"
#include "Manager.h"
#include "Operator.h"
#include "Task.h"
#include <iostream>



Manager::Manager()
{
    for (int i = 0; i < 1; i++) {
        m_operator[i] = std::move(Operator(this, count));
        count++;
        current_operator++;
    }
}


Manager::~Manager()
{
    for (int i = 0; i < thread_.size(); i++)
    {
        thread_[i].join();
    }
    for (int i = 0; i < m_operator.size(); i++) {
        delete &m_operator[i];
    }
}


void Manager::PutToQueue(Task&& task) {
    //std::lock_guard<std::mutex> locker(mutex);
    queue_.push(std::move(task));
}

void Manager::Run() {
    for (size_t i = 0; i < m_operator.size(); i++)
    {
        std::thread thread(&Operator::Work,std::ref(m_operator[i]));
        thread_.push_back(std::move(thread));
    }
    while (true)
    {
        if (queue_.size() > 2 * thread_.size() && thread_.size() < MAX_OF_OPERATOR) {
            m_operator[current_operator] = std::move(Operator(this, count));
            count++;
            std::thread thread(&Operator::Work, std::ref(m_operator[current_operator]));
            thread_.push_back(std::move(thread));
            current_operator++;
        }

        if (queue_.size()+2 <= thread_.size() && thread_.size() > 1) {
            m_operator[current_operator - 1].Off();
            thread_[current_operator-1].join();
            //m_operator[current_operator - 1].destroy();
            m_operator.erase(current_operator - 1);
            current_operator--;
        }
    }
}

void Manager::PopTask(Operator* op) {
    std::lock_guard<std::mutex> locker(mutex);
    std::cout << " Pop task. Size: " << queue_.size() << std::endl;
    if(!queue_.empty()){
        auto task = queue_.front();
        op->GetTask(std::move(task));
        queue_.pop();
    }
}

bool Manager::CheckQueue() {
    std::lock_guard<std::mutex> locker(mutex);
    return !queue_.empty();
}
