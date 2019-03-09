public class User {
    private String username;
    private String accountType;
    private float credit;

    /**
     * User class constructor
     * 
     * @return None
     */
    public User(String username, String accountType, float credit) {
        this.username = username;
        this.accountType = accountType;
        this.credit = credit;
    }

    /**
     * This method gets the User's name and returns it as a string.
     * 
     * @return the username
     */
    public String getUsername() {
        return username;
    }

    /**
     * This method gets the User's account type and returns it as a string.
     * 
     * @return the accountType
     */
    public String getAccountType() {
        return accountType;
    }

    /**
     * This method gets the User's current credit and returns it as a float.
     * 
     * @return the credit
     */
    public float getCredit() {
        return credit;
    }

}