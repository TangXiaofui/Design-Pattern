#include <iostream>
using namespace std;

//锦囊
class content
{
public:
	content(){};
	~content(){};
	virtual void Operate()=0;
};

//妙计
class func1:public content
{
public:
	func1(){};
	~func1(){};
	void Operate(){
		cout << "func1" << endl;
	}
};


class func2:public content
{
public:
	func2(){};
	~func2(){};
	void Operate()
	{
		cout << "func2" << endl;
	}
};

//英雄
class Hero
{
public:
	Hero(content *c){
		mContent = c;
	};
	~Hero(){
		cout << "delete" << endl;
		delete mContent;
	};
	void Operate()
	{
		this->mContent->Operate();
	}
	content *mContent;
};

int main(int argc, char const *argv[])
{
	Hero *t = new Hero(new func1());
	t->Operate();

	delete t;

	t = new Hero(new func2);
	t->Operate();
	delete t;



	return 0;
}