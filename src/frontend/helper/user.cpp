#include "user.h"

/**
   * This is the User which represents the user structure for the Ticket Selling Service System.
   * @param args Unused.
   * @return Nothing.
*/
User::User()
{
    username = "";
    accountType = "";
    credit = -1;
    loggedIn = false;
}
/**
   * This is the User which represents the user structure for the Ticket Selling Service System. Overloaded for input
   * @param newUser Name of the user
   * @param newType Type of the user
   * @param newCredit Credit of the user
   * @param newLoggedIn Log in status of the user 
   * @return Nothing.
*/
User::User(string newUser, string newType, float newCredit, bool newLoggedIn)
{
    username = newUser;
    accountType = newType;
    credit = newCredit;
    loggedIn = newLoggedIn;
}

/**
   * This method returns the name of the user
   * @param newUser Name of the user
   * @return username - Name of user
*/
string User::getUsername()
{
    return username;
}

/**
   * This method sets the name of the user
   * @param user -  Name of the user
   * @return nothing
*/
void User::setUsername(string user)
{
    username = user;
}

/**
   * This method gets the users account type
   * @return accountType - User account type
*/
string User::getAccountType()
{
    return accountType;
}

/**
   * This method sets the users account type
   * @param type - User account type
   * @return nothing
*/
void User::setAccountType(string type)
{
    accountType = type;
}

/**
   * This method gets the amount of credit for the user
   * @return credit - amount of credit user has
*/
float User::getCredit()
{
    return credit;
}

/**
   * This method sets the amount of credit for the user
   * @param newCredit - New amount of credit
   * @return nothing
*/
void User::setCredit(float newCredit)
{
    credit = newCredit;
}

/**
   * This method returns the loggedIn status for the user
   * @return loginStatus - Login status of the user
*/
bool User::getLoggedIn()
{
    return loggedIn;
}

/**
   * This method sets the loggedIn status for the user
   * @param loginStatus - Login status of the user
   * @return nothing
*/
void User::setLoggedIn(bool loginStatus)
{
    loggedIn = loginStatus;
}