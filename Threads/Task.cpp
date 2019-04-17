#include "pch.h"
#include "Task.h"


Task::Task(int nomer, LevelOfHard slojnost)
{
	id_ = nomer;
	level_ = slojnost;
}


Task::~Task()
{
}

int Task::GetLevel()
{
	return (int)level_;
}

unsigned int Task::GetId()
{
    return id_;
}
