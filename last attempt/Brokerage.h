
/* Authors: Grant Hill, Jordan Edwards, Murtaza Hakimi
*
* ProjectSpring2017:
* Description:
*
* Phase-1: Turn in a main program BrokerageMain.cpp and all supporting files
* Brokerage.h, Brokerage.cpp, Chrono.h, Chrono.cpp and std_lib_facilities_4.h,
* plus the special Project Cover Sheet and a standard testing doc. All
* appropriate error conditions will also be tested for correct handling.
*
*/

#include "chrono.h"

using namespace Chrono;

//------------------------------------------------------------------------------

namespace Hades {

//------------------------------------------------------------------------------

/* Stock Struct:
*
* Holds information about the type and price of a stock in USD. Only holds
* stock of the five following types:
*
* - Intel: "INTC", $35.91
* - Google: "GOOG", $830.63
* - Apple: "AAPL", $138.96
* - Yahoo: "YHOO", $45.94
* - IBM: "IBM", $180.53
*
*/

//------------------------------------------------------------------------------

struct Stock {
public:
  class Invalid { }; // throw as exception

  Stock(string t); // check for valid type and initialize
  Stock(); // default constructor

  // non-modifying operations:
  double get_price() const { return price; }
  string get_type() const { return type; }

private:
  string type;
  double price;
};

//------------------------------------------------------------------------------

bool valid_stock_type(string n); // returns true if one of 5 stock types

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Stock& s);
istream& operator>>(istream& is, Stock& ss);

//------------------------------------------------------------------------------

/* Share Class:
*
* Holds information about the stock shares objects in Brokerage. I.E. the
* type of stock, the number of shares, and the equivalent USD value
*
*/

//------------------------------------------------------------------------------

class Share {
public:
  class Invalid { }; // throw as exception

  Share(Stock s, double a); // check for valid amount and initialize
  Share(); // default constructor

  // non-modifying operations:
  Stock get_stock() const { return stock; }
  double get_amount() const { return amount; }
  double get_value() const { return value; }

  // modifying operations:
  void set_value() { value = stock.get_price()*amount; }
  void change_amount(int change) {
    amount += change;
    set_value();
  }

//------------------------------------------------------------------------------

private:
bool valid_amount(double n) {
  if(n >= 0) { return true; }
  return false;
} // returns true if amount is a positive number

//------------------------------------------------------------------------------

private:
  Stock stock;
  double amount;
  double value;
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Share& s);
istream& operator>>(istream& is, Share& ss);

//------------------------------------------------------------------------------

/* Patron Class:
*
* Holds information about the customers in Brokerage. I.E. name, account
* number, stock shares held, cash account is USD, and account balance (total
* assets) in USD
*
*/

//------------------------------------------------------------------------------

class Patron {
public:
  class Invalid { }; // throw as exception

  Patron(string n, int a); // check for valid name and acct num and initialize
  Patron(); // default constructor

  // non-modifying operations:
  string get_name() const { return name; }
  int get_acct_num() const { return acct_num; }
  vector<Share> get_shares() const { return shares; }
  double get_cash() const { return cash; }
  double get_bal() const { return bal; }

  // modifying operations:
  void set_bal();

  void sale(Share n);
  void buy(Share n);

  void add(double n) { cash += n; set_bal(); }
  void rem(double n) { cash -= n; set_bal(); }

//------------------------------------------------------------------------------

private:
  bool valid_name(string s); // return true if "firstname_lastname" format

//------------------------------------------------------------------------------

  bool valid_acct_num(int n) {
    if(n>=0 && n<=9999) { return true; }
    return false;
  } // return true if non negative number

//------------------------------------------------------------------------------

private:
  string name;
  int acct_num;
  vector<Share> shares;
  double cash;
  double bal;
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Patron& p);
istream& operator>>(istream& is, Patron& pp);

//------------------------------------------------------------------------------

/* Transaction Struct:
*
* Holds information about Patron stock Shares Sale/Buy in their account, and
* Patron cash Add/Remove to/from their account. Each Transaction should
* include:
*
* - Stock Shares or cash involved in transaction
* - Patron name, account number, and resulting account balance in terms of
*   stock shares value and cash in USD
* - A string containing the transaction type
* - The transaction date and time
*
*/

//------------------------------------------------------------------------------

struct Transaction {
public:
  class Invalid { };

  Transaction(Date date, Time time, Patron patron, string type, string actual, double amount); // check type is (1-2) and initialize
  Transaction(); // default constructor

  // non-modifying operations:
  Date get_date() const { return date; }
  Time get_time() const { return time; }
  Patron get_patron() const { return patron; }
  double get_amount() const { return amount; }
  bool is_cash() const { return isCash; }
  string get_type() const { return type; };
  string get_actual() const { return actual; }
  double get_value() const { return value; }

private:
  Date date;
  Time time;
  Patron patron;
  string type;
  string actual;
  double amount;

  double value = 1.0;


  bool isCash = false; // constructor sets true if cash transaction

//------------------------------------------------------------------------------

  bool valid_type(string n); // returns true if add, sale, buy, or remove
//------------------------------------------------------------------------------

  bool valid_act(string n);  // returns true if 1 of four stocks or "cash"
//------------------------------------------------------------------------------

  bool valid_am(double n) {
    if(n>=0) { return true; }
    return false;
  } // returns true if positive number

//------------------------------------------------------------------------------

};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Transaction& t);
istream& operator>>(istream& is, Transaction& tt);

//------------------------------------------------------------------------------

/* Brokerage Class:
*
* Deals only in USD, contains a brokerage_state function to display data to
* the user in BrokerageMain.cpp, and contains a list of Patrons and a list of
* Transactions done by Patrons.
*
*/

//------------------------------------------------------------------------------

class Brokerage {
public:
  class Invalid { }; // throw as exception

  Brokerage(string file_name); // check for valid file name and initialize
  Brokerage(); // default constructor

  // non-modifying operations:
  vector<Patron> get_patrons() const { return p; }
  vector<Transaction> get_trans() const { return t; }
  vector<Share> get_total_shares() const { return totalShares; }
  double get_total_cash() const { return totalCash; }
  double get_total_USD() const { return totalUSD; }

  // modifying operations:
  void set_totalCash();
  void set_totalUSD();
  void add_patron(Patron n); // check if patron's acct num exists and initialize
  void add_trans(Transaction n);

  bool patron_exists(Patron n); // return true if patron acct num exists

private:
  vector<Patron> p;
  vector<Transaction> t;
  vector<Share> totalShares;
  double totalCash;
  double totalUSD;
};

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Brokerage& b);
istream& operator>>(istream& is, Brokerage& bb);

//------------------------------------------------------------------------------

} // hades
