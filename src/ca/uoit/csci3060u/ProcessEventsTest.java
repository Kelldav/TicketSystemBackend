package ca.uoit.csci3060u;

import org.junit.Assert;

import static org.junit.Assert.*;

public class ProcessEventsTest {

    @org.junit.Test
    public void readTicketsFile() {
        ProcessEvents processEvents = new ProcessEvents();
        Boolean result = processEvents.readTicketsFile("files/availableTickets.txt");
        Assert.assertEquals(true, result);
    }

    @org.junit.Test
    public void getEvents() {
        ProcessEvents processEvents = new ProcessEvents();
        processEvents.readTicketsFile("files/availableTickets.txt");
        Assert.assertEquals(2, processEvents.getEvents().size());
    }
}