#include "pch.h"
#include "Manager.h"
#include "Operator.h"
#include "Task.h"
#include <iostream>



Manager::Manager()
//Создаем олного оператора при создании манагера.
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


void Manager::PutToQueue(Task&& task)
//просто функция, чтобы положить в очередь очередную задачу
{
    queue_.push(std::move(task));
}

void Manager::Run()
//Главный цикл
{
    //запускаем операторов в потоке а.к.а вызываем метод Work каждого оператора в отдельном потоке
    for (size_t i = 0; i < m_operator.size(); i++)
    {
        std::thread thread(&Operator::Work,std::ref(m_operator[i]));
        thread_.push_back(std::move(thread));
    }
    //вечный цикл
    while (true)
    {
        //Если операторов мало, создает ещё и запускает в отдельных потоках
        if (queue_.size() > 2 * thread_.size() && thread_.size() < MAX_OF_OPERATOR) {
            m_operator[current_operator] = std::move(Operator(this, count));
            count++;
            std::thread thread(&Operator::Work, std::ref(m_operator[current_operator]));
            thread_.push_back(std::move(thread));
            current_operator++;
        }
        //Если операторов много,  гасит работу, дожидается завершения потока и удаляет оператора
        if (queue_.size()+2 <= thread_.size() && thread_.size() > 1 && current_operator > 1) {
            m_operator[current_operator - 1].Off();
            thread_[current_operator-1].join();
            //m_operator[current_operator - 1].destroy();
            m_operator.erase(current_operator - 1);
            current_operator--;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Manager::PopTask(Operator* op)
//С помощью этой функции операторы берут себе задачу.
{
    std::lock_guard<std::mutex> locker(mutex);
    std::cout << "\n----------> Pop task. Size of queue: " << queue_.size() <<", count of oper: " << thread_.size() << ", Mean time of wait: " << (double)time / n << "\n"<< std::endl;
    if(!queue_.empty()){
        auto task = queue_.front();
        //Если очередь не пуста, то манагер отдает задачу оператору, который вызвал этот метод. В ответ получает время исполнения задачи
        time += op->GetTask(std::move(task));
        n++;
        queue_.pop();
    }
}

bool Manager::CheckQueue() {
    //проверка пуста ли очередь задач
    std::lock_guard<std::mutex> locker(mutex);
    return !queue_.empty();
}
