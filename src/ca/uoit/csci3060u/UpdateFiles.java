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

    }

    void writeEventsFile() throws IOException {

    }

    void writeUserAccountsFile() throws IOException {

    }

}
