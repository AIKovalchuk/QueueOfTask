#include "pch.h"
#include "Manager.h"


Manager::Manager()
{
}


Manager::~Manager()
{
}


void Manager::PutToQueue(Task&& task) {
    //TODO
}

void Manager::Run() {
    //TODO
}

Task* Manager::PopTask() {
    return new Task();
}