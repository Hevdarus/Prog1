#include "std_lib_facilities.h"

template<typename T>
struct S
{
	
	S(T v = 0) : val(v) {}

	T& get();
	const T& get() const;

	void set(T t);
	//const void set(T t) const;

private:

	T val;

};

template<typename T>
T& S<T>::get(){return val;}

template<typename T>
const T& S<T>::get() const {return val;}



template<typename T>
void S<T>::set(T t){val = t;}
//template<typename T>
//const void S<T>::set(T t) const {val = t;}

template<typename T>
istream& operator>>(istream& is, S<T>& s){

	T v;
	is>>v;
	if(!is){return is;}

	s.set(v);

	return is;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v){

	T va;
	is>>va;
	v.push_back(va);
	return is;
}

template<typename T>
void read_val(T& v){

	cin>>v;

}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){

	for(int i=0; i<v.size(); i++){
		os<<v[i]<<' ';
	}

	os<<endl;

	return os;

}

int main() {

	S<int> si(5);
	S<char> sc('X');
	S<double> sd(3.14);
	S<string> ss("Szöveg");
	vector<int> ve = {1, 2, 3, 4};
	S<vector<int>> svi(ve);

	cout<<si.get()<<endl;
	cout<<sc.get()<<endl;
	cout<<sd.get()<<endl;
	cout<<ss.get()<<endl;
	cout<<svi.get();



	S<int> ii(8);
	ii.set(12);
	cout<<ii.get()<<endl;

	S<char> sch;
	cout<<"Char: ";
	read_val(sch);
	cout<<sch.get()<<endl;

	S<int> si2;
	cout<<"Int: ";
	read_val(si2);
	cout<<si2.get()<<endl;

	/*vector<int> vi = {5, 6, 7};
	S<vector<int>> svi2(vi);
	read_val(svi2);
	cout<<svi2.get();*/

	

	return 0;
}