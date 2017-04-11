
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

#include "hades.h"
#include "chrono.h"

using namespace chrono;
using namespace Hades;

int main() {

  bool run = true;

  string brokerage_name;
  string input_filename;

  int user_choice;
  char uc;

  //cout << "Enter Brokerage name as a string (no spaces): " << endl;
  //cin >> brokerage_name;
  Brokerage brok = Brokerage();

  cout << "Enter input file name as a string w/ no spaces" <<
  " or special characters (or Q to skip)" << endl;
  cin >> input_filename;
  /* implement if stream or do nothing if q */

  cout << "Enter desired option:" << endl
  << "1. display information about Stock Shares and Cash in the Brokerage" << endl
  << "2. add a new Patron to the Brokerage" << endl
  << "3. check if someone is already a Patron" << endl
  << "4. display all Patrons" << endl
  << "5. add Cash to a Patron account" << endl
  << "6. remove Cash from a Patron account" << endl
  << "7. do a Stock Shares Sale for a Patron" << endl
  << "8. do a Stock Shares Buy for a Patron" << endl
  << "9. display all Patrons that are overdrawn" << endl
  << "10. display all transactions ever done by Patrons" << endl
  << "11. quit" << endl;

  cin >> user_choice;

  while (run) {
    switch (user_choice) {
      case 1: {
        cout << "Enter Shares Stock Type (i=Intel, g=Google, a=Apple, y=Yahoo, I=IBM or C=Cash or A=ALL): ";
        cin >> uc;
        switch(uc) {
          case 'i': {
              cout << brok.get_share(0);
            }
            break;
          case 'g': {
              cout << brok.get_share(1);
            }
            break;
          case 'a': {
              cout << brok.get_share(2);
            }
            break;
          case 'y': {
              cout << brok.get_share(3);
            }
            break;
          case 'I': {
              cout << brok.get_share(4);
            }
            break;
          case 'C': {
              cout << brok.get_totalCash();
            }
            break;
          case 'A': {
              cout << brok.get_totalUSD();
            }
            break;
          default: { cout << "enter a valid option";}
          break;
          }
        }
      break;
      case 2: {
        string name;
        int ac;
        cout << "What is your name?" << endl;
        cin >> name;
        cout << "What is your account number?" << endl;
        cin >> ac;
        Patron *p = new Patron(name, ac);
        brok.add_patron(p);
        cout << endl << p;
      }
      break;
      case 3: {

      }
      break;
      case 4: {

      }
      break;
      case 5: {

      }
      break;
      case 6: {

      }
      break;
      case 7: {

      }
      break;
      case 8: {

      }
      break;
      case 9: {

      }
      break;
      case 10: {

      }
      break;
      case 11: {
        run = false;
      }
      break;
      default: { cout << "enter a valid option number" << endl; }
      break;
    }
  }

  return 0;
}
