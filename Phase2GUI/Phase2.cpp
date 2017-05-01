// Example code from Chapter 16.5 from textbook (chapter.16.7.cpp)
// with additional annotations.
// This code constructs a GUI that interacts with the user through
// buttons, boxes, and menus to draw an open polyline defined by
// points given by the user.

#include <iostream>    // for i/o
#include <sstream>     // for string streams
#include "Graph.h"     // next 3 are for graphics library
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

//----------------------------------------------------------
// define a struct that is a window in which lines can be
// entered via a GUI

struct Lines_window : Graph_lib::Window {       // inherits from Window

  // constructor
  Lines_window(Point xy,             // top lefthand corner
	       int w,                // width
	       int h,                // height
	       const string& title); // label

private:
  // data members
  Open_polyline lines;               // shape to hold the lines themselves

  // widgets:
  Button show_brokerage;                // button indicating next point is ready
  Button add_patron;
  Button is_patron;
  Button patrons;
  Button add_cash;
  Button rem_cash;
  Button sell_stock;
  Button buy_stock;
  Button deadbeats;
  Button transactions;
  Button transfer;
  Button quit_button;
  Button next_button;


  In_box I2;
  In_box I3;
  In_box I4;
  In_box I5;
  In_box I6;

  Out_box B1;
  Out_box B2;
  Out_box B3;
  Out_box B4;
  Out_box B5;
  Out_box B6;

  Out_box L1;
  Out_box L2;
  Out_box L3;
  Out_box L4;
  Out_box L5;
  Out_box L6;
  Out_box L7;
  Out_box L8;
  Out_box L9;
  Out_box L10;

  Out_box O1;
  Out_box O2;
  Out_box O3;
  Out_box O4;
  Out_box O5;
  Out_box O6;
  Out_box O7;
  Out_box O8;
  Out_box O9;
  Out_box O10;

  // Menu color_menu;
  // Button menu_button;

  // function members

  // actions invoked by callbacks:



  // void next();   // defined below

   void quit();   // defined below
   void showBrokerage();
   void addPatron();
   void isPatron();
   void patrons();
   void addCash();
   void remCash();
   void sellStock();
   void buyStock();
   void deadbeats();
   void transactions();
   void transfer();

  // callback functions; declared here and defined below.

  // static void cb_red(Address, Address);
  // static void cb_blue(Address, Address);
  // static void cb_black(Address, Address);
  // static void cb_menu(Address, Address);
  // static void cb_next(Address, Address);
   static void cb_quit(Address, Address);
   static void cb_showBrokerage(Address, Address);
   static void cb_addPatron(Address, Address);
   static void cb_isPatron(Address, Address);
   static void cb_patrons(Address, Address);
   static void cb_addCash(Address, Address);
   static void cb_remCash(Address, Address);
   static void cb_sellStock(Address, Address);
   static void cb_buyStock(Address, Address);
   static void cb_deadbeats(Address, Address);
   static void cb_transactions(Address, Address);
   static void cb_transfer(Address, Address);
};

// ----------------------------------------------------------
// now define the parts of Lines_window that were only declared
// inside the class

// constructor:

