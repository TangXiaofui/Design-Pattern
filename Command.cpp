#include <iostream>
#include <vector>

using namespace std;


class cook
{
public:
	void MakeCheck(){
		cout << "MakeCheck" << endl;
	}
	void MakeDuck(){
		cout << "MakeDuck" << endl;
	}
};


class Command
{
public:
	Command(cook *c){
		m_cook = c;
	};
	~Command(){};
	virtual void Execute() = 0;
protected:
	cook *m_cook;
};

class MakeCheckCmd:public Command
{
public:
	MakeCheckCmd(cook* c):Command(c){};
	~MakeCheckCmd(){};
	void Execute(){
		m_cook->MakeCheck();
	}
};

class MakeDuckCmd:public Command
{
public:
	MakeDuckCmd(cook *c):Command(c){};
	~MakeDuckCmd(){};
	void Execute()
	{
		m_cook->MakeDuck();
	}
	
};

class Waiter
{
public:
	Waiter(){};
	~Waiter(){};
	void SetCmd(Command* cmd)
	{
		cmdList.push_back(cmd);
	}
	void Notify()
	{
		for(std::vector<Command*>::const_iterator it = cmdList.cbegin(); it != cmdList.cend() ; it++)
		{
			(*it)->Execute();
		}
	}
	std::vector<Command*> cmdList;
};


int main(int argc, char const *argv[])
{
	cook *c = new cook;
	MakeCheckCmd *cm = new MakeCheckCmd(c);
	MakeDuckCmd *dm = new MakeDuckCmd(c);
	Waiter *w = new Waiter();
	w->SetCmd(cm);
	w->SetCmd(dm);
	w->Notify();

	delete c;
	delete cm;
	delete dm;
	delete w;
	return 0;
}