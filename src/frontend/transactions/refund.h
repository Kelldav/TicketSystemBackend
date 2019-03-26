//This file contains the refund class for refund.cpp file

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  // For userList and eventList vectors
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include <regex>

#include "../helper/user.h"

#ifndef REFUND_H_
#define REFUND_H_

class refund
{
public:
  refund(User &currentUser, vector<User> &userList, string userAccounts, string availableTickets, string dailyTransactionFile);
};

#endif
