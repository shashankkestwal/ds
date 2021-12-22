#include <iostream>
using namespace std;


int power(int num, int pow) {
	if (pow <= 0) {
		return -1;
	} else if (pow == 1) {
		return num;
	}
	return num * power(num , pow - 1);
}

int main(int argc, char const *argv[])
{
	cout << power(-11,2);
	return 0;
}