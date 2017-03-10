#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;


class Observer
{
public:
	Observer(){};
	virtual ~Observer(){};
	virtual void update(){};
};

class Blog
{
public:
	Blog(){};
	~Blog(){};
	virtual void Attach(Observer *obser)
	{
		m_observerlist.push_back(obser);
	}
	virtual void remove(Observer *obser)
	{
		m_observerlist.remove(obser);
	}
	virtual void setStatus(string s)
	{
		m_status = s;
	}
	virtual string getStatus()
	{
		return m_status;
	}
	void Notify()
	{
		list<Observer*>::iterator iter;
		for(iter = m_observerlist.begin();iter != m_observerlist.end() ; iter++)
		{
			(*iter)->update();
		}
	}

	std::list<Observer*> m_observerlist;
	string m_status;
	
};


class CSDNBlog:public Blog
{
public:
	CSDNBlog(string name):m_name(name){ };
	~CSDNBlog(){};
	void setStatus()
	{
		Blog::m_status = m_name+":"+Blog::m_status;
	}
	string getStatus()
	{
		return Blog::m_status;
	}
	string m_name;
};


class ObserverBlog:public Observer
{
public:
	ObserverBlog(string name,Blog *blog):m_name(name),m_blog(blog){};
	~ObserverBlog(){};
	void update()
	{
		cout <<"Notify " <<m_name << " to read " << m_blog->getStatus() << endl;
	}

	string m_name;
	Blog *m_blog;
};



int main(int argc, char const *argv[])
{
	Blog *pb = new CSDNBlog("txh");
	Observer *po = new ObserverBlog("user1",pb);

	pb->Attach(po);

	pb->setStatus("Design Model");
	pb->Notify();

	delete pb;
	delete po;
	return 0;
}