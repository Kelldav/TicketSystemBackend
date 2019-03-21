package ca.uoit.csci3060u;

import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class UpdateFilesTest {
    
    @Test
    public void writeDTF() {
        processTransactions processTransactions = new processTransactions();
        if (processTransactions.readMergedTransactions("files/dailyTransactionFile.txt")) {
            ProcessUsers processUsers = new ProcessUsers();
            if (processUsers.readUsersFile("files/userAccounts.txt")) {
                ProcessEvents processEvents = new ProcessEvents();
                if (processEvents.readTicketsFile("files/availableTickets.txt")) {
                    UpdateFiles updateFiles = new UpdateFiles(processTransactions.getTransactions(), processUsers.getUsers(), processEvents.getEvents());
                    Boolean result1 = updateFiles.writeDTF();
                    assertEquals(true, result1);
                }
                else {
                    Assert.fail("Error reading Available Tickets file");
                }
            }
            else {
                Assert.fail("Error reading User Accounts file");
            }
        }
        else {
            Assert.fail("Error reading Daily Transaction file");
        }

    }

    @Test
    public void writeEventsFile() {
        processTransactions processTransactions = new processTransactions();
        if (processTransactions.readMergedTransactions("files/dailyTransactionFile.txt")) {
            ProcessUsers processUsers = new ProcessUsers();
            if (processUsers.readUsersFile("files/userAccounts.txt")) {
                ProcessEvents processEvents = new ProcessEvents();
                if (processEvents.readTicketsFile("files/availableTickets.txt")) {
                    UpdateFiles updateFiles = new UpdateFiles(processTransactions.getTransactions(), processUsers.getUsers(), processEvents.getEvents());
                    Boolean result1 = updateFiles.writeEventsFile();
                    assertEquals(true, result1);
                }
                else {
                    Assert.fail("Error reading Available Tickets file");
                }
            }
            else {
                Assert.fail("Error reading User Accounts file");
            }
        }
        else {
            Assert.fail("Error reading Daily Transaction file");
        }
    }

    @Test
    public void writeUserAccountsFile() {
        processTransactions processTransactions = new processTransactions();
        if (processTransactions.readMergedTransactions("files/dailyTransactionFile.txt")) {
            ProcessUsers processUsers = new ProcessUsers();
            if (processUsers.readUsersFile("files/userAccounts.txt")) {
                ProcessEvents processEvents = new ProcessEvents();
                if (processEvents.readTicketsFile("files/availableTickets.txt")) {
                    UpdateFiles updateFiles = new UpdateFiles(processTransactions.getTransactions(), processUsers.getUsers(), processEvents.getEvents());
                    Boolean result1 = updateFiles.writeUserAccountsFile();
                    assertEquals(true, result1);
                }
                else {
                    Assert.fail("Error reading Available Tickets file");
                }
            }
            else {
                Assert.fail("Error reading User Accounts file");
            }
        }
        else {
            Assert.fail("Error reading Daily Transaction file");
        }
    }

    @Test
    public void paddingZero() {
    }

    @Test
    public void paddingSpace() {
    }
}