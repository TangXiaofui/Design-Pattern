#include <iostream>
using namespace std;


class ProductionInterface
{
public:
	ProductionInterface(){};
	virtual ~ProductionInterface(){};
	virtual void GetVersion() = 0;
};

class Robot:public ProductionInterface
{
public:
	Robot(){};
	~Robot(){
		cout << "delete Robot" << endl;
	};
	void GetVersion()
	{
		cout << "This is a Robot" << endl;
	}
};

class FactoryInterface
{
public:
	FactoryInterface(){};
	virtual ~FactoryInterface(){};
	virtual ProductionInterface* createProduction() = 0;
};

class Factory_1:public FactoryInterface
{
public:
	Factory_1(){};
	~Factory_1(){
		cout <<" delete Factory_1" << endl;
	};
	ProductionInterface* createProduction()
	{
		cout << "creata robot" << endl;
		return new Robot();
	}
	
};



int main(int argc, char const *argv[])
{
	FactoryInterface *factory = new Factory_1();
	ProductionInterface *production = factory->createProduction();
	production->GetVersion();
	delete factory;
	delete production;
	return 0;
}