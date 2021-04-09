#include "Lines_Window.h"

Lines_Window :: Lines_Window(Point xy, int w, int h, const string& title)
: Window{xy, w, h, title},
next_button{Point{x_max()-150, 0}, 150, 40, "Next",
 [](Address, Address pw) {reference_to<Lines_Window>(pw).next();}},

quit_button{Point{x_max()-150, 40}, 150, 40, "Quit",
 [](Address, Address pw) {reference_to<Lines_Window>(pw).quit();}},

next_x{Point{300, 0}, 50, 40, "next_x:"},
next_y{Point{450, 0}, 50, 40, "next_y:"},

xy_out{Point{100,0},100, 40, "current x,y:"},

color_menu{Point{x_max()-300, 0}, 150, 40,Menu::vertical, "Color"},

style_menu{Point{x_max()-300, 0}, 150, 40,Menu::vertical, "Style"},

color_menu_button{Point{x_max()-300, 0}, 150, 40, "Color menu",
 [](Address, Address pw) {reference_to<Lines_Window>(pw).color_menu_pressed();}},

style_menu_button{Point{x_max()-300, 40}, 150, 40, "Style menu",
 [](Address, Address pw) {reference_to<Lines_Window>(pw).style_menu_pressed();}}

{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	attach(lines);

	xy_out.put("No point");

	//color_menu
	color_menu.attach(new Button(Point{0,0},0,0,"red",
	 [](Address, Address pw) {reference_to<Lines_Window>(pw).red_pressed();}));
	color_menu.attach(new Button(Point{0,0},0,0,"blue",
	 [](Address, Address pw) {reference_to<Lines_Window>(pw).blue_pressed();}));
	color_menu.attach(new Button(Point{0,0},0,0,"black",
	 [](Address, Address pw) {reference_to<Lines_Window>(pw).black_pressed();}));
	attach(color_menu);
	color_menu.hide();

	//style_menu
	style_menu.attach(new Button(Point{0,0},0,0,"solid",
	 [](Address, Address pw) {reference_to<Lines_Window>(pw).solid_pressed();}));
	style_menu.attach(new Button(Point{0,0},0,0,"dash",
	 [](Address, Address pw) {reference_to<Lines_Window>(pw).dash_pressed();}));
	style_menu.attach(new Button(Point{0,0},0,0,"dot",
	 [](Address, Address pw) {reference_to<Lines_Window>(pw).dot_pressed();}));
	attach(style_menu);
	style_menu.hide();

	attach(color_menu_button);
	attach(style_menu_button);
}

void Lines_Window::quit(){

	hide();
}

void Lines_Window::next(){

	int x=next_x.get_int();
	int y=next_y.get_int();
	
	lines.add(Point{x,y});

	ostringstream ss;
	ss <<'('<< x <<','<< y <<')';

	xy_out.put(ss.str());

	redraw();
}

//Színek
void Lines_Window::red_pressed(){

	change_color(Color::red);
	hide_menu();
	redraw();
}

void Lines_Window::blue_pressed(){

	change_color(Color::blue);
	hide_menu();
	redraw();
}

void Lines_Window::black_pressed(){

	change_color(Color::black);
	hide_menu();
	redraw();
}
//Színek vége

//Stílusok
void Lines_Window::solid_pressed(){

	change_style(Line_style::solid);
	hide_menu();
	redraw();
}

void Lines_Window::dash_pressed(){

	change_style(Line_style::dash);
	hide_menu();
	redraw();
}

void Lines_Window::dot_pressed(){

	change_style(Line_style::dot);
	hide_menu();
	redraw();
}
//Stílusok vége

//Menük
void Lines_Window::color_menu_pressed(){

	color_menu_button.hide();
	color_menu.show();
	style_menu_button.hide();
}

void Lines_Window::style_menu_pressed(){

	style_menu_button.hide();
	style_menu.show();
	color_menu_button.hide();
}

void Lines_Window::hide_menu(){

	//Menük elrejtése
	style_menu.hide();
	color_menu.hide();
	//Gombok láthatóva tevése
	style_menu_button.show();
	color_menu_button.show();

}
//Menük vége

//Változtatások
void Lines_Window::change_color(Color c){

	lines.set_color(c);
}

void Lines_Window::change_style(Line_style s){

	lines.set_style(s);
}
//Változtatások vége








