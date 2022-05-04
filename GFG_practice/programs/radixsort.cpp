#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class RadixSort{
    
    private:
        T *A;
        int k,d;
        T highest;
        
    public:
        T *B;
        int n;
        RadixSort();
        void insert();
        int dvalue();
        void counting_sort(int d);
        void display();
        void Radix_Sort(int d);
};

template<class T>
RadixSort<T> :: RadixSort(){
    cout<<"\nEnter number of elements in the array : ";
    cin>>n;
    k = 9; //assuming value of k will be in range 0 to 9
    d=0;
    A = new T[n];
    B = new T[n];
}

template<class T>
void RadixSort<T> :: insert(){       
    
    highest = INT16_MIN;
    cout<<"\nEnter elements in the array : ";
    for(int i=0;i<n;i++){
        cin>>A[i] ;
        
        if(A[i]>highest){
            highest = A[i];
        }
    }    
}

template<class T>
int RadixSort<T> :: dvalue(){
    while((highest = (int)highest/10) != 0)
        d++;
    d++;
 return d; //return highest order digit count
}

template<class T>
void RadixSort<T> :: display(){
    cout<<"\nEntered array :: [ ";
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
    cout<<"]\n";
}

template <class T>
void RadixSort<T> :: counting_sort(int index){
    
    T *C = new T[k+1];

    for(int i=0;i<=k;i++)
        C[i]=0;

    int modulo,divide;
    
    //POWER FUNCTION WAS GIVING VALUE LESS BY 1 FOR EVEN VALUE OF 'index' variable
    if (index%2==0){
        modulo = pow(10,index) + 1;
        divide = pow(10,index-1) + 1;
    }
    else{
        modulo = pow(10,index);
        divide = pow(10,index-1);
    }

    //TO GET nth DIGIT OF A NUMBER
    for(int j=0;j<n;j++) {
        C[(int)((A[j]%modulo)/divide)] = C[(int)((A[j]%modulo)/divide)] +1;
    }
    //C[i] now contains the number of elements equal to i.
   
    for(int i=1;i<=k;i++){
        C[i] = C[i] + C[i-1];
    //C[i] now contains the number of elements less than or equal to i.
    }

    //put the elements in B at the right position
    for(int j=n-1;j>=0;j--){
        B[C[(int)((A[j]%modulo)/divide)]-1] = A[j];
        C[(int)((A[j]%modulo)/divide)] = C[(int)((A[j]%modulo)/divide)]-1;
    } 
   
    //updating array A with sorted values
    for(int i=0;i<n;i++){
        A[i] = B[i];
    }    
}

template<class T>
void RadixSort<T> :: Radix_Sort(int d){
    cout<<"\n----------------IMPLEMENTING RADIX-SORT---------------------\n";
    for(int i=1;i<=d;i++){
       counting_sort(i);
    }
}

int main(){

    RadixSort<int> rs;

    rs.insert();

    rs.display();

    rs.Radix_Sort(rs.dvalue());
    
    cout<<"\nFinal Sorted Array :: [ ";
    for(int i=0;i<rs.n;i++)
        cout<<rs.B[i]<<" ";
    cout<<"]"<<endl;
 
 return 0;   
}