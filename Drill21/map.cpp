#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>

template<typename T, typename U>
void print(std::map<T,U>& m){

	std::cout<<"Content of map: "<<std::endl;

	for(auto& a : m){
		std::cout<<a.first<<' '<<a.second<<std::endl;
	}

}

void Beolv(std::map<std::string, int>& m){

	std::string szo="";
	int x=0;
	for(int i=0; i<10; i++){
		std::cin>>szo>>x;
		m.insert(std::pair<std::string, int>(szo, x));
	}


}

int main(){

	std::map<std::string, int> msi;

	msi.insert(std::pair<std::string, int>("Szöveg", 12));
	msi.insert(std::pair<std::string, int>("Este", 4));
	msi.insert(std::pair<std::string, int>("Van", 542));
	msi.insert(std::pair<std::string, int>("Virtual", 5345));
	msi.insert(std::pair<std::string, int>("Note", 43));
	msi.insert(std::pair<std::string, int>("Standard", 2));
	msi.insert(std::pair<std::string, int>("Húr", 23));
	msi.insert(std::pair<std::string, int>("Egész", 8));
	msi.insert(std::pair<std::string, int>("Valami", 26));
	msi.insert(std::pair<std::string, int>("Nice", 69));

	print(msi);

	msi.erase(msi.begin(), msi.end());

	print(msi);

	Beolv(msi);
	std::cout<<"New ";
	print(msi);

	int sum = std::accumulate(msi.begin(), msi.end(), 0,
		[](int s, const std::pair<std::string,int>& m) //átad egy párt
		{return s+=m.second; });

	std::cout<<"The values summed: "<<sum<<std::endl;

	std::map<int, std::string> mis;

	std::map<std::string, int>::iterator it=msi.begin();

	for(it=msi.begin(); it!=msi.end(); it++){
		mis.insert(std::pair<int, std::string>((*it).second, (*it).first));

	}

	print(mis);




	return 0;
}