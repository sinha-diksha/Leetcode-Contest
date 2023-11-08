/*2357. Make Array Zero by Subtracting Equal Amounts
User Accepted:11544
User Tried:12289
Total Accepted:12024
Total Submissions:18464
Difficulty:Easy
You are given a non-negative integer array nums. In one operation, you must:

Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0.

 

Example 1:

Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].
Example 2:

Input: nums = [0]
Output: 0
Explanation: Each element in nums is already 0 so no operations are needed.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100*/

#include <bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int>& nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int ans=0;
    for(int i=0; i<n; i++){
        if(nums[i]==0){
            continue;
        }
        int k=nums[i];
        for(int j=i; j<n; j++){
            nums[j]-=k;
        }
        ans++;
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        cout<<minimumOperations(v)<<endl;
    }
}