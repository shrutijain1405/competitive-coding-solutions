/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

S/I = 1024
S/0 = 32

S/I = 4
S/0 = 2
*/
#include<math.h>
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
         long lb = 0;
         long ub = x;
         long mid = (ub+lb+1)/2;
         long sqrt = 0;
         bool isFound = false;
         while(!isFound){
            mid = (ub+lb+1)/2;
            if((mid*mid)<x && ((mid+1)*(mid+1))<x)
                lb = mid + 1;
            else if((mid*mid)>x && ((mid+1)*(mid+1))>x)
                ub = mid - 1;
            else{
                isFound = true;
                sqrt = mid;
                if((mid+1)*(mid+1) == x)
                    sqrt = mid+1;
            }
         }
         return (sqrt);
    }
};
int main(){
    Solution ob;
    int sqrt = ob.mySqrt(9);
    cout<<sqrt<<endl;
}