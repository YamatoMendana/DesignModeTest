#include <iostream>
#include <stdio.h>

using namespace std;

//��ģʽ
class MessagerImp {
public:
	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~MessagerImp() {}
};

class Messager {
protected:
    MessagerImp* messagerImp;//...
public:
    Messager(MessagerImp* mimp) : messagerImp(mimp) { }
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(const char* image) = 0;

    virtual ~Messager() {}
};




//ƽ̨ʵ�� n
class PCMessagerImp : public MessagerImp {
public:

    virtual void PlaySound() {
        //**********
    }
    virtual void DrawShape() {
        //**********
    }
    virtual void WriteText() {
        //**********
    }
    virtual void Connect() {
        //**********
    }
};

class MobileMessagerImp : public MessagerImp {
public:

    virtual void PlaySound() {
        //==========
    }
    virtual void DrawShape() {
        //==========
    }
    virtual void WriteText() {
        //==========
    }
    virtual void Connect() {
        //==========
    }
};

//ҵ����� m
//�����Ŀ��1+n+m
class MessagerLite : public Messager {
public:
    MessagerLite(MessagerImp* mimp) : Messager(mimp) {

    }
    virtual void Login(string username, string password) {

        messagerImp->Connect(); //messagerImpl�ֶ��ڸ�����������
        //........
        cout << "MessagerLite:Login" << endl;
    }
    virtual void SendMessage(string message) {

        messagerImp->WriteText();
        cout << "MessagerLite:Login" << endl;
        //........
    }
    virtual void SendPicture(const char* image) {

        messagerImp->DrawShape();
        //........
        cout << "MessagerLite:Login" << endl;
    }
};


class MessagerPerfect :public Messager {
public:
    MessagerPerfect(MessagerImp* mimp) : Messager(mimp) {

    }
    virtual void Login(string username, string password) {

        messagerImp->PlaySound();
        //********
        messagerImp->Connect();
        //........
        cout << "MessagerPerfect:Login" << endl;
    }
    virtual void SendMessage(string message) {

        messagerImp->PlaySound();
        //********
        messagerImp->WriteText();
        //........
        cout << "MessagerPerfect:SendMessage" << endl;
    }
    virtual void SendPicture(const char* imageName) {

        messagerImp->PlaySound();
        //********
        messagerImp->DrawShape();
        //........
        cout << "MessagerPerfect:SendPicture" << endl;
    }
};


