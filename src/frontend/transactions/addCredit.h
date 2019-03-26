//This file contains the addCredit class for addCredit.cpp file

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  // For userList and eventList vectors
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include <regex>

#include "../helper/user.h"

#ifndef ADDCREDIT_H_
#define ADDCREDIT_H_

class addCredit
{
public:
  addCredit(User &currentUser, vector<User> &userList, string userAccounts, string availableTickets, string dailyTransactionFile);
};

#endif
