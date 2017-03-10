#include <iostream>
using namespace std;

class OS
{
public:
	OS(){};
	~OS(){};
	virtual void run() = 0;
};


class Linux:public OS
{
public:
	Linux(){};
	~Linux(){};
	virtual void run()
	{
		cout << "Linux" << endl;
	}
};

class Windows:public OS
{
public:
	Windows(){};
	~Windows(){};
	virtual void run()
	{
		cout << "Windows" << endl;
	}
	
};


class Computer
{
public:
	Computer(){};
	~Computer(){};
	virtual void installOS(OS *os) = 0;
};

class IBM:public Computer
{
public:
	IBM(){};
	~IBM(){};
	virtual void installOS(OS *os)
	{
		cout << "IBM" << endl;
		os->run();
	}
};


int main(int argc, char const *argv[])
{
	OS *l = new Linux;
	Computer *c = new IBM;
	c->installOS(l);
	delete l;
	delete c;
	return 0;
}