#include <iostream>
#include <string>
using namespace std;


class Manager
{
public:
	Manager(Manager *manager,string name):m_manager(manager),m_name(name){};
	virtual ~Manager(){};
	virtual void RequestToDeal(string name,int Salary) = 0;
	Manager *m_manager;
	string m_name;
};

class CommonManager:public Manager
{
public:
	CommonManager(Manager *manager,string name):Manager(manager,name){};
	~CommonManager(){};
	void RequestToDeal(string name,int Salary)
	{
		if (Salary < 500)
		{
			cout << m_name << " allow " << name << " pay raise" << endl;
 		}
 		else
 		{
 			m_manager->RequestToDeal(name,Salary);
 		}
	}
};

class Majordomo:public Manager
{
public:
	Majordomo(Manager *manager,string name):Manager(manager,name){};
	~Majordomo(){};
	void RequestToDeal(string name ,int Salary)
	{
		if (Salary < 1000)
		{
			cout << m_name << " allow " << name << " pay raise" << endl;
		}
		else
		{
			m_manager->RequestToDeal(name,Salary);
		}
	}
	
};

class GeneralManager:public Manager
{
public:
	GeneralManager(Manager *manager,string name):Manager(manager,name){};
	~GeneralManager(){};
	void RequestToDeal(string name,int Salary)
	{
		if (Salary < 2000)
		{
			cout << m_name << " allow " << name << " pay raise" << endl;
		}
		else
			cout << m_name << " disallow " << name << " pay raise" << endl;
	}
};


int main(int argc, char const *argv[])
{
	Manager *pgm = new GeneralManager(NULL,"A");
	Manager *pmm = new Majordomo(pgm,"B");
	Manager *pcm = new CommonManager(pmm,"C");
	pcm->RequestToDeal("D",400);
	pcm->RequestToDeal("E",900);
	pcm->RequestToDeal("F",3000);

	delete pgm;
	delete pmm;
	delete pcm;
	return 0;
}