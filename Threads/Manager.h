#pragma once
#include <queue>
#include <thread>
#include <mutex>
#include "Operator.h"
#include "Task.h"

class Manager
{
public:
    Manager();
    ~Manager();
    void PutToQueue(Task&& task);
    void Run();
    Task* PopTask();
private:
    std::queue<Task> queue_;
};

