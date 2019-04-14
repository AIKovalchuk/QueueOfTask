#pragma once
#include "space.h"
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
private:

};

