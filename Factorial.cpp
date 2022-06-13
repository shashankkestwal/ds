#include <iostream>
using namespace std;

int factorail(int num){
	if (num < 0) {
		return -1;
	} else if (num <= 1) {
		return 1;
	} 
	return num * factorail(num-1);
}


int main(){
	int number;
	cout << "Enter the number whose factorial is needed :";
	cin >> number;
	cout << factorail(number);
	return 0;
}
