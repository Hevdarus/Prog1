// g++ drill15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images

#include "Graph.h"
#include "Simple_window.h"
#include <cmath>

double one(double x){return 1;}
double slope(double x){return x/2;}
double square(double x){return x*x;}
double sloping_cos(double x){return cos(x)+slope(x);}

int main(){
	using namespace Graph_lib;

	int const x_max=600;
	int const y_max=600;

	int x_orig=x_max/2;
	int y_orig=y_max/2;

	Point orig{x_orig, y_orig};

	int x_length=400;
	int y_length=400;

	Simple_window win(Point{20, 20}, x_max, y_max, "Function graphs");

	Axis x{Axis::x,Point{(x_max-x_length)/2, y_orig}, x_length, x_length/20, "1 == 20 pixels" };
	Axis y{Axis::y,Point{x_orig, (y_max-y_length)/2+y_length}, y_length, y_length/20, "1 == 20 pixels" };
	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(y);
	win.attach(x);

	//Függvények
	double r_min=-10;
	double r_max=11;

	int n_points=400;
	double x_scale=20, y_scale=20; 

	Function egy {one, r_min, r_max, orig, n_points, x_scale, y_scale};
	Function lejt {slope, r_min, r_max, orig, n_points, x_scale, y_scale};
	Text szov1 {Point{100, 380}, "x/2"};	

	Function negy {square, r_min, r_max, orig, n_points, x_scale, y_scale};

	Function cosine {cos, r_min, r_max, orig, n_points, x_scale, y_scale};
	cosine.set_color(Color::blue);

	Function slopcos {sloping_cos, r_min, r_max, orig, n_points, x_scale, y_scale};


	win.attach(egy);
	win.attach(lejt);
	win.attach(szov1);
	win.attach(negy);
	win.attach(cosine);
	win.attach(slopcos);

	win.wait_for_button();
}