#include "refund.h"
#include "../frontend.h"
#include "../helper/fileIO.h"

using namespace std;

/**
   * This method transfers credit from the given seller account to the given user account. Admin privileges are required.
   * @param currUser A reference to the current user
   * @param users A list of all the user accounts
   * @param userAccounts The name & path of the user accounts file given
   * @param availableTickets The name & path of the available tickets file given
   * @param dailyTransactionFile The name & path of the daily transaction file given
   * @return Nothing.
*/
refund::refund(User &currUser, vector<User> &users, string userAccounts, string availableTickets, string dailyTransactionFile)
{
    User &currentUser = const_cast<User &>(currUser);
    vector<User> &userList = const_cast<vector<User> &>(users);

    if (currentUser.getAccountType() == "AA")
    {
        string buyerUsername;
        string sellerUsername;

        bool buyerFound = false;
        bool sellerFound = false;

        int buyerUserIndex;
        int sellerUserIndex;

        float creditAmount;
        string creditAmountInput;

        cout << "Please enter buyer username: ";
        cin >> buyerUsername;
        cout << endl;

        cout << "Please enter seller username: ";
        cin >> sellerUsername;
        cout << endl;

        if (buyerUsername != sellerUsername)
        {
            cout << "Please enter refund credit amount: ";
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

                    if (creditAmount >= 0.00)
                    {
                        //Check if buyer username exists
                        for (int i = 0; i < userList.size(); i++)
                        {
                            if (userList[i].getUsername() == buyerUsername)
                            {
                                buyerFound = true;
                                buyerUserIndex = i;
                            }
                        }

                        for (int i = 0; i < userList.size(); i++)
                        {
                            if (userList[i].getUsername() == sellerUsername)
                            {
                                sellerFound = true;
                                sellerUserIndex = i;
                            }
                        }

                        if (buyerFound && sellerFound)
                        {
                            if (userList[sellerUserIndex].getCredit() >= creditAmount)
                            {
                                userList[buyerUserIndex].setCredit(userList[buyerUserIndex].getCredit() + creditAmount);
                                userList[sellerUserIndex].setCredit(userList[sellerUserIndex].getCredit() - creditAmount);

                                cout << "Refund successfully transferred" << endl;

                                // write refund to daily transaction file
                                writeRefund("05", buyerUsername, sellerUsername, creditAmount, dailyTransactionFile);

                                mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                            }
                            else
                            {
                                cout << "Error: The user does not have enough credits to transfer that amount" << endl;
                                mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                            }
                        }
                        else
                        {
                            cout << "Error: Both buyer and seller must be current users" << endl;
                            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
                        }
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
            cout << "Error: Usernames cannot be the same" << endl;
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