#include <iostream>
using namespace std;

int linear_search_iterative(int list_size, int *list, int search_item) {
	for (int i = 0; i < list_size; i++)
	{
		if (list[i] == search_item) {
			return i;
		}
	}
	return -1;
}

int linear_search_recursive(int list_size, int *list, int search_item) {
	list_size--;

	if (list_size >= 0)
	{
		cout << "I am here 111 "<< endl;
		if (list[list_size] == search_item) {
			return list_size; 
		}
		else {
			cout << "I am here "<< endl;
			linear_search_recursive(list_size, list, search_item);
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int N;
	cout << "Enter the size of the list : ";
	cin >> N;
	int list[N];
	cout << "Enter the elements for the list : ";
	for (int i = 0; i < N; ++i) {
		cin >> list[i];
	}
	int search_item;
	cout << "Enter the element you want to search in list : ";
	cin >> search_item; 
	int choice;

	cout << "Press 1 for recursive search any other for iterative search : ";
	cin >>  choice ;
	switch (choice) {
		case 1:
			if (linear_search_recursive(N, list , search_item) != -1) {
				cout << "Element found at index " << linear_search_recursive(N, list , search_item) << endl;
			} else {
				cout << "Element not found " << endl;
			}
			break;
		default :
			if (linear_search_iterative(N, list , search_item) != -1) {
				cout << "Element found at index " << linear_search_iterative(N, list , search_item) << endl;
			} else {
				cout << "Element not found " << endl;
			}
			break;
	}
	return 0;
}