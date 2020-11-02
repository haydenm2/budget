#ifndef BUDGET_CLASS_HPP
#define BUDGET_CLASS_HPP

#include <string>
#include <sqlite3.h>

#include "Date.hpp"


class Budget
{
public:
    Budget();
    Budget(sqlite3* db);
    ~Budget();
    void add_item(float value, std::string category, Date date, std::string description);
    void output_month(std::string month);
private:
    sqlite3* database;
};

#endif
