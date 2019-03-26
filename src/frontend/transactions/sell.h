//This file contains the sellTickets class for sell.cpp file

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  // For userList and eventList vectors
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include <regex>

#include "../helper/user.h"

#ifndef SELL_H_
#define SELL_H_

class sellTickets
{
public:
  sellTickets(User &currentUser, string userAccounts, string availableTickets, string dailyTransactionFile);
};

#endif
