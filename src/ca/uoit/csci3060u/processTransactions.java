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
					float credit = Float.parseFloat(line.substring(22, 29));

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
				else if (code.equals("03") || code.equals("04")) {
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

	public ArrayList<Transaction> getTransactions() {
		return this.transactionList;
	}


}