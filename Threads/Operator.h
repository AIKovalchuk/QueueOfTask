#pragma once
#include "space.h"
#include <mutex>

using namespace space;
class Manager;
class Task;
class Operator
{
    
protected:
    Manager* manager_;
public:
    Operator();
    Operator(Manager* manager);
    virtual ~Operator();
    void DoTask(Task && task);
    void Work();
    void PrintTask(unsigned int i);
    void GetTask(Task&& task);
    void Off();
    void destroy();
private:
    Experience experience_;
    bool work;
};