Lines_window::Lines_window(Point xy, int w, int h, const string& title) :

  // initialization - start by calling constructor of base class
  Window(xy,w,h,title),

  show_brokerage(
	      Point(0,0),
	      120, 23,
	      "ShowBrokerage",
	      cb_showBrokerage),

  add_patron(
	      Point(0,23),
	      120, 23,
	      "AddPatron",
	      cb_addPatron),

  is_patron(
		  Point(0,46),
		  120, 23,
		  "Is?Patron",
		  cb_isPatron),

  patrons(
		  Point(0,69),
		  120, 23,
		  "Patrons",
		  cb_patrons),

  add_cash(
		  Point(0,92),
		  120, 23,
		  "AddCash",
		  cb_addCash),

  rem_cash(
		  Point(0,115),
		  120, 23,
		  "RemCash",
		  cb_remCash),

  sell_stock(
		  Point(0,138),
		  120, 23,
		  "SellStock",
		  cb_sellStock),

  buy_stock(
		  Point(0,161),
		  120, 23,
		  "BuyStock",
		  cb_buyStock),

  deadbeats(
		  Point(0,184),
		  120, 23,
		  "DeadBeats",
		  cb_deadbeats),

  transactions(
		  Point(0,207),
		  120, 23,
		  "Xactions",
		  cb_transactions),

  transfer(
		  Point(0,230),
		  120, 23,
		  "Transfer",
		  cb_transfer),

  next_button(
		  Point(0,276),
		  120, 23,
		  "Next",
		  cb_quit),

  quit_button(
		  Point(0,253),
		  120, 23,
		  "Quit",
		  cb_quit),



  // In/Out-Boxes--------------------------

	I2( Point(200, 0),
		120, 23,
		"I2:"),

	I3( Point(200, 23),
		120, 23,
		"I3:"),

	I4( Point(200, 46),
		120, 23,
		"I4:"),

	I5( Point(200, 69),
		120, 23,
		"I5:"),

	I6( Point(200,92),
		120, 23,
		"I6:"),



	B1( Point(200, 138),
		120, 23,
		"INTC:"),

	B2( Point(200, 161),
		120, 23,
		"GOOG:"),

	B3( Point(200, 184),
		120, 23,
		"AAPL:"),

	B4( Point(200, 207),
		120, 23,
		"YHOO:"),

	B5( Point(200, 230),
		120, 23,
		"IBM:"),

	B6( Point(200, 253),
		120, 23,
		"Cash:"),



	L1( Point(400, 0),
		120, 23,
		"L1:"),

	L2( Point(400, 23),
		120, 23,
		"L2:"),

	L3( Point(400, 46),
		120, 23,
		"L3:"),

	L4( Point(400, 69),
		120, 23,
		"L4:"),

	L5( Point(400, 92),
		120, 23,
		"L5:"),

	L6( Point(400, 115),
		120, 23,
		"L6:"),

	L7( Point(400, 138),
		120, 23,
		"L7:"),

	L8( Point(400, 161),
		120, 23,
		"L8:"),

	L9( Point(400, 184),
		120, 23,
		"L9:"),

	L10( Point(400, 207),
		120, 23,
		"L10:"),


	O1( Point(600, 0),
		120, 23,
		"O1:"),

	O2( Point(600, 23),
		120, 23,
		"O2:"),

	O3( Point(600, 46),
		120, 23,
		"O3:"),

	O4( Point(600, 69),
		120, 23,
		"O4:"),

	O5( Point(600, 92),
		120, 23,
		"O5:"),

	O6( Point(600, 115),
		120, 23,
		"O6:"),

	O7( Point(600, 138),
		120, 23,
		"O7:"),

	O8( Point(600, 161),
		120, 23,
		"O8:"),

	O9( Point(600, 184),
		120, 23,
		"O9:"),

	O10( Point(600, 207),
		120, 23,
		"O10:")

  // next_x(
	 // Point(x_max()-345,0),
	 // 50, 20,
	 // "next x:"),
  //initialize the next_y inbox
  // next_y(
	 // Point(x_max()-345,25),
	 // 50, 20,
	 // "next y:"),
  // initialize the outbox
  // xy_out(
	 // Point(100,0),
	 // 100, 20,
	 // "current (x,y):"),
  // initialize the size_x inbox
  // size_x(
	// Point(x_max()-210,0),
	// 50, 20,
	// "next x size:"),
  // size_y(
	// Point(x_max()-210,25),
	// 50, 20,
	// "next y size:"),
  // size_out(
	// Point(100,25),
	// 100, 25,
	// "size (x,y):"),
  // initialize the color menu
  // color_menu(
	     // Point(x_max()-70,30),   // location of menu
	     // 70, 20,                 // dimensions of menu
	     // Menu::vertical,         // list menu items vertically
	     // "color"),               // label of menu
  // initialize the menu button
  // menu_button(
	      // Point(x_max()-80,30),  // location of menu button
	      // 80, 20,                // dimensions of button
	      // "color menu",          // label of button
	      // cb_menu)               // callback for button

  // body of constructor follows
{
  // attach buttons and boxes to window
  attach(show_brokerage);
  attach(add_patron);
  attach(is_patron);
  attach(patrons);
  attach(add_cash);
  attach(rem_cash);
  attach(sell_stock);
  attach(buy_stock);
  attach(deadbeats);
  attach(transactions);
  attach(transfer);
  attach(quit_button);
  attach(next_button);


  attach(I2);
  attach(I3);
  attach(I4);
  attach(I5);
  attach(I6);

  attach(B1);
  attach(B2);
  attach(B3);
  attach(B4);
  attach(B5);
  attach(B6);

  attach(L1);
  attach(L2);
  attach(L3);
  attach(L4);
  attach(L5);
  attach(L6);
  attach(L7);
  attach(L8);
  attach(L9);
  attach(L10);

  attach(O1);
  attach(O2);
  attach(O3);
  attach(O4);
  attach(O5);
  attach(O6);
  attach(O7);
  attach(O8);
  attach(O9);
  attach(O10);

  // attach shape that holds the lines to be displayed
  attach(lines);
}

