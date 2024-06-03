#include <stdio.h>
#include <iostream>


/*
* ������ģʽ
Director -> HouseDirector (�ȶ�)
Builder -> HouseBuilder (�ȶ�)
ConcreteBuilder -> StoneHouseBuilder ���仯��
*/

/*
ͨ��HouseDirector ����ȡѡ���췽ʽStoneHouseBuilder����.....
Ȼ���ڹ���Ĺ����е���house������������ݣ����������Ϸ���houseָ��
*/

//����ı�ʾ
class House {
	//...
};

class StoneHouse : public House {


};

//����Ĺ���
class HouseBuilder {
public:
	House* GetResult() {
		return pHouse;
	}

	virtual ~HouseBuilder() { }
public:
	House* pHouse;
	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual void BuildPart3() = 0;
	virtual void BuildPart4() = 0;
	virtual void BuildPart5() = 0;
};


class StoneHouseBuilder : public HouseBuilder {
public:
	virtual void BuildPart1() {
		//pHouse->Part1 = ...;
		cout << "StoneHouseBuilder::BuildPart1" << endl;
	}
	virtual void BuildPart2() {}
	virtual void BuildPart3() {}
	virtual void BuildPart4() {}
	virtual void BuildPart5() {}
};

class HouseDirector {
public:
	HouseBuilder* pHouseBuilder;

	HouseDirector(HouseBuilder* pHouseBuilder) {
		this->pHouseBuilder = pHouseBuilder;
	}

	House* Construct() {
		pHouseBuilder->BuildPart1();

		for (int i = 0; i < 4; i++) {
			pHouseBuilder->BuildPart2();
		}

		pHouseBuilder->BuildPart3();

		pHouseBuilder->BuildPart4(); 

		pHouseBuilder->BuildPart5();

		return pHouseBuilder->GetResult();
	}
};



