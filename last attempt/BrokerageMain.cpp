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

  string brokerage_name;
  string input_filename;
  string patron_name;
  int acct_num;
  double deposit;

  char user_choice;

  //cout << "Enter Brokerage name as a string (no spaces): " << endl;
  //cin >> brokerage_name;
  Brokerage brok = Brokerage();

  cout << "Enter input file name as a string w/ no spaces" <<
  " or special characters (or Q to skip)" << endl;
  cin >> input_filename;
  /* implement if stream or do nothing if q */
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
              << "CASH" << brok.get_total_cash() << endl
              << "USD "<< brok.get_total_USD() << endl;
            }
            break;
          default: { cout << "enter a valid option" << endl;}
          break;
          }
        }
      break;
      case 'B': {
        cout << "Enter Patron's name (use underscores for spaces):"
        cin >> patron_name;
        cout << "Enter Patron's Brokerage account number (a nonnegative integer):"
        cin >> acct_num;
        brok.add(Patron(patron_name, acct_num));
        cout << "Enter initial deposit by this Patron (USDs only):"
        cin >> deposit;
        for(int i = 0; i<brok.get_patrons().size(); i++) {
          if(brok.get_patron()[i].get_acct_num() == acct_num) {
            brok.get_patron()[i].add(deposit);
            brok.set_totalCash();
          }
        }
      }
      break;
      case 'C': {

      }
      break;
      case 'D': {

      }
      break;
      case 'E': {

      }
      break;
      case 'F': {

      }
      break;
      case 'G': {

      }
      break;
      case 'H': {

      }
      break;
      case 'I': {

      }
      break;
      case 'J': {

      }
      break;
      case 'K': {
        run = false;
      }
      break;
      default: { cout << "enter a valid option number" << endl; }
      break;
    }
  }

  return 0;
}
