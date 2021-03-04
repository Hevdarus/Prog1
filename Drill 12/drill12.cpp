/*
    g++ drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"


int main(){

	using namespace Graph_lib;

	//Az ablak létrehozása
	Point kezd {200, 200};

	Simple_window win (kezd, 900, 600, "My window");

	//x tengely hozzáadása

	Axis xa(Axis::x, Point{20, 300}, 350, 15, "x axis");
	xa.set_color(Color::red);

	//y tengely hozzáadása
	Axis ya(Axis::y, Point{20, 300}, 350, 15, "y axis");
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);

	//sinus függvény
	Function sine (sin, 0, 100, Point{20, 150}, 1000, 50, 50);
	sine.set_color(Color::blue);


	//polygon
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);

	//téglalap
	Rectangle r(Point{200,200}, 100, 50);
	r.set_color(Color::green);

	//Zárt sokszög
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50, 80});
	poly_rect.add(Point{50,70});
	r.set_fill_color(Color::yellow);


	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash,2));

	//szöveg
	Text t(Point{150,150}, "Hello, grafikus világ");
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	t.set_color(Color::green);

	//Kép
	Image ii(Point{200,150}, "badge.jpg");
	//ii.move(100,200);

	//"A többi"
	Circle c(Point{100,200},100);

	/*Ellipse e(Point{100,200}, 75,25);
	e.set_color(Color::dark_red);*/

	Mark m(Point{200,200}, 'X');

	/*osrtingstream oss;
	oss<<"screen size: "<<x_max()<<"*"<<y_max();*/


	//Text sizes(Point{100,20},oss.str());

	Image cal(Point{225,225}, "snow_cpp.gif");
	cal.set_mask(Point{40,40}, 200, 150);







	win.attach(xa);
	//win.set_label("Canvas 2");

	win.attach(ya);
	//win.set_label("Canvas 3");
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	win.attach(ii);
	win.attach(c);
	win.attach(m);
	//win.attach(e);

	//win.attach(sizes);
	win.attach(cal);

	win.wait_for_button();

	return 0;
}