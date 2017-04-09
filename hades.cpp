
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

#include "hades.h"

#include "chrono.h"

using namespace Chrono;

//------------------------------------------------------------------------------

namespace Hades {

//------------------------------------------------------------------------------
// Brokerage member function definitions:
//------------------------------------------------------------------------------

Brokerage::Brokerage(string fn)
{
  /* use ifstream to read file */
}

//------------------------------------------------------------------------------

Brokerage::Brokerage()
{
  /* automatically creates an empty vector of patrons and transactions */
}

//------------------------------------------------------------------------------

void Brokerage::add_patron(Patron n)
{

}

//------------------------------------------------------------------------------

void Brokerage::add_trans(Transaction n)
{

}

//------------------------------------------------------------------------------
// Brokerage helper functions:
//------------------------------------------------------------------------------

bool Brokerage::patron_exists(Patron p)
{

}

//------------------------------------------------------------------------------

void Brokerage::brokerage_state(int n)
{

}

//------------------------------------------------------------------------------

ostream& operator<<(ostream os, const Brokerage& b)
{

}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Brokerage& bb)
{

}

//------------------------------------------------------------------------------
// Stock member function definitions:
//------------------------------------------------------------------------------

Stock::Stock(int tt)
  : t(tt)
{
  if(!valid_type(tt)) { throw Invalid(); }

  switch (tt) {
    case 1: { p = 35.91; }
    break;
    case 2: { p = 830.63; }
    break;
    case 3: { p = 138.96; }
    break;
    case 4: { p = 45.94; }
    break;
    case 5: { p = 180.53; }
    break;
    default: { p = 0; }
    break;
  }
}

//------------------------------------------------------------------------------

Stock::Stock()
{
  /* supposed to do nothing */
}

//------------------------------------------------------------------------------

string Stock::get_type(int n)
{
  switch (n) {
    case 1: { return "INTC"; }
    break;
    case 2: { return "GOOG"; }
    break;
    case 3: { return "AAPL"; }
    break;
    case 4: { return "YHOO"; }
    break;
    case 5: { return "IMB"; }
    break;
    default: { return " "; }
    break;
  }
}

//------------------------------------------------------------------------------
// Stock helper functions:
//------------------------------------------------------------------------------

bool Stock::valid_type(int n)
{
  if( (n<1) || (n>5) ) { return false; }
  else { return true; }
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Stock& s)
{

}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Stock& ss)
{

}

//------------------------------------------------------------------------------
// Share member function definitions:
//------------------------------------------------------------------------------

Share::Share(Stock *ss, double aa)
  : s(ss), a(aa)
{
  if(!valid_amount(aa)) { throw Invalid(); }
}

//------------------------------------------------------------------------------

Share::Share()
{
  /* supposed to do nothing */
}

//------------------------------------------------------------------------------
// Share helper function:
//------------------------------------------------------------------------------

bool Share::valid_amount(double n)
{
  if(n<=0) {return false; }
  else { return true; }
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Share& s)
{

}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Share& ss)
{

}

//------------------------------------------------------------------------------
// Patron member function definitions:
//------------------------------------------------------------------------------

Patron::Patron(string nn, int aa)
  : n(nn), a(aa)
{
  if(!valid_name(nn)) { throw Invalid(); }
  if(!valid_acct_num(aa)) { throw Invalid(); }
  c = 0;
  b = 0;
}

//------------------------------------------------------------------------------

Patron::Patron()
{
  n = "John_Doe";
  a = 0000;
  c = 0;
  b = 0;
}

//------------------------------------------------------------------------------

void Patron::set_bal()
{
  double temp;
  for(int i = 0; i < s.size(); i++) {
    temp += s[i]->get_value();
  }
  temp += c;

//  return temp; // FIXME: This fxn is void… it shouldn't return anything
}

//------------------------------------------------------------------------------

void Patron::sale(Share *n)
{
  c += n->get_value();
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == n) { s.erase(s.begin() + i); }
  }
}

//------------------------------------------------------------------------------

void Patron::buy(Share *n)
{
  c -= n->get_value();
  s.push_back(n);
}

//------------------------------------------------------------------------------

void Patron::add_trans(Transaction *t)
{
    if(!c) {
      if(t->get_type_num() == 1 ) { this->buy(t->get_share()); }
      else { this->sale(t->get_share()); }
    }
    else if(t->get_type_num() == 1) { this->add(t->get_amount()); }
    else { this->rem(t->get_amount()); }

}

//------------------------------------------------------------------------------
// Patron helper functions:
//------------------------------------------------------------------------------

bool Patron::valid_name(string s)
{
  if(s.size() < 3) { return false; }

  int underscores_found = 0;
  for(int i = 0; i < s.size(); i++) {
    if(isspace(s.at(i))) { return false; }

    if(s.at(i) == '_') { underscores_found++; }
  }

  if(underscores_found != 1) { return false; }

  return true;
}

//------------------------------------------------------------------------------

bool Patron::valid_acct_num(int n)
{
  if((n<0) || (n>9999)) { return false; }
  else { return true; }
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Patron& p)
{

}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Patron& pp)
{

}

//-----------------------------------------------------------------------------
// Transaction member function definition:
//-----------------------------------------------------------------------------

Transaction::Transaction(Date dd, Time tt, Patron *pp, int tyy, Share *ss)
  : d(dd), t(tt), p(pp), ty(tyy), s(ss)
{
  if(!valid_type(tyy)) { throw Invalid(); }
  c = false;
}

//-----------------------------------------------------------------------------

Transaction::Transaction(Date dd, Time tt, Patron *pp, int tyy, double aa)
  : d(dd), t(tt), p(pp), ty(tyy), a(aa)
{
  if(!valid_type(tyy)) { throw Invalid(); }
  if(!valid_amount(aa)) { throw Invalid(); }
  c = true;
}

Transaction::Transaction()
{
  /* supposed to do nothing */
}

//-----------------------------------------------------------------------------

string Transaction::get_type(int n)
{
  if(!c) {
    if(n == 1) { return "Bought"; }
    return "Sold";
  }
  else {
    if(n == 1) { return "Added"; }
    return "Removed";
  }
}

//-----------------------------------------------------------------------------
// Transaction helper funtions:
//-----------------------------------------------------------------------------

bool Transaction::valid_type(int n)
{
  if((n>=1) && (n<=2)) { return true; }
  else { return false; }
}

//-----------------------------------------------------------------------------

bool Transaction::valid_amount(double n)
{
  if(n<0) { return false; }
  return true;
}

//-----------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Transaction& t)
{

}

//-----------------------------------------------------------------------------

istream& operator>>(istream& is, Transaction& tt)
{

}

//-----------------------------------------------------------------------------

} // Hades
