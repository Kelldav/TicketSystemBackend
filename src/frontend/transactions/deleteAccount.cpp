#include "deleteAccount.h"
#include "../frontend.h"
#include "../helper/fileIO.h"

using namespace std;

/**
   * This method deletes a given users account. Admin privileges are required.
   * @param currUser A reference to the current user
   * @param users A list of all the user accounts
   * @param userAccounts The name & path of the user accounts file given
   * @param availableTickets The name & path of the available tickets file given
   * @param dailyTransactionFile The name & path of the daily transaction file given
   * @return Nothing.
*/
deleteAccount::deleteAccount(User &currUser, vector<User> &users, string userAccounts, string availableTickets, string dailyTransactionFile)
{
    User &currentUser = const_cast<User &>(currUser);
    vector<User> &userList = const_cast<vector<User> &>(users);

    if (currentUser.getAccountType() == "AA")
    {
        string username;
        bool found = false;

        cout << "Enter a username to delete: ";
        cin >> username;
        cout << endl;

        if (currentUser.getUsername() != username)
        {

            for (int i = 0; i < userList.size(); i++)
            {
                if (userList[i].getUsername() == username)
                {
                    found = true;

                    // Write delete user to daily transaction file
                    writeCreateDeleteAddCreditEnd("02", userList[i].getUsername(), userList[i].getAccountType(), userList[i].getCredit(), dailyTransactionFile);

                    // Remove user from userList
                    userList.erase(userList.begin() + i);

                    cout << "User deleted successfully" << endl;
                    mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                }
            }
            if (!found)
            {
                cout << "Error: Username does not exist." << endl;
                mainMenu(userAccounts, availableTickets, dailyTransactionFile);
            }
        }
        else
        {
            cout << "Error: You can't delete your own account while logged in" << endl;
            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
        }
    }
    else
    {
        // Only if it doesn't exist
        cout << "Error: You do not have adequate permissions for this task." << endl;
        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
    }
}