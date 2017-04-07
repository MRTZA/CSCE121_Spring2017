
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

#include "std_lib_facilities_4"

// include the following to get current Date and Time
#include <iomanip>
#include <ctime>

#include "chrono.h"
#include "chrono.cpp"

using namespace Chrono;

//------------------------------------------------------------------------------

namespace Hades {

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

  // modifying operations:
  void add_patron(Patron n); // check if patron's acct num exists and initialize
  void add_trans(Transaction n);

private:
  vector<Patron> p;
  vector<Transaction> t;

};

//------------------------------------------------------------------------------

bool patron_exists(Patron& p); // return true if patron acct num exists

//------------------------------------------------------------------------------

void brokerage_state(int n); // different ouput options (1-3)

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Brokerage& b);
istream& operator>>(istream& is, Brokerage& bb);

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

  Stock(int t, double p); // check for valid type and price and initialize
  Stock(); // default constructor

  // non-modifying operations:
  string get_type_num() const { return t; }
  double get_price() const { return p; }

  string get_type(int n);

private:
  int t;
  double p;

};

//------------------------------------------------------------------------------

bool valid_type(int n); // returns true if int is between 1-5, inclusive
bool valid_price(double n); // return true if price is positive

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
  Stock get_Stock() const { return s; }
  double get_amount() const { return a; }
  double get_value() const { return v; }

  // modifying operations:
  void set_value() { v = s.get_price()*a; }

private:
  Stock s;
  double a;
  double v;

};

//------------------------------------------------------------------------------

bool valid_amount(double n); // returns true if amount is a positive number

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
  string get_name() const { return n; }
  int get_acct_num() const { return a; }
  vector<Share> get_shares() const { return s; }
  double get_cash() const { return c; }
  double get_bal() const { return b; }

  // modifying operations:
  void sale(Share s);
  void buy(Share s);
  void add(double n);
  void rem(double n);

private:
  string n;
  int a;
  vector<Share> s;
  double c;
  double b;

};

//------------------------------------------------------------------------------

bool valid_name(string s); // return true if "firstname_lastname" format
bool valid_acct_num(int n); // return true if non negative number

//------------------------------------------------------------------------------

void add_trans(Transaction t);

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

  Transaction(Date d, Time, t, Patron p, int ty, Share s); // check type is (1-2) and initialize
  Transaction(Date d, Time t, Patron p, int ty, double a); // check type is (1-2) and amount is positive and initialize
  Transaction(); // default constructor

  // non-modifying operations:
  Date get_date() const { return d; }
  Time get_time() const { return t; }
  Patron get_patron() const { return p; }
  int get_type_num() const { return ty; }
  Share get_share() const { return s; }
  double get_amount() const { return a; }

  string get_type(int n);

private:
  Date d;
  Time t;
  Patron p;
  int ty;
  Share s;
  double a;

  bool c; // constructor sets true if cash transaction, false if stock transaction

}

//------------------------------------------------------------------------------

bool valid_type(int n); // returns true if between 1-2, inclusive
bool valid_amount(double n); // returns true if positive number

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Transaction& t);
istream& operator>>(istream& is, Transaction& tt);

//------------------------------------------------------------------------------

} // Hades
