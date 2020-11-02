#include <iostream>
#include <sqlite3.h>
#include <signal.h>
#include <unistd.h>

#include "Budget.hpp"


static volatile bool killEvent = false;

void killSignalHandler(int signal)
{
    killEvent = false;
}

int main()
{
    signal(SIGINT, killSignalHandler);
    sqlite3* database;
    int loadError{0};
    loadError = sqlite3_open("../budget.db", &database);

    if(loadError)
    {
        std::cerr << "Error opening database " << sqlite3_errmsg(database) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened database Successfully!" << std::endl;

    Budget budget(database);

    while(!killEvent)
    {
        std::cout << "Running program..." << std::endl;
        sleep(1);
    }
    sqlite3_close(database);
    return 0;
}
