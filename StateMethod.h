
/*
State状态模式

当状态增加的时候，NetworkProcesser中不必发生改变，达到了稳定
*/

class NetworkState {

public:
    NetworkState* pNext;
    virtual void Operation1() = 0;
    virtual void Operation2() = 0;
    virtual void Operation3() = 0;

    virtual ~NetworkState() {}
};


class OpenState :public NetworkState {

    static NetworkState* m_instance;
public:
    static NetworkState* getInstance() {
        if (m_instance == nullptr) {
            m_instance = new OpenState();
        }
        return m_instance;
    }

    void Operation1() {

        //**********
        pNext = CloseState::getInstance();
    }

    void Operation2() {

        //..........
        pNext = ConnectState::getInstance();
    }

    void Operation3() {

        //$$$$$$$$$$
        pNext = OpenState::getInstance();
    }
};

class CloseState :public NetworkState { };
//...
//扩展
class WaitState : public NetworkState { };

class NetworkProcessor {

    NetworkState* pState;

public:

    NetworkProcessor(NetworkState* pState) {

        this->pState = pState;
    }

    void Operation1() {
        //...
        pState->Operation1();
        pState = pState->pNext;
        //...
    }

    void Operation2() {
        //...
        pState->Operation2();
        pState = pState->pNext;
        //...
    }

    void Operation3() {
        //...
        pState->Operation3();
        pState = pState->pNext;
        //...
    }

};
