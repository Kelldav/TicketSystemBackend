package ca.uoit.csci3060u;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class UpdateFiles {
    ArrayList<Transaction> transactionList;
    ArrayList<User> userList;
    ArrayList<Event> eventList;

    public UpdateFiles(ArrayList<Transaction> transactionList, ArrayList<User> userList, ArrayList<Event> eventList) {
        this.transactionList = transactionList;
        this.userList = userList;
        this.eventList = eventList;
    }

    /**
     * Appends the transaction to today's transaction file
     */
    void processTransactions() {

        for (Transaction transaction : transactionList) {
            switch(transaction.code) {
                // 00 - Logout
                case "00":
                    // update credit on logout
                    break;
                // 01 - Create
                case "01":
                    createAccount(transaction);
                    break;
                // 02 - Delete
                case "02":
                    deleteAccount(transaction);
                    break;
                // 03 - Sell
                case "03":
                    sellTicket(transaction);
                    break;
                // 04 - Buy
                case "04":
                    buyTicket(transaction);
                    break;
                // 05 - Refund
                case "05":
                    refundTicket(transaction);
                    break;
                // 06 - AddCredit
                case "06":
                    addCredit(transaction);
                    break;
                default:
                    break;
            }
        }
    }

    void createAccount(Transaction transaction) {
        User newUser = new User(transaction.username, transaction.userType, transaction.credit);
        userList.add(newUser);
    }

    void deleteAccount(Transaction transaction) {
        // Find index of user and remove it
        for (int i=0; i < userList.size(); i++) {
            if (userList.get(i).getUsername() == transaction.username) {
                userList.remove(i);
            }
        }
    }

    void sellTicket(Transaction transaction) {
        String eventName;
        String sellerUsername;
        int numOfTickets;
        float ticketPrice;

        // Update ticketList
        for (int i=0; i < eventList.size(); i++) {
            if (eventList.get(i).getEventName() == transaction.eventName) {
                eventName = transaction.eventName;
                sellerUsername = transaction.seller;
                numOfTickets = transaction.ticketAmount;
                ticketPrice = transaction.ticketPrice;

                Event newEvent = new Event(eventName, sellerUsername, numOfTickets, ticketPrice);
                eventList.add(newEvent);
            }
        }
    }

    void buyTicket(Transaction transaction) {
        int numOfTickets;

        // Update ticketList
        for (int i=0; i < eventList.size(); i++) {
            if (eventList.get(i).getEventName() == transaction.eventName) {
                numOfTickets = eventList.get(i).getNumOfTickets() - transaction.ticketAmount;
                eventList.get(i).setNumOfTickets(numOfTickets);
            }
        }

        // Update Seller Credit and Buyer Credit
        for (int i=0; i < userList.size(); i++) {
            // Buyer Credit
            if (userList.get(i).getUsername() == transaction.username) {
                float credit = transaction.ticketPrice * transaction.ticketAmount;
                userList.get(i).setCredit(userList.get(i).getCredit() - credit );
            }
            // Seller Credit
            if (userList.get(i).getUsername() == transaction.seller) {
                float credit = transaction.ticketPrice * transaction.ticketAmount;
                userList.get(i).setCredit(userList.get(i).getCredit() + credit );
            }
        }
    }

    void refundTicket(Transaction transaction) {
        int numOfTickets;

        // Update ticketList
        for (int i=0; i < eventList.size(); i++) {
            if (eventList.get(i).getEventName() == transaction.eventName) {
                numOfTickets = eventList.get(i).getNumOfTickets() + transaction.ticketAmount;
                eventList.get(i).setNumOfTickets(numOfTickets);
            }
        }

        // Update Seller Credit and Buyer Credit
        for (int i=0; i < userList.size(); i++) {
            // Buyer Credit
            if (userList.get(i).getUsername() == transaction.username) {
                float credit = transaction.ticketPrice * transaction.ticketAmount;
                userList.get(i).setCredit(userList.get(i).getCredit() + credit );
            }
            // Seller Credit
            if (userList.get(i).getUsername() == transaction.seller) {
                float credit = transaction.ticketPrice * transaction.ticketAmount;
                userList.get(i).setCredit(userList.get(i).getCredit() - credit );
            }
        }
    }

    void addCredit(Transaction transaction) {
        // Update User Credit
        for (int i=0; i < userList.size(); i++) {
            if (userList.get(i).getUsername() == transaction.username) {
                float credit = transaction.ticketPrice * transaction.ticketAmount;
                userList.get(i).setCredit(userList.get(i).getCredit() + credit );
            }
        }
    }

    void writeDTF() throws IOException {
        // Write updated transactions to new daily transactions file
        String transactionStr = "";
        String filename = "newDailyTransactionFile.txt";
        BufferedWriter writer = new BufferedWriter(new FileWriter(filename));

        for (Transaction transaction : transactionList) {
            if (transaction.code.equals("01") || transaction.code.equals("02") || transaction.code.equals("06") || transaction.code.equals("00")) {
                transactionStr = transaction.code + paddingSpace("name", transaction.username) + transaction.userType + paddingZero("credit", transaction.credit, 0);
            }
            else if (transaction.code.equals("05")) {
                transactionStr = transaction.code + paddingSpace("name", transaction.username) + paddingSpace("name", transaction.seller) + paddingZero("credit", transaction.credit, 0);
            }
            else if (transaction.code.equals("04") || transaction.code.equals("04")) {
                transactionStr = transaction.code + paddingSpace("event", transaction.eventName) + paddingSpace("name", transaction.seller) + paddingZero("tickets", 0,transaction.ticketAmount) + paddingZero("price", transaction.ticketPrice, 0);
            }

            writer.write(transactionStr);
        }
        writer.close();

    }

    void writeEventsFile() throws IOException {
        String eventStr = "";
        String filename = "newAvailableTickets.txt";
        BufferedWriter writer = new BufferedWriter(new FileWriter(filename));

        for (Event event : eventList) {
            eventStr = paddingSpace("event", event.getEventName()) + paddingSpace("name", event.getSellerUsername()) + paddingZero("tickets", 0, event.getNumOfTickets()) + paddingZero("price", event.getTicketPrice(), 0);
            writer.write(eventStr);
        }
        writer.close();

    }

    void writeUserAccountsFile() throws IOException {
        String userStr = "";
        String filename = "newUserAccounts.txt";
        BufferedWriter writer = new BufferedWriter(new FileWriter(filename));

        for (User user : userList) {
            userStr = paddingSpace("name", user.getUsername()) + user.getAccountType() + paddingZero("credit", user.getCredit(), 0);
            writer.write(userStr);
        }
        writer.close();
    }

    /**
     * This method adds padding (zeros) to credit, number of tickets, or ticket price strings for writing to the daily transaction file.
     * @param type - Dictates the type of numerical input
     * @param credit - The amount of credit
     * @param numOfTickets - The number of tickets
     * @return string - This returns a string with the number padded by zeroes
     */
    String paddingZero(String type, float credit, int numOfTickets)
    {
        String str;
        String paddedStr = "";

        if (type == "credit")
        {

            str = Float.toString(credit);
            // Padding user credit (9 characters)
            if (str.length() < 9)
            {
                paddedStr = "0".repeat(9-str.length()) + str;
            }
        }
        if (type == "tickets")
        {
            str = Integer.toString(numOfTickets);
            // Padding number of tickets (3 characters)
            if (str.length() < 3)
            {
                paddedStr = "0".repeat(3-str.length()) + str;
            }
        }
        if (type == "price")
        {
            str = Float.toString(credit);
            // Padding price per ticket (6 characters)
            if (str.length() < 6)
            {
                paddedStr = "0".repeat(6-str.length()) + str;
            }
        }
        return paddedStr;
    }

    /**
     * This method adds padding spaces (_) to usernames, or event names for writing to the daily transaction file.
     * @param type - Dictates the type of text needing space padding
     * @param name - The text to be padded
     * @return string - This returns the string padded with '_' characters
     */
    String paddingSpace(String type, String name)
    {
        if (type == "name")
        {
            // Padding username (13 characters)
            if (name.length() < 13)
            {
                while (name.length() < 13) {
                    name += "_";
                }
            }
        }
        else if (type == "event")
        {
            // Padding event (19 characters)
            if (name.length() < 19)
            {
                while (name.length() < 19) {
                    name += "_";

                }
            }
        }
        return name;
    }


}
