#include <vector>
#include <fstream>
#include <iostream>
#include <numeric>
#include <algorithm>



template<typename T>
void print(std::vector<T>& v){

	for(auto a : v){
		std::cout<<a<<' ';
	}
	std::cout<<std::endl;

}

struct Less_than{
	double v;
	Less_than(double vv) : v(vv){}

	bool operator()(double x){return x < v; }

};

int main()
{

	const std::string fs {"szamok.txt"};
	std::ifstream ifs {fs};
	if(!ifs) throw std::runtime_error("could not read from file: " + fs);

	std::vector<double> vd;

	for(double i; ifs>>i;) vd.push_back(i);

	print(vd);

	std::vector<int> vi(vd.size());

	std::copy(vd.begin(), vd.end(), vi.begin());

	//print(vi);

	std::cout<<"Pairs:"<<std::endl;
	for(int i = 0; i < vd.size(); i++){
		std::cout<<vd[i]<<' '<<vi[i]<<std::endl;

	}

	double d_sum = std::accumulate(vd.begin(), vd.end(),0.0);

	std::cout<<"Sum of vd: "<<d_sum<<std::endl;

	int i_sum=std::accumulate(vi.begin(), vi.end(), 0);

	std::cout<<"The difference between the double and integer vector summs: "
		<<d_sum-i_sum<<std::endl;

	std::reverse(vd.begin(), vd.end());
	std::cout<<"Reversed vd:"<<std::endl;
	print(vd);

	double mean=d_sum/vd.size();
	std::cout<<"Mean value: "<<mean<<std::endl;

	std::vector<double> vd2(vd.size());

	/*for(int i = 0; i < vd.size(); i++){
		if(vd[i]<mean){
			vd2.push_back(vd[i]);
		}

	}*/

	auto it = std::copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(mean));

	vd2.resize(std::distance(vd2.begin(), it));
	print(vd2);

	std::sort(vd.begin(), vd.end());

	print(vd);

	return 0;
}