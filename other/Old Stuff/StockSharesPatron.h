#include "std_lib_facilities_4.h"

struct Stock {	
	private:
		string type;
		double price;
	public:
		Stock(string t);
		Stock();
		
		string get_type() const { return type; }
		double get_price() const { return price; }

}

class Shares {
	Stock stockType;
	double numShares;
	double dollarValue;
	
	public:
		Shares(Stock s, double n);
		Shares();
		
		double get_amount() const { return numShares; }
		double get_value() const { return dollarValue; }
		Stock get_stock() const { return stockType; }
	
}

class Patron {
	string name;
	int accountNum;
	vector<Shares> portfolio;		
	double cashAccount;
	double accountBalance;
	vector<Transaction> transactions
	
	//helper functions
	void add_shares(Transaction tt);		
	void add_cash(Transaction tt);			
	void remove_shares(Transaction tt);		
	void remove_cash(Transaction tt);		
	
	public:
		Patron(string n, int a, double c);
		Patron();
		
		string getName() const { return name; }
		int getAccountNumber() const { return accountNum; }
		double getCashAmount() const { return cashAccount; }
		double getAccountBalance() const { return accountBalance; }
		vector<Shares> getPortfolio() const { return portfolio; }
		
		void add_transaction(Transaction t);		
		bool is_overdrawn() { return (accountBalance > 0); }		
}