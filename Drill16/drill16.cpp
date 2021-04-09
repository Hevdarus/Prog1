/*
    g++ drill16.cpp Graph.cpp Window.cpp GUI.cpp Lines_Window.cpp -o drill16 `fltk-config --ldflags --use-images`
*/
#include "Graph.h"
#include "Lines_Window.h"

int main(){

	using namespace Graph_lib;

	Lines_Window win{Point{50, 50}, 1920, 1080, "Window"};

	return gui_main();



	return 0;
}