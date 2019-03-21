package ca.uoit.csci3060u;

import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class processTransactionsTest {

    @Test
    public void readMergedTransactions() {
        processTransactions pt = new processTransactions();
        Boolean result = pt.readMergedTransactions("files/dailyTransactionFile.txt");
        Assert.assertEquals(true, result);
    }

    @Test
    public void getTransactions() {
        processTransactions pt = new processTransactions();
        Boolean result = pt.readMergedTransactions("files/dailyTransactionFile.txt");
        if (result) {
            Assert.assertEquals(2, pt.getTransactions().size());
        } else {
            Assert.fail("Error reading Available tickets file");
        }
    }
}