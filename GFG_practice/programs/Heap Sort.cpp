#include<iostream>
using namespace std;

template<class t>
class heap{
      int size,heapSize,count=0;
      t arr[20];
      void buildMaxHeap();
      void maxHeapiFy(t*,int);
      void exchange(int i ,int j );
      public:
      void input();
      void heapSort();
      void display();
};

template<class t>
void heap<t>::input(){
    cout<<"Enter the size of the  array: ";
    cin>>size;
    heapSize=size;
    cout<<"\nEnter the elements of the array:-"<<endl;
    for(int i =0;i<size;i++){
        cin>>arr[i];
    }
    
}

template<class t>
void heap<t>::buildMaxHeap() {    
    for(int i =size/2; i>=0; i--)  {    
        maxHeapiFy(arr,i);
    }
}

template<class t>
void heap<t>::maxHeapiFy(t arr[],int i ) {  

    int l = 2*i+1;
    int r= 2*i+2;
    int largest=i;
    if(l<=heapSize-1 && arr[l]>=arr[i]){
        largest=l;
        count++;
    }    
    if(r<=heapSize-1 && arr[r]>=arr[largest]){
          largest=r;
          count++;
    }    
    if(i!=largest){
        exchange(i,largest);
        maxHeapiFy(arr,largest);
    }
}

template<class t>
void heap<t>::exchange(int i , int j) {   //function to put values in order
    int temp= arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

template<class t>
void heap<t>::heapSort(){
    
    buildMaxHeap();
    for(int i=size-1;i>=1;i--){
        exchange(i,0);
        heapSize=heapSize-1;
        maxHeapiFy(arr,0);
    }
 }

template<class t>
void heap<t>::display() {
    cout<<"\nSorted array is :- \n"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nNo of comparisons = "<<count<<" ";
}


int main(){
    char repeat;
    int ch ;
    do{
    cout<<" 1. Integer operations "<<endl;
    cout<<" 2. Char operations "<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    if(ch==1) {
        heap<int> obj;
        obj.input();
        cout<<"------------Heap Sort in Progress-----------";
        obj.heapSort();
        obj.display();
    }
    
    else if (ch==2) {
        heap<char>obj;
        obj.input();
        cout<<"------------Heap Sort in Progress-----------";
        obj.heapSort();
        obj.display();
    }

    else cout<<"Invalid choice. "<<endl;

    cout<<"\n\nWant to repeat ? [y][n]? "<<endl;
    cin>>repeat;
    }while(repeat=='y' || repeat=='Y');
    
    return 0;
}