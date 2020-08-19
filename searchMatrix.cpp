/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.empty()==true)
            return false;
        else{
            bool flag = false;
            int n = matrix[0].size(); //no of cols
            int m = matrix.size(); //no of rows
            int lb = 0;
            int ub = (m*n) -1;
            int mid = (lb+ub)/2;
            while(lb<=ub){
                mid = (lb+ub)/2;
                int r = mid/n;
                int c= mid%n;
                if(matrix[r][c] > target)
                    ub = mid-1;
                else if(matrix[r][c] < target)
                    lb = mid + 1;
                else{
                    flag = true;
                    break;
                }
            }
            return flag;
        }
    }
};
int main(){
	Solution ob;
	//vector< vector<int> > matrix = {};
	vector< vector<int> > matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	bool ans = ob.searchMatrix(matrix, 100);
	cout<<"ans = "<<ans<<endl;
	return 0;
}