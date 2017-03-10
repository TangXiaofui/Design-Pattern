#include <iostream>
#include <memory>

using namespace std;


class CLinux
{
public:
	CLinux(){};
	~CLinux(){
		cout << "~CLinux" << endl;
	};
	virtual void product() = 0;
};

class ClinuxMobile:public CLinux
{
public:
	ClinuxMobile(){};
	~ClinuxMobile(){
		cout << "~ClinuxMobile" << endl;
	};
	void product()
	{
		cout << "product linuxMobile" << endl;
	}
};

class ClinuxPC:public CLinux
{
public:
	ClinuxPC(){};
	~ClinuxPC(){};
	void product()
	{
		cout << "product linuxPC" << endl;
	}
};

class CWindows
{
public:
	CWindows(){};
	~CWindows(){
		cout << "~CWindows" << endl;
	};
	virtual void product() = 0;
};


class CWindowsMobile:public CWindows
{
public:
	CWindowsMobile(){};
	~CWindowsMobile(){
		cout << "~CWindowsMobile" << endl;
	};
	void product()
	{
		cout << "product CWindowsMobile" << endl;
	}
};

class CWindowsPC:public CWindows
{
public:
	CWindowsPC(){};
	~CWindowsPC(){};
	void product()
	{
		cout << "product CWindowsPC" << endl;
	}
};

class AbstrateFactory
{
public:
	AbstrateFactory(){};
	~AbstrateFactory(){
		cout << "~AbstrateFactory" << endl;
	};
	virtual shared_ptr<CLinux> createLinux() = 0;
	virtual shared_ptr<CWindows> createWindows() = 0;
};

class MobileFactory:public AbstrateFactory
{
public:
	MobileFactory(){};
	~MobileFactory(){
		cout << "~MobileFactory" << endl;
	};
	shared_ptr<CLinux> createLinux()
	{
		return make_shared<ClinuxMobile>();
	}
	shared_ptr<CWindows> createWindows()
	{
		return make_shared<CWindowsMobile>();
	}
};

class PCFactory:public AbstrateFactory
{
public:
	PCFactory(){};
	~PCFactory(){
		cout << "~PCFactory" << endl;
	};
	shared_ptr<CLinux> createLinux()
	{
		return make_shared<ClinuxPC>();
	}
	shared_ptr<CWindows> createWindows()
	{
		return make_shared<CWindowsPC>();
	}
	
};


void test(shared_ptr<AbstrateFactory> tmp)
{
	shared_ptr<CLinux> t1 = tmp->createLinux();
	shared_ptr<CWindows> t2 = tmp->createWindows();
	t1->product();
	t2->product();
}

int main(int argc, char const *argv[])
{
	test(make_shared<MobileFactory>());
	
	test(make_shared<PCFactory>());
	return 0;
}