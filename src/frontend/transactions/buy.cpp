#include "buy.h"
#include "../frontend.h"
#include "../helper/fileIO.h"

using namespace std;

/**
   * This method is used by users with full-standard, buy-standard, or admin privileges to purchase tickets to a given event.
   * @param user A reference to the current user
   * @param events A list of all the events
   * @param users A list of all the user accounts
   * @param userAccounts The name & path of the user accounts file given
   * @param availableTickets The name & path of the available tickets file given
   * @param dailyTransactionFile The name & path of the daily transaction file given
   * @return Nothing.
*/
buyTicket::buyTicket(User &user, vector<Event> &events, vector<User> &users, string userAccounts, string availableTickets, string dailyTransactionFile)
{
    User &currentUser = const_cast<User &>(user);
    vector<Event> &eventList = const_cast<vector<Event> &>(events);
    vector<User> &userList = const_cast<vector<User> &>(users);

    if (currentUser.getLoggedIn() == true)
    {
        if (currentUser.getAccountType() != "SS")
        {
            //Authencation checked, therefore begin buy setup
            string eventName;
            int numOfTickets;
            string ticketNumInput;
            string sellerUsername;
            string confirmation;

            cout << "Please enter event title: ";
            cin >> eventName;
            cout << endl;

            //Check for event errors
            bool eventFound = false;
            int eventIndex;

            for (int i = 0; i < eventList.size(); i++)
            {
                if (eventList[i].getEventname() == eventName)
                {
                    eventFound = true;
                    eventIndex = i;
                }
            }

            if (eventFound == true)
            {
                if (eventList[eventIndex].getNumOfTickets() > 0)
                {
                    regex integerCheck("^[-+]?[0-9]*$");

                    cout << "Please enter ticket amount: ";
                    cin.ignore();
                    getline(cin, ticketNumInput);
                    cout << endl;

                    if (regex_match(ticketNumInput, integerCheck))
                    {

                        numOfTickets = stoi(ticketNumInput);

                        if (numOfTickets > 0)
                        {
                            if (currentUser.getAccountType() == "AA" || numOfTickets <= 4)
                            {
                                cout << "Please enter seller username: ";
                                cin >> sellerUsername;
                                cout << endl;

                                bool sellerFound = false;

                                for (int i = 0; i < userList.size(); i++)
                                {
                                    if (userList[i].getUsername() == sellerUsername)
                                    {
                                        sellerFound = true;
                                    }
                                }

                                if (sellerFound == true)
                                {
                                    if (eventList[eventIndex].getSellername() == sellerUsername)
                                    {

                                        cout << "Please confirm this purchase, please type \"yes\" or \"no\": ";
                                        cin >> confirmation;
                                        cout << endl;

                                        if (confirmation == "yes")
                                        {

                                            //Check if user has enough credit to purchase that many tickets for that price
                                            if (currentUser.getCredit() >= eventList[eventIndex].getPriceOfTicket() * numOfTickets)
                                            {

                                                cout << "Tickets successfully purchased." << endl;

                                                currentUser.setCredit(currentUser.getCredit() - eventList[eventIndex].getPriceOfTicket() * numOfTickets);
                                                eventList[eventIndex].setNumOfTickets(eventList[eventIndex].getNumOfTickets() - numOfTickets);

                                                // TODO:
                                                writeBuySell("04", eventName, sellerUsername, eventList[eventIndex].getNumOfTickets(), eventList[eventIndex].getPriceOfTicket(), dailyTransactionFile);
                                                mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                                            }
                                            else
                                            {
                                                cout << "Error: Insufficient credit." << endl;
                                                mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                                            }
                                        }
                                        else
                                        {
                                            cout << "Purchase not confirmed, returning to main menu." << endl;
                                            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                                        }
                                    }
                                    else
                                    {
                                        cout << "Error: There is no event titled that sold by that user." << endl;
                                        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                                    }
                                }
                                else
                                {
                                    cout << "Error: Seller user does not exist." << endl;
                                    mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                                }
                            }
                            else
                            {
                                cout << "Error: The number of tickets exceeds the maximum amount." << endl;
                                mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                            }
                        }

                        else
                        {
                            cout << "Error: The number of tickets must be greater than zero." << endl;
                            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                        }
                    }
                    else
                    {
                        cout << "Error: The ticket amount contains invalid characters." << endl;
                        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                    }
                }
                else
                {
                    cout << "Error: There are no available tickets for this event." << endl;
                    mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                }
            }
            else
            {
                cout << "Error: This event does not exist." << endl;
                mainMenu(userAccounts, availableTickets, dailyTransactionFile);
            }
        }
        else
        {
            cout << "Error: You do not have adequate permissions for this task." << endl;
            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
        }
    }
    else
    {
        cout << "Error: You are not logged in." << endl;
        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
    }
}