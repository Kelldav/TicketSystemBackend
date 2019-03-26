//This file contains the Event class for event.cpp file

#include <iostream>
#include <string>
#include <fstream>
#include <vector>  // For userList and eventList vectors
#include <iomanip> // setprecision
#include <sstream> // stringstream

#ifndef EVENT_H_
#define EVENT_H_

using namespace std;

/**
   * This is the Events class which represents the events for the Ticket Selling Service System.
   * @param args Unused.
   * @return Nothing.
   */
class Event
{
  private:
    string eventName;
    string seller;
    int numOfTickets;
    float priceOfTickets;

  public:
    Event();                                                                        // Constructor (null)
    Event(string eventName, string seller, int numOfTickets, float priceOfTickets); // Constructor

    // Getter and setter methods
    string getEventname();
    string getSellername();
    int getNumOfTickets();
    void setNumOfTickets(int tickets);
    float getPriceOfTicket();
    void setPriceOfTicket(float price);
};

#endif