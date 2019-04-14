#pragma once
#include "space.h"

using namespace space;

class Task
{
public:
	Task();
    Task(int);
    ~Task();
private:
    unsigned int id_;
    LevelOfHard level_;
};

