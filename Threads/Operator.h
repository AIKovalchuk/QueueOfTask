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
    Operator(Manager* manager, unsigned int);
    virtual ~Operator();
    int DoTask(Task && task);
    void Work();
    void PrintTask(unsigned int i, unsigned int time);
    int GetTask(Task&& task);
    void Off();
    void destroy();
private:
    Experience experience_;     //Опыт работы. Только для вычесления времени выполнения задачи
    bool work;                  //Переменная служит, чтобы "выключать" оператора
    unsigned int id_;           //айди оператора
};

