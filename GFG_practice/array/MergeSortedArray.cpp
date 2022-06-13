#include <bits/stdc++.h>
using namespace std;

vector <int> insertElement(vector <int> num) {
    int size;
    cout << "Enter vector size :";
    cin >> size;
    // auto counter = num.begin();
    int count = 0;
    int val;
    // counter--;
    // cout << *counter  << "data ";
    // cout << "enter vector elements\n";
    while(count < size) {
        cin >> val;
        num.push_back(val);
        count++;
    }
    return num;
}

void mergeVectors(vector <int> v1, int num1, vector<int> v2, int num2) {
    auto counter = v1.begin();
    auto first = v1.begin(),second = v2.begin();
    cout << num1 << "  " << num2 << "  ";
    while(counter != v1.end()) {
        cout << *counter << " ";
        if(*first > *second) {
            v1.insert(counter,*second);
            v1.pop_back();
            second++;
        } else {
            first++; 
        }
        counter++;
    }

    for (auto i = v1.begin(); i < v1.end(); ++i) {
        cout << *i;
    }
}

int main() {
    vector<int> num1, num2;
    num1 = insertElement(num1);
    num2 = insertElement(num2);
    // for (int i = 0; i < num1.size(); ++i) {
    //     cout << num1[i] <<"  ";
    // }

    mergeVectors(num1, num1.size() - num2.size(), num2,num2.size());
    return 0;
}