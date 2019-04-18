#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include "Task.h"
#include "Manager.h"
#include "space.h"
#include <thread>

using namespace space;

class Client
{
protected:
    Manager* manager_;

public:
    Client(Manager* manager);
    ~Client();

	void Run();

	unsigned int GetRandomNumber(int, int);

	

private:
	unsigned int nomer; //nomer zadachi
    std::shared_ptr<std::thread> thread;
};

#endif