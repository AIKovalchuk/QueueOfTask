#include "pch.h"
#include "Manager.h"
#include "Operator.h"
#include "Task.h"



Manager::Manager()
{
    for (int i = 0; i < 5; i++) {
        m_operator[i] = std::move(Operator(this));
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
    mutex.lock();
    queue_.push(std::move(task));
    mutex.unlock();
}

void Manager::Run() {
    for (size_t i = 0; i<5; i++)
    {
        std::thread thread(&Operator::Work,std::ref(m_operator[i]));
        thread_.push_back(std::move(thread));
    }
    while (true)
    {
        if (queue_.size() > 2 * thread_.size() && thread_.size() < MAX_OF_OPERATOR) {
            m_operator[current_operator] = std::move(Operator(this));
            std::thread thread(&Operator::Work, std::ref(m_operator[current_operator]));
            thread_.push_back(std::move(thread));
            current_operator++;
        }

        if (queue_.size() <= thread_.size() && thread_.size() > 1) {
            thread_[current_operator-1].join();
            delete &m_operator[current_operator - 1];
            m_operator.erase(current_operator - 1);
        }
    }
}

Task&& Manager::PopTask() {
    mutex.lock();
    if (queue_.size() != 0)
    {
        auto task = queue_.front();
        queue_.pop();
        return std::move(task);
    }
    else
    {
        throw std::logic_error("No tasks in the queue!");
    }
    
    mutex.unlock();
}

bool Manager::CheckQueue() {
    return !queue_.empty();
}
