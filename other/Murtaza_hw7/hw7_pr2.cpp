/* Author: Murtaza Hakimi
*
* HW7_PR2:
* Description:
*
* Create a graphics display window to display Bell Curve, with the following
* GUI widgets:
* In-Box’s to specify X and Y coordinate points in the Window for the Bell Curve
* Out-Box to show the last X,Y coordinate points for the Bell Curve
* In-Box’s to specify X and Y scalars to control the size of the Bell Curve
* Out-Box to show the last X,Y scalars for the Bell Curve
* Next Button to redraw the Bell Curve with the last X,Y coordinate points and scalars
* Menu Button and Color Menu (red, blue, black) to change Bell Curve color
* Quit Button to exit Window and program
*
*/

#include "std_lib_facilities_4.h"
#include <iostream>    // for i/o
#include <sstream>     // for string streams
#include "Graph.h"     // next 3 are for graphics library
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

double bell(double per)
{
  double mid = 0.5;
  double val;
  if (per < 0) per *= -1;
  if (per > mid) {
    per = 1 - per;
    val = 1 - ((per - ((1 - per) * per)) * (1 / (1 - mid)));
  } else {
    val = (per - ((1 - per) * per)) * (1 / mid);
  }
  val = 1 - val;
  return val;
}


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
  Button next_button;                // button indicating next point is ready
  Button quit_button;                // end program
  In_box next_x;                     // box for entering x coord of next point
  In_box next_y;                     // box for entering y coord of next point
  In_box scale_x;                    // box for entering x scalar of next point
  In_box scale_y;                    // box for entering y scalar of next point
  Out_box xy_out;                    // box for displaying last point entered
  Out_box scale_out;                 // box for displaying the scale fo last point entered
  Menu color_menu;                   // menu of color choices for the lines
  Button menu_button;                // button to display the color menu

  // function members

  void change(Color c) {             // change the color of the lines
    lines.set_color(c);
  }

  void hide_menu() {
    // hides the color menu and shows the button to display the color menu
    color_menu.hide();
    menu_button.show();
  }

  // actions invoked by callbacks:

  void red_pressed() {
    change(Color::red);
    hide_menu();        // once a color is chosen from the menu, hide the menu
  }

  void blue_pressed() {
    change(Color::blue);
    hide_menu();
  }

  void black_pressed() {
    change(Color::black);
    hide_menu();
  }

  void menu_pressed() {
    // when menu button is pressed, hide the menu button and show the
    // actual menu of colors
    menu_button.hide();
    color_menu.show();
  }

  void next();   // defined below

  void quit();   // defined below

  // callback functions; declared here and defined below.

  static void cb_red(Address, Address);
  static void cb_blue(Address, Address);
  static void cb_black(Address, Address);
  static void cb_menu(Address, Address);
  static void cb_next(Address, Address);
  static void cb_quit(Address, Address);
};

// ----------------------------------------------------------
// now define the parts of Lines_window that were only declared
// inside the class

// constructor:

