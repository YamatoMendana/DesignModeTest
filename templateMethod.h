#include <stdio.h>

//Ä£°åÄ£Ê½
class Library {
public:
	Library() {}
	virtual ~Library() {}
	void run() {
		step1();

		if (step2())
		{
			step3();
		}

		for (int i = 0; i < 4; i++)
		{
			step4();
		}

		step5();
	}

	virtual int step2() = 0;
	virtual int step4() = 0;

protected:
	int step1()
	{
		printf("step1\n");
		return 1;
	}

	int step3()
	{
		printf("step3\n");
		return 1;
	}

	int step5()
	{
		printf("step5\n");
		return 1;
	}

};

class myLibrary :public Library {
public:
	virtual int step2()
	{
		printf("step2\n");
		return 1;
	}

	virtual int step4()
	{
		printf("step4\n");
		return 1;
	}
};


