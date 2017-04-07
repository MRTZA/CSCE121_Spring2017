

#include "std_lib_facilities_4"

//------------------------------------------------------------------------------

namespace Brokerage {

//------------------------------------------------------------------------------

class Brokerage {
public:

private:

};

//------------------------------------------------------------------------------

struct Transaction {
public:

  class Invalid { };          // to throw as an exception

  Transaction(Date d, Time t, Patron& p, bool ty, Share s); // check for valid share amount
  Transaction(Date d, Time t, Patron& p, bool ty, double a); // check for valid cash amount
  Transaction(); // default constructor

  // non modifying operations
  Date date() { return d; }
  Time time() { return t; }
  Patron patron() { return p; }
  bool type() { return ty; }
  Share shares() { return s; }
  double amount() { return a; }

private:
  Date d;
  Time t;
  Patron p;
  bool ty;
  Share s;
  double a;

  bool cash; // to identify if cash or stock transaction

};

//------------------------------------------------------------------------------

bool is_pos(double pos); // return true if the number is >= 0

//------------------------------------------------------------------------------

string trans_type(bool ty); // for output operator

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Transaction& t); // overloaded output operator

//------------------------------------------------------------------------------

/* stock, shares, and patron classes */

//------------------------------------------------------------------------------

} // Brokerage

//------------------------------------------------------------------------------
