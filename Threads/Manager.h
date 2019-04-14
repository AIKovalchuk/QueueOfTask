#pragma once
#include <queue>
#include <thread>
#include <mutex>
#include "Operator.h"
#include "Task.h"
#include <vector>
#include <map>


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
    std::vector<std::thread> thread_;
    std::map<uint16_t, std::shared_ptr<Operator> > m_operator;  // map[operator_id] = operator
    std::vector<Operator> vec_operator_;
    const unsigned int MAX_OF_OPERATOR = 20;
    unsigned int current_operator;
};

