#include "pch.h"
#include "Operator.h"
#include "Manager.h"
#include "Task.h"
#include <iostream>
#include <chrono>


Operator::Operator()
{
}

Operator::Operator(Manager* manager, unsigned int id)
{
    this->manager_ = manager;
    this->experience_ = (Experience)(rand() % 3 + 1);
    this->work = true;
    this->id_ = id;
}


Operator::~Operator()
{
}

int Operator::DoTask(Task&& task)
//Иметация выполнение задачи
{
    unsigned int time = 5 * task.GetLevel() / (int)experience_;
    std::this_thread::sleep_for(std::chrono::seconds(time));
    PrintTask(task.GetId(), time);
    return time;
}

void Operator::Work() {
    while (work)
    {
        //если очередь не пуста, прочит дать задачу.
        if (manager_->CheckQueue()) {
            manager_->PopTask(this);
        }
        //немного замедлить, а то нагрузка большая
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Operator::PrintTask(unsigned int i, unsigned int time) {
    std::mutex mutex_;
    std::lock_guard<std::mutex> locker(mutex_);
    std::cout << "====Task Complete. #" << i << ", spending time: " << time << ", Operator id: " << id_<< "===" << std::endl;
}

int Operator::GetTask(Task && task)
{
    return DoTask(std::move(task));
}

void Operator::Off()
{
    this->work = false;
}

void Operator::destroy()
{
    Operator::~Operator();
}
