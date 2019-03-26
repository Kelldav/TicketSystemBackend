#include "addCredit.h"
#include "../frontend.h"
#include "../helper/fileIO.h"

using namespace std;

/**
   * This method adds credit to a given users account.
   * @param currUser A reference to the current user
   * @param users A list of all the users
   * @param userAccounts The name & path of the user accounts file given
   * @param availableTickets The name & path of the available tickets file given
   * @param dailyTransactionFile The name & path of the daily transaction file given
   * @return Nothing.
*/
addCredit::addCredit(User &currUser, vector<User> &users, string userAccounts, string availableTickets, string dailyTransactionFile)
{
    User &currentUser = const_cast<User &>(currUser);
    vector<User> &userList = const_cast<vector<User> &>(users);

    if (currentUser.getLoggedIn() == true)
    {

        string creditAmountInput;

        cout << "Please enter credit amount: ";
        cin.ignore();
        getline(cin, creditAmountInput);
        cout << endl;

        float creditAmount;

        regex integerCheck("^[-+]?[0-9]*$");
        regex decimalCheck("^[-+]?[0-9]*\\.[0-9]*$");
        regex validDecimalPlaceCheck("^[-+]?[0-9]*\\.[0-9]{2}$");

        //If the credit amount is an integer & only an integer, add two zero decimal places
        if (regex_match(creditAmountInput, integerCheck))
        {
            creditAmountInput += ".00";
        }

        //Check if the input is a valid decimal & one with two decimal places
        if (regex_match(creditAmountInput, decimalCheck))
        {
            if (regex_match(creditAmountInput, validDecimalPlaceCheck))
            {

                creditAmount = atof((creditAmountInput).c_str());

                if (creditAmount >= 0 && creditAmount <= 1000)
                {
                    //If no issues with creditAmount input
                    if (currentUser.getAccountType() == "AA")
                    {
                        cout << "Please enter username to receive credit: ";

                        string creditUsername;
                        cin >> creditUsername;
                        cout << endl;

                        //If no issues with username inputuserList
                        int creditUserListIndex = -1;
                        for (int i = 0; i < userList.size(); i++)
                        {
                            if (userList[i].getUsername() == creditUsername)
                            {
                                creditUserListIndex = i;
                            }
                        }
                        if (creditUserListIndex != -1)
                        {
                            // Add credit to user
                            userList[creditUserListIndex].setCredit(userList[creditUserListIndex].getCredit() + creditAmount);

                            // TODO: Write add credit to daily transaction file
                            writeCreateDeleteAddCreditEnd("06", userList[creditUserListIndex].getUsername(), userList[creditUserListIndex].getAccountType(), userList[creditUserListIndex].getCredit(), dailyTransactionFile);

                            cout << "Credit successfully added." << endl;
                            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                        }
                        else
                        {
                            cout << "Error: Username does not exist in system" << endl;
                            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                        }
                    }
                    else
                    {
                        //If no issues with creditAmount input
                        currentUser.setCredit(currentUser.getCredit() + creditAmount);

                        // TODO: Write add credit to daily transaction file
                        writeCreateDeleteAddCreditEnd("06", currentUser.getUsername(), currentUser.getAccountType(), currentUser.getCredit(), dailyTransactionFile);

                        cout << "Credit successfully added." << endl;
                        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                    }
                }
                else if (creditAmount > 1000)
                {
                    cout << "Error: The credit amount exceeds the maximum amount." << endl;
                    mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                }
                else
                {
                    cout << "Error: The credit amount cannot be negative" << endl;
                    mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                }
            }
            else
            {
                cout << "Error: The credit amount has an invalid decimal format." << endl;
                mainMenu(userAccounts, availableTickets, dailyTransactionFile);
            }
        }
        else
        {
            cout << "Error: The credit amount contains invalid characters." << endl;
            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
        }
    }
    else
    {
        cout << "Error: You are not logged in." << endl;
        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
    }
}