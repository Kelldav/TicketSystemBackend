#include "login.h"
#include "../helper/user.h"
#include "../frontend.h"

using namespace std;

/**
   * This method is used to login to the ticket selling service system.
   * @param user A reference to the current user
   * @param users A list of all the user accounts
   * @param userAccounts The name & path of the user accounts file given
   * @param availableTickets The name & path of the available tickets file given
   * @param dailyTransactionFile The name & path of the daily transaction file given
   * @return Nothing.
*/
Login::Login(User &user, vector<User> &users, string userAccounts, string availableTickets, string dailyTransactionFile)
{
    User &currentUser = const_cast<User &>(user);
    vector<User> &userList = const_cast<vector<User> &>(users);

    if (currentUser.getLoggedIn() == false)
    {
        string username;

        cout << "Please enter your username: ";
        cin >> username;
        cout << endl;

        // Check if username exists
        for (int i = 0; i < userList.size(); i++)
        {
            if (userList[i].getUsername().compare(username) == 0)
            {
                currentUser.setUsername(userList[i].getUsername());
                currentUser.setAccountType(userList[i].getAccountType());
                currentUser.setCredit(userList[i].getCredit());
                currentUser.setLoggedIn(true);
                break;
            }
        }
        if (currentUser.getUsername() == username)
        {
            cout << "Login successful" << endl;
            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
        }
        else
        {
            cout << "Error: Invalid username" << endl;
            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
        }
    }
    else
    {
        cout << "Error: You are already logged in" << endl;
        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
    }
}