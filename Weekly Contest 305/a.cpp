/*
Number of Arithmetic Triplets

You are given a 0-indexed, strictly increasing integer array nums and a positive integer diff. A triplet (i, j, k) is an arithmetic 
triplet if the following conditions are met:

i < j < k,
nums[j] - nums[i] == diff, and
nums[k] - nums[j] == diff.
Return the number of unique arithmetic triplets.

 

Example 1:

Input: nums = [0,1,4,6,7,10], diff = 3
Output: 2
Explanation:
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3. 
Example 2:

Input: nums = [4,5,6,7,8,9], diff = 2
Output: 2
Explanation:
(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.
 

Constraints:

3 <= nums.length <= 200
0 <= nums[i] <= 200
1 <= diff <= 50
nums is strictly increasing.

*/

#include <bits/stdc++.h>
using namespace std;
int arithmeticTriplets(vector<int>& nums, int diff) {
        int count=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            // cout<<count<<endl;
            int r=nums[i]+diff;
            int j=-1;
            if(binary_search(nums.begin()+i+1, nums.end(),r)){
                j=lower_bound(nums.begin()+i+1, nums.end(),r)-nums.begin();
            }
            else{
                continue;
            }
            if(j==n){
                continue;
            }
            int m=-1;
            if(binary_search(nums.begin()+j+1, nums.end(),r+diff)){
                m=lower_bound(nums.begin()+j+1, nums.end(), nums[j]+diff)-nums.begin();
            }
            else{
                continue;
            }
            
            if(m==n){
                continue;
            }
            count++;
        }
        return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0; i<n; i++){
            cin>>nums[i];
        }
        int diff;
        cin>>diff;
        cout<<arithmeticTriplets(nums,diff)<<endl;
    }
}