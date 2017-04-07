
#include "Brokerage.h"

namespace Brokerage {

//------------------------------------------------------------------------------
// Brokerage member function definitions:
//------------------------------------------------------------------------------

/* Implement Brokerage Class */

//------------------------------------------------------------------------------
// Brokerage helper functions:
//------------------------------------------------------------------------------

/* Implement Brokerage Class */

//------------------------------------------------------------------------------
// Transaction member function definitions:
//------------------------------------------------------------------------------

Transaction::Transaction(Date dd, Time tt, Patron& pp, bool tyy, Share ss,)
  : d(dd), t(tt), p(pp), ty(tyy), s(ss),
  {
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
              << t.trans_type(t.type()) << " " << t.shares().get_amount() << " shares of " << t.shares().get_stock().get_type()
              << " at $" << t.shares().get_value() << endl;
  }
  else {
    return os << "Date: " << t.date() << endl;
              << "Time: " << t.time() << endl;
              << t.trans_type(t.type()) << " $" << t.amount() << " in cash"<< endl;
  }
}

//------------------------------------------------------------------------------
// Share member function definitions:
//------------------------------------------------------------------------------

/* Implement Share Class */

//------------------------------------------------------------------------------
// Share helper functions:
//------------------------------------------------------------------------------

/* Implement Share Class */

//------------------------------------------------------------------------------
// Stock member function definitions:
//------------------------------------------------------------------------------

/* Implement Stock Class */

//------------------------------------------------------------------------------
// Stock helper functions:
//------------------------------------------------------------------------------

/* Implement Stock Class */

//------------------------------------------------------------------------------
// Patron member function definitions:
//------------------------------------------------------------------------------

/* Implement Patron Class */

//------------------------------------------------------------------------------
// Patron helper functions:
//------------------------------------------------------------------------------

/* Implement Patron Class */

//------------------------------------------------------------------------------

} // Brokerage

//------------------------------------------------------------------------------
