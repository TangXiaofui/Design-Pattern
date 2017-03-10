#include <iostream>
#include <string>
#include <memory>
using namespace std;


class LetterProcess
{
public:
	LetterProcess(){};
	~LetterProcess(){};
	virtual void WriteContent(string content) = 0;
	virtual void FillAddress(string address) = 0;
	virtual void LetterIntoEnvolop() = 0;
	virtual void SendLetter() = 0;
};

class LetterProcessImp:public LetterProcess
{
public:
	LetterProcessImp(){
		cout << "LetterProcessImp constration" << endl;
	};
	~LetterProcessImp(){
		cout << "LetterProcessImp destration" << endl;
	};

	void WriteContent(string content)
	{
		cout << "WriteContent" << " " << content <<endl;
	}

	void FillAddress(string address)
	{
		cout << "FillAddress " << address <<endl;
	}

	void LetterIntoEnvolop()
	{
		cout << "LetterIntoEnvolop" << endl;
	}

	void SendLetter()
	{
		cout << "SendLetter " << endl;
	}
};


class ModernPostoffice
{
public:
	ModernPostoffice(){
		this->pLetterProcess = make_shared<LetterProcessImp>();

	};
	~ModernPostoffice(){};

	void SendLetter(string content,string address)
	{
		pLetterProcess->WriteContent(content);
		pLetterProcess->FillAddress(address);
		pLetterProcess->LetterIntoEnvolop();
		pLetterProcess->SendLetter();
	}
private:
	shared_ptr<LetterProcess> pLetterProcess;

};


int main(int argc, char const *argv[])
{
	ModernPostoffice tmp;
	tmp.SendLetter("a","b");
	return 0;
}