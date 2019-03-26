#include "logout.h"
#include "../frontend.h"
#include "../helper/fileIO.h"
#include "../helper/user.h"

using namespace std;

/**
   * This method is used to logout from the ticket selling system, and writes transactions to the daily transaction file.
   * @param user A reference to the current user
   * @param userAccounts The name & path of the user accounts file given
   * @param availableTickets The name & path of the available tickets file given
   * @param dailyTransactionFile The name & path of the daily transaction file given
   * @return Nothing.
*/
Logout::Logout(User &user, string userAccounts, string availableTickets, string dailyTransactionFile)
{
    User &currentUser = const_cast<User &>(user);

    if (currentUser.getLoggedIn() == true)
    {
        // Write end session to daily transaction file
        writeCreateDeleteAddCreditEnd("00", currentUser.getUsername(), currentUser.getAccountType(), currentUser.getCredit(), dailyTransactionFile);

        // Clear current user
        currentUser.setUsername("");
        currentUser.setAccountType("");
        currentUser.setCredit(-1);
        currentUser.setLoggedIn(false);

        // Logout current user
        cout << "Logout successful\nThank you for using the Ticket Selling Service System \n"
             << endl;

        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
    }
    else
    {
        cout << "Error: You are not logged in." << endl;
        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
    }
}
