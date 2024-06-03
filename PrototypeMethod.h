#pragma once

#include <stdio.h>
#include <iostream>



class ISplitterPrototype {
public:
	virtual void split() = 0;
	virtual ISplitterPrototype* clone() = 0; //通过克隆自己来创建指针
	virtual ~ISplitterPrototype() { }
};

//具体类
class BinarySplitterPrototype : public ISplitterPrototype
{
public:
	BinarySplitterPrototype() {
		i = 1;
	}
	virtual ISplitterPrototype* clone() {
		cout << "BinarySplitter::clone" << endl;
		return new BinarySplitterPrototype(*this); //克隆自己，通过拷贝构造
	}
	void split() {
		printf("i = %x\n", &i);
	}

private:
	int i;
};

class TxtSplitterPrototype : public ISplitterPrototype
{
	virtual ISplitterPrototype* clone() {
		cout << "BinarySplitter::clone" << endl;
		return new TxtSplitterPrototype(*this); //克隆自己，通过拷贝构造
	}
	void split() {}
};

class PictureSplitterPrototype : public ISplitterPrototype
{
	virtual ISplitterPrototype* clone() {
		cout << "BinarySplitter::clone" << endl;
		return new PictureSplitterPrototype(*this); //克隆自己，通过拷贝构造
	}

	void split() {}
};

class VideoSplitterPrototype : public ISplitterPrototype
{
	virtual ISplitterPrototype* clone() {
		return new VideoSplitterPrototype(*this); //克隆自己，通过拷贝构造进行深克隆
	}

	void split() {}
};

