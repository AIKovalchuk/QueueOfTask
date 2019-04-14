#include "pch.h"
#include "Manager.h"


Manager::Manager()
{
    for (int i = 0; i < 20; i++) {
        m_operator[i] = std::move(std::make_shared<Operator>());
    }
}


Manager::~Manager()
{
}


void Manager::PutToQueue(Task&& task) {
    //TODO
}

void Manager::Run() {
    for (size_t i = 0; i<5; i++)
    {
        std::thread thread(m_operator[i]->Work);
        thread_.push_back(std::move(thread));
    }
    while (true)
    {
        if (queue_.size() > 2 * thread_.size() && thread_.size() < MAX_OF_OPERATOR) {

        }

        if (queue_.size() <= thread_.size && thread_.size() > 1) {

        }
    }
}

Task* Manager::PopTask() {
    return new Task();
}
