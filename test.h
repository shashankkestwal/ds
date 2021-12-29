#include <iostream>
using namespace std;

class Test{
public :
	int data;
	// Test(int);
	void printdata();
};

class Test2: public Test{
public:
	Test2();
	void printdata(int);
};