#include "pch.h"
#include "Task.h"

Task::Task()
{
}

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