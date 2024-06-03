#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

/*工厂模式
Product -> ISplitter (稳定)
ConcreteProduct -> XXSplitter （稳定）
Creator -> SplitterFactory （变化）
ConcreteCreator -> XXSplitterFactory （变化）
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
//具体类
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

//具体工厂
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
	SplitterFactory* factory; //工厂
public:
	FactoryRun(SplitterFactory* factory) {
		this->factory = factory;
	}

	void run() {
		ISplitter* splitter = factory->createSplitter();  //多态new
		splitter->split();
	}
};

