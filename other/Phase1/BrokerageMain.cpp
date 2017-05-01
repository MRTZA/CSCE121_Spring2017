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

#include "Brokerage.h"

using namespace Hades;

int main() {

  bool run = true;

  string brokerage_name; // used to create file
  string input_filename;
  string patron_name;
  int acct_num;
  double deposit;
  double withdrawl;
  double amount_sale;
  double amount_buy;

  char user_choice;

  cout << "Enter Brokerage name as a string (no spaces): " << endl;
  cin >> brokerage_name;

  Brokerage brok;

  cout << "Enter input file name as a string w/ no spaces" <<
  " or special characters (or Q to skip)" << endl;
  cin >> input_filename;
  if(input_filename != "Q" && input_filename != "q") {
	  ifstream ist {input_filename};
	  ist >> brok;
  }
  else {
	  brok = Brokerage();
  }

while(run) {
  cout << "Enter desired option:" << endl
  << "A. display information about Stock Shares and Cash in the Brokerage" << endl
  << "B. add a new Patron to the Brokerage" << endl
  << "C. check if someone is already a Patron" << endl
  << "D. display all Patrons" << endl
  << "E. add Cash to a Patron account" << endl
  << "F. remove Cash from a Patron account" << endl
  << "G. do a Stock Shares Sale for a Patron" << endl
  << "H. do a Stock Shares Buy for a Patron" << endl
  << "I. display all Patrons that are overdrawn" << endl
  << "J. display all transactions ever done by Patrons" << endl
  << "K. quit" << endl;

  cin >> user_choice;

    switch (user_choice) {
      case 'A': {
        cout << "Enter Shares Stock Type (i=Intel, g=Google, a=Apple, y=Yahoo, I=IBM or C=Cash or A=ALL): ";

        cin >> user_choice;

        switch(user_choice) {
          case 'i': {
              cout << brok.get_total_shares()[0] << endl;
            }
            break;
          case 'g': {
              cout << brok.get_total_shares()[1] << endl;
            }
            break;
          case 'a': {
              cout << brok.get_total_shares()[2] << endl;
            }
            break;
          case 'y': {
              cout << brok.get_total_shares()[3] << endl;
            }
            break;
          case 'I': {
              cout << brok.get_total_shares()[4] << endl;
            }
            break;
          case 'C': {
              cout << "CASH "<< brok.get_total_cash() << endl;
            }
            break;
          case 'A': {
              cout << brok.get_total_shares()[0] << endl
              << brok.get_total_shares()[1] << endl
              << brok.get_total_shares()[2] << endl
              << brok.get_total_shares()[3] << endl
              << brok.get_total_shares()[4] << endl
              << "CASH " << brok.get_total_cash() << endl
              << "USD "<< brok.get_total_USD() << endl;
            }
            break;
          default: { cout << "enter a valid option" << endl;}
          break;
          }
        }
      break;

//------------------------------------------------------------------------------

      case 'B': {
        cout << "Enter Patron's name (use underscores for spaces):";
        cin >> patron_name;
        cout << "Enter Patron's Brokerage account number (a 4 digit nonnegative integer):";
        cin >> acct_num;
        cout << "Enter initial deposit by this Patron (USDs only):";
        cin >> deposit;
		bool overwrite = true;
		for(int i = 0; i<brok.get_patrons().size(); i++) {
			if(brok.get_patrons().at(i).get_acct_num() == acct_num) {
				cout << "Account number already exists. Do you want to overwrite? (Y/N): " << endl;
				char response;
				cin >> response;
				if(response == 'N' || response == 'n') {
					overwrite = false;
					break;
				}
				else if(response == 'Y' || response == 'y') {
					brok.get_patrons().erase(brok.get_patrons().begin() + i);
				}
				else{cout << "Invalid answer, action aborted" << endl; break;}
			}
		}
			
        if(overwrite) {
			Patron pat = Patron(patron_name, acct_num);
			pat.add(deposit);
			brok.add_patron(pat);
		}
      }
      break;

//------------------------------------------------------------------------------

      case 'C': {
        cout << "Enter Patron's Brokerage account number (a 4 digit nonnegative integer):";
        cin >> acct_num;
        bool exists = false;

        //finds patron
        int where;
        for(int i = 0; i<brok.get_patrons().size(); i++) {
          if(brok.get_patrons()[i].get_acct_num() == acct_num) {
            exists = true;
            where = i;
          }
        }

        if(exists) {
          cout << "Yes, there is a " << brok.get_patrons()[where].get_name() << " with that Brokerage account number."
          << endl;
          cout << brok.get_patrons()[where];
          cout << endl;
        }
        else { cout << "No, there is no Patron with that Brokerage account number." << endl; }
      }
      break;
      case 'D': {
        for(int i=0; i<brok.get_patrons().size(); i++) {
          cout << brok.get_patrons()[i] << endl;
        }
      }
      break;

//------------------------------------------------------------------------------

      case 'E': {
        cout << "Enter Brokerage account number of Patron doing deposit:";
        cin >> acct_num;

        //finds patron
        int where = -1;
        for(int i = 0; i<brok.get_patrons().size(); i++) {
          if(brok.get_patrons()[i].get_acct_num() == acct_num) {
            where = i;
          }
        }
		if(where != -1){
			cout << "Enter deposit in USD's for this Patron:";
			cin >> deposit;
			cout << "Old Account Cash Balance: " << brok.get_patrons()[where].get_cash() << endl;
			cout << "Old Account USDs Balance: " << brok.get_patrons()[where].get_bal() << endl;

			Patron pat = brok.get_patrons()[where];
			pat.add(deposit);
			brok.add_patron(pat);
			Transaction trans = Transaction(Date(), Time(), pat, "ADD", "CASH", deposit);
			brok.add_trans(trans);

			// finds new locaton of patron
			for(int i = 0; i<brok.get_patrons().size(); i++) {
			  if(brok.get_patrons()[i].get_acct_num() == acct_num) {
				where = i;
			  }
			}

			cout << "New Account Cash Balance: " << brok.get_patrons()[where].get_cash() << endl;
			cout << "New Account USDs Balance: " << brok.get_patrons()[where].get_bal() << endl;
		}
		else {
			cout << "Patron doesn't exist" << endl;
		}
	  }
      break;

//------------------------------------------------------------------------------

      case 'F': {
        cout << "Enter Brokerage account number of Patron doing witdrawl:";
        cin >> acct_num;

        // finds patron
        int where = -1;
        for(int i = 0; i<brok.get_patrons().size(); i++) {
          if(brok.get_patrons()[i].get_acct_num() == acct_num) {
            where = i;
          }
        }
		if(where != -1) {
			cout << "Enter witdrawl in USD's for this Patron:";
			cin >> withdrawl;
			cout << "Old Account Cash Balance: " << brok.get_patrons()[where].get_cash() << endl;
			cout << "Old Account USDs Balance: " << brok.get_patrons()[where].get_bal() << endl;

			Patron pat = brok.get_patrons()[where];
			pat.rem(withdrawl);
			brok.add_patron(pat);
			Transaction trans = Transaction(Date(), Time(), pat, "REMOVE", "CASH", withdrawl);
			brok.add_trans(trans);

			// finds new patron location
			for(int i = 0; i<brok.get_patrons().size(); i++) {
			  if(brok.get_patrons()[i].get_acct_num() == acct_num) {
				where = i;
			  }
			}

			cout << "New Account Cash Balance: " << brok.get_patrons()[where].get_cash() << endl;
			cout << "New Account USDs Balance: " << brok.get_patrons()[where].get_bal() << endl;
		}
		else {
			cout << "Patron doesn't exist" << endl;
		}
	}
      break;

//------------------------------------------------------------------------------

      case 'G': {
        cout << "Enter Brokerage account number of Patron doing sale:";
        cin >> acct_num;

        cout << "Enter Shares Stock Type (i=Intel, g=Google, a=Apple, y=Yahoo, I=IBM):";
        cin >> user_choice;

        cout << "Enter Shares Stock Amount:";
        cin >> amount_sale;

        // find patron
        int where = -1;
        for(int i = 0; i<brok.get_patrons().size(); i++) {
          if(brok.get_patrons()[i].get_acct_num() == acct_num) {
            where = i;
          }
        }
		if(where != -1) {
			double oldCash = brok.get_patrons()[where].get_cash();
			double oldBal = brok.get_patrons()[where].get_bal();

			Share share;
			string stock;
			// finds which share
			int share_index;
			switch (user_choice) {
			  case 'i': { share_index = 0; share = Share(Stock("INTC"), amount_sale); stock = "INTC"; }
			  break;
			  case 'g': { share_index = 1; share = Share(Stock("GOOG"), amount_sale); stock = "GOOG"; }
			  break;
			  case 'a': { share_index = 2; share = Share(Stock("AAPL"), amount_sale); stock = "AAPL"; }
			  break;
			  case 'y': { share_index = 3; share = Share(Stock("YHOO"), amount_sale); stock = "YHOO"; }
			  break;
			  case 'I': { share_index = 4; share = Share(Stock("IBM"), amount_sale); stock = "IBM"; }
			  break;
			  default: { share_index = 5; }
			  break;
			}
			if(amount_sale < brok.get_patrons()[where].get_shares().at(share_index).get_amount()) {
				cout << "Old " << stock << " in Brokerage:" << brok.get_patrons()[where].get_shares()[share_index] << endl;

				Patron pat = brok.get_patrons()[where];
				pat.sale(share);
				brok.add_patron(pat);
				Transaction trans = Transaction(Date(), Time(), pat, "SALE", stock, amount_sale);
				brok.add_trans(trans);

				// finds new patron location
				for(int i = 0; i<brok.get_patrons().size(); i++) {
				  if(brok.get_patrons()[i].get_acct_num() == acct_num) {
					where = i;
				  }
				}
				
				cout << "New " << stock << " in Brokerage:" << brok.get_patrons()[where].get_shares()[share_index] << endl;
				cout << "Adding Cash " << share.get_value() << "from Patron " <<  pat.get_name() << "account." << endl;

				cout << "Old Account Cash Balance: " << oldCash << endl;
				cout << "Old Account USDs Balance: " << oldBal << endl;

				cout << "New Account Cash Balance: " << brok.get_patrons()[where].get_cash() << endl;
				cout << "New Account USDs Balance: " << brok.get_patrons()[where].get_bal() << endl;
		 
			}
			else {
				cout << "Not enough shares to sell" << endl;
			}
		}
		else {
			cout << "Patron doesn't exist" << endl;
		}
    }
    break;

//------------------------------------------------------------------------------

      case 'H': {
        cout << "Enter Brokerage account number of Patron doing buy:";
        cin >> acct_num;

        cout << "Enter Shares Stock Type (i=Intel, g=Google, a=Apple, y=Yahoo, I=IBM):";
        cin >> user_choice;

        cout << "Enter Shares Stock Amount:";
        cin >> amount_buy;

        // find patron
        int where = -1;
        for(int i = 0; i<brok.get_patrons().size(); i++) {
          if(brok.get_patrons()[i].get_acct_num() == acct_num) {
            where = i;
          }
        }
		if(where != -1) {
			double oldCash = brok.get_patrons()[where].get_cash();
			double oldBal = brok.get_patrons()[where].get_bal();

			Share share;
			string stock;
			// finds which share
			int share_index;
			switch (user_choice) {
			  case 'i': { share_index = 0; share = Share(Stock("INTC"), amount_buy); stock = "INTC"; }
			  break;
			  case 'g': { share_index = 1; share = Share(Stock("GOOG"), amount_buy); stock = "GOOG"; }
			  break;
			  case 'a': { share_index = 2; share = Share(Stock("AAPL"), amount_buy); stock = "AAPL"; }
			  break;
			  case 'y': { share_index = 3; share = Share(Stock("YHOO"), amount_buy); stock = "YHOO"; }
			  break;
			  case 'I': { share_index = 4; share = Share(Stock("IBM"), amount_buy); stock = "IBM"; }
			  break;
			  default: { share_index = 5; }
			  break;
			}

			cout << "Old " << stock << " in Brokerage:" << brok.get_patrons()[where].get_shares()[share_index] << endl;

			Patron pat = brok.get_patrons()[where];
			pat.buy(share);
			brok.add_patron(pat);
			Transaction trans = Transaction(Date(), Time(), pat, "BUY", stock, amount_buy);
			brok.add_trans(trans);

			// finds new patron location
			for(int i = 0; i<brok.get_patrons().size(); i++) {
			  if(brok.get_patrons()[i].get_acct_num() == acct_num) {
				where = i;
			  }
			}

			cout << "New " << stock << " in Brokerage:" << brok.get_patrons()[where].get_shares()[share_index] << endl;
			cout << "Removing Cash " << share.get_value() << "from Patron " <<  pat.get_name() << "account." << endl;

			cout << "Old Account Cash Balance: " << oldCash << endl;
			cout << "Old Account USDs Balance: " << oldBal << endl;

			cout << "New Account Cash Balance: " << brok.get_patrons()[where].get_cash() << endl;
			cout << "New Account USDs Balance: " << brok.get_patrons()[where].get_bal() << endl;
		}
		else {
			cout << "Patron doesn't exist" << endl;
		}
	  }
      break;

//------------------------------------------------------------------------------

      case 'I': {
        for(int i=0; i<brok.get_patrons().size(); i++) {
          if(brok.get_patrons()[i].get_cash() < 0.0) {
            cout << brok.get_patrons()[i] << endl;
          }
        }
      }
      break;

//------------------------------------------------------------------------------

      case 'J': {
        for(int i = 0; i < brok.get_trans().size(); i++) {
          cout << brok.get_trans()[i] << endl;
        }
      }
      break;

//------------------------------------------------------------------------------

      case 'K': {
		char save;
        cout << "Would you like to save? Y/N: " << endl;
		cin >> save;
		
		if(save == 'Y' || save == 'y') {
			string fileName;
			cout << "Enter output File Name as a string with no spaces or special characters: ";
			cin >> fileName;
			ofstream of1{fileName};
			of1 << brok;
		}
        run = false;
      }
      break;

//------------------------------------------------------------------------------

      default: { cout << "enter a valid option number" << endl; }
      break;
    }
  }

  return 0;
}
