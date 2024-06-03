#include "strategyMethod.h"
#include "templateMethod.h"
#include "ObserverMethod.h"
#include "decoratorMethod.h"
#include "bridgeMethod.h"
#include "FactoryMethod.h"
#include "AbstractFactoryMethod.h"
#include "PrototypeMethod.h"
#include "builderMethod.h"
#include "SingletonMethod.h"

#define templateMethod 0
#define strategyMethod 0
#define ObserverMethod 0
#define decoratorMethod 0
#define bridgeMethod 0
#define FactoryMethod 0
#define AbstractFactoryMethod 0
#define PrototypeMethod 0
#define builderMethod 0
#define SingletonMethod 0




int main()
{

#if templateMethod
	myLibrary lib;
	lib.run();
#endif 

#if strategyMethod
	TaxStrategy* cn = new CNTax();
	Context* ctx = new Context(cn, 100.0);
	double val = ctx->CalculateTax();
	printf("money val = %lf\n", val);

#endif

#if ObserverMethod
	Consumer cs;
	cs.run();

#endif

#if decoratorMethod
	Stream* s1 = new FileStream();
	CryptoStream* s2 = new CryptoStream(s1);
	BufferedStream* s3 = new BufferedStream(s1);
	BufferedStream* s4 = new BufferedStream(s2);

	s2->Read(1);
	s2->Write('w');
	s2->Seek(1);

#endif

#if bridgeMethod
	//运行时装配
	MessagerImp* mImp = new PCMessagerImp();
	Messager* m = new MessagerPerfect(mImp);

	m->Login("admin", "123456");
	m->SendMessage("hello");
	m->SendPicture("./");
#endif

#if FactoryMethod
	SplitterFactory* sf = new BinarySplitterFactory();
	FactoryRun fr(sf);
	fr.run();
#endif

#if AbstractFactoryMethod
	IDBFactory* dbFactory = new OracleDBFactory();
	EmployeeDAO dao(dbFactory);
	dao.run();

#endif

#if PrototypeMethod
	ISplitterPrototype* splitter1 = new BinarySplitterPrototype();
	splitter1->split();
	ISplitterPrototype* splitter2 = splitter1->clone();
	splitter2->split();

	printf("%x , %x\n", &splitter1, &splitter2);

#endif

#if builderMethod
	HouseBuilder* pHouseBuilder = new StoneHouseBuilder();
	HouseDirector* pHouseDirector = new HouseDirector(pHouseBuilder);
	House* house = pHouseDirector->Construct();

#endif

#if SingletonMethod
	Singleton* single = Singleton::getInstance();

#endif

	return 0;
}