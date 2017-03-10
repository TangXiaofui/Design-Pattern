#include <iostream>
using namespace std;

class War;

class State
{
public:
	State(){};
	virtual ~State(){
		cout << "~~~~" << endl;
	};
	virtual void begin(){};
	virtual void mid(){};
	virtual void end(){};
	virtual void current(War *){};
};

class War
{
public:
	State *m_state;
	int m_day;
	War(State *state,int day = 0):m_state(state),m_day(day){};
	~War(){
		delete m_state;					//!!!!!!!!!!!
	};
	int getDay()
	{
		return m_day;
	}
	void setDay(int day)
	{
		m_day = day;
	}
	void setState(State *state)
	{
		delete m_state;
		m_state = state;
	}
	void getState()
	{
		m_state->current(this);
	}
};


class CendState:public State
{
public:
	CendState(){};
	~CendState(){};
	void current(War *war){
		end(war);
	};
	void end(War* war)
	{
		cout << "War End" << endl;
	}
};


class CMidState:public State
{
public:
	CMidState(){};
	~CMidState(){};
	void current(War *war)
	{
		mid(war);
	}
	void mid(War *war)
	{
		if (war->getDay() < 20)
		{
			cout << war->getDay() << " mid " << endl;
		}
		else
		{
			war->setState(new CendState());
			war->getState();
		}
	}
	
};

class CbeginState:public State
{
public:
	CbeginState(){};
	~CbeginState(){};
	void current(War *war){
		begin(war);
	};
	void begin(War *war)
	{
		if (war->getDay() < 10)
		{
			cout << war->getDay() << " begin " << endl;
		}
		else
		{
			war->setState(new CMidState());
			war->getState();
		}
	}
};


int main(int argc, char const *argv[])
{
	State *s = new CbeginState();
	War *w = new War(s);
	for (int i = 0; i < 21; ++i)
	{
		w->setDay(i);
		w->getState();
	}
	delete w;

	return 0;
}