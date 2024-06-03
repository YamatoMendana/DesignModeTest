#pragma once

#include <stdio.h>
#include <iostream>



class ISplitterPrototype {
public:
	virtual void split() = 0;
	virtual ISplitterPrototype* clone() = 0; //ͨ����¡�Լ�������ָ��
	virtual ~ISplitterPrototype() { }
};

//������
class BinarySplitterPrototype : public ISplitterPrototype
{
public:
	BinarySplitterPrototype() {
		i = 1;
	}
	virtual ISplitterPrototype* clone() {
		cout << "BinarySplitter::clone" << endl;
		return new BinarySplitterPrototype(*this); //��¡�Լ���ͨ����������
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
		return new TxtSplitterPrototype(*this); //��¡�Լ���ͨ����������
	}
	void split() {}
};

class PictureSplitterPrototype : public ISplitterPrototype
{
	virtual ISplitterPrototype* clone() {
		cout << "BinarySplitter::clone" << endl;
		return new PictureSplitterPrototype(*this); //��¡�Լ���ͨ����������
	}

	void split() {}
};

class VideoSplitterPrototype : public ISplitterPrototype
{
	virtual ISplitterPrototype* clone() {
		return new VideoSplitterPrototype(*this); //��¡�Լ���ͨ����������������¡
	}

	void split() {}
};

