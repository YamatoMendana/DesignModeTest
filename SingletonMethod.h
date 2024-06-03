#include <stdio.h>
#include <iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
	//���뽫��Ĺ��캯����Ϊ˽��
	Singleton() {}
	Singleton(const Singleton& other) {}
public:
	static Singleton* getInstance();
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

/*
//�̷߳ǰ�ȫ�汾
Singleton* Singleton::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new Singleton()��
	}
	return m_instance;
}
*/


//�̰߳�ȫ�汾�������Ĵ���̫�ߣ�m_instance��Ϊ�յ�ʱ�򣬶��ڶ��Ƕ�������ʱ��������˷�
Singleton* Singleton::getInstance() {
	mutex mtx; //����������ʱ���ͷ���
	mtx.lock();
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	mtx.unlock();
	return m_instance;
}


/*
//˫��������������ڴ��дreorder����ȫ
//���еı����������ܻ����reorder
Singleton* Singleton::getInstance() {
	if (m_instance == nullptr) { //��С��m_instance��Ϊ��ʱ���Ƕ�ȡ����ʱ��ļ�������
		Lock lock;
		if (m_instance == nullptr) { //���������߳�ͬʱ��m_instanceΪ��ʱ����
			//����˳��1. �����ڴ� 2.���ù����� 3.�ڴ��ַ����
			//���������reorder��1.�����ڴ� 2.�����ڴ��ַ��m_instance 3.���ù�������
			//���threadA�ڻ�û�е��ù�������ʱ��threadB�����ˣ�����m_instance��Ϊ�գ�ֱ�ӷ��ض��󣬴�ʱ��m_instance�ǲ����õģ�ֻ�Ƿ�����һ��ԭ���ڴ棬��û��ִ�й������������״̬���ԡ�double-check lock��ƭ��threadB��threadB�õ���ָ����ָ��Ķ���ֻ�ж����ַ����û��ִ�й������������˫��������ܳ��ֵ����⡣
			m_instance = new Singleton();
		}
	}
	return m_instance;
}
*/

/*
//C++ 11�汾֮��Ŀ�ƽ̨ʵ�� (volatile)
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
	Singleton* tmp = m_instance.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);//��ȡ�ڴ�fence
	if (tmp == nullptr) {
		std::lock_guard<std::mutex> lock(m_mutex);
		tmp = m_instance.load(std::memory_order_relaxed);
		if (tmp == nullptr) {
			tmp = new Singleton; //��֤��tmp�������reorder
			std::atomic_thread_fence(std::memory_order_release);//�ͷ��ڴ�fence
			m_instance.store(tmp, std::memory_order_relaxed);
		}
	}
	return tmp;
}
*/
