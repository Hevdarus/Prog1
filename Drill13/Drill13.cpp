/*
    g++ Drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"




int main(){

	using namespace Graph_lib;
//1. feladat
	int x_max=1000;
	int y_max=800;

	Simple_window win{Point{100, 100}, x_max, y_max, "Window"};

	int x_grid_end=800;
	int x_grid=x_grid_end/8;
	int y_grid=y_max/8;


//2. feladat
	Lines grid; //Négyzetrács
	for(int i=0; i<8; i++){
		grid.add(Point{(i+1)*x_grid, 0}, Point{(i+1)*x_grid, y_max});//Függőleges
	}
	for(int i=0; i<8; i++){
		grid.add(Point{0, (i+1)*y_grid}, Point{x_grid_end, (i+1)*y_grid});//Vízszintes
	}
	win.attach(grid);


//3. feladat
	Vector_ref<Rectangle> vr; //Téglalapok vektora
	for(int i=0; i<8; i++){
		vr.push_back(new Rectangle (Point{i*x_grid, i*y_grid}, Point{(i+1)*x_grid, (i+1)*y_grid}));
		vr[i].set_fill_color(Color::red);
		win.attach(vr[i]);
	}

//4.feladat
	Vector_ref<Image> vi; //Képek vektora
	vi.push_back(new Image(Point{2*x_grid, 0}, "badge.jpg"));
	vi[0].set_mask(Point{2*x_grid, 0}, 2*x_grid, 2*y_grid);

	vi.push_back(new Image(Point{5*x_grid, 2*y_grid}, "badge.jpg"));
	vi[1].set_mask(Point{x_grid,y_grid}, 2*x_grid, 2*y_grid);

	vi.push_back(new Image(Point{0, 3*y_grid}, "badge.jpg"));
	vi[2].set_mask(Point{0, 2*y_grid}, 2*x_grid, 2*y_grid);

	for(int i=0; i<vi.size(); i++){
		win.attach(vi[i]); //A képek ablakra csatolása
	}

//5.feladat
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			Image mo (Point{j*x_grid, i*y_grid}, "100.jpg");
			win.attach(mo);
			win.wait_for_button();
		}
	}
	



	return 0;
}