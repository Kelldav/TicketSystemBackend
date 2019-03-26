#include "event.h"

using namespace std;
/**
   * This is the Event which represents the events structure for the Ticket Selling Service System.
   * @param args Unused.
   * @return Nothing.
*/
Event::Event()
{
    eventName = "";
    string seller = "";
    int numOfTickets = -1;
    float priceOfTickets = -1;
}
/**
   * This is the Event which represents the events structure for the Ticket Selling Service System. Overloaded for inputs
   * @param name Name of the event
   * @param sellerName Username of the seller
   * @param tickets The number of tickets for the event
   * @param price The price of each ticket 
   * @return Nothing.
*/
Event::Event(string name, string sellerName, int tickets, float price)
{
    eventName = name;
    seller = sellerName;
    numOfTickets = tickets;
    priceOfTickets = price;
}

/**
   * This method gets the event name
   * @return eventName - Name of event
*/
string Event::getEventname()
{
    return eventName;
}

/**
   * This method gets the sellers name
   * @return seller - name of seller
*/
string Event::getSellername()
{
    return seller;
}

/**
   * This method gets the number of tickets
   * @return numOfTickets - number of tickets
*/
int Event::getNumOfTickets()
{
    return numOfTickets;
}

/**
   * This method sets the number of tickets
   * @param numOfTickets - number of tickets
*/
void Event::setNumOfTickets(int tickets)
{
    numOfTickets = tickets;
}

/**
   * This method gets the price of the ticket
   * @return price - ticket price
*/
float Event::getPriceOfTicket()
{
    return priceOfTickets;
}

/**
   * This method sets the price of the ticket
   * @param price - ticket price
   * @return nothing
*/
void Event::setPriceOfTicket(float price)
{
    priceOfTickets = price;
}
