#include "sell.h"
#include "../frontend.h"
#include "../helper/fileIO.h"

using namespace std;

/**
   * This method is used by users with full-standard, sell-standard, or admin privileges to sell tickets to a given event. 
   * @param currUser A reference to the current user
   * @param userAccounts The name & path of the user accounts file given
   * @param availableTickets The name & path of the available tickets file given
   * @param dailyTransactionFile The name & path of the daily transaction file given
   * @return Nothing.
*/
sellTickets::sellTickets(User &currUser, string userAccounts, string availableTickets, string dailyTransactionFile)
{
    User &currentUser = const_cast<User &>(currUser);

    if (currentUser.getLoggedIn() == true)
    {
        if (currentUser.getAccountType() != "BS")
        {
            //Authencation checked, therefore begin sell setup
            string eventName;
            float priceOfTickets;
            string priceInput;
            int numOfTickets;
            string ticketNumInput;

            cout << "Please enter event title: ";
            cin >> eventName;
            cout << endl;

            //Check for eventName input errors
            if (eventName.length() <= 25)
            {

                cout << "Please enter ticket price: ";
                cin.ignore();
                getline(cin, priceInput);
                cout << endl;

                regex integerCheck("^[-+]?[0-9]*$");
                regex decimalCheck("^[-+]?[0-9]*\\.[0-9]*$");
                regex validDecimalPlaceCheck("^[-+]?[0-9]*\\.[0-9]{2}$");

                //If the credit amount is an integer & only an integer, add two zero decimal places
                if (regex_match(priceInput, integerCheck))
                {
                    priceInput += ".00";
                }

                //Check if the input is a valid decimal & one with two decimal places
                if (regex_match(priceInput, decimalCheck))
                {
                    if (regex_match(priceInput, validDecimalPlaceCheck))
                    {

                        priceOfTickets = atof((priceInput).c_str());

                        //Check for priceOfTickets input errors
                        if (priceOfTickets >= 0 && priceOfTickets <= 1000)
                        {

                            cout << "Please enter number of tickets: ";
                            getline(cin, ticketNumInput);
                            cout << endl;

                            if (regex_match(ticketNumInput, integerCheck))
                            {

                                numOfTickets = stoi(ticketNumInput);
                                //Check for numOfTickets input errors
                                if (numOfTickets > 0 && numOfTickets <= 100)
                                {

                                    cout << "Event successfully setup." << endl;

                                    // write sell to daily transaction file
                                    writeBuySell("03", eventName, currentUser.getUsername(), numOfTickets, priceOfTickets, dailyTransactionFile);

                                    mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                                }

                                else if (numOfTickets > 100)
                                {
                                    cout << "Error: The number of tickets exceeds the maximum amount." << endl;
                                    mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                                }

                                else
                                {
                                    cout << "Error: The number of tickets must be greater than zero" << endl;
                                    mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                                }
                            }
                            else
                            {
                                cout << "Error: The ticket amount contains invalid characters." << endl;
                                mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                            }
                        }
                        else if (priceOfTickets > 1000)
                        {
                            cout << "Error: The ticket price exceeds the maximum amount." << endl;
                            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                        }
                        else
                        {
                            cout << "Error: The ticket price cannot be negative" << endl;
                            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                        }
                    }
                    else
                    {
                        cout << "Error: The ticket price has an invalid decimal format." << endl;
                        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                    }
                }
                else
                {
                    cout << "Error: The ticket price contains invalid characters." << endl;
                    mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                }
            }
            else
            {
                cout << "Error: The event title exceeds the character limit." << endl;
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
