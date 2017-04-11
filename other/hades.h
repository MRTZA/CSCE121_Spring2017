
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

#include "std_lib_facilities_4.h"

// include the following to get current Date and Time
#include <iomanip>
#include <ctime>

#include "chrono.h"

using namespace Chrono;

//------------------------------------------------------------------------------

namespace Hades {

// forward-declare classes
class Transaction;
class Share;
class Stock;

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

  Patron(const Patron &ref) {
	  this->n = ref.n;
	  this->a = ref.a;
	  this->s = ref.s;
	  this->c = ref.c;
	  this->b = ref.b;
  }

  Patron(string n, int a); // check for valid name and acct num and initialize
  Patron(); // default constructor

  // non-modifying operations:
  string get_name() const { return n; }
  int get_acct_num() const { return a; }
  vector<Share *> get_shares() const { return s; }
  double get_cash() const { return c; }
  double get_bal() const { return b; }

  // modifying operations:
  void set_bal();

  void sale(Share *n);
  void buy(Share *n);

  void add(double n) { c += n; set_bal(); }
  void rem(double n) { c -= n; set_bal(); }

  void add_trans(Transaction *t);

private:
  string n;
  int a;
  vector<Share *> s;
  double c;
  double b;

  bool valid_name(string s); // return true if "firstname_lastname" format
  bool valid_acct_num(int n); // return true if non negative number

};

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Patron& p);
istream& operator>>(istream& is, Patron& pp);

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
  vector<Patron *> get_patrons() const { return p; }
  vector<Transaction *> get_trans() const { return t; }

  Share *get_share(int i) {
    return s[i];
  }

  double get_totalCash() {
    double temp;
    for(int i = 0; i<p.size(); i++) {
      temp += p[i]->get_cash();
    }
    return temp;
  }

  double get_totalUSD() {
    double temp;
    for(int i = 0; i<p.size(); i++) {
      temp += p[i]->get_bal();
    }
    return temp;
  }

  // modifying operations:
  void add_patron(Patron *n); // check if patron's acct num exists and initialize
  void add_trans(Transaction *n);

private:
  vector<Patron *> p;
  vector<Transaction *> t;

  vector<Share *> s;

  double totalCash;
  double totalUSD;

  bool patron_exists(Patron *n); // return true if patron acct num exists

  void brokerage_state(char n); // different ouput options (1-3)
};

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

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

  Stock(const Stock &ref) {
	  this->t = ref.t;
	  this->p = ref.p;
  }

  Stock(int t); // check for valid type and initialize
  Stock(); // default constructor

  // non-modifying operations:
  int get_type_num() const { return t; }
  double get_price() const { return p; }

  string get_type(int n) const;

private:
  int t;
  double p;

  bool valid_type(int n); // returns true if int is between 1-5, inclusive
};

//------------------------------------------------------------------------------

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

  Share(const Share &ref) {
	  this->s = ref.s;
	  this->a = ref.a;
	  this->v = ref.v;
  }

  Share(Stock *s, double a); // check for valid amount and initialize
  Share(); // default constructor

  // non-modifying operations:
  Stock *get_Stock() const { return s; }
  double get_amount() const { return a; }
  double get_value() const { return v; }

  void change_amount(int change) {
	  this->a += change;
  }

  // modifying operations:
  void set_value() { v = s->get_price()*a; }

private:
  Stock *s;
  double a;
  double v;


  bool valid_amount(double n); // returns true if amount is a positive number
};

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Share& s);
istream& operator>>(istream& is, Share& ss);

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

  Transaction(const Transaction &ref) {
	  this->d = ref.d;
	  this->t = ref.t;
	  this->p = ref.p;
	  this->ty = ref.ty;
	  this->s = ref.s;
	  this->a = ref.a;
	  this->c = ref.c;
  }

  Transaction(Date d, Time t, Patron *p, int ty, Share *s); // check type is (1-2) and initialize
  Transaction(Date d, Time t, Patron *p, int ty, double a); // check type is (1-2) and amount is positive and initialize
  Transaction(); // default constructor

  // non-modifying operations:
  Date get_date() const { return d; }
  Time get_time() const { return t; }
  Patron *get_patron() const { return p; }
  int get_type_num() const { return ty; }
  Share *get_share() const { return s; }
  double get_amount() const { return a; }
  bool is_cash() const { return c; }

  string get_type(int n) const;

private:
  Date d;
  Time t;
  Patron *p;
  int ty;
  Share *s;
  double a;

  bool c; // constructor sets true if cash transaction, false if stock transaction


  bool valid_type(int n); // returns true if between 1-4, inclusive
  bool valid_amount(double n); // returns true if positive number

};

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Transaction& t);
istream& operator>>(istream& is, Transaction& tt);

//------------------------------------------------------------------------------

} // Hades
