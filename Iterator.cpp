#include <iostream>
#include <vector>
using namespace std;
#define COUNT 10
class Iterator
{
public:
	Iterator(){};
	~Iterator(){};
	virtual bool hasNext() = 0;
	virtual int next() = 0;
};

class AggregateAiter:public Iterator
{
public:
	AggregateAiter(std::vector<int> v)
	{
		m_position = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			vData.push_back(v.at(i));
		}
	};
	~AggregateAiter(){};
	bool hasNext()
	{
		if (m_position < vData.size())
		{
			return true;
		}
		else
			return false;
	}
	int next()
	{
		int data = vData[m_position];
		++m_position;
		return data;
	}
	std::vector<int> vData;
	int m_position;
};

class AggregateBiter:public Iterator
{
public:
	AggregateBiter(int *pdata){
		m_position = 0;
		for (int i = 0; i < COUNT; ++i)
		{
			m_data[i] = pdata[i];
		}
	};
	~AggregateBiter(){};
	bool hasNext()
	{
		if (m_position < COUNT)
		{
			return true;
		}
		else
			return false;
	};
	int next()
	{
		int data = m_data[m_position];
		++m_position;
		return data;
	};

	int m_position;
	int m_data[COUNT];
};

class AggregateA
{
public:
	AggregateA(){
		for (int i = 0; i < COUNT; ++i)
		{
			vData.push_back(i+1);
		}
	};
	~AggregateA(){};
	Iterator * createIterator()
	{
		return new AggregateAiter(vData);
	};
	std::vector<int> vData;
	
};

class AggregateB
{
public:
	AggregateB(){
		for (int i = 0; i < COUNT; ++i)
		{
			m_data[i] = COUNT + i;
		}
	};
	~AggregateB(){};
	Iterator* createIterator(){
		return new AggregateBiter(m_data);
	};
	 int m_data[COUNT];
};

class AggregateMag
{
public:
	AggregateMag(){};
	~AggregateMag(){};
	void PrintAll(){
		Iterator *itA =  mA.createIterator();
		Iterator *itB =  mB.createIterator();
		PrintAll(itA);
		PrintAll(itB);
		delete itA;
		delete itB;
	}
	void PrintAll(Iterator *it)
	{
		while(it->hasNext())
		{
			cout << it->next() << endl;
		}
	}
	AggregateA mA;
	AggregateB mB;
};

int main(int argc, char const *argv[])
{
	AggregateMag a;
	a.PrintAll();
	return 0;
}