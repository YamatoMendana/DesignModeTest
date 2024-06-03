#include <stdio.h>
#include <iostream>


/*
* 构造器模式
Director -> HouseDirector (稳定)
Builder -> HouseBuilder (稳定)
ConcreteBuilder -> StoneHouseBuilder （变化）
*/

/*
通过HouseDirector 来获取选择建造方式StoneHouseBuilder或者.....
然后在构造的过称中调用house（添加属性数据），最后构造完毕返回house指针
*/

//对象的表示
class House {
	//...
};

class StoneHouse : public House {


};

//对象的构建
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



