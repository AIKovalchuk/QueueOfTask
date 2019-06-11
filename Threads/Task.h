#pragma once
#include "space.h"

using namespace space;

class Task
{
public:
	Task();
    Task(int, LevelOfHard);
    ~Task();

	int GetLevel();
    unsigned int GetId();

private:
	unsigned int id_;       //����� ������
	LevelOfHard level_;     //���������
};

