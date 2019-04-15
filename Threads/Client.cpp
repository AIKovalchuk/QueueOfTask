#include "pch.h"
#include "Client.h"
#include "space.h"
#include <iostream>
#include <cstdlib>

Client::Client(Manager* manager)
{
    this->manager_ = manager;
	this->nomer = 0;
}


Client::~Client()
{
}

void Client::Run()
{
	while (true)
	{
		int min = 1;
		int max = 3;
		nomer++;
		LevelOfHard slojnost = (LevelOfHard)(GetRandomNumber(min, max)); //рандомно генерит сложность
		Task zadacha(nomer, slojnost);
		manager_->PutToQueue(std::move(zadacha));
	}
}

//const int RAND_MAX = 32767;

int Client::GetRandomNumber(int min, int max)
{
	/*
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand()*fraction*(max - min + 1) + min);
	*/
	return (rand() % max + min);
}