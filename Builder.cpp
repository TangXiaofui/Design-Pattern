#include <iostream>
#include <vector>
using namespace std;

typedef enum HUMANTYPETag{
	FATMAN,
	THINMAN,
	NORMALMAN
}HUMANTYPE;

class man
{
public:
	man(){};
	~man(){};
	void setHead(HUMANTYPE t)
	{
		m_type = t;
	}
	void setBody(HUMANTYPE t)
	{
		m_type = t;
	}
	void ShowMan()
	{
		switch(m_type){
			case FATMAN:
				cout << "FATMAN" << endl;
			break;
			case THINMAN:
				cout << "THINMAN" << endl;
			break;
			case NORMALMAN:
				cout << "NORMALMAN" << endl;
			break;
			default:
			break;
		}
	}

	HUMANTYPE m_type;
};


class Builder
{
public:
	Builder(){};
	~Builder(){};
	virtual void BuilderHead()=0;
	virtual void BuilderBody()=0;
	virtual man *getMan()=0; 
};


class FatManBuilder :public Builder
{
public:
	FatManBuilder(){
		Fatman = new man();
	};
	~FatManBuilder(){};
	void BuilderHead()
	{
		Fatman->setHead(FATMAN);
	}
	void BuilderBody()
	{
		Fatman->setBody(FATMAN);
	}
	man* getMan()
	{
		return Fatman;
	}
	man *Fatman;
};

class Director
{
public:
	Director(Builder *builder){
		m_builder = builder;
	};
	~Director(){};
	void createMan()
	{
		m_builder->BuilderHead();
		m_builder->BuilderBody();
	}

	Builder *m_builder;
	
};


int main(int argc, char const *argv[])
{
	FatManBuilder *fm = new FatManBuilder;
	Director *boss = new Director(fm);
	boss->createMan();

	man *people = fm->getMan();
	people->ShowMan();


	delete boss;
	delete fm;
	return 0;
}


