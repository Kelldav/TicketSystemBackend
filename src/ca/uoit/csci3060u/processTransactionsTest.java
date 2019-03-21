package ca.uoit.csci3060u;

import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class processTransactionsTest {

    @Test
    public void readMergedTransactions() {

        // branch coverage
        processTransactions pt1 = new processTransactions();
        Boolean result1 = pt1.readMergedTransactions("files/fakeDailyTransactionFile.txt");
        Assert.assertEquals(false, result1);

        // Loop coverage
        processTransactions pt2 = new processTransactions();
        Boolean result2 = pt2.readMergedTransactions("files/dailyTransactionFile.txt");
        Assert.assertEquals(true, result2);
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