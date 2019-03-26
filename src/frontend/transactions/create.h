//This file contains the create class for create.cpp file

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  // For userList and eventList vectors
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include <regex>

#include "../helper/user.h"

#ifndef CREATE_H_
#define CREATE_H_

class create
{
public:
  create(User &currentUser, vector<User> &userList, string userAccounts, string availableTickets, string dailyTransactionFile);
};

#endif
