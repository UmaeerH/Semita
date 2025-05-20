#include "misc.h"
#include "termcolor/termcolor.hpp"
#include <iostream>

using namespace std;

/*
db   d8b   db d88888b db       .o88b.  .d88b.  .88b  d88. d88888b      d888888b  .d88b.  
88   I8I   88 88'     88      d8P  Y8 .8P  Y8. 88'YbdP`88 88'          `~~88~~' .8P  Y8. 
88   I8I   88 88ooooo 88      8P      88    88 88  88  88 88ooooo         88    88    88 
Y8   I8I   88 88~~~~~ 88      8b      88    88 88  88  88 88~~~~~         88    88    88 
`8b d8'8b d8' 88.     88booo. Y8b  d8 `8b  d8' 88  88  88 88.             88    `8b  d8' 
 `8b8' `8d8'  Y88888P Y88888P  `Y88P'  `Y88P'  YP  YP  YP Y88888P         YP     `Y88P'  
                                                                                         
                                                                                         
.d8888. d88888b .88b  d88. d888888b d888888b  .d8b.  db                                  
88'  YP 88'     88'YbdP`88   `88'   `~~88~~' d8' `8b 88                                  
`8bo.   88ooooo 88  88  88    88       88    88ooo88 YP                                  
  `Y8b. 88~~~~~ 88  88  88    88       88    88~~~88                                     
db   8D 88.     88  88  88   .88.      88    88   88 db                                  
`8888Y' Y88888P YP  YP  YP Y888888P    YP    YP   YP YP                                  
*/


void introPrint()
{ // Surely there's a better way to do this
    cout << termcolor::red << "==============================================================================================" << termcolor::green << endl;
    cout << "db   d8b   db d88888b db       .o88b.  .d88b.  .88b  d88. d88888b      d888888b  .d88b.  " << endl;
    cout << "88   I8I   88 88'     88      d8P  Y8 .8P  Y8. 88'YbdP`88 88'          `~~88~~' .8P  Y8. " << endl;
    cout << "88   I8I   88 88ooooo 88      8P      88    88 88  88  88 88ooooo         88    88    88 " << endl;
    cout << "Y8   I8I   88 88~~~~~ 88      8b      88    88 88  88  88 88~~~~~         88    88    88 " << endl;
    cout << "`8b d8'8b d8' 88.     88booo. Y8b  d8 `8b  d8' 88  88  88 88.             88    `8b  d8' " << endl;
    cout << " `8b8' `8d8'  Y88888P Y88888P  `Y88P'  `Y88P'  YP  YP  YP Y88888P         YP     `Y88P'  " << endl;
    cout << "                                                                                         " << endl;
    cout << "                                                                                         " << endl;
    cout << ".d8888. d88888b .88b  d88. d888888b d888888b  .d8b.  db                                  " << endl;
    cout << "88'  YP 88'     88'YbdP`88   `88'   `~~88~~' d8' `8b 88                                  " << endl;
    cout << "`8bo.   88ooooo 88  88  88    88       88    88ooo88 YP                                  " << endl;
    cout << "  `Y8b. 88~~~~~ 88  88  88    88       88    88~~~88                                     " << endl;
    cout << "db   8D 88.     88  88  88   .88.      88    88   88 db                                  " << endl;
    cout << "`8888Y' Y88888P YP  YP  YP Y888888P    YP    YP   YP YP                                  " << endl;
    cout << termcolor::red << "==============================================================================================" << termcolor::reset << endl;
}