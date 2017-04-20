
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

#include "Brokerage.h"

using namespace Chrono;

//------------------------------------------------------------------------------

namespace Hades {

//------------------------------------------------------------------------------
// Stock member function definitions:
//------------------------------------------------------------------------------

Stock::Stock(string tt)
  : type(tt)
{
  if(!valid_stock_type(tt)) { throw Invalid(); }

  if(tt == "INTC") {
    price = 35.91;
  }
  else if(tt == "GOOG") {
    price = 830.63;
  }
  else if(tt == "AAPL") {
    price = 138.96;
  }
  else if(tt == "YHOO") {
    price = 45.94;
  }
  else {
    price = 180.53;
  }
}

//------------------------------------------------------------------------------

Stock::Stock()
{
  //...
}

//------------------------------------------------------------------------------
// Stock helper functions:
//------------------------------------------------------------------------------

bool valid_stock_type(string n)
{
  if(n == "INTC" || n == "GOOG" || n == "YHOO" || n == "AAPL" || n == "IBM")
  { return true; }
  return false;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Stock& s)
{
  return os << s.get_type() << " "
            << s.get_price();
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Stock& ss)
{
  string type;
  double price;
  char ch1;
  is >> type >> ch1 >> price;
  if (!is) return is;
  if (ch1!=' ') {                                     // oops: format error
      is.clear(ios_base::failbit);                    // set the fail bit
      return is;
  }
  ss = Stock(type);
  return is;
}

//------------------------------------------------------------------------------
// Share member function definitions:
//------------------------------------------------------------------------------

Share::Share(Stock ss, double aa)
  : stock(ss), amount(aa)
{
  if(!valid_amount(aa)) { throw Invalid(); }
  set_value();
}

//------------------------------------------------------------------------------

Share::Share()
{
  //...
}

//------------------------------------------------------------------------------
// Share helper function:
//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Share& s)
{
  return os << s.get_stock() << " "
            << s.get_amount() << " "
            << s.get_value();
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Share& ss)
{
  Stock q;
  double amount;
  double value;
  char ch1, ch2;
  is >> q >> ch1 >> amount >> ch2 >> value;
  if(!is) return is;
  if(ch1!=' ' || ch2!=' ') {      // oops: format error
    is.clear(ios_base::failbit);  // set the fail bit
    return is;
  }
  ss = Share(q, amount);
  return is;
}

//------------------------------------------------------------------------------
// Patron member function definitions:
//------------------------------------------------------------------------------

Patron::Patron(string nn, int aa)
  : name(nn), acct_num(aa)
{
  if(!valid_name(nn)) { throw Invalid(); }
  if(!valid_acct_num(aa)) { throw Invalid(); }
  cash = 0;
  bal = 0;

	const double am = 0.0;
	Share intc = Share(Stock("INTC"), am);
	Share goog = Share(Stock("GOOG"), am);
	Share aapl = Share(Stock("AAPL"), am);
	Share yhoo = Share(Stock("YHOO"), am);
	Share ibm = Share(Stock("IBM"), am);

	shares.push_back(intc);
	shares.push_back(goog);
	shares.push_back(aapl);
	shares.push_back(yhoo);
	shares.push_back(ibm);
}

//------------------------------------------------------------------------------

Patron::Patron()
{
  name = "John_Doe";
  acct_num = 0000;
  cash = 0;
  bal = 0;

  const double am = 0.0;
  Share intc = Share(Stock("INTC"), am);
  Share goog = Share(Stock("GOOG"), am);
  Share aapl = Share(Stock("AAPL"), am);
  Share yhoo = Share(Stock("YHOO"), am);
  Share ibm = Share(Stock("IBM"), am);

  shares.push_back(intc);
  shares.push_back(goog);
  shares.push_back(aapl);
  shares.push_back(yhoo);
  shares.push_back(ibm);
}

//------------------------------------------------------------------------------

void Patron::set_bal()
{
  double temp;
  for(int i = 0; i < shares.size(); i++) {
    temp += shares[i].get_value();
  }
  temp += cash;
  bal = temp;
//  return temp; // FIXME: This fxn is void… it shouldn't return anything
}

//------------------------------------------------------------------------------

void Patron::sale(Share n)
{
  if(n.get_stock().get_type() == "INTC") {
    cash += n.get_value();
    shares[0].change_amount(-1.0*n.get_amount());
    set_bal();
  }
  else if(n.get_stock().get_type() == "GOOG") {
    cash += n.get_value();
    shares[1].change_amount(-1.0*n.get_amount());
    set_bal();
  }
  else if(n.get_stock().get_type() == "AAPL") {
    cash += n.get_value();
    shares[2].change_amount(-1.0*n.get_amount());
    set_bal();
  }
  else if(n.get_stock().get_type() == "YHOO") {
    cash += n.get_value();
    shares[3].change_amount(-1.0*n.get_amount());
    set_bal();
  }
  else {
    cash += n.get_value();
    shares[4].change_amount(-1.0*n.get_amount());
    set_bal();
  }
}

//------------------------------------------------------------------------------

void Patron::buy(Share n)
{
  if(n.get_stock().get_type() == "INTC") {
    cash -= n.get_value();
    shares[0].change_amount(n.get_amount());
    set_bal();
  }
  else if(n.get_stock().get_type() == "GOOG") {
    cash -= n.get_value();
    shares[1].change_amount(n.get_amount());
    set_bal();
  }
  else if(n.get_stock().get_type() == "AAPL") {
    cash -= n.get_value();
    shares[2].change_amount(n.get_amount());
    set_bal();
  }
  else if(n.get_stock().get_type() == "YHOO") {
    cash -= n.get_value();
    shares[3].change_amount(n.get_amount());
    set_bal();
  }
  else {
    cash -= n.get_value();
    shares[4].change_amount(n.get_amount());
    set_bal();
  }
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

ostream& operator<<(ostream& os, const Patron& p)
{
  return os << p.get_name() << " "
            << p.get_acct_num() << " "
            << p.get_cash() << " "
            << p.get_bal() << " "
            << p.get_shares()[0] << " "
            << p.get_shares()[1] << " "
            << p.get_shares()[2] << " "
            << p.get_shares()[3] << " "
            << p.get_shares()[4];
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Patron& pp)
{
  Share s1, s2, s3, s4, s5;
  string name;
  int acct_num;
  char ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8;
  double cash;
  double bal;
  is >> name >> ch1 >> acct_num >> ch2 >> cash >> ch3 >> bal >> ch4
     >> s1 >> ch5 >> s2 >> ch6 >> s3 >> ch7 >> s4 >> ch8 >> s5;
  if(!is) return is;
  if(ch1!=' ' || ch2!=' ' || ch3!=' ' || ch4!=' ' || ch5!=' ' || ch6!=' ' || ch7!=' ' || ch8!=' ' ) {      // oops: format error
    is.clear(ios_base::failbit);              // set the fail bit
    return is;
  }
  pp = Patron(name, acct_num);

  pp.buy(s1);
  pp.buy(s2);
  pp.buy(s3);
  pp.buy(s4);
  pp.buy(s5);

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

Transaction::Transaction(Date dd, Time tt, Patron pp, string tyy, string act, double aa)
  : date(dd), time(tt), patron(pp), type(tyy), actual(act), amount(aa)
{
  if(!valid_type(tyy)) { throw Invalid(); }

  if(act == "INTC") {
    value = 35.91*aa;
    if(tyy == "BUY") {
      pp.buy(Share(Stock("INTC"), aa));
    }
    else { pp.sale(Share(Stock("INTC"), aa)); }
  }
  else if(act == "GOOG") {
    value = 830.63*aa;
    if(tyy == "BUY") {
      pp.buy(Share(Stock("GOOG"), aa));
    }
    else { pp.sale(Share(Stock("GOOG"), aa)); }
  }
  else if(act == "AAPL") {
    value = 138.96*aa;
    if(tyy == "BUY") {
      pp.buy(Share(Stock("AAPL"), aa));
    }
    else { pp.sale(Share(Stock("AAPL"), aa)); }
  }
  else if(act == "YHOO") {
    value = 45.94*aa;
    if(tyy == "BUY") {
      pp.buy(Share(Stock("YHOO"), aa));
    }
    else { pp.sale(Share(Stock("YHOO"), aa)); }
  }
  else if(act == "IBM") {
    value = 180.53*aa;
    if(tyy == "BUY") {
      pp.buy(Share(Stock("IBM"), aa));
    }
    else { pp.sale(Share(Stock("IBM"), aa)); }
  }
  else {
    if(tyy == "ADD") {
      pp.add(aa);
    }
    else { pp.rem(aa); }
    isCash = true;
  }
}

//-----------------------------------------------------------------------------

Transaction::Transaction()
{
  /* supposed to do nothing */
}

//-----------------------------------------------------------------------------
// Transaction helper funtions:
//-----------------------------------------------------------------------------

bool Transaction::valid_act(string n)
{
  if(n == "INTC" || n == "GOOG" || n == "AAPL" || n == "YHOO" || n == "IBM" || n == "CASH") {
    return true;
  }
  return false;
}

//-----------------------------------------------------------------------------

bool Transaction::valid_type(string n)
{
  if(n == "BUY" || n == "SALE" || n == "ADD" || n == "REMOVE") {
    return true;
  }
  return false;
}

//-----------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Transaction& t)
{
  return os << t.get_patron() << " "
            << t.get_date() << " "
            << t.get_time() << " "
            << t.get_type() << " "
            << t.get_actual() << " "
            << t.get_amount() << " "
            << t.get_value();
}

//-----------------------------------------------------------------------------

istream& operator>>(istream& is, Transaction& tt)
{
    Patron p;
    Date d;
    Time t;
    string ty;
    string actu;
    double a;
    double v;
    char ch1, ch2, ch3, ch4, ch5, ch6;

    is >> p >> ch1 >> d >> ch2 >> t >> ch3 >> ty >> ch4 >> actu >> ch5 >> a >> ch6 >> v;
    if(!is) return is;
    if(ch1!=' ' || ch2!=' ' || ch3!=' ' || ch4!=' ' || ch5!=' ' || ch6!=' ') {      // oops: format error
      is.clear(ios_base::failbit);              // set the fail bit
      return is;
    }
    tt = Transaction(d, t, p, ty, actu, a);
    return is;
}

//------------------------------------------------------------------------------
// Brokerage member function definitions:
//------------------------------------------------------------------------------

Brokerage::Brokerage(string fn)
{
  Brokerage b = Brokerage();
  ifstream ist {fn};
  if(!ist) error("Can't open input file ", fn);
  
  ist >> b;
}

//------------------------------------------------------------------------------

Brokerage::Brokerage()
{
  /* automatically creates an empty vector of patrons and transactions */
  const double am = 0;
	Share intc = Share(Stock("INTC"), am);
	Share goog = Share(Stock("GOOG"), am);
	Share aapl = Share(Stock("AAPL"), am);
	Share yhoo = Share(Stock("YHOO"), am);
	Share ibm = Share(Stock("IBM"), am);

	totalShares.push_back(intc);
	totalShares.push_back(goog);
	totalShares.push_back(aapl);
	totalShares.push_back(yhoo);
	totalShares.push_back(ibm);

  totalCash = 0;
  totalUSD = 0;
}

//------------------------------------------------------------------------------

void Brokerage::set_totalCash()
{
  double temp = 0.0;
  for(int i = 0; i<p.size(); i++) {
    temp += p[i].get_cash();
  }
  totalCash = temp;
}

//------------------------------------------------------------------------------

void Brokerage::set_totalUSD()
{
  double temp = 0.0;
  for(int i = 0; i<p.size(); i++) {
    temp += p[i].get_bal();
  }
  totalUSD = temp;
}

//------------------------------------------------------------------------------

void Brokerage::add_patron(Patron n)
{
	

  if(patron_exists(n)) { //throw Invalid();
		for(int i = 0; i<p.size(); i++) {
			if(p[i].get_acct_num() == n.get_acct_num()) {
			p.erase(p.begin() + i);
			}
		}
  }
  set_totalCash();
  set_totalUSD();
  p.push_back(n);
  for(int i = 0; i < totalShares.size(); i++) {
    totalShares[i] = n.get_shares()[i];
  }
  // for(int i = 0; i<n.get_shares().size(); i++) {
  //   totalShares.push_back(n.get_shares()[i]);
  // }
  set_totalCash();
  set_totalUSD();
}

//------------------------------------------------------------------------------

void Brokerage::add_trans(Transaction n)
{
  if(!patron_exists(n.get_patron())) { throw Invalid(); }
  t.push_back(n);
}

//------------------------------------------------------------------------------
// Brokerage helper functions:
//------------------------------------------------------------------------------

bool Brokerage::patron_exists(Patron n)
{
  for(int i = 0; i < p.size(); i++) {
    if(p[i].get_acct_num() == n.get_acct_num()) { return true; }
  }
  return false;
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Brokerage& b)
{
	os << "B BBB" << endl;
	
	for(int i=0; i<b.get_total_shares().size(); i++) {
		os << "s " << b.get_total_shares().at(i).get_stock() << endl;
	}
	
	for(int i=0; i<b.get_total_shares().size(); i++) {
		os << "S " << b.get_total_shares().at(i) << endl;
	}
	
	os << "C " << b.get_total_cash() << endl;
	os << "U " << b.get_total_USD() << endl;
	
	for(int i=0; i<b.get_patrons().size(); i++) {
		os << "P " << b.get_patrons().at(i) << endl;
	}
	
	for(int i=0; i<b.get_trans().size(); i++) {
		os << "X " << b.get_trans().at(i) << endl;
	}
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Brokerage& bb)
{
	Brokerage b;
	char type;
	
	while(is >> type) {
		cout << "Type Detected" << endl;
		switch (type) {
			case 's': {
				String tempType;
				double tempPrice;
				char ch1;
				is >> tempType >> ch1 >> tempPrice;
			}
			break;
			
			case 'S': {
				String tempType;
				double tempPrice;
				double tempAmount;
				double tempValue;
				char ch1;
				char ch2;
				char ch3;
				is >> tempType >> ch1 >> tempPrice >> ch2 >> tempAmount 
				   >> ch3 >> tempValue;
			}
			break;
			
			case 'C': {
				double cash;
				is >> cash;
			}
			break;
			
			case 'U': {
				double value;
				is >> value;
			}
			break;
			
			case 'P': {
				string tempName;
				int tempNum;
				double tempCash;
				double tempValue;
				is >> tempName >> tempNum >> tempCash >> tempValue;
				Patron tempPatron = Patron(tempName, tempNum);
				tempPatron.add(tempValue);
				for(int i=0; i<5; i++) {
					string tempType;
					double tempPrice;
					double tempAmount;
					double tempValue;
					is >> tempType >> tempPrice >> tempAmount >> tempValue;
					  
					Stock tempStock(tempType);
					Share tempShare(tempStock, tempAmount);
					tempPatron.buy(tempShare);
				}
				b.add_patron(tempPatron);
			}
			break;
			
			case 'X': {
				string tempName;
				int tempNum;
				double tempCash;
				double tempValue;
				is >> tempName >> tempNum >> tempCash >> tempValue;
				
				int where = -1;
				for(int i = b.get_trans().size() - 1; i>=0; i--) {
					if(b.get_trans()[i].get_patron().get_acct_num() == tempNum) {
					where = i;
					i=0;
					}
				}
				Patron tempPatron;
				if(where != -1) {
					tempPatron = b.get_trans().at(where).get_patron();
				}
				else {
					tempPatron = Patron(tempName, tempNum);
				}
				
				for(int i=0; i<5; i++) {
					string tempStockType;
					double tempPrice;
					double tempAmount;
					double tempStockValue;
					is >> tempStockType >> tempPrice >> tempAmount 
					   >> tempStockValue;
				}
				
				Date tempDate;
				Time tempTime;
				is >> tempDate >> tempTime;
				
				string tempFakeType;
				string tempTransType;
				string tempActual;
				double tempPrice;
				double tempAmount;
				double tempEndValue;
				is >> tempFakeType >> tempActual >> tempPrice
				   >> tempAmount >> tempEndValue;
				
				if(tempFakeType == "Cash_Deposit") {
					tempTransType = "ADD";
					tempPatron.add(tempAmount);
				}
				else if(tempFakeType == "Cash_Withdraw") {
					tempTransType = "REMOVE";
					tempPatron.rem(tempAmount);
				}
				else if(tempFakeType == "Stock_Sale") {
					tempTransType = "SALE";
					tempPatron.sale(Share(tempActual,tempAmount));
				}
				else if(tempFakeType == "Stock_Buy") {
					tempTransType = "BUY";
					tempPatron.buy(Share(tempActual,tempAmount));
				}
				   
				Transaction tempTransaction = Transaction(tempDate, tempTime,
											  tempPatron, tempTransType, 
											  tempActual, tempAmount);
				try {
					b.add_trans(tempTransaction);
				}
				catch(Brokerage::Invalid) {}
			}
			break;
			
			default: {
				string skip;
				is >> skip;
			}
		}
		
	}
	
	bb = b;
	return is;
	
}

} // Brokerage
