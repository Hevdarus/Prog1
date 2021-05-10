#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

template<typename C>
void print(C& cont){

	for (auto& a : cont){
		std::cout<< a <<' ';
	}
	std::cout<<std::endl;
}

template<typename C>
void increase(C& cont, int n){

	for(auto& a : cont){
		a+=n;
	}

}
template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 begin1, Iter1 end, Iter2 begin2){
	
	//if(f1==e1){throw "Empty container";}
	while(begin1!=end){

		*begin2=*begin1;
		begin1++;
		begin2++;
	}

	return begin2;
}

int main(){

	const int size=10;
	
	//Array
	std::array<int, size> array = {0,1,2,3,4,5,6,7,8,9};
	std::cout<<"Array: ";
	print(array);

	//Vector
	std::vector<int> vi{0,1,2,3,4,5,6,7,8,9};
	std::cout<<"Vector: ";
	print(vi);

	//List
	std::list<int> li{0,1,2,3,4,5,6,7,8,9};
	std::cout<<"List: ";
	print(li);


	//2nd array
	std::array<int, size>array2=array;

	//2nd vector
	std::vector<int> vi2=vi;

	//2nd list
	std::list<int> li2=li;

	//increase
	increase(array, 2);
	increase(vi, 3);
	increase(li, 5);

	std::cout<<"After increase: "<<std::endl;
	std::cout<<"Array: ";
	print(array);
	std::cout<<"Vector: ";
	print(vi);
	std::cout<<"List: ";
	print(li);

	//copy
	my_copy(array.begin(), array.end(), vi.begin());
	my_copy(li.begin(), li.end(), array.begin());

	std::cout<<"After copy: "<<std::endl;
	std::cout<<"Vector: ";
	print(vi);
	std::cout<<"Array: ";
	print(array);

	//find
	int vik=3;
	auto viit=std::find(vi.begin(), vi.end(), vik);
	if(viit!=vi.end()){
		std::cout<<vik<<" found at position "<<std::distance(vi.begin(), viit)
		<<std::endl;
	}else {std::cout<<vik<<" was not found"<<std::endl;}

	int lik=27;
	auto liit=std::find(li.begin(), li.end(), lik);
	if(liit!=li.end()){
		std::cout<<lik<<" found at position "<<std::distance(li.begin(), liit)
		<<std::endl;
	}else{std::cout<<lik<< " was not fonund"<<std::endl;}
	
	
	return 0;
}