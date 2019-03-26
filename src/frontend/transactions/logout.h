//This file contains the Logout class for Logout.cpp file

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  // For userList and eventList vectors
#include <iomanip> // setprecision
#include <sstream> // stringstream

#include "../helper/user.h"

#ifndef LOGOUT_H_
#define LOGOUT_H_

class Logout
{
public:
  Logout(User &currentUser, string userAccounts, string availableTickets, string dailyTransactionFile);
};

#endif
