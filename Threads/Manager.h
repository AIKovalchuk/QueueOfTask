#pragma once 

#include <queue>
#include <thread>
#include <mutex>
#include <vector>
#include <memory>
#include <map>
#include "Task.h"

class Operator;

class Manager
{
public:
    Manager();
    ~Manager();
    void PutToQueue(Task&& task);
    void Run();
    void PopTask(Operator* op);
    bool CheckQueue();
private:
    std::queue<Task> queue_;
    std::vector<std::thread> thread_;
    std::map<uint16_t, Operator > m_operator;  // map[operator_id] = operator
    const unsigned int MAX_OF_OPERATOR = 20;
    unsigned int current_operator = 0;
    std::mutex mutex;
};

