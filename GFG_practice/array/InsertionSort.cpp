#include <bits/stdc++.h>
using namespace std;

class InsertionSort {
public:  
    template <class T>  
    void insertionSort(T arr[], int n) 
    { 
        int i, j, count = 0; 
        T key;
        for (i = 1; i < n; i++) { 
            key = arr[i]; 
            j = i - 1; 
            
            while (j >= 0 && arr[j] > key) { 
                arr[j + 1] = arr[j]; 
                j = j - 1; 
                count ++;
            } 
            arr[j + 1] = key; 
        } 
        cout << "total number of comparisons = " << count  << endl;
    } 

    template <class T> 
    void printArray(T arr[], int n) { 
        int i; 
        for (i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;
    } 
};


int main() { 
    int size;
    int choice;

    cout << "1:int" << endl;
    cout << "2:char" << endl;
    cout << "3:float" << endl;
    cout << "Enter the datatype: ";
    cin >> choice;

    if(choice == 1) {
        cout << "Enter the size of the array :";
        cin >> size;
        int array[size];
        cout << "Enter the elements of array :" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> array[i];
        }
        InsertionSort i;

        i.insertionSort<int>(array, size); 
        i.printArray<int>(array, size);
    } else if (choice == 2){
        cout << "Enter the size of the array :";
        cin >> size;
        char array[size];
        cout << "Enter the elements of array :" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> array[i];
        }
        InsertionSort i;
        i.insertionSort<char>(array, size); 
        i.printArray<char>(array, size);
    } else if (choice == 3){
        cout << "Enter the size of the array :";
        cin >> size;
        float array[size];
        cout << "Enter the elements of array :" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> array[i];
        }
        InsertionSort i;
        i.insertionSort<float>(array, size); 
        i.printArray<float>(array, size);
    }
    return 0; 
} 


