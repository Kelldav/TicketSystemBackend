//This file contains the declerations of the fileIO methods that are defined in fileIO.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  // For userList and eventList vectors
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include "user.h"
#include "event.h"

using namespace std;

#ifndef FRONTEND_FILEIO_H
#define FRONTEND_FILEIO_H

vector<Event> readEvents(string availableTickets);
vector<User> readUsers(string userAccounts);
void writeCreateDeleteAddCreditEnd(string code, string username, string accountType, float credit, string dailyTransactionFile);
void writeBuySell(string code, string eventName, string username, int numOfTickets, float pricePerTicket, string dailyTransactionFile);
void writeRefund(string code, string buyerName, string sellerName, float credit, string dailyTransactionFile);

// Helper functions
string paddingSpace(string type, string name);
string paddingZero(string type, float credit, int numOfTickets);

#endif //FRONTEND_FILEIO_H
