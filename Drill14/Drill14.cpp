# include <iostream>

using namespace std;


class B1{ 
public:
 	virtual void vf(){cout<<"B1::vf()"<<endl;}; //virtual
 	void f(){cout<<"B1::f()"<<endl;}; //non-virtual
 	virtual void pvf() =0; //emiatt B1 absztarkt
};

class D1 : public B1{
public:
	void vf(){cout<<"D1::vf()"<<endl;}; //virtual override
	void f(){cout<<"D1::f()"<<endl;}; //non-virtual "override"
	void pvf(){cout<<"D1::pvf()"<<endl;};
};

class D2 : public D1{
public:
		void pvf(){cout<<"D2::pvf()"<<endl;};
};

class B2{
public:
	virtual void pvf() =0;

};

class D21 : public B2{
public:
	string s="Ezt kell kiírni";
	void pvf(){cout<<s<<endl;};
};


class D22 : public B2{
public:
	int s=69;
	void pvf(){cout<<s<<endl;};
};

void f(B2& b2){
	b2.pvf();
}



int main(){
	/*B1 b; //b object

	b.vf();
	b.f();
	b.pvf();*/

	D1 d; //d object

	d.vf();
	d.f();
	d.pvf();

	B1& bref=d; //B1-re referencia
	
	bref.vf();
	bref.f();
	bref.pvf();

	D2 d2; //D2 object

	d2.vf();
	d2.f();
	d2.pvf();

	D21 d21;//D21 object
	d21.pvf();

	D22 d22;//D22 object
	d22.pvf();

	f(d21); //f hívása
	f(d22);

return 0;
}