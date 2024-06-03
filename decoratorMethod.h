#include <stdio.h>
#include <iostream>


using namespace std;

//װ��ģʽ

//ҵ�����
class Stream {
public:
	virtual void Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream() {}
};

//������
class FileStream : public Stream {
public:
	virtual void Read(int number) {
		//���ļ���
		cout << "FileStream::Read" << endl;
	}
	virtual void Seek(int position) {
		//��λ�ļ���
		cout << "FileStream::Seek" << endl;
	}
	virtual void Write(char data) {
		//д�ļ���
		cout << "FileStream::Write" << endl;
	}

};

class NetworkStream :public Stream {
public:
	virtual void Read(int number) {
		//���ļ���
		cout << "NetworkStream::Read" << endl;
	}
	virtual void Seek(int position) {
		//��λ�ļ���
		cout << "NetworkStream::Seek" << endl;
	}
	virtual void Write(char data) {
		//д�ļ���
		cout << "NetworkStream::Write" << endl;
	}

};

class MemoryStream :public Stream {
public:
	virtual void Read(int number) {
		//���ļ���
		cout << "MemoryStream::Read" << endl;
	}
	virtual void Seek(int position) {
		//��λ�ļ���
		cout << "MemoryStream::Seek" << endl;
	}
	virtual void Write(char data) {
		//д�ļ���
		cout << "MemoryStream::Write" << endl;
	}

};

//��չ����
class DecoratorStream : public Stream {
protected:
	Stream* stream;//...

	DecoratorStream(Stream* stm) : stream(stm) {

	}
};

class CryptoStream : public DecoratorStream {
public:
	CryptoStream(Stream* stm) : DecoratorStream(stm) {

	}

	virtual void Read(int number) {

		//����ļ��ܲ���...
		stream->Read(number);//���ļ���
	}

	virtual void Seek(int position) {
		//����ļ��ܲ���...
		stream->Seek(position);//��λ�ļ���
		//����ļ��ܲ���...
	}

	virtual void Write(char data) {
		//����ļ��ܲ���...
		stream->Write(data);//д�ļ���
		//����ļ��ܲ���...
	}
};


class BufferedStream : public DecoratorStream {
public:
	BufferedStream(Stream* stm) :DecoratorStream(stm) {

	}
	virtual void Read(int number) {

		//����ļ��ܲ���...
		stream->Read(number);//���ļ���
	}

	virtual void Seek(int position) {
		//����ļ��ܲ���...
		stream->Seek(position);//��λ�ļ���
		//����ļ��ܲ���...
	}

	virtual void Write(char data) {
		//����ļ��ܲ���...
		stream->Write(data);//д�ļ���
		//����ļ��ܲ���...
	}
};

