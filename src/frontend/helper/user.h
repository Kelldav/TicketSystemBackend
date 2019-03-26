//This file contains the User class for user.cpp file

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  // For userList and eventList vectors
#include <iomanip> // setprecision
#include <sstream> // stringstream

#ifndef USER_H_
#define USER_H_

using namespace std;

/**
   * This is the User class which represents the events for the Ticket Selling Service System.
   * @param args Unused.
   * @return Nothing.
   */

class User
{
private:
  string username;
  string accountType;
  float credit;
  bool loggedIn;

public:
  User();                                                                 // Constructor (null)
  User(string username, string accountType, float credit, bool loggedIn); // Constructor

  // Getter and setter methods
  string getUsername();
  void setUsername(string username);
  string getAccountType();
  void setAccountType(string accountType);
  float getCredit();
  void setCredit(float newCredit);
  bool getLoggedIn();
  void setLoggedIn(bool loginStatus);
};

#endif