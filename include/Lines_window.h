#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	bool wait_for_button();

private:
	Menu color_menu;

	void change(Color c) { lines.set_color(c); }

	void red_pressed() { change(Color::red); hide_menu(); }
	void blue_pressed() { change(Color::blue); hide_menu(); }
	void black_pressed() { change(Color::black); hide_menu(); }
	void menu_pressed() { menu_button.hide(); color_menu.show(); }

	void hide_menu() { color_menu.hide(); menu_button.show(); }


	Button next_button;
	Button quit_button;
	Button menu_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();

};