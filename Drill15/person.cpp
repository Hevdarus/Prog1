#include "std_lib_facilities.h"


struct Person{
private:
	string first_name;
	string last_name;
	int age;
public:
	Person() {};
	Person(string f, string l, int a) : first_name(f), last_name(l), age(a) {
		if(!valid_age()) error("Rossz kor!"); 
		else if(!valid_name()) error("Rossz név!");
	};
	bool valid_age();//TODO
	bool valid_name();
	string get_last_name();
	string get_first_name();
	int get_age();

};

//getter függv
string Person::get_last_name(){return last_name;}
string Person::get_first_name(){return first_name;}
int Person::get_age(){return age;}

//Ellenőrzés
bool Person::valid_name(){
	for(int i=0; i<first_name.length(); i++){
		if (first_name[i]==';' || first_name[i]==':' || first_name[i]=='"' ||
		 first_name[i]=='[' || first_name[i]==']' || first_name[i]=='*' ||
		 first_name[i]=='&' || first_name[i]=='^' || first_name[i]=='%' ||
		 first_name[i]=='$' || first_name[i]=='#' || first_name[i]=='@' || first_name[i]=='!')
		{
			return false;
		}
	}
	for(int i=0; i<last_name.length(); i++){
		if (last_name[i]==';' || last_name[i]==':' || last_name[i]=='"' ||
		 last_name[i]=='[' || last_name[i]==']' || last_name[i]=='*' ||
		 last_name[i]=='&' || last_name[i]=='^' || last_name[i]=='%' ||
		 last_name[i]=='$' || last_name[i]=='#' || last_name[i]=='@' || last_name[i]=='!'){
			return false;
		}
	}
	return true;

}

bool Person::valid_age(){
	if(age<0||age>150)return false;
	return true;
}

/*Person::Person(string n, int a){
	bool kapcs=true;
	name=n;
	for(int i=0; i<name.length(); i++){
		if (name[i]==';' || name[i]==':' || name[i]=='"' || name[i]=='[' || name[i]==']' || name[i]=='*' ||
		 name[i]=='&' || name[i]=='^' || name[i]=='%' || name[i]=='$' || name[i]=='#' || name[i]=='@' || name[i]=='!'){
			kapcs=false;
			name="";
		}
	}
	if(kapcs==false){error("Rossz név!");}

	if(a<0||a>150){
		error("Rossz kor!");
	}else{
		age = a;
	}
}*/

//Operátot túlterhelés
ostream& operator<<(ostream& os, Person P)
{
	os<<P.get_first_name()<<" "<<P.get_last_name()<<" "<<P.get_age();
	return os;
};

istream& operator>> (istream& is, Person& P)
{
	string f, l;
	int a;
	is >> f >> l >> a;
	if (!is) return is;
	P = Person(f, l, a);
	return is;
}




int main()
{

	/*Person P1;
	P1.name="Goofy";
	P1.age=63;

	cout<<"Name: "<<P1.name<<", age: "<<P1.age<<endl;
	cout<<P1<<endl;

	Person P2;
	cout<<"Adj meg egy nevet, kort!"<<endl;
	cin>>P2;
	cout<<P2<<endl;*/

	vector <Person> vp;
	Person PP;

	int i=0;

	cout<<"Adjon meg egy nevet és egy kort: (Vezetéknév keresztnév kor) (Kilépés parancssal kiléphet)"<<endl;

	while(cin){
		cin>>PP;
		if(PP.get_first_name()=="Kilépés") break;
		vp.push_back(PP);
	}

	for(int i=0; i<vp.size(); i++){
		cout<<vp[i]<<endl;
	}


	return 0;
}