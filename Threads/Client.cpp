#include "pch.h"
#include "Client.h"
#include "Manager.h"

Client::Client(Manager* manager)
{
    this->manager_ = manager;
}


Client::~Client()
{
}
