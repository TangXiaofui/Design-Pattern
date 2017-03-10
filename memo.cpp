#include <iostream>
#include <vector>
using namespace std;

class CMemo
{
public:
	int blood;
	int magic;
	CMemo(int b,int m):blood(b),magic(m){};
	~CMemo(){};
	CMemo& operator =(const CMemo &m)
	{
		blood = m.blood;
		magic = m.magic;
	}
};


class CGamePlayer
{
public:
	CMemo memo;
	CGamePlayer(int b,int m):memo(b,m){};
	CMemo save()
	{
		return memo;
	}
	CMemo load(CMemo m)
	{
		memo = m;
	}
	void hurt()
	{
		memo.blood -= 10;
	}
	void Show()
	{
		cout << "blood " << memo.blood << " " << "magic " << memo.magic << endl; 
	}
	~CGamePlayer(){};
};

class CareTaker
{
public:
	CareTaker(){};
	~CareTaker(){};
	void Save(CMemo m)
	{
		m_vMemo.push_back(m);
	}
	CMemo Load(int index)
	{
		return m_vMemo[index];
	}
	std::vector<CMemo> m_vMemo;	
};


int main(int argc, char const *argv[])
{
	CareTaker ct;
	CGamePlayer gp(100,100);
	gp.Show();

	ct.Save(gp.save());
	gp.hurt();
	gp.Show();

	gp.load(ct.Load(0));
	gp.Show();
	return 0;
}