#include <iostream>
#include <memory>
using namespace std;

class HummerModel
{
public:
	HummerModel(){};
	~HummerModel(){};
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void Alarm() = 0;
	virtual void EngineBoom() = 0;
	virtual bool isAlarm()
	{
		//钩子函数
		return true;
	}
	virtual void run()
	{
		start();
		EngineBoom();
		if (isAlarm())
		{
			Alarm();
		}
		stop();
	}
};


class HummerH1:public HummerModel
{
public:
	HummerH1(){};
	~HummerH1(){};
	void start()
	{
		cout <<"start H1"<< endl;
	}

	void EngineBoom()
	{
		cout <<"Hong Hong...." << endl;
	}

	void Alarm()
	{
		cout << "B~~~~~~~~~~~" << endl;
	}

	void stop()
	{
		cout << "stop H1" << endl;
	}

	bool isAlarm()
	{
		return AlarmFlag;
	}

	void SetAlarm(bool flag)
	{
         AlarmFlag = flag;
	}
private:
	bool AlarmFlag;
	
};


int main(int argc, char const *argv[])
{
	shared_ptr<HummerModel> tmp = make_shared<HummerH1>();
	tmp->run();

	cout << endl;
	shared_ptr<HummerH1> t1 = make_shared<HummerH1>();
	t1->SetAlarm(true);
	t1->run();
	return 0;
}
