#include <iostream>
#include <string>
using namespace std;


class Resume
{
public:
	string m_content;
	//Resume(){};							//!!!!!!!!!!!!!
	Resume(string content):m_content(content){};
	virtual ~Resume(){};
	virtual void setContent(){};
	virtual Resume* clone() = 0;
	virtual void show()
	{
		cout << m_content << endl;
	}
};

class ResumeA:public Resume
{
public:
	ResumeA(string content):Resume(content){};
	ResumeA(const ResumeA &r):Resume(m_content)				//!!!!!!!!!!!!!!!!!!!
	{
		 m_content = r.m_content;
	}
	~ResumeA(){};
	ResumeA* clone()
	{
		return new ResumeA(*this);
	}
};


class A
{
public:
	A(int i ){};
	~A(){};
};

class B:public A
{
public:
	B():A(3){};
	B(const B &t):A(3){};
	~B(){};
	
};


int main(int argc, char const *argv[])
{
	ResumeA r("this is Prototype");
	r.show();
	ResumeA *r1 = r.clone();
	r1->show();
	delete r1;
	// B b;
	return 0;
}