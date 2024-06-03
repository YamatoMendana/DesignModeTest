#include <stdio.h>
#include <string>
#include <list>
#include <iostream>

using namespace std;

//观察者模式
class IProgress {
public:
	virtual void DoProgress(float val) = 0;
	virtual ~IProgress() {}
};


class FileSplitter {
	
private:
	string m_filePath;
	int m_fileNum;
	list<IProgress*> m_iprogressList;

public:
	FileSplitter(const string& filename, int filenum)
	{
		m_filePath = filename;
		m_fileNum = filenum;
	}
	
	void split() {
		for (int i = 0; i < m_fileNum; i++)
		{
			float progressValue = m_fileNum;
			progressValue = (i + 1) / progressValue;
			onProgress(progressValue);

		}
	}

	void addProgress(IProgress* ipgress) {
		m_iprogressList.push_back(ipgress);
	}

	void removeProgress(IProgress* ipgress) {
		m_iprogressList.remove(ipgress);
	}

protected:
	virtual void onProgress(float val)
	{
		printf("now list count: %d\n", (int)m_iprogressList.size());
		list<IProgress*>::iterator itor = m_iprogressList.begin();
		
		while (itor != m_iprogressList.end())
		{
			(*itor)->DoProgress(val);
			itor++;
		}
	}
};

class ConsoleNotifier :public IProgress
{
public:
	virtual void DoProgress(float val)
	{
		cout << "ConsoleNotifier:\n\t";
	}
};

class Consumer:public IProgress{
private:
	IProgress* progressBar;
public:
	void run()
	{
		string filePath = "hello world";
		int number = 4;

		ConsoleNotifier cn;

		FileSplitter splitter(filePath, number);

		splitter.addProgress(&cn);//订阅
		splitter.addProgress(this);//订阅
		

		splitter.split();

		splitter.removeProgress(this);

	}

	virtual void  DoProgress(float val)
	{
		printf("run show : % f\n", val);
	}

};