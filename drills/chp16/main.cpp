#include <cstdio>
#include <exception>
#include "../../include/Simple_window.h"
#include "Lines_window.h"

/*
    g++ main.cpp ../../include/*.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/

int main() {
    try {
        Lines_window win(Point(100,100), 600, 400, "lines");
        return gui_main();
    }
    catch (exception& e) {
        cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        cerr << "Some exception\n";
        return 2;
    }
}