#include "fileIO.h"
#include "user.h"
#include "event.h"

/**
   * This method adds padding spaces (_) to usernames, or event names for writing to the daily transaction file.
   * @param type - Dictates the type of text needing space padding
   * @param name - The text to be padded
   * @return string - This returns the string padded with '_' characters
*/
string paddingSpace(string type, string name)
{
    if (type == "name")
    {
        // Padding username (13 characters)
        if (name.length() < 13)
        {
            while (name.length() < 13)
                name.append(" ");
        }
    }
    else if (type == "event")
    {
        // Padding event (19 characters)
        if (name.length() < 19)
        {
            while (name.length() < 19)
                name.append(" ");
        }
    }
    return name;
}

/**
   * This method adds padding (zeros) to credit, number of tickets, or ticket price strings for writing to the daily transaction file.
   * @param type - Dictates the type of numerical input
   * @param credit - The amount of credit
   * @param numOfTickets - The number of tickets
   * @return string - This returns a string with the number padded by zeroes
*/
string paddingZero(string type, float credit, int numOfTickets)
{
    string str, paddedStr;
    stringstream stream;

    if (type == "credit")
    {
        stream << fixed << setprecision(2) << credit;
        str = stream.str();
        // Padding user credit (9 characters)
        if (str.length() < 9)
        {
            paddedStr = string(9 - str.length(), '0') + str;
        }
    }
    if (type == "tickets")
    {
        str = to_string(numOfTickets);
        // Padding number of tickets (3 characters)
        if (str.length() < 3)
        {
            paddedStr = string(3 - str.length(), '0') + str;
        }
    }
    if (type == "price")
    {
        stream << fixed << setprecision(2) << credit;
        str = stream.str();
        // Padding price per ticket (6 characters)
        if (str.length() < 6)
        {
            paddedStr = string(6 - str.length(), '0') + str;
        }
    }
    return paddedStr;
}

/**
   * This method reads the userAccount file into memory and stores them as in userList variables.
   * @param userAccounts The name & path of the user accounts file given
   * @return Nothing.
*/
vector<User> readUsers(string userAccounts)
{
    vector<User> userList;
    // Populate userList
    string userAccountsFile = userAccounts;
    ifstream userStream(userAccountsFile);
    string userLine;

    if (userStream.is_open())
    {
        // Read users from userAccountFile into userList array
        while (getline(userStream, userLine))
        {
            // User account Format: UUUUUUUUUUUUUUU_TT_CCCCCCCCC
            // Username length - 13 characters
            // User account type - 2 characters
            // User credits - 9 characters
            string tempUsername = userLine.substr(0, 13);
            string username = tempUsername.substr(0, tempUsername.find(' '));
            string tempAccountType = userLine.substr(14, 2);
            float tempCredit = atof((userLine.substr(17).c_str()));
            bool tempLoggedIn = false;

            User tempUser(username, tempAccountType, tempCredit, tempLoggedIn);
            userList.push_back(tempUser);
        }
        userStream.close();
    }
    return userList;
}
/**
   * This method reads the availableTickets file into memory and stores them as in eventList variables.
   * @param availableTickets The name & path of the available tickets file given
   * @return Nothing.
*/
vector<Event> readEvents(string availableTickets)
{
    vector<Event> eventList;
    // Populate eventList
    string availableTicketsFile = availableTickets;
    ifstream ticketsStream(availableTicketsFile);
    string ticketLine;

    if (ticketsStream.is_open())
    {
        // Read Events from availableTickets
        while (getline(ticketsStream, ticketLine))
        {
            // Available tickets Format: EEEEEEEEEEEEEEEEEEE_SSSSSSSSSSSSS_TTT_PPPPPP
            // Event name - 19 characters
            // Seller's username - 14 characters
            // Number of tickets for sale - 3 characters
            // Price per ticket - 6 characters
            string eventName = "";
            string tempSeller = "";
            string seller = "";
            string tempTickets = "";
            int numOfTickets = -1;
            float priceOfTickets = -1;

            eventName = ticketLine.substr(0, 19).substr(0, ticketLine.find(' '));
            tempSeller = ticketLine.substr(20, 13);
            seller = tempSeller.substr(0, tempSeller.find(' '));
            tempTickets = ticketLine.substr(34, 37);
            numOfTickets = stoi(tempTickets.substr(0, tempTickets.find(' ')).c_str());
            priceOfTickets = atof(ticketLine.substr(38).c_str());

            Event tempEvent(eventName, seller, numOfTickets, priceOfTickets);
            eventList.push_back(tempEvent);
        }
        ticketsStream.close();
    }
    return eventList;
}

/**
   * This method writes the create, delete, addCredit, and end session (logout) transactions to the daily transaction file.
   * @param code The code used for type of transaction
   * @param username The username for the account
   * @param accountType The account type of the user
   * @param credit The amount of credit of the user
   * @param dailyTransactionFile The name & path of the daily transaction file given
   * @return Nothing.
*/
void writeCreateDeleteAddCreditEnd(string code, string username, string accountType, float credit, string dailyTransactionFile)
{
    // Write create(01), delete(02), addcredit(06), end session (00)
    // Format: XX_UUUUUUUUUUUUU_TT_CCCCCCCCC
    std::ofstream DTFStream;
    DTFStream.open(dailyTransactionFile, std::ios::app);
    DTFStream << code << " "
              << paddingSpace("name", username) << " "
              << accountType << " "
              << paddingZero("credit", credit, 0) << "\n";
    DTFStream.close();
}

/**
   * This method writes the buy and sell transactions from the buy or sell methods to the daily transaction file.
   * @param code The code used for type of transaction
   * @param eventName The name of the event in the transaction
   * @param username The username for the account
   * @param numOfTickets The number of tickets in the transaction
   * @param pricePerTicket The price of each ticket in the transaction
   * @param dailyTransactionFile The name & path of the daily transaction file given
   * @return Nothing.
*/
void writeBuySell(string code, string eventName, string username, int numOfTickets, float pricePerTicket, string dailyTransactionFile)
{
    // Write buy(04), sell(03)
    // Format: XX_EEEEEEEEEEEEEEEEEEE_SSSSSSSSSSSSS_TTT_PPPPPP
    std::ofstream DTFStream;
    DTFStream.open(dailyTransactionFile, std::ios::app);
    DTFStream << code << " "
              << paddingSpace("event", eventName) << " "
              << paddingSpace("name", username) << " "
              << paddingZero("tickets", 0.0, numOfTickets) << " "
              << paddingZero("price", pricePerTicket, 0) << "\n";
    DTFStream.close();
}

/**
   * This method writes the refund transaction from the refund() method to the daily transaction file.
   * @param code The code used for type of transaction
   * @param buyerName The username of the buyer in the transaction
   * @param sellerName The username of the seller in the transaction
   * @param credit The amount of credit being transacted
   * @param dailyTransactionFile The name & path of the daily transaction file given
   * @return Nothing.
*/
void writeRefund(string code, string buyerName, string sellerName, float credit, string dailyTransactionFile)
{
    // Write buy (04), sell (03)
    // Format: XX_UUUUUUUUUUUUU_SSSSSSSSSSSSS_TTT_PPPPPP
    std::ofstream DTFStream;
    DTFStream.open(dailyTransactionFile, std::ios::app);
    DTFStream << code << " "
              << paddingSpace("name", buyerName) << " "
              << paddingSpace("name", sellerName) << " "
              << paddingZero("credit", credit, 0) << "\n";
    DTFStream.close();
}