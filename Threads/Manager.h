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
    std::queue<Task> queue_;                    // очередь задач на исполнение. Попалняется благодаря клиентам и направляется в операторы
    std::vector<std::thread> thread_;           // вектор тредов. Хранит треды в которых работают операторы
    std::map<uint16_t, Operator > m_operator;   // map[operator_id] = operator. Мапа в которой хранится объект оператора по индексу
    const unsigned int MAX_OF_OPERATOR = 20;    //макс колличество операторов
    unsigned int current_operator = 0;          //текущее колличество операторов
    std::mutex mutex;                           //блокировщик для потокбезопасности
    unsigned int count = 1;                     //эээ
    int n;                                      //шо цэ
    int time = 0;                               // время для замера среднего
};

