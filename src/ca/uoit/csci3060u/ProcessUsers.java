package ca.uoit.csci3060u;

import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;


public class ProcessUsers {
    private ArrayList<User> userList; // List containing all users in file

    /**
     * This method reads users from a text file and stores them in the userList.
     * @param filename - Text file containing user accounts.
     * @return None
     */
    public Boolean readUsersFile(String filename) {
        userList = new ArrayList<User>(); // Initialize userList

        // Read userAccounts.txt file
        BufferedReader reader;
        try {
            reader = new BufferedReader(new FileReader(filename));
            String line = reader.readLine();
            while (line != null) {
                // User account Format: UUUUUUUUUUUUUUU_TT_CCCCCCCCC
                // Username length - 13 characters
                // User account type - 2 characters
                // User credits - 9 characters

                String username = line.substring(0, 13).split("_")[0];
                String accountType = line.substring(14, 16).split("_")[0];
                float credit = Float.parseFloat(line.substring(17));

                User tempUser = new User(username, accountType, credit);
                userList.add(tempUser);
                line = reader.readLine(); // read next line
            }
            reader.close();
            return true;
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }

    }

    /**
     * This method returns a list containing all users in the userAccounts.txt file.
     * @return this.userList - A list containing all users in the userAccounts.txt file.
     */
    public ArrayList<User> getUsers() {
        return this.userList;
    }
}