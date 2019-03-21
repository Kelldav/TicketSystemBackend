package ca.uoit.csci3060u;

public class Event {
    private String eventName;
    private String sellerUsername;
    private int numOfTickets;
    private float ticketPrice;

    /**
     * Event class constructor
     * 
     * @return None
     */
    public Event(String eventName, String sellerUsername, int numOfTickets, float ticketPrice) {
        this.eventName = eventName;
        this.sellerUsername = sellerUsername;
        this.numOfTickets = numOfTickets;
        this.ticketPrice = ticketPrice;
    }

    /**
     * This method gets the Event's name and returns it as a string.
     * 
     * @return the eventName
     */
    public String getEventName() {
        return eventName;
    }

    /**
     * This method gets the seller's name and returns it as a string.
     * 
     * @return the sellerUsername
     */
    public String getSellerUsername() {
        return sellerUsername;
    }

    /**
     * This method gets the number of tickets available for the event and returns it
     * as an integer.
     * 
     * @return the numOfTickets
     */
    public int getNumOfTickets() {
        return numOfTickets;
    }

    /**
     * This method gets the price per ticket for the event and returns it as a
     * float.
     * 
     * @return the ticketPrice
     */
    public float getTicketPrice() {
        return ticketPrice;
    }

    /**
     * This method sets the number of tickets available for the event.
     *
     * @return None
     */
    public void setNumOfTickets(int numOfTickets) {
        this.numOfTickets = numOfTickets;
    }

}