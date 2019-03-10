package ca.uoit.csci3060u;

public class Transaction{
	String code;
	String username;
	String seller;
	String userType;
	String eventName;
	int ticketAmount;
	float ticketPrice;
	float credit;

	public Transaction(String code, String username, String userType, float credit){
		if(code == "01" || code == "02" || code == "06" || code == "00"){
			this.code = code;
			this.username = username;
			this.userType = userType;
			this.credit = credit;
		}
		
		else{
			this.code = code;
			this.username = username;
			this.seller = userType;
			this.credit = credit;
		}
	}

	public Transaction(String code, String eventName, String seller, int ticketAmount, float ticketPrice){
		this.code = code;
		this.eventName = eventName;
		this.seller = seller;
		this.ticketAmount = ticketAmount;
		this.ticketPrice = ticketPrice;
	}

}