#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	bool wait_for_button();

private:
	Menu color_menu, ls_menu;

	void change(Color c) { lines.set_color(c); }
	void ls_change(Line_style s) {lines.set_style(s);};

	void red_pressed() { change(Color::red); hide_menu(); }
	void blue_pressed() { change(Color::blue); hide_menu(); }
	void black_pressed() { change(Color::black); hide_menu(); }
	void solid_pressed() { ls_change(Line_style::solid); ls_hide_menu(); }
	void dash_pressed() { ls_change(Line_style::dash); ls_hide_menu(); }
	void dot_pressed() { ls_change(Line_style::dot); ls_hide_menu(); }
	void menu_pressed() { menu_button.hide(); color_menu.show(); }
	void ls_menu_pressed() { ls_menu_button.hide(); ls_menu.show(); }

	void ls_hide_menu() {ls_menu.hide(); ls_menu_button.show();};
	void hide_menu() { color_menu.hide(); menu_button.show(); }


	Button next_button;
	Button quit_button;
	Button menu_button;
	Button ls_menu_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();

};