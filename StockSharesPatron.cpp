#include "StockSharesPatron.h"

//-----------------------------------------------------------------------------------

//STOCK CODE

Stock::Stock(string t) {
	type = t;
	switch (type) {
		case "INTC":
			price = 35.91;
			break;
		case "GOOG":
			price = 830.63;
			break;
		case "AAPL":
			price = 138.96;
			break;
		case "YHOO":
			price = 45.94;
			break;
		case "IBM":
			price = 180.53;
			break;
		default:
			error("Please use a valid stock type");
	}
}

//Default constructor results in Intel stock
Stock::Stock() {
	type = "INTC";
	double = 35.91;
}

//-----------------------------------------------------------------------------------

//SHARES CODE

Shares::Shares(Stock s, double n) {
	stockType = s;
	numShares = n;
	dollarValue = stockType.getPrice() * numShares;
}

//Default constructor is 0 shares of Intel Stock
Shares::Shares() {
	stockType = Stock();
	numShares = 0;
	dollarValue = 0;
}

//---------------------------------------------------------------------------------

//PATRON CODE

Patron::Patron(string n, int a, double c) {
	name = n;
	accountNum = a;
	cashAccount = c;
	accountBalance = c;
	portfolio.resize(5);
}

//Default constructor results in an account under John_Doe with act numer 0000 and balance $0
Patron::Patron() {
	name = "John_Doe";
	accountNum = 0000;
	cashAccount = 0;
	accountBalance = 0;
	portfolio.resize(5);
}

void Patron::add_shares(Transaction tt) {
	int idx;
	switch (tt.get_stock().get_type()) {
		case "INTC":
			idx = 0;
			break;
		case "GOOG":
			idx = 1;
			break;
		case "AAPL":
			idx = 2;
			break;
		case "YHOO":
			idx = 3;
			break;
		case "IBM":
			idx = 4;
			break;
		default:
			error("Please use a valid stock type");
	}
	portfolio.at(idx) = portfolio.at(idx) + tt.share().get_amount();
	accountBalance = accountBalance + tt.share().get_value();
}

void Patron::add_transaction(Transaction t) {
	transactions.push_back(t);
	//*********Insert Transaction code stuff here********
}