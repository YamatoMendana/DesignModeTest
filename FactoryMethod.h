#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

/*����ģʽ
Product -> ISplitter (�ȶ�)
ConcreteProduct -> XXSplitter ���ȶ���
Creator -> SplitterFactory ���仯��
ConcreteCreator -> XXSplitterFactory ���仯��
*/
class ISplitter {
public:
	virtual void split() = 0;
	virtual ~ISplitter() { }
};


//SplitterFactory.cpp
class SplitterFactory {
public:
	virtual ISplitter* createSplitter() = 0;
	virtual ~SplitterFactory() { }
};



//FileSplitter2.cpp
//������
class BinarySplitter : public ISplitter
{
	virtual void split() {
		//...
		cout << "BinarySplitter::split" << endl;
	}
};

class TxtSplitter : public ISplitter
{
	virtual void split() {
		//...
	}
};

class PictureSplitter : public ISplitter
{
	virtual void split() {
		//...
	}
};

class VideoSplitter : public ISplitter
{
	virtual void split() {
		//...
	}
};

//���幤��
class BinarySplitterFactory : public SplitterFactory {
public:
	virtual ISplitter* createSplitter() {
		return new BinarySplitter();
	}
};

class TxtSplitterFactory : public SplitterFactory {
public:
	virtual ISplitter* createSplitter() {
		return new TxtSplitter();
	}
};

class PictureSplitterFactory : public SplitterFactory {
public:
	virtual ISplitter* createSplitter() {
		return new PictureSplitter();
	}
};

class VideoSplitterFactory : public SplitterFactory {
public:
	virtual ISplitter* createSplitter() {
		return new VideoSplitter();
	}
};

class FactoryRun
{
	SplitterFactory* factory; //����
public:
	FactoryRun(SplitterFactory* factory) {
		this->factory = factory;
	}

	void run() {
		ISplitter* splitter = factory->createSplitter();  //��̬new
		splitter->split();
	}
};

