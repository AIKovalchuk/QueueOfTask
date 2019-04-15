#include "pch.h"
#include "Client.h"
#include "Manager.h"
#include <stdlib.h>
Client::Client(Manager* manager)
{
    this->manager_ = manager;
}


Client::~Client()
{
}
