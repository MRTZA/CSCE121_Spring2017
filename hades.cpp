
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

#include "hades.h"

#include "chrono.h"
#include "chrono.cpp"

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

bool patron_exists(Patron p)
{

}

//------------------------------------------------------------------------------

void brokerage_state(int n)
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

Stock::Stock(int tt, double pp)
  : t(tt), p(pp)
{

}

//------------------------------------------------------------------------------

Stock:Stock()
{
  /* supposed to do nothing */
}

//------------------------------------------------------------------------------

string Stock::get_type(int n)
{

}

//------------------------------------------------------------------------------
// Stock helper functions:
//------------------------------------------------------------------------------

bool valid_type(int n)
{

}

//------------------------------------------------------------------------------

bool valid_price(double n)
{

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

Share::Share(Stock ss, double aa)
  : s(ss), a(aa)
{

}

//------------------------------------------------------------------------------

Share::Share()
{
  /* supposed to do nothing */
}

//------------------------------------------------------------------------------

void Share::set_value()
{

}

//------------------------------------------------------------------------------
// Share helper function:
//------------------------------------------------------------------------------

bool valid_amount(double n)
{

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

}

//------------------------------------------------------------------------------

Patron::Patron()
{
  /* supposed to do nothing */
}

//------------------------------------------------------------------------------

void Patron::sale(Share s)
{

}

//------------------------------------------------------------------------------

void Patron::buy(Share s)
{

}

//------------------------------------------------------------------------------

void Patron::add(double n)
{

}

//------------------------------------------------------------------------------

void Patron::rem(double n)
{

}

//------------------------------------------------------------------------------

void Patron::add_trans(Transaction t)
{

}

//------------------------------------------------------------------------------
// Patron helper functions:
//------------------------------------------------------------------------------

bool valid_name(string s)
{

}

//------------------------------------------------------------------------------

bool valid_acct_num(int n)
{

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

Transaction::Transaction(Date dd, Time tt, Patron pp, int tyy, Share ss)
  : d(dd), t(tt), p(pp), ty(tyy), s(ss)
{

}

//-----------------------------------------------------------------------------

Transaction:Transaction(Date dd, Time tt, Patron pp, int tyy, double aa)
  : d(dd), t(tt), p(pp), ty(tyy), a(aa)
{

}

Tansaction::Transaction()
{
  /* supposed to do nothing */
}

//-----------------------------------------------------------------------------

string Transaction::get_type(int n)
{

}

//-----------------------------------------------------------------------------
// Transaction helper funtions:
//-----------------------------------------------------------------------------

bool valid_type(int n)
{

}

//-----------------------------------------------------------------------------

bool valid_ammount(double n)
{

}

//-----------------------------------------------------------------------------

stream& operator<<(ostream& os, const Transaction& t)
{

}

//-----------------------------------------------------------------------------

istream& operator>>(istream& is, Transaction& tt)
{

}

//-----------------------------------------------------------------------------

} // Hades
