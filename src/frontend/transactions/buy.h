//This file contains the buyTicket class for buy.cpp file

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  // For userList and eventList vectors
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include <regex>

#include "../helper/user.h"
#include "../helper/event.h"

#ifndef BUY_H_
#define BUY_H_

class buyTicket
{
public:
  buyTicket(User &currentUser, vector<Event> &eventList, vector<User> &userList, string userAccounts, string availableTickets, string dailyTransactionFile);
};

#endif
