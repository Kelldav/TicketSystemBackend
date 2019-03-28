
//package ca.uoit.csci3060u;

import java.io.IOException;

public class Backend {
    public static void main(String[] args) throws IOException {
        // Have them output errors via ErrorLog
        String dailyTransactionFile;
        String userAccountsFile;
        String availableTicketsFile;

        if (args.length == 3) {
            // Read filenames
            dailyTransactionFile = args[0];
            userAccountsFile = args[1];
            availableTicketsFile = args[2];

            // Read files
            processTransactions processTransactions = new processTransactions();
            processTransactions.readMergedTransactions(dailyTransactionFile);

            ProcessUsers processUsers = new ProcessUsers();
            processUsers.readUsersFile(userAccountsFile);

            ProcessEvents processEvents = new ProcessEvents();
            processEvents.readTicketsFile(availableTicketsFile);

            // Write new files
            UpdateFiles updateFiles = new UpdateFiles(processTransactions.getTransactions(), processUsers.getUsers(),
                    processEvents.getEvents());
            updateFiles.writeDTF();
            updateFiles.writeUserAccountsFile();
            updateFiles.writeEventsFile();

        } else {
            System.out.println(
                    "Error: Invalid arguments. \n Please pass the following files in order: <Daily Transaction File> <User Accounts File> <Available Tickets File>");
        }

    }
}
