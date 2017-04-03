#include <iostream>

using namespace std;

int main(){

  int choice = 0;
  bool run = true;

  while(run) {
    // menu options
    cout << "Options: " << endl
    << "1. Display Brokerage State" << endl
    << "2. New Patron" << endl
    << "3. Existing Patron" << endl
    << "4. Patron Info" << endl
    << "5. Add Cash" << endl
    << "6. Remove Cash" << endl
    << "7. Stock Sale" << endl
    << "8. Stock Buy" << endl
    << "9. Overdrawn Patrons" << endl
    << "10. Public Transaction History" << endl
    << "11. Quit" << endl;

    cin >> choice;

    switch (choice) {
      case 1: {cout << "1. Shares of a Stock Type" << endl
      << "2. Shares of All Cash Accounts" << endl
      << "3. All Shares" << endl;

      cin >> choice;

      switch (choice) {
        case 1: {
          cout << "1. First Stock Type" << endl
          << "2. Second Stock Type" << endl
          << "3. Third Stock Type" << endl
          << "4. Fourth Stock Type" << endl
          << "5. Fifth Stock Type" << endl;

          cin >> choice;

          switch (choice) {
            case 1:{} //stuff
            break;
            case 2:{} //stuff
            break;
            case 3:{} //stuff
            break;
            case 4:{} //stuff
            break;
            case 5:{} //stuff
            break;
            default: {cout << "Please enter a valid option..." << endl; }
            // loop back up so they can enter a valid integer
            break;
          }
        }
        break;
        case 2: { /* output shares of all cash accounts */ }
        break;
        case 3: { /* output shares of all accounts */ }
        break;
        default: { cout << "Please enter a valid option..." << endl; }
        // loop back up so they can enter a valid integer
        break;
      }
    }
    break;
    case 2: { /* use constructor to make new patron, if account # matches dont add */ }
    break;
    case 3: { /* check if patron exists */ }
    break;
    case 4: { /* display all patrons */ }
    break;
    case 5: { /* using account number, add cash */ }
    break;
    case 6: { /* using account number, remove cash */ }
    break;
    case 7: { /* sale */ }
    break;
    case 8: { /* buy */ }
    break;
    case 9: { /* list deadbeats */ }
    break;
    case 10: { /* displays all transactions */ }
    break;
    case 11: { /* quits program */
      run = false;
    }
    break;
    default: {cout << "Please enter a valid option..." << endl;}
    // loop back up so they can enter a valid integer
    break;
  }
}
return 0;

}
