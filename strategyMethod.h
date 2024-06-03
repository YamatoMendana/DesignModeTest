#include <stdio.h>

//²ßÂÔÄ£Ê½
class TaxStrategy {
public:
	TaxStrategy() {}
	virtual double Calculate(double num) = 0;
	virtual ~TaxStrategy() {}
};

class CNTax :public TaxStrategy {
public:
	virtual double Calculate(double num)
	{
		printf("CN\n");
		return num;
	}
};

class USTax :public TaxStrategy {
public:
	virtual double Calculate(double num)
	{
		printf("US\n");
		return num;
	}
};

class Context {
public:
	Context(TaxStrategy* strategy,double num) {
		this->strategy = strategy;
		money = num;
	}
	~Context() {
		delete this->strategy;
	}
	double CalculateTax()
	{
		double val = strategy->Calculate(money);
		return val;
	}
private:
	TaxStrategy* strategy;
	double money;

};

