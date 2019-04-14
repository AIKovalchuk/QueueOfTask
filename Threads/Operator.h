#pragma once
#include "space.h"

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
private:
    Experience experience_;


};

