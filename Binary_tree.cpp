#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node (int d){
		this->data = d;
		this->left = this->right = NULL;
	}
};
 

class BinarySearchTree{
public:
	Node* root;
	BinarySearchTree(){
		this->root = NULL;
	}

	Node* create_node(int data){
		Node* N = new Node(data);
		return N;
	}

	void insert_in_tree(int data){
		
		Node* n = create_node(data);
		if (root == NULL)
		{
			root = n;
			return;
		}
		Node* node = this->root;
		Node* parent_node;
		while(node != NULL){
			parent_node = node;
			if (n->data < node->data ) {
				node = node->left;
			} else if(n->data > node->data) {
				node = node->right;
			} else if (n->data == node->data) {
				cout <<"cannot put identical data in binary tree"<<endl;
			}
		}
		if (parent_node->data < n->data){
				parent_node->right = n;
		} else {
			parent_node->left = n;
		}
	}
	bool search_in_tree(int data) {
		Node* node = this->root;
		while(node != NULL) {
			if (data == node->data) {
				return true;
			}else if(data < node->data) {
				node = node->left;
			} else {
				node = node->right;
			}
		}
		return false;
	}


	void breadth_first_traversal() {
		Node* node = this->root;
		queue<Node*> nodes_queue;
		nodes_queue.push(node);
		while(!nodes_queue.empty()) {
			Node* visited_node = nodes_queue.front();
			cout << visited_node->data << " ";
			nodes_queue.pop();
			if (visited_node->left != NULL) {
				nodes_queue.push(visited_node->left);
			} 
			if (visited_node->right != NULL) {
				nodes_queue.push(visited_node->right);
			}
		}
	}

	void interative_preorder_traversal() {
		Node* node = this->root;
		stack<Node*> node_stack;
		node_stack.push(node);
		while(!node_stack.empty()) {
			Node* current_node = node_stack.top();
			node_stack.pop();
			cout << current_node->data << " ";
			if (current_node->right != NULL) {
				node_stack.push(current_node->right);
			}

			if (current_node->left != NULL) {
				node_stack.push(current_node->left);
			}
		}
		cout << endl;

	}

	
	void interative_inorder_traversal () {
		stack<Node*> s;
	    Node *curr = root;
	 
	    while (curr != NULL || s.empty() == false)
	    {
	        while (curr !=  NULL)
	        {
	            s.push(curr);
	            curr = curr->left;
	        }
	        curr = s.top();
	        cout << curr->data << " ";
	        s.pop();

	        curr = curr->right;
	    } 
	    cout << endl;
	}

	void interative_postorder_traversal() {
		if (root == NULL)
	       return;
	 
	    // Create two stacks
	    stack<Node*> s1, s2;
	 
	    // push root to first stack
	    s1.push(root);
	    Node* node;
	 
	    // Run while first stack is not empty
	    while (!s1.empty()) {
	        // Pop an item from s1 and push it to s2
	        node = s1.top();
	        s1.pop();
	        s2.push(node);
	 
	        // Push left and right children
	        // of removed item to s1
	        if (node->left)
	            s1.push(node->left);
	        if (node->right)
	            s1.push(node->right);
	    }
	 
	    // Print all elements of second stack
	    while (!s2.empty()) {
	        node = s2.top();
	        cout << node->data << " ";
	        s2.pop();
	    }
	    cout << endl;
	}

	void recursive_postorder_traversal(Node * temp) {
		this->recursive_postorder_traversal(temp->left);
		this->recursive_postorder_traversal(temp->right);
		cout << temp->data;
	}

	void postorder_recursive_traversal() {
		this->recursive_postorder_traversal(this->root);
	}

	Node* inorder_predecessor_node(Node* deleted_node) {
		Node* inorder_pre = deleted_node->left;
		while(inorder_pre->right != NULL){
			inorder_pre = inorder_pre->right;
		}
		return inorder_pre;
	}


	Node* search_tree(int data) {

		Node* node = this->root;
		Node* parentNode ;
		while(node != NULL ) {
			if (data == node->data) {
				return parentNode;
			} else {
				parentNode = node;
				if(data < node->data) {
					node = node->left;
				} else {
					node = node->right;
				}
			}
		}
		return NULL;
	}

	void delete_node(int deleted_node_data) {
		if (root->data == deleted_node_data) {
			Node* inorder_pre = this->inorder_predecessor_node(root);
			int new_data = inorder_pre->data;
			delete_node(inorder_pre->data);
			root->data = new_data;
			return;
		}


		Node* parent_node = search_tree(deleted_node_data);
		Node* deleted_node;
		char child ;

	 	if (parent_node->data > deleted_node_data) {
			deleted_node = parent_node->left;
			child = 'l';
		} else {
			deleted_node = parent_node->right;
			child = 'r';
		}


		if (deleted_node->left == NULL && deleted_node->right == NULL){
			if (child == 'l') {
				parent_node->left = NULL;
				delete deleted_node;
			} else if (child == 'r') {
				parent_node->right = NULL;
				delete deleted_node;
			}
			return;
		}
		if ((deleted_node->left == NULL && deleted_node->right != NULL) )
		{
			Node* connecting_node = deleted_node->right;
			if (child == 'l') {
				parent_node->left = connecting_node;
				free(deleted_node);
			} else if (child == 'r') {
				parent_node->right = connecting_node;
				free(deleted_node);
			}
			return ;
		}

		if ((deleted_node->left != NULL && deleted_node->right == NULL))
		{
			Node* connecting_node = deleted_node->left;
			if (child == 'l') {
				parent_node->left = connecting_node;
				free(deleted_node);
			} else if (child == 'r') {
				parent_node->right = connecting_node;
				free(deleted_node);
			}
			return ;
		}


		if (deleted_node->left != NULL && deleted_node->right != NULL){
			Node* inorder_pre = this->inorder_predecessor_node(deleted_node);
			int new_data = inorder_pre->data;
			delete_node(inorder_pre->data);
			deleted_node->data = new_data;
		}
	}
};

int main(int argc, char const *argv[])
{
	BinarySearchTree b;
	cout << "_____Binary Search Tree_________ " <<endl;

	char more;
	do{
		cout <<"(i)Insert a node "<<endl;
		cout <<"(ii)Search a node " <<endl;
		cout <<"(iii)Delete a node "<<endl;
		cout <<"(iv)Preorder traversal ";
		cout <<"Inorder traversal ";
		cout <<"Postorder traversal "<<endl;
		int choice;
		cout << "Enter the operation you want to perform :";
		cin >> choice ;
		int data ;
		switch (choice){
			case 1:	
				cout << "Enter the data for the node :";
				cin >> data; 
				b.insert_in_tree(data);
				break;
			case 2:
				
				cout << "Enter the data you want to search in tree :";
				cin >> data ;
				if (b.search_in_tree(data)){
					cout << "Element found in the tree "<< endl;
				} else{
					cout << "Element not found "<< endl;
				}
				break;
			case 3:
				cout << " Enter the data you want to delete :"<< endl;
				cin >> data;
				b.delete_node(data);
				break;
			case 4:
				cout << "preorder traversal "<< endl;
				b.interative_preorder_traversal();
				cout << "inorder traversal "<< endl;
				b.interative_inorder_traversal();
				cout << "postorder traversal "<< endl;
				b.interative_postorder_traversal();
				break;
			default:
				cout << "Invalid input "<<endl;
				break;
		}

		cout << "press n/N to exit :";
		cin >> more;
	} while(more !='n' && more != 'N');
	return 0;	
}

