//This file declares the mainMenu method to be defined in frontend.cpp 

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  // For userList and eventList vectors
#include <iomanip> // setprecision
#include <sstream> // stringstream

using namespace std;

#ifndef FRONTEND_FRONTEND_H
#define FRONTEND_FRONTEND_H

void mainMenu(string userAccounts, string availableTickets, string dailyTransactionFile);

#endif //FRONTEND_FRONTEND_H
