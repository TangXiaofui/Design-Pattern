#include <iostream>
using namespace std;

//针对单例的操作需要加互斥锁
class Singleton
{
public:
	static Singleton &getInstance()
	{
		static Singleton instance;
		return instance;
	}
private:
	Singleton(){
		cout << "Singleton create" << endl;
	};
	~Singleton(){
		cout << "~Singleton" << endl;
	};
	Singleton(const Singleton &) = delete;
	Singleton& operator = (const Singleton&) = delete;
	
};

//#pragma once
// #include <iostream>
// using std::cout;
// using std::endl;
// using std::string;
// class CEmperor
// {
// public:
//     static CEmperor * GetInstance();
//     static void ReleaseInstance();
//     void EmperorInfo(void);
//     void SetEmperorTag(string tag);
// private:
//     CEmperor(void);
//     virtual ~CEmperor(void);
//     CEmperor(const CEmperor&);
//     CEmperor& operator=(const CEmperor&);
//     static CEmperor *m_pEmperor;
//     static HANDLE m_pMutex;
//     string m_EmperorTag;
//     class CGarbo
//     {
//     public:
//         CGarbo()
//         {
//             cout << "Create Garbo" << endl;
//         }
//         ~CGarbo()
//         {
//             cout << "Destroy Garbo" << endl;
//             if (NULL != m_pEmperor)
//             {
//                 WaitForSingleObject(m_pMutex, INFINITE);
//                 if (NULL != m_pEmperor)
//                 {
//                     cout << "Remove instance" << endl;
//                     delete m_pEmperor;
//                     m_pEmperor = NULL;
//                 }
//                 ReleaseMutex(m_pMutex);
//             }
//             if (NULL != m_pMutex)
//             {
//                 cout << "Delete mutex" << endl;
//                 CloseHandle(m_pMutex);
//                 m_pMutex = NULL;
//             }
//         }
//     };
//     static CGarbo m_Garbo;		//为了实现最后自动释放Emperor类
// };
//Emperor.cpp
// #include "StdAfx.h"
// #include "Emperor.h"
// #include <iostream>
// using std::cout;
// using std::endl;
// using std::string;
// CEmperor* CEmperor::m_pEmperor = NULL;
// HANDLE CEmperor::m_pMutex = CreateMutex(NULL, FALSE, NULL);
// CEmperor::CGarbo CEmperor::m_Garbo;
// CEmperor::CEmperor(void)
// {
//     cout << "Create CEmperor Instance" << endl;
// }
// CEmperor::~CEmperor(void)
// {
//     cout << "Destroy CEmperor Instance and release its resource" << endl;
// }
// void CEmperor::EmperorInfo(void)
// {
//     char msgBuffer[50] = { 0 };
//     sprintf_s(msgBuffer, 50, "皇ê帝?某3某3某3... ...(%s).", m_EmperorTag.c_str());
//     string msg(msgBuffer);
//     cout << msg.c_str() << endl;
// }
// CEmperor* CEmperor::GetInstance()
// {
//     if (NULL == m_pEmperor)
//     {
//         WaitForSingleObject(m_pMutex, INFINITE);
//         if (NULL == m_pEmperor)
//             m_pEmperor = new CEmperor();
//         ReleaseMutex(m_pMutex);
//     }
//     return m_pEmperor;
// }
// void CEmperor::ReleaseInstance()
// {
//     if (NULL != m_pEmperor)
//     {
//         WaitForSingleObject(m_pMutex, INFINITE);
//         if (NULL != m_pEmperor)
//         {
//             delete m_pEmperor;
//             m_pEmperor = NULL;
//         }
//         ReleaseMutex(m_pMutex);
//     }
// }
// void CEmperor::SetEmperorTag( string tag )
// {
//     m_EmperorTag = tag;
// }
// //Singleton.cpp
// #include "stdafx.h"
// #include "Emperor.h"
// void DoIt()

// {
//     CEmperor *pEmperor1 = CEmperor::GetInstance();
//     pEmperor1->SetEmperorTag("95");
//     pEmperor1->EmperorInfo();

//     CEmperor *pEmperor2 = CEmperor::GetInstance();
//     pEmperor2->EmperorInfo();

//     CEmperor *pEmperor3 = CEmperor::GetInstance();
//     pEmperor3->EmperorInfo();

//     CEmperor *pEmperor4 = pEmperor3;
//     pEmperor4->EmperorInfo();

//     CEmperor *pEmperor5 = NULL;
//     pEmperor5 = pEmperor4;
//     pEmperor5->EmperorInfo();

//     CEmperor::ReleaseInstance();

// }

// int _tmain(int argc, _TCHAR* argv[])

// {

//     DoIt();


//     _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
//     _CrtDumpMemoryLeaks();
//     return 0;
// }



int main(int argc, char const *argv[])
{
	Singleton &s = Singleton::getInstance(); 
	Singleton &s1 = Singleton::getInstance(); 
	cout << hex << &s << endl;
	cout << hex << &s1 << endl;
	return 0;
}