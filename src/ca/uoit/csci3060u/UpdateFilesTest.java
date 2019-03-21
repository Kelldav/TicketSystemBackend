package ca.uoit.csci3060u;

import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class UpdateFilesTest {

    @Test
    public void writeDTF() {
        processTransactions pt = new processTransactions();
        if (pt.readMergedTransactions("files/dailyTransactionFile.txt")) {
            ProcessUsers processUsers = new ProcessUsers();
            if (processUsers.readUsersFile("files/userAccounts.txt")) {
                ProcessEvents processEvents = new ProcessEvents();
                if (processEvents.readTicketsFile("files/availableTickets.txt")) {
                    UpdateFiles updateFiles = new UpdateFiles(pt.getTransactions(), processUsers.getUsers(), processEvents.getEvents());
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
        processTransactions pt = new processTransactions();
        if (pt.readMergedTransactions("files/dailyTransactionFile.txt")) {
            ProcessUsers processUsers = new ProcessUsers();
            if (processUsers.readUsersFile("files/userAccounts.txt")) {
                ProcessEvents processEvents = new ProcessEvents();
                if (processEvents.readTicketsFile("files/availableTickets.txt")) {
                    UpdateFiles updateFiles = new UpdateFiles(pt.getTransactions(), processUsers.getUsers(), processEvents.getEvents());
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
        processTransactions pt = new processTransactions();
        if (pt.readMergedTransactions("files/dailyTransactionFile.txt")) {
            ProcessUsers processUsers = new ProcessUsers();
            if (processUsers.readUsersFile("files/userAccounts.txt")) {
                ProcessEvents processEvents = new ProcessEvents();
                if (processEvents.readTicketsFile("files/availableTickets.txt")) {
                    UpdateFiles updateFiles = new UpdateFiles(pt.getTransactions(), processUsers.getUsers(), processEvents.getEvents());
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
        processTransactions pt = new processTransactions();
        if (pt.readMergedTransactions("files/dailyTransactionFile.txt")) {
            ProcessUsers processUsers = new ProcessUsers();
            if (processUsers.readUsersFile("files/userAccounts.txt")) {
                ProcessEvents processEvents = new ProcessEvents();
                if (processEvents.readTicketsFile("files/availableTickets.txt")) {
                    UpdateFiles updateFiles = new UpdateFiles(pt.getTransactions(), processUsers.getUsers(), processEvents.getEvents());
                    String str1 = updateFiles.paddingZero("credit", (float) 53.35, 0);
                    String str2 = updateFiles.paddingZero("tickets", 0, 10);
                    String str3 = updateFiles.paddingZero("price", (float) 000053.35, 0);

                    Assert.assertEquals("000053.35", str1);
                    Assert.assertEquals("010", str2);
                    Assert.assertEquals("053.35", str3);
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
    public void paddingSpace() {
        processTransactions pt = new processTransactions();
        if (pt.readMergedTransactions("files/dailyTransactionFile.txt")) {
            ProcessUsers processUsers = new ProcessUsers();
            if (processUsers.readUsersFile("files/userAccounts.txt")) {
                ProcessEvents processEvents = new ProcessEvents();
                if (processEvents.readTicketsFile("files/availableTickets.txt")) {
                    UpdateFiles updateFiles = new UpdateFiles(pt.getTransactions(), processUsers.getUsers(), processEvents.getEvents());
                    String str1 = updateFiles.paddingSpace("name", "username");
                    String str2 = updateFiles.paddingSpace("event", "admin");

                    Assert.assertEquals(13, str1.length());
                    Assert.assertEquals(19, str2.length());
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
}