Lines_window::Lines_window(Point xy, int w, int h, const string& title) :

  // initialization - start by calling constructor of base class
  Window(xy,w,h,title),

  // initialize "Next point" button
  next_button(
	      Point(x_max()-150,0),   // location of button
	      70, 20,                 // dimensions of button
	      "Next point",           // label of button
	      cb_next),               // callback function for button
  // initialize quit button
  quit_button(
	      Point(x_max()-70,0),    // location of button
	      70, 20,                 // dimensions of button
	      "Quit",                 // label of button
	      cb_quit),               // callback function for button
  // initialize the next_x inbox
  next_x(
	 Point(x_max()-330,0),       // location of box
	 50, 20,                     // dimensions of box
	 "coord x:"),                 // label of box
  // initialize the next_y inbox
  next_y(
	 Point(x_max()-210,0),       // location of box
	 50, 20,                     // dimensions of box
	 "coord y:"),                 // label of box
  // initialize the scale_x inbox
  scale_x(
    Point(x_max()-330, 30),
    50, 20,
    "scale x:"),
  //initialize the scale_y inbox
  scale_y(
    Point(x_max()-210, 30),
    50, 20,
    "scale y:"),
  // initialize the outbox
  xy_out(
	 Point(100,0),               // location of box
	 100, 20,                    // dimensions of box
	 "coord (x,y):"),            // label of box
  // initialize the outbox
  scale_out(
    Point(100, 30),
    100, 20,
    "scale (x,y):"),
  // initialize the color menu
  color_menu(
	     Point(x_max()-70,30),   // location of menu
	     70, 20,                 // dimensions of menu
	     Menu::vertical,         // list menu items vertically
	     "color"),               // label of menu
  // initialize the menu button
  menu_button(
	      Point(x_max()-80,30),  // location of menu button
	      80, 20,                // dimensions of button
	      "color menu",          // label of button
	      cb_menu)               // callback for button

  // body of constructor follows
{
  // attach buttons and boxes to window
  attach(next_button);
  attach(quit_button);
  attach(next_x);
  attach(next_y);
  attach(scale_x);
  attach(scale_y);
  attach(scale_out);
  attach(xy_out);
  xy_out.put("no point");        // output to out box
  scale_out.put("no scale");     // output to out box

  // First make 3 buttons for color menu, one for each color, and
  // attach them to the menu: the attach function of the Menu struct
  // adjusts the size and location of the buttons; note callback functions).
  // Then attach menu to window but hide it (initially, the menu button
  // is displayed, not the actual menu of color choices).

  color_menu.attach(new Button(Point(0,0),0,0,"red",cb_red));
  color_menu.attach(new Button(Point(0,0),0,0,"blue",cb_blue));
  color_menu.attach(new Button(Point(0,0),0,0,"black",cb_black));
  attach(color_menu);
  color_menu.hide();

  // attach menu button
  attach(menu_button);

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

void Lines_window::cb_quit(Address, Address pw) {
  reference_to<Lines_window>(pw).quit();   // quit is defined next
}

//------------------------------------
// what to do when quit button is pressed

void Lines_window::quit() {
  hide();                   // FLTK idiom for delete window
}

// ----------------------------
// callback function for next button - boilerplate:

void Lines_window::cb_next(Address, Address pw) {
  reference_to<Lines_window>(pw).next();  // next is defined next
}

// -------------------------------
// what to do when "next point" button is pressed

void Lines_window::next() {
  // get input data from the inboxes - x and y coordinates
  // of next point
  int x = next_x.get_int();
  int y = next_y.get_int();

  int x_scale = scale_x.get_int();
  int y_scale = scale_y.get_int();

  // add the new point to the lines object
  // lines.add(Point(x,y));

  // update current position readout - make a string with the
  // coordinate info and use the out box
  stringstream co;
  co << '(' << x << ',' << y << ')';
  xy_out.put(co.str());

  // update current scalar readout = make a string with the
  // scale info and use the correct out box
  stringstream sc;
  sc << '(' << x_scale << ',' << y_scale << ')';
  scale_out.put(sc.str());

  // center of the the panel
  float gigMeDaddy = float(x_max()) / 2.f;

  // finds each point on the bell curve
  for(int i = 0; i < 100; i++) {
      float bellY =  - bell((float(i) / 50.f) - 1.f);
      bellY *= y_scale;
      bellY += y;

      float bellX = - ((float(i) / 50.f) - 1.f);
      bellX *= x_scale;
      bellX += x;
      //float bellX = ((float(i) * (1.f / 50.f))) * (x_scale/2);
      //bellX += gigMeDaddy;

      lines.add(Point(bellX, bellY));
  }

  // Function gaus(bell,     // plot bell (gaussian) function
  //   -1,1,   // range of x-values
  //   Point(x,y),  // location of the origin
  //   100,    // number of points to plot
  //   x_scale,y_scale);  // scaling factors for x and y values
  // attach(gaus);


  redraw();  // function inherited from Window to redraw the window
}

// -------------------------------
// callback for when red button (part of color menu) is pressed - boilerplate

void Lines_window::cb_red(Address, Address pw) {
  reference_to<Lines_window>(pw).red_pressed();
  // red_pressed defined in Lines_window class as part of declaration
}

// -------------------------------
// callback for when blue button (part of color menu) is pressed - boilerplate

void Lines_window::cb_blue(Address, Address pw) {
  reference_to<Lines_window>(pw).blue_pressed();
  // blue_pressed defined in Lines_window class as part of declaration
}

// -------------------------------
// callback for when black button (part of color menu) is pressed - boilerplate

void Lines_window::cb_black(Address, Address pw) {
  reference_to<Lines_window>(pw).black_pressed();
  // black_pressed defined in Lines_window class as part of declaration
}

// -------------------------------
// callback for when menu button is pressed - boilerplate

void Lines_window::cb_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).menu_pressed();
    // menu_pressed defined in Lines_window class as part of declaration
}

// ---------------------------------------------------
// main - just creates window and invokes gui_main

int main()
  try {
    // construct the GUI window
    Lines_window win(Point(100,100),600,400,"Bell Curve");
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
