
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
  const double am = 0;
	Share *intc = new Share(new Stock(1), am);
	Share *goog = new Share(new Stock(2), am);
	Share *aapl = new Share(new Stock(3), am);
	Share *yhoo = new Share(new Stock(4), am);
	Share *ibm = new Share(new Stock(5), am);

	s.push_back(intc);
	s.push_back(goog);
	s.push_back(aapl);
	s.push_back(yhoo);
	s.push_back(ibm);

  totalCash = 0;
  totalUSD = 0;
}

//------------------------------------------------------------------------------

void Brokerage::add_patron(Patron *n)
{
  if(patron_exists(n)) { throw Invalid(); }
  p.push_back(n);
  for(int i = 0; i<n->get_shares().size(); i++) {
    for(int j= 0; j<=5; i++) {
      if(n->get_shares()[i]->get_Stock()->get_type_num() == s[j]->get_Stock()->get_type_num()) {
        s[j]->change_amount(n->get_shares()[i]->get_amount());
        s[j]->set_value();
      }
    }
  }
}

//------------------------------------------------------------------------------

void Brokerage::add_trans(Transaction *n)
{
  if(!patron_exists(n->get_patron())) { throw Invalid(); }

  for(int i = 0; i < p.size(); i++) {
    if(p[i]->get_acct_num() == n->get_patron()->get_acct_num()) {
      p[i]->add_trans(n);
    }
  }

  t.push_back(n);
}

//------------------------------------------------------------------------------
// Brokerage helper functions:
//------------------------------------------------------------------------------

bool Brokerage::patron_exists(Patron *n)
{
  for(int i = 0; i < p.size(); i++) {
    if(p[i]->get_acct_num() == n->get_acct_num()) { return true; }
  }
  return false;
}

//------------------------------------------------------------------------------

void Brokerage::brokerage_state(char n)
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

string Stock::get_type(int n) const
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
  return os << " " << s.get_type(s.get_type_num()) << " "
            << "$" << s.get_price() << " ";
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Stock& ss)
{
  int t;
  string n;
  double p;
  char ch1, ch2, ch3, ch4;
  is >> ch1 >> n >> ch2 >> ch3 >> p >> ch4;
  if (!is) return is;
  if (ch1!=' ' || ch2!=' ' || ch3!='$' || ch4!=' ') { // oops: format error
      is.clear(ios_base::failbit);                    // set the fail bit
      return is;
  }
  if(p == 35.91) { t = 1; }
  else if( p == 830.63) { t = 2; }
  else if( p == 138.96) { t = 3; }
  else if( p == 45.94) { t = 4; }
  else if( p == 180.53) { t = 5; }
  ss = Stock(t);
  return is;
}

//------------------------------------------------------------------------------
// Share member function definitions:
//------------------------------------------------------------------------------

Share::Share(Stock *ss, double aa)
  : s(ss), a(aa)
{
  if(!valid_amount(aa)) { throw Invalid(); }
  set_value();
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
  if(n<0) {return false; }
  else { return true; }
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Share& s)
{
  return os << s.get_Stock()
            << s.get_amount() << " "
            << "$" << s.get_value();
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Share& ss)
{
  Stock q;
  double a;
  double v;

  char ch1, ch2;
  is >> q >> a >> ch1 >> ch2 >> v;
  if(!is) return is;
  if(ch1!=' ' || ch2!='$') {      // oops: format error
    is.clear(ios_base::failbit);  // set the fail bit
    return is;
  }
  ss = Share(new Stock(q), a);
  return is;
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

	const double am = 0;
	Share *intc = new Share(new Stock(1), am);
	Share *goog = new Share(new Stock(2), am);
	Share *aapl = new Share(new Stock(3), am);
	Share *yhoo = new Share(new Stock(4), am);
	Share *ibm = new Share(new Stock(5), am);

	s.push_back(intc);
	s.push_back(goog);
	s.push_back(aapl);
	s.push_back(yhoo);
	s.push_back(ibm);
}

//------------------------------------------------------------------------------

Patron::Patron()
{
  n = "John_Doe";
  a = 0000;
  c = 0;
  b = 0;

	const double am = 0;
	Share *intc = new Share(new Stock(1), am);
	Share *goog = new Share(new Stock(2), am);
	Share *aapl = new Share(new Stock(3), am);
	Share *yhoo = new Share(new Stock(4), am);
	Share *ibm = new Share(new Stock(5), am);

	s.push_back(intc);
	s.push_back(goog);
	s.push_back(aapl);
	s.push_back(yhoo);
	s.push_back(ibm);
}

