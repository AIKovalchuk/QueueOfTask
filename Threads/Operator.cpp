#include "pch.h"
#include "Operator.h"
#include "Manager.h"
#include "Task.h"
#include <iostream>
#include <chrono>


Operator::Operator()
{
}

Operator::Operator(Manager* manager)
{
    this->manager_ = manager;
    this->experience_ = (Experience)(rand() % 3 + 1);
    this->work = true;
}


Operator::~Operator()
{
}

void Operator::DoTask(Task&& task) {
    std::this_thread::sleep_for(std::chrono::seconds(2*task.GetLevel() / (int)experience_));
    PrintTask(task.GetId());
}

void Operator::Work() {
    while (work)
    {
        if (manager_->CheckQueue()) {
            manager_->PopTask(this);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Operator::PrintTask(unsigned int i) {
    std::mutex mutex_;
    std::lock_guard<std::mutex> locker(mutex_);
    std::cout << "Task Comlete. #" << i << std::endl;
}

void Operator::GetTask(Task && task)
{
    DoTask(std::move(task));
}

void Operator::Off()
{
    this->work = false;
}

void Operator::destroy()
{
    Operator::~Operator();
}
