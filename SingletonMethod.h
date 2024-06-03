#include <stdio.h>
#include <iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
	//必须将类的构造函数设为私有
	Singleton() {}
	Singleton(const Singleton& other) {}
public:
	static Singleton* getInstance();
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

/*
//线程非安全版本
Singleton* Singleton::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new Singleton()；
	}
	return m_instance;
}
*/


//线程安全版本，但锁的代价太高：m_instance不为空的时候，对于都是读操作的时候加锁是浪费
Singleton* Singleton::getInstance() {
	mutex mtx; //函数结束的时候释放锁
	mtx.lock();
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	mtx.unlock();
	return m_instance;
}


/*
//双检查锁，但由于内存读写reorder不安全
//所有的编译器都可能会出现reorder
Singleton* Singleton::getInstance() {
	if (m_instance == nullptr) { //减小了m_instance不为空时都是读取操作时候的加锁代价
		Lock lock;
		if (m_instance == nullptr) { //避免两个线程同时在m_instance为空时进来
			//常见顺序：1. 分配内存 2.调用构造器 3.内存地址返回
			//如果编译器reorder：1.分配内存 2.返回内存地址给m_instance 3.调用构造器。
			//如果threadA在还没有调用构造器的时候，threadB进来了，发现m_instance不为空，直接返回对象，此时的m_instance是不可用的，只是分配了一个原生内存，并没有执行构造器，对象的状态不对。double-check lock欺骗了threadB，threadB拿到的指针所指向的对象只有对象地址，而没有执行构造器，这就是双检查锁可能出现的问题。
			m_instance = new Singleton();
		}
	}
	return m_instance;
}
*/

/*
//C++ 11版本之后的跨平台实现 (volatile)
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
	Singleton* tmp = m_instance.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
	if (tmp == nullptr) {
		std::lock_guard<std::mutex> lock(m_mutex);
		tmp = m_instance.load(std::memory_order_relaxed);
		if (tmp == nullptr) {
			tmp = new Singleton; //保证了tmp不会出现reorder
			std::atomic_thread_fence(std::memory_order_release);//释放内存fence
			m_instance.store(tmp, std::memory_order_relaxed);
		}
	}
	return tmp;
}
*/