//------------------------------------------------------------------------------

void Patron::set_bal()
{
  double temp;
  for(int i = 0; i < s.size(); i++) {
    temp += s[i]->get_value();
  }
  temp += c;
  b = temp;
//  return temp; // FIXME: This fxn is void… it shouldn't return anything
}

//------------------------------------------------------------------------------

void Patron::sale(Share *n)
{
  c += n->get_value();
  s[n->get_Stock()->get_type_num()+1]->change_amount(-n->get_amount());
  s[n->get_Stock()->get_type_num()+1]->set_value();
  set_bal();
}

//------------------------------------------------------------------------------

void Patron::buy(Share *n)
{
  c -= n->get_value();
  s[n->get_Stock()->get_type_num()+1]->change_amount(n->get_amount());
  s[n->get_Stock()->get_type_num()+1]->set_value();
  set_bal();
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
  return os << p.get_name() << " "
            << p.get_acct_num() << " "
            << p.get_cash() << " "
            << p.get_bal()
            << p.get_shares()[1]
            << p.get_shares()[2]
            << p.get_shares()[3]
            << p.get_shares()[4]
            << p.get_shares()[5];
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Patron& pp)
{
  Share s1, s2, s3, s4, s5;
  string name;
  int acct_num;
  char ch1, ch2, ch3;
  double cash;
  double bal;
  is >> name >> ch1 >> acct_num >> ch2 >> cash >> ch3 >> bal
     >> s1 >> s2 >> s3 >> s4 >> s5;
  if(!is) return is;
  if(ch1!=' ' || ch2!=' ' || ch3!=' ') {      // oops: format error
    is.clear(ios_base::failbit);              // set the fail bit
    return is;
  }
  pp = Patron(name, acct_num);

  pp.buy(new Share(s1));
  pp.buy(new Share(s2));
  pp.buy(new Share(s3));
  pp.buy(new Share(s4));
  pp.buy(new Share(s5));

  pp.add(s1.get_value());
  pp.add(s2.get_value());
  pp.add(s3.get_value());
  pp.add(s4.get_value());
  pp.add(s5.get_value());
  pp.add(cash);
  pp.set_bal();
  return is;
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

string Transaction::get_type(int n) const
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
  if(t.is_cash()) {
    string s = " cash ";
    double cash = 1.0;
    return os << t.get_patron() << " "
              << t.get_date() << " "
              << t.get_time() << " "
              << t.get_type(0) << s << cash
              << t.get_amount();
  }
  return os << t.get_patron() << " "
            << t.get_date() << " "
            << t.get_time() << " "
            << t.get_type(0) << t.get_share()->get_Stock()->get_type(t.get_share()->get_Stock()->get_type_num()) << t.get_share()->get_amount()
            << t.get_share()->get_value();
}

//-----------------------------------------------------------------------------

istream& operator>>(istream& is, Transaction& tt)
{
    Patron p;
    Date d;
    Time t;
    string type;
    string stock_cash;
    double c;
    double a;
    char ch1, ch2, ch3;
    int num_type;
    int num_type_stock;

    is >> p >> ch1 >> d >> ch2 >> t >> type >> stock_cash >> c >> a;
    if(!is) return is;
    if(ch1!=' ' || ch2!=' ' || ch3!=' ') {      // oops: format error
      is.clear(ios_base::failbit);              // set the fail bit
      return is;
    }
    if(stock_cash == "INTC") { num_type_stock = 1; }
    else if(stock_cash == "GOOG") { num_type_stock = 2; }
    else if(stock_cash == "AAPL") { num_type_stock = 3; }
    else if(stock_cash == "YHOO") { num_type_stock = 4; }
    else { num_type_stock = 5; }

    if(type == "Bought"){
      num_type = 1;
      Stock *stock = new Stock(num_type_stock);
      Share *sh = new Share(stock, c);
      tt = Transaction(d, t, new Patron(p), num_type, sh);
    }
    else if(type == "Sold") {
      num_type = 2;
      Stock *stock = new Stock(num_type_stock);
      Share *sh = new Share(stock, c);
      tt = Transaction(d, t, new Patron(p), num_type, sh);
    }
    else if(type == "Added") {
      num_type = 1;
      tt = Transaction(d, t, new Patron(p), num_type, a);
    }
    else { num_type = 2;  tt = Transaction(d, t, new Patron(p), num_type, a); }
    return is;

}

//-----------------------------------------------------------------------------

} // Hades