// ----------------------------
// callback function for quit button - boilerplate:
// When the button is pressed, the system invokes the
// specified callback function.  First argument is address of the
// button (which we won't use, so we don't bother to name it).  Second
// argument, named pw, is address of the window containing the pressed
// button, i.e., address of our Lines_window object.  reference_to
// converts the address pw into a reference to a Lines_window object,
// so we can call the quit() function.  Objective is to call function
// quit() which does the real work specific to this button.



//------------------------------------
// what to do when quit button is pressed

void Lines_window::quit() {
  hide();                   // FLTK idiom for delete window
}
void Lines_window::cb_quit(Address, Address pw) {
  reference_to<Lines_window>(pw).quit();   // quit is defined next
}

// static void cb_isPatron(Address, Address);
// static void cb_patrons(Address, Address);
// static void cb_addCash(Address, Address);
// static void cb_remCash(Address, Address);
// static void cb_sellStock(Address, Address);
// static void cb_buyStock(Address, Address);
// static void cb_deadbeats(Address, Address);
// static void cb_transactions(Address, Address);
// static void cb_transfer(Address, Address);

void Lines_window::show_brokerage() {

}
void Lines_window::cb_showBrokerage(Address, Address pw) {
  reference_to<Lines_window>(pw).show_brokerage();
}

//------------------------------------------------------------------------------

void Lines_window::addPatron() {

}
void Lines_window::cb_addPatron(Address, Address pw) {
  reference_to<Lines_window>(pw).addPatron();
}

//------------------------------------------------------------------------------

void Lines_window::patrons() {

}
void Lines_window::cb_patrons(Address, Address pw) {
  reference_to<Lines_window>(pw).patrons();
}

//------------------------------------------------------------------------------

void Lines_window::addCash() {

}
void Lines_window::cb_addCash(Address, Address pw) {
  reference_to<Lines_window>(pw).addCash();
}

//------------------------------------------------------------------------------

void Lines_window::remCash() {

}
void Lines_window::cb_remCash(Address, Address pw) {
  reference_to<Lines_window>(pw).remCash();
}

//------------------------------------------------------------------------------

void Lines_window::sellStock() {

}
void Lines_window::cb_sellStock(Address, Address pw) {
  reference_to<Lines_window>(pw).sellStock();
}

//------------------------------------------------------------------------------

void Lines_window::buyStock() {

}
void Lines_window::cb_buyStock(Address, Address pw) {
  reference_to<Lines_window>(pw).buyStock();
}

//------------------------------------------------------------------------------

void Lines_window::deadbeats() {

}
void Lines_window::cb_deadbeats(Address, Address pw) {
  reference_to<Lines_window>(pw).deadbeats();
}

//------------------------------------------------------------------------------

void Lines_window::transfer() {

}
void Lines_window::cb_transfer(Address, Address pw) {
  reference_to<Lines_window>(pw).transfer();
}

//------------------------------------------------------------------------------

void Lines_window::transactions() {

}
void Lines_window::cb_transactions(Address, Address pw) {
  reference_to<Lines_window>(pw).transactions();
}

// -------------------------------
// what to do when "next point" button is pressed




// -------------------------------
// callback for when red button (part of color menu) is pressed - boilerplate



// -------------------------------
// callback for when blue button (part of color menu) is pressed - boilerplate



// -------------------------------
// callback for when black button (part of color menu) is pressed - boilerplate



// -------------------------------
// callback for when menu button is pressed - boilerplate



// ---------------------------------------------------
// main - just creates window and invokes gui_main

int main()
  try {
    // construct the GUI window
    Lines_window win(Point(100,100),800,400,"lines");

	return gui_main();  // inherited from Window; calls FLTK's run
  }
  catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
  }
  catch(...) {
    cerr << "some exception\n";
    return 2;
  }
