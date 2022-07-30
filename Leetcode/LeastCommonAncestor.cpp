#include <iostream>
using namespace std;

class Solution {
  unordered_map<int, int> umap;
  void dfs(TreeNode* node, int parent = -1 ){
    if(!node) return;
    umap[node->val] = parent;
    if(node->left) {
      dfs(node->left, node->val);
    }
    if(node->right) {
      dfs(node->right, node->val);
    }
  }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        for(auto item : umap ) {
          cout << item->first <<"    " << item->second << endl;
        }
        return root;
    }
};

