/**
* Takes in-order and post-order arrays as inputs(hard coded) and outputs a binary tree.  
*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
	int indexOf(vector<int>& arr, int x){
		int i = 0;
		for(i=0; i<arr.size(); i++){
			if(arr[i] == x)
				break;
		}
		return i;
	}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int length = inorder.size();
        if (length == 0)
        {
        	TreeNode* root = nullptr;
        	return root;
        }
        if (length == 1)
        {
        	TreeNode* root = new TreeNode(inorder[0]);
        	return root;
        }
        else{

        	int value = postorder[length-1];
        	int val_ind = indexOf(inorder , value);
        	vector<int> post_copy = postorder;
        	reverse(post_copy.begin(),post_copy.end());
        	if(inorder == postorder){ //right tree missing
        		vector<int>::const_iterator it = inorder.begin();
        		TreeNode* left = new TreeNode(*it);
        		it++;
        		TreeNode* root;
        		while(it != inorder.end()){
        			root = new TreeNode(*it , left , nullptr);
        			it++;
        			left = root;
        		}
        		return(root);
        	}

        	if(inorder == post_copy) { //left tree missing
        		vector<int>::const_iterator it = postorder.begin();
        		TreeNode* right = new TreeNode(*it);
        		it++;
        		TreeNode* root;
        		while(it != postorder.end()){
        			root = new TreeNode(*it , nullptr , right);
        			it++;
        			right = root;
        		}
        		return(root);
        	}

        	else{
        		if(val_ind == 0){
        			vector<int> in_right(inorder.begin()+val_ind+1, inorder.end());
        			vector<int> post_right(postorder.begin()+0, postorder.begin() + in_right.size()+0);
	        		TreeNode* left = nullptr;
	        		TreeNode* right = buildTree(in_right, post_right);
	        		TreeNode* root = new TreeNode(value, left, right);
	        		return(root);
	        	}
	        	if(val_ind == length-1){
	        		vector<int> in_left(inorder.begin(), inorder.begin()+val_ind);
	        		vector<int> post_left(postorder.begin(), postorder.begin() + in_left.size());
	        		TreeNode* left = buildTree(in_left, post_left);
	        		TreeNode* right = nullptr;
	        		TreeNode* root = new TreeNode(value, left, right);
	        		return(root);

	        	}
	        	else{
	        		vector<int> in_left(inorder.begin(), inorder.begin()+val_ind);
	        		vector<int> in_right(inorder.begin()+val_ind+1, inorder.end());
	       	    	vector<int> post_left(postorder.begin(), postorder.begin() + in_left.size());
	        		vector<int> post_right(postorder.begin()+in_left.size(), postorder.begin() + in_right.size()+in_left.size());
	        		TreeNode* left = buildTree(in_left, post_left);
	        		TreeNode* right = buildTree(in_right, post_right);
	            	TreeNode* root = new TreeNode(value, left, right);
	        		return(root);
	        	}
	        }
    	}
    }
    void display(TreeNode* a){
    	cout << (a)->val << endl;
    	if(a->left != nullptr){
    		cout<< "left" <<endl;
    		display(a->left);
    	}
    	if(a->left == nullptr){
    		cout<<"left" <<endl;
    		cout<<"null"<<endl;
    	}
    	if(a->right != nullptr){
    		cout<< "right" <<endl;
    		display(a->right);
    	}
    	if(a->right == nullptr){
    		cout<< "right" <<endl;
    		cout<<"null"<<endl;	
    	}
    }
};
int main(int argc, char const *argv[])
{	
	vector<int> inorder = {8,4,9,2,10,5,12,11,13,1,6,3,7};
	vector<int> postorder = {8,9,4,10,12,13,11,5,2,6,7,3,1};
	Solution ob;
	TreeNode* root = ob.buildTree(inorder,postorder);
	cout<<"display"<<endl;
	ob.display(root);
	
	return 0;
}