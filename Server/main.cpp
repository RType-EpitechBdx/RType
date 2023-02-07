#include "Server.hpp"
#include <iostream>
#include <vector>

int main()
{
    Server server;
    server.setPort(55002);
    server.startServer();
    return 0;
}