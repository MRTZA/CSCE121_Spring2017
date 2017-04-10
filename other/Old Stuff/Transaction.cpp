
#include "Transaction.h"

//------------------------------------------------------------------------------
// Transaction member function definitions:
//------------------------------------------------------------------------------

Transaction::Transaction(Date dd, Time tt, Patron& pp, bool tyy, Stock ss, double, shh)
  : d(dd), t(tt), p(pp), ty(tyy), s(ss), sh(shh)
  {
    if(!is_pos(shh)) { throw Invalid(); }
    cash = false;
  }

//------------------------------------------------------------------------------

Transaction::Transaction(Date dd, Time tt, Patron& pp, bool tyy, double aa)
  : d(dd), t(tt), p(pp), ty(tyy), a(aa)
  {
    if(!is_pos(aa)) { throw Invalid(); }
    cash = true;
  }

//------------------------------------------------------------------------------

Transaction::Transaction()
{
  /* supposed to do absolutely nothing */
}

//------------------------------------------------------------------------------
// Transaction helper functions:
//------------------------------------------------------------------------------

bool is_pos(double pos)
{
  if(pos<0) { return false; }
  else { return true; }
}

//------------------------------------------------------------------------------

string trans_type(bool ty)
{
  if(!cash) {
    if(!ty) { return "bought" }
    else { return "sold" }
  }
  else {
    if(!ty) { return "removed" }
    else { return "added"}
  }
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Transaction& t)
{
  if(!cash) {
    return os << "Date: " << t.date() << endl;
              << "Time: " << t.time() << endl;
              << t.trans_type(t.type()) << " " << t.shares() << " shares of " << t.stock()
              << " at $" << t.shares()*t.stock().getPrice() << endl;
  }
  else {
    return os << "Date: " << t.date() << endl;
              << "Time: " << t.time() << endl;
              << t.trans_type(t.type()) << " $" << t.amount() << " in cash"<< endl;
  }
}

//------------------------------------------------------------------------------
