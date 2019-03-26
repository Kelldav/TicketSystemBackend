//This file contains the deleteAccount class for deleteAccount.cpp file

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  // For userList and eventList vectors
#include <iomanip> // setprecision
#include <sstream> // stringstream

#include "../helper/user.h"

#ifndef DELETEACCOUNT_H_
#define DELETEACCOUNT_H_

class deleteAccount
{
public:
  deleteAccount(User &currentUser, vector<User> &userList, string userAccounts, string availableTickets, string dailyTransactionFile);
};

#endif
