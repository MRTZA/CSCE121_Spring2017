
#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "GUI.h"
#include "Window.h"
#include <iostream>    // for i/o
#include <sstream>

using namespace Graph_lib;
using namespace std;

// -----------------------------------------------
// define a struct that is a window in which the
// menu options can be displayed via a GUI

struct Brokerage_window : Graph_lib::Window { // inherits from Window

  // constructor
  Brokerage_window(Point xy,    // top lefthand corner
    int w,                      // width
    int h,                      // height
    const string& title);       // label

private:

  // widgets:
  Menu options_menu;                   // menu of main options
  Button menu_button;                  // button to display the option menu

  // function members

  void hide_menu() {
    // hides the options menu and shows the button to display the menu
    options_menu.hide();
    menu_button.show();
  }

  void BrokerageState_pressed() {
    //write in Graph.cpp & Graph.h??
    hide_menu();
  }


}

int main(){

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

  return 0; // chacnges

}
