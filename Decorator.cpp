#include <iostream>
#include <string>
using namespace std;


class Phone
{
public:
	Phone(){};
	~Phone(){};
	virtual void showDecorator() = 0;
};

class iPhone:public Phone
{
public:
	string m_pname;
	iPhone(string str):m_pname(str){};
	~iPhone();
	void showDecorator()
	{
		cout << m_pname << endl;
	}
};

class DecoratorPhone:public Phone
{
public:
	Phone *mp;
	DecoratorPhone(Phone *p):mp(p){};
	~DecoratorPhone(){};
	void showDecorator()
	{
		mp->showDecorator();
	}
};

class DecoratorPhoneA:public DecoratorPhone
{
public:
	DecoratorPhoneA(Phone *p):DecoratorPhone(p){};
	~DecoratorPhoneA(){};
	void showDecorator()
	{
		DecoratorPhone::showDecorator();
		addDecorator();
	}
	void addDecorator()
	{
		cout << "add flower" << endl;
	}
};

class DecoratorPhoneB:public DecoratorPhone
{
public:
	DecoratorPhoneB(Phone *p):DecoratorPhone(p){};
	~DecoratorPhoneB(){};
	void showDecorator()
	{
		DecoratorPhone::showDecorator();
		addDecorator();
	}
	void addDecorator()
	{
		cout << "add some" << endl;
	}
};

int main(int argc, char const *argv[])
{
	Phone *p = new iPhone(string("iPhone"));
	DecoratorPhoneA *pa = new DecoratorPhoneA(p);
	DecoratorPhoneB *pb = new DecoratorPhoneB(pa);
	pb->showDecorator();

	delete p;
	delete pa;
	delete pb;
	return 0;
}