#include <iostream>
using namespace std;

class GameProxyInterface
{
public:
	GameProxyInterface(){};
	virtual ~GameProxyInterface(){};
	virtual void KillBoss()=0;
	virtual void UpGrade() = 0;
};


class GamePlayer1:public GameProxyInterface
{
public:
	GamePlayer1(){};
	~GamePlayer1(){};
	void KillBoss()
	{
		cout << "GamePlayer1 KillBoss" << endl;
	}
	void UpGrade()
	{
		cout << "GamePlayer1 UpGrade" << endl;
	}
};

class GamePlayer2:public GameProxyInterface
{
public:
	GamePlayer2(){};
	~GamePlayer2(){};
	void KillBoss()
	{
		cout << "GamePlayer2 KillBoss" << endl;	
	}
	void UpGrade()
	{
		cout << "GamePlayer2 UpGrade" << endl;
	}
};

class GameProxy:public GameProxyInterface
{
public:
	GameProxy(GameProxyInterface *proxy){
		this->mProxy = proxy;
	};
	~GameProxy(){
		delete this->mProxy;
	};
	void KillBoss()
	{
		mProxy->KillBoss();
	}
	void UpGrade()
	{
		mProxy->UpGrade();
	}

	GameProxyInterface *mProxy;
	
};

int main(int argc, char const *argv[])
{
	GameProxy *proxy = new GameProxy(new GamePlayer1());
	proxy->KillBoss();
	proxy->UpGrade();
	delete proxy;

	proxy = new GameProxy(new GamePlayer2());
	proxy->KillBoss();
	proxy->UpGrade();
	delete proxy;
	return 0;
}