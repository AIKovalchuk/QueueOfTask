#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include "Task.h"
#include "Manager.h"
#include "space.h"

using namespace space;

class Client
{
protected:
    Manager* manager_;
public:
    Client(Manager* manager);
    ~Client();

	void Run();

	int GetRandomNumber(int, int);

	

private:
	int nomer; //nomer zadachi

};

#endif