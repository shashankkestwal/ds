#include <bits/stdc++.h>
using namespace std;

class Bucket {
    private:
    int size;
    float *arr;
    vector<float> *bucket;

    public:
    Bucket(){
        cout<<"Enter number of elements : ";
        cin>>size;
        arr=new float[size];
        bucket=new vector<float>[size];
    }
    void inputElements(){
        for(int i=0;i<size;i++){
            cout<<"Enter element ["<<i<<"] : ";
            cin>>arr[i];
        }
    }
    void printData(){
        cout<<"The array is : ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<", ";
        }
        cout<<"\n";
    }
    void bucketSort() {
        for(int i = 0; i < size; i++) {
            int bucketIndex = int(size * arr[i]);
            bucket[bucketIndex].push_back(arr[i]);
        }
        for(int i = 0; i < size; i++) {
            insertionSort(bucket[i]);
        }
        int index = 0;
        for(int i = 0; i < size; i++) {
            for(float j : bucket[i]) {
                arr[index++] = j;
            }
        }
    }
    private:
    void insertionSort(vector<float> &arr){
        for(int j=1;j<arr.size();j++){
            float key=arr[j];
            int i=j-1;
            while(i>=0 && arr[i]>key){
                swap(arr[i+1],arr[i]);
                i--;
            }
            arr[i+1]=key;
        }
    }
};

int main() {
    Bucket ob;

    ob.inputElements();
    ob.printData();
    ob.bucketSort();
    cout<<"The array after sorting is : \n";
    ob.printData();
    
    return 0;
}