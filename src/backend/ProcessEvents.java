
//package ca.uoit.csci3060u;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class ProcessEvents {
    private ArrayList<Event> eventList; // List containing all users in file

    /**
     * This method reads events from the availableTickets.txt file and stores them
     * in the eventList.
     * 
     * @param filename - Text file containing available tickets accounts.
     * @return Boolean - read file successfully
     */
    public Boolean readTicketsFile(String filename) {
        eventList = new ArrayList<Event>(); // Initialize eventList

        // Read availableTickets.txt file
        BufferedReader reader;
        try {
            reader = new BufferedReader(new FileReader(filename));
            String line = reader.readLine();
            while (line != null) {
                // Available tickets Format: EEEEEEEEEEEEEEEEEEE_SSSSSSSSSSSSS_TTT_PPPPPP
                // Event name - 19 characters
                // Seller's username - 14 characters
                // Number of tickets for sale - 3 characters
                // Price per ticket - 6 characters
                String eventName = line.substring(0, 19).split("_")[0];
                String sellerUsername = line.substring(20, 33).split("_")[0];
                int numOfTickets = Integer.parseInt(line.substring(34, 37));
                float ticketPrice = Float.parseFloat(line.substring(38));

                // Create temp event from line and append event to eventList
                Event tempEvent = new Event(eventName, sellerUsername, numOfTickets, ticketPrice);
                eventList.add(tempEvent);

                line = reader.readLine(); // read next line
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }

    /**
     * This method returns a list of all the events in the availableTickets.txt
     * file.
     * 
     * @return this.eventList - A list of all the events in the availableTickets.txt
     *         file.
     */
    public ArrayList<Event> getEvents() {
        return this.eventList;
    }
}
