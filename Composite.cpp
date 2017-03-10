#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Company
{
public:
	Company(string name):m_name(name){};
	~Company(){};
	virtual void Add(Company *){};
	virtual void Show(int ) = 0;
	string m_name;
};

class ConcreteCompany:public Company
{
public:
	ConcreteCompany(string name):Company(name){};
	~ConcreteCompany(){};
	void Add(Company *com)
	{
		m_comlist.push_back(com);
	}
	void Show(int depth)
	{
		for (int i = 0; i < depth; ++i)
		{
			cout << "-";
		}
		cout << Company::m_name << endl;
		std::vector<Company*>::iterator iter;
		for (iter = m_comlist.begin();iter != m_comlist.end();iter++)
		{
			(*iter)->Show(depth+2);
		}
	}
	std::vector<Company*> m_comlist;
};


class FinanceDepartment:public Company
{
public:
	FinanceDepartment(string name):Company(name){};
	~FinanceDepartment(){};
	void Show(int depth)
	{
		for (int i = 0; i < depth; ++i)
		{
			cout << "-";
		}
		cout << Company::m_name << endl;
	}
};

class HumanResourceDepartment:public Company
{
public:
	HumanResourceDepartment(string name):Company(name){};
	~HumanResourceDepartment(){};
	void Show(int depth)
	{
		for (int i = 0; i < depth; ++i)
		{
			cout << "-";
		}
		cout << Company::m_name << endl;
	}
};


class test
{
public:
	test(){};
	~test(){
		cout << "~test" <<endl;
	};
	
};


int main(int argc, char const *argv[])
{
	//使用智能指针
	Company *proot = new ConcreteCompany("TXH Corp");
	Company *pleft1 = new HumanResourceDepartment("HumanResourceDepartment");
	Company *pleft2 = new FinanceDepartment("FinanceDepartment");
	proot->Add(pleft1);
	proot->Add(pleft2);

	Company *pSubroot = new ConcreteCompany("TXH Sub Corp");
	Company *pSleft1 = new HumanResourceDepartment("HumanResourceDepartment");
	Company *pSleft2 = new FinanceDepartment("FinanceDepartment");
	pSubroot->Add(pSleft1);
	pSubroot->Add(pSleft2);
	proot->Add(pSubroot);
	proot->Show(0);


	// test *t  =  new test();
	// std::vector<test*> v;
	// v.push_back(t);
	// delete t;

	delete proot;
	delete pleft1;
	delete pleft2;
	delete pSubroot;
	delete pSleft1;
	delete pSleft2;
	return 0;
}