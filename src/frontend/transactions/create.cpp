#include "create.h"
#include "../frontend.h"
#include "../helper/fileIO.h"

using namespace std;

/**
   * This method creates a new user account. Admin privileges are required.
   * @param currUser A reference to the current user
   * @param users A list of all the user accounts
   * @param userAccounts The name & path of the user accounts file given
   * @param availableTickets The name & path of the available tickets file given
   * @param dailyTransactionFile The name & path of the daily transaction file given
   * @return Nothing.
*/
create::create(User &currUser, vector<User> &users, string userAccounts, string availableTickets, string dailyTransactionFile)
{
    User &currentUser = const_cast<User &>(currUser);
    vector<User> &userList = const_cast<vector<User> &>(users);

    if (currentUser.getAccountType() == "AA")
    {
        string username;
        string accountType;

        cout << "Enter a username: ";
        cin >> username;
        cout << endl;

        // Check if the username entered is more than 15 characters
        if (username.length() > 15)
        {
            cout << "Error: Username cannot be more than 15 characters." << endl;
            mainMenu(userAccounts, availableTickets, dailyTransactionFile);
        }

        // Exits to main menu if username exists
        for (int i = 0; i < userList.size(); i++)
        {
            if (userList[i].getUsername() == username)
            {
                cout << "Error: Username already exists!" << endl;
                mainMenu(userAccounts, availableTickets, dailyTransactionFile);
            }
        }

        cout << "Enter user privilege: ";
        cin >> accountType;
        cout << endl;

        if ((accountType == "AA") || (accountType == "FS") || (accountType == "BS") || (accountType == "SS"))
        {
            // Add credit to new user
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

                    if (creditAmount >= 0)
                    {
                        // Write new user to userList
                        User tempUser = User(username, accountType, creditAmount, false);
                        userList.push_back(tempUser);

                        // TODO: Write new user to daily transaction file
                        writeCreateDeleteAddCreditEnd("01", tempUser.getUsername(), tempUser.getAccountType(), tempUser.getCredit(), dailyTransactionFile);

                        // Print status
                        if (accountType == "AA")
                            cout << "Admin user created successfully" << endl;
                        else if (accountType == "FS")
                            cout << "Full standard user created successfully" << endl;
                        else if (accountType == "BS")
                            cout << "Buy standard user created successfully" << endl;
                        else if (accountType == "SS")
                            cout << "Sell Standard user created successfully" << endl;
                    }
                    else
                    {
                        cout << "Error: The credit amount cannot be a negative value" << endl;
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
            cout << "Error: Invalid input" << endl;
        }
        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
    }
    else
    {
        cout << "Error: You do not have adequate permissions for this task." << endl;
        mainMenu(userAccounts, availableTickets, dailyTransactionFile);
    }
}