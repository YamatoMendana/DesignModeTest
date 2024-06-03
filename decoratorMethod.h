#include <stdio.h>
#include <iostream>


using namespace std;

//装饰模式

//业务操作
class Stream {
public:
	virtual void Read(int number) = 0;
	virtual void Seek(int position) = 0;
	virtual void Write(char data) = 0;

	virtual ~Stream() {}
};

//主体类
class FileStream : public Stream {
public:
	virtual void Read(int number) {
		//读文件流
		cout << "FileStream::Read" << endl;
	}
	virtual void Seek(int position) {
		//定位文件流
		cout << "FileStream::Seek" << endl;
	}
	virtual void Write(char data) {
		//写文件流
		cout << "FileStream::Write" << endl;
	}

};

class NetworkStream :public Stream {
public:
	virtual void Read(int number) {
		//读文件流
		cout << "NetworkStream::Read" << endl;
	}
	virtual void Seek(int position) {
		//定位文件流
		cout << "NetworkStream::Seek" << endl;
	}
	virtual void Write(char data) {
		//写文件流
		cout << "NetworkStream::Write" << endl;
	}

};

class MemoryStream :public Stream {
public:
	virtual void Read(int number) {
		//读文件流
		cout << "MemoryStream::Read" << endl;
	}
	virtual void Seek(int position) {
		//定位文件流
		cout << "MemoryStream::Seek" << endl;
	}
	virtual void Write(char data) {
		//写文件流
		cout << "MemoryStream::Write" << endl;
	}

};

//扩展操作
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

		//额外的加密操作...
		stream->Read(number);//读文件流
	}

	virtual void Seek(int position) {
		//额外的加密操作...
		stream->Seek(position);//定位文件流
		//额外的加密操作...
	}

	virtual void Write(char data) {
		//额外的加密操作...
		stream->Write(data);//写文件流
		//额外的加密操作...
	}
};


class BufferedStream : public DecoratorStream {
public:
	BufferedStream(Stream* stm) :DecoratorStream(stm) {

	}
	virtual void Read(int number) {

		//额外的加密操作...
		stream->Read(number);//读文件流
	}

	virtual void Seek(int position) {
		//额外的加密操作...
		stream->Seek(position);//定位文件流
		//额外的加密操作...
	}

	virtual void Write(char data) {
		//额外的加密操作...
		stream->Write(data);//写文件流
		//额外的加密操作...
	}
};

