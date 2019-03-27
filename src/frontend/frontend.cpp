#include "frontend.h"
#include "helper/fileIO.h"
#include "transactions/login.h"
#include "transactions/logout.h"
#include "transactions/create.h"
#include "transactions/deleteAccount.h"
#include "transactions/buy.h"
#include "transactions/sell.h"
#include "transactions/refund.h"
#include "transactions/addCredit.h"

using namespace std;

// Global variables
User currentUser;
vector<User> userList;
vector<Event> eventList;

/**
   * This method invokes the main menu.
   * @param userAccounts The name & path of the user accounts file given
   * @param availableTickets The name & path of the available tickets file given
   * @param dailyTransactionFile The name & path of the daily transaction file given
   * @return Nothing.
   */
void mainMenu(string userAccounts, string availableTickets, string dailyTransactionFile)
{
    userList = readUsers(userAccounts);
    eventList = readEvents(availableTickets);
    string cmd;

    cout << "Enter a system command: ";
    cin >> cmd;
    cout << endl;

    if (cmd == "login")
    {
        Login login = Login(currentUser, userList, userAccounts, availableTickets, dailyTransactionFile);
    }
    else if (cmd == "logout")
    {
        Logout logout = Logout(currentUser, userAccounts, availableTickets, dailyTransactionFile);
    }
    else if (cmd == "create")
    {
        create createUser = create(currentUser, userList, userAccounts, availableTickets, dailyTransactionFile);
    }
    else if (cmd == "delete")
    {
        deleteAccount deleteAccount1 = deleteAccount(currentUser, userList, userAccounts, availableTickets, dailyTransactionFile);
    }
    else if (cmd == "buy")
    {
        buyTicket buyTicket1 = buyTicket(currentUser, eventList, userList, userAccounts, availableTickets, dailyTransactionFile);
    }
    else if (cmd == "sell")
    {
        sellTickets sellTickets1 = sellTickets(currentUser, userAccounts, availableTickets, dailyTransactionFile);
    }
    else if (cmd == "refund")
    {
        refund refund1 = refund(currentUser, userList, userAccounts, availableTickets, dailyTransactionFile);
    }
    else if (cmd == "addcredit")
    {
        addCredit addCredit1 = addCredit(currentUser, userList, userAccounts, availableTickets, dailyTransactionFile);
    }
    else if (cmd == "exit")
    {
        exit(0);
    }
    else
    {
        cout << "Error: Invalid command" << endl;
        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
    }
}
/**
   * Main method starts the program and runs the main menu method to begin
   * @param argc The number of arguements
   * @param argv Inputted command line arguements. A list containing all the nessecary file names & paths to run.
   * @return an integer zero
*/
int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        string userAccounts = argv[1];
        string availableTickets = argv[2];
        string dailyTransactionFile = argv[3];
        cout << "Welcome to the Ticket Selling Service System" << endl;
        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
    }
    else
    {
        cout << "Error: Invalid number of arguments." << endl;
        cout << "Expecting: ./frontend files/userAccounts.txt files/availabletickets.txt files/dailyTransactionFile.txt" << endl;
    }

    return 0;
}