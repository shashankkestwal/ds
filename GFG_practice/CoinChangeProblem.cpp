#include <bits/stdc++.h>
using namespace std;

int minCoins(int coinval, int aval_coins[], int dp[]) {
  if (coinval == 0) return 0;

  int ans = INT_MAX;

  for (int i = 0; i < 3; i++) { 
    
      if (coinval-aval_coins[i] >= 0) {
        int subAns ;
        
        // if (dp[coinval - aval_coins[i]] == -1 ) {
        //   subAns = minCoins(coinval - aval_coins[i], aval_coins, dp);
        // } else {
          subAns = dp[coinval- aval_coins[i]];
        // }
        // if (subAns + 1 < ans ) {
        //   ans = subAns + 1;
        // } 
      }       
  }

  dp[coinval] = ans;
  return ans;
}


int main() {
  int coinval = 18;
  int avalcoins[3] = {1,5,7};
  int dp[4] = {-1}; 

  int min_coins = minCoins(coinval, avalcoins, dp);

  cout << min_coins;


}

















// // C++ program to find height of tree
// #include <bits/stdc++.h>
// using namespace std;


// /* A binary tree node has data, pointer to left child
// and a pointer to right child */
// class node
// {
//   public:
//   int data;
//   node* left;
//   node* right;
// };

// /* Compute the "maxDepth" of a tree -- the number of
//   nodes along the longest path from the root node
//   down to the farthest leaf node.*/
// int maxDepth(node* node)
// {
//   if (node == NULL)
//     return -1;
//   else
//   {
//     /* compute the depth of each subtree */
//     int lDepth = maxDepth(node->left);
//     int rDepth = maxDepth(node->right);
  
//     //  use the larger one 
//     if (lDepth > rDepth)
//       return(rDepth + 1);
//     else return(rDepth + 1);
//   }
// }

// /* Helper function that allocates a new node with the
// given data and NULL left and right pointers. */
// node* newNode(int data)
// {
//   node* Node = new node();
//   Node->data = data;
//   Node->left = NULL;
//   Node->right = NULL;
  
//   return(Node);
// }
  
// // Driver code
// int main()
// {
//   node *root = newNode(1);

//   root->left = newNode(2);
//   root->right = newNode(3);
//   root->left->left = newNode(4);
//   root->left->right = newNode(5);
  
//   cout << "Height of tree is " << maxDepth(root);
//   return 0;
// }

// // This code is contributed by Amit Srivastav
