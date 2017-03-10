#include <iostream>
#include <memory>
using namespace std;


class Target
{
public:
	Target(){};
	~Target(){};
	virtual void JulySeven()
	{
		cout << "chinese festival" << endl;
	}
};

class Adaptee
{
public:
	Adaptee(){};
	~Adaptee(){};
	virtual void MarchFourteen()
	{
		cout << "America festival" << endl;
	}
};


//适配器类
class Adapter:public Target,public Adaptee
{
public:
	Adapter(){};
	~Adapter(){
		cout << "~Adapter" << endl;
	};
	void JulySeven()
	{
		cout << "Adapter" << endl;
		MarchFourteen();
	}
};

//适配器对象
class Adapter1:public Target
{
public:
	Adapter1(){};
	~Adapter1(){
		cout << "~Adapter1" << endl;
	};
	void JulySeven()
	{
		cout << "Adapter1" << endl;
		adaptee.MarchFourteen();
	}
private:
	Adaptee adaptee; 
};


int main(int argc, char const *argv[])
{
	shared_ptr<Target> tmp = make_shared<Adapter>();
	tmp->JulySeven();

	tmp=make_shared<Adapter1>();
	tmp->JulySeven();
	return 0;
}