//This file contains the Login class for Login.cpp file

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  // For userList and eventList vectors
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include "../helper/user.h"

#ifndef LOGIN_H_
#define LOGIN_H_

class Login
{
public:
  Login(User &currentUser, vector<User> &userList, string userAccounts, string availableTickets, string dailyTransactionFile);
};

#endif
