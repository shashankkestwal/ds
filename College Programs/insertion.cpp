#include<iostream>
using namespace std;

template<class t>
class Insertion {
  public:
    t arr[20];
    int size;
    int comp_count;
    Insertion();
    void input();
    void display();
    void insertion_sort();
};

template<class T>
Insertion<T>::Insertion() {
     size=0;
     comp_count=0;
}

template<class T>
void Insertion<T>::input() {
     cout<<"Enter the size of the array: "<<endl;
     cin>>size;
     arr[size];
     cout<<"Enter the values in the array. "<<endl;
     for(int i =0;i<size;i++){
         cin>>arr[i];
     }
}

template<class T>
void Insertion<T>::insertion_sort() {

   for(int i =1;i<size;i++){  // starting from second index 
       int j=i-1; 
       T key=arr[i]; 
         // storing the index of its predecessor
       
        if(key>arr[j]) //if key is at correct position
           comp_count++; // still one comparison is made     
       
        while(j>=0 && arr[j]>=key) {               //comparing if predecessors are in order       
          comp_count++;
          arr[j+1]=arr[j];
          j--;
       }  
       arr[j+1]=key;
   }
   cout<<"\nArray after Sorting is: ";
   display();
  cout<<"\n No of comparisons= "<<comp_count;
}

template<class T>
void Insertion<T>::display(){
    for(int i =0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    int ch;
    cout<<"Program for insertion sort" << endl;
    cout<<"Enter 1: Integer "<<endl;
    cout<<"Enter 2: Char "<<endl;
    cout<<"Enter 3: Float "<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    if(ch==1){
        Insertion<int>obj;
        obj.input();
        cout<<"Entered Array is: ";
        obj.display();
        
        obj.insertion_sort();
    }
     
       else if (ch==2) {
        Insertion<char>obj;
        obj.input();
        cout<<"Entered Array is: ";
        obj.display();
        obj.insertion_sort();
    }

     else if (ch==3) {
        Insertion<float>obj;
        obj.input();
        cout<<"Entered Array is: ";
        obj.display();
        obj.insertion_sort();
    }
     else 
          cout<<"Invaid Value!"<<endl;
}