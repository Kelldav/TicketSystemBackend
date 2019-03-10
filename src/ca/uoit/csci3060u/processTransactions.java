package ca.uoit.csci3060u;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class processTransactions {
	private ArrayList<Transaction> transactionList; // Arraylist that will contain all the transactions from
													// mergedtransactions

	/**
	 * Scans the merged transaction file and outputs the information
	 * 
	 * @param filename - Text file containing the merged transactions.
	 *                 XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC (01-create, 02-delete,
	 *                 06-addCredit, 00-end of session)
	 *                 XX_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC (05-refund)
	 *                 XX_EEEEEEEEEEEEEEEEEEE_SSSSSSSSSSSSS_TTT_PPPPPP (03-sell,
	 *                 04-buy)
	 * 
	 */
	void readMergedTransactions(String filename) {
		transactionList = new ArrayList<Transaction>();
		int i;
		String character;
		BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader(filename));
			String line = reader.readLine();
			while (line != null) {
				String code = line.substring(0, 2);

				// reading a transaction of buy, delete, addCredit or end of session
				if (code.equals("01") || code.equals("02") || code.equals("06") || code.equals("00")) {
					i = 18;
					character = line.substring(i - 1, i);
					while (character == " ") {
						i--;
						character = line.substring(i - 1, i);
					}
					String username = line.substring(3, i);
					String userType = line.substring(19, 21);
					float credit = Float.parseFloat(line.substring(22, 31));

					// Create temp transaction from line and append transaction to transactionList
					Transaction tempTransaction = new Transaction(code, username, userType, credit);
					transactionList.add(tempTransaction);
				}

				// reading a transaction of refund
				else if (code.equals("05")) {
					i = 18;
					character = line.substring(i - 1, i);
					while (character == " ") {
						i--;
						character = line.substring(i - 1, i);
					}
					String username = line.substring(3, i);

					i = 34;
					character = line.substring(i - 1, i);
					while (character == " ") {
						i--;
						character = line.substring(i - 1, i);
					}
					String seller = line.substring(19, i);
					float credit = Float.parseFloat(line.substring(35, 44));

					Transaction tempTransaction = new Transaction(code, username, seller, credit);
					transactionList.add(tempTransaction);
				}

				// reading a transaction of sell or buy
				else if (code.equals("3") || code.equals("4")) {
					i = 22;
					character = line.substring(i - 1, i);
					while (character == " ") {
						i--;
						character = line.substring(i - 1, i);
					}
					String eventName = line.substring(3, i);

					i = 36;
					character = line.substring(i - 1, i);
					while (character == " ") {
						i--;
						character = line.substring(i - 1, i);
					}
					String seller = line.substring(23, i);

					int ticketAmount = Integer.parseInt(line.substring(37, 40));
					float ticketPrice = Float.parseFloat(line.substring(41, 47));

					Transaction tempTransaction = new Transaction(code, eventName, seller, ticketAmount, ticketPrice);
					transactionList.add(tempTransaction);
				}

				line = reader.readLine(); // read next line
			}
			reader.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	/**
	 * Appends the transaction to today's transaction file
	 */
	void processTransactions() {

	}

/**
   * This method adds padding (zeros) to credit, number of tickets, or ticket price strings for writing to the daily transaction file.
   * @param type - Dictates the type of numerical input
   * @param credit - The amount of credit
   * @param numOfTickets - The number of tickets
   * @return string - This returns a string with the number padded by zeroes
*/
String paddingZero(String type, float credit, int numOfTickets)
{
    String str;
    String paddedStr = "";

    if (type == "credit")
    {

        str = Float.toString(credit);
        // Padding user credit (9 characters)
        if (str.length() < 9)
        {
            paddedStr = "0".repeat(9-str.length()) + str;
        }
    }
    if (type == "tickets")
    {
        str = Integer.toString(numOfTickets);
        // Padding number of tickets (3 characters)
        if (str.length() < 3)
        {
			paddedStr = "0".repeat(3-str.length()) + str;
        }
    }
    if (type == "price")
    {
		str = Float.toString(credit);
		// Padding price per ticket (6 characters)
        if (str.length() < 6)
        {
			paddedStr = "0".repeat(6-str.length()) + str;
        }
    }
    return paddedStr;
}

	/**
	 * This method adds padding spaces (_) to usernames, or event names for writing to the daily transaction file.
	 * @param type - Dictates the type of text needing space padding
	 * @param name - The text to be padded
	 * @return string - This returns the string padded with '_' characters
	 */
	String paddingSpace(String type, String name)
	{
		if (type == "name")
		{
			// Padding username (13 characters)
			if (name.length() < 13)
			{
				while (name.length() < 13) {
					name += "_";
				}
			}
		}
		else if (type == "event")
		{
			// Padding event (19 characters)
			if (name.length() < 19)
			{
				while (name.length() < 19) {
					name += "_";

				}
			}
		}
		return name;
	}

}