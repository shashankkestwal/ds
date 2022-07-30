// #include <iostream>
// #include <stdlib.h> 
// #include <cstring>
// #include <stack>
// #include <stdlib.h>
// #include <vector>
// #include <sstream>
// using namespace std;


// vector<string> tokenize(string s, string del = " ")
// {
// 	vector<string> str_arr;
// 	int number_of_items = 0;
//     int start = 0;
//     int end = s.find(del);
//     while (end != -1) {
//         str_arr.push_back(s.substr(start, end - start));
//         start = end + del.size();
//         end = s.find(del, start);
//         number_of_items++;
//     }
//     cout << number_of_items <<"    ";
//     str_arr.push_back(s.substr(start, end - start));

//     return str_arr;
// }


// bool is_operator(string str) {
// 	if (str == "+") {
// 		return true;
// 	} else if (str == "-") {
// 		return true;
// 	} else if(str == "*") {
// 		return true;
// 	} else if (str == "/") {
// 		return true;
// 	}
// 	return false;
// }




// void postFix(string strin){

// 	stack<int> s;
// 	vector<string> tokenized_array = tokenize(strin);

// 	for (auto iter = tokenized_array.begin(); iter != tokenized_array.end(); ++iter) {
// 		string str = *iter;

// 			if ( str == "+" ) {
// 				int a = s.top();
// 				s.pop();
// 				int b = s.top();
// 				s.pop();
// 				a = a + b;
// 				s.push(a);
// 			} else if ( str == "-") {
// 				int a = s.top();
// 				s.pop();
// 				int b = s.top();
// 				s.pop();
// 				a = a - b;
// 				s.push(a);
// 			} else if ( str == "*") {
// 				int a = s.top();
// 				s.pop();
// 				int b = s.top();
// 				s.pop();
// 				a = a * b;
// 				s.push(a);
// 			} else if (str == "/") {
// 				int a = s.top();
// 				s.pop();
// 				int b = s.top();
// 				s.pop();
// 				a = a / b;
// 				s.push(a);
// 			} else {
		
// 	   		 string str = *iter;
	 
// 	   		 stringstream geek(str);
// 	   		 int x = 0;
// 	   		 geek >> x;		
// 	   		 cout << x;	
// 			}
// 	}
        



	
	
// 	// vector<string>::iterator iter = tokenized_array.begin();
// 	// vector<string>::iterator end = tokenized_array.end();
// 	// int count = 0;
// 	// while(iter != end) {
// 	// 	count++;
		


			
		
// 	// iter++;	
// 	// }
// 	// cout << endl << count;

// 	// int i = 0;
// 	// while(i <= str.length()) {
		
// 	// 	if ( int(str[i]) >= 48 && int(str[i]) <= 57) {
// 	// 		int temp = int(str[i]);
// 	// 		temp = temp % 48;
// 	// 		s.push(temp);
	
// 	// 	i++;

// 	// }
// 	// cout << s.top();
// 	// return 0;
// }



// // int convert_to_number(string str) {
	
// // }

// int main() {
// 	string a;
// 	cin >> a;
// 	postFix(a);

// 	return 0;
// }



// C++ program to evaluate value of a postfix expression
#include <iostream>
#include <string.h>

using namespace std;

// Stack type
struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

// Stack Operations
struct Stack* createStack( unsigned capacity )
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	if (!stack) return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));

	if (!stack->array) return NULL;

	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}

char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}

void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}


// The main function that returns value of a given postfix expression
int evaluatePostfix(char* exp)
{
	// Create a stack of capacity equal to expression size
	struct Stack* stack = createStack(strlen(exp));
	int i;

	// See if stack was created successfully
	if (!stack) return -1;

	// Scan all characters one by one
	for (i = 0; exp[i]; ++i)
	{
		// If the scanned character is an operand (number here),
		// push it to the stack.
		if (isdigit(exp[i]))
			push(stack, exp[i] - '0');

		// If the scanned character is an operator, pop two
		// elements from stack apply the operator
		else
		{
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (exp[i])
			{
			case '+': push(stack, val2 + val1); break;
			case '-': push(stack, val2 - val1); break;
			case '*': push(stack, val2 * val1); break;
			case '/': push(stack, val2/val1); break;
			}
		}
	}
	return pop(stack);
}

// Driver program to test above functions
int main()
{
	char exp[] = "119-";
	cout<<"postfix evaluation: "<< evaluatePostfix(exp);
	return 0;
}
