#include "pch.h"
#include "Operator.h"
#include "Manager.h"
#include "Task.h"



Operator::Operator()
{
}

Operator::Operator(Manager* manager)
{
    this->manager_ = manager;
    this->experience_ = (Experience)(rand() % 3 + 1);
}


Operator::~Operator()
{
}

void Operator::DoTask(Task&& task) {
    std::this_thread::sleep_for(std::chrono::seconds(5*task.GetLevel() / (int)experience_));
}

void Operator::Work() {
    while (true)
    {
        if (manager_->CheckQueue()) {
            DoTask(std::move(manager_->PopTask()));
        }
    }
}