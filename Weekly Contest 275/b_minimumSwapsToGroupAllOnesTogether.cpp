/*Minimum Swaps to Group All 1's Together II

A swap is defined as taking two distinct positions in an array and swapping the values in them.


Given array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

example:
i/p =  10101
o/p= 1

*/

#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>& nums){
    int numOnes=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]==1){
            numOnes++;
        }
    }
    if(numOnes==0 || numOnes==1){
        return 0;
    }
    int count=0;
    for(int i=0; i<numOnes; i++){
        if(nums[i]==0){
            count++;
        }
    }
    int ans=count;
    for(int i=numOnes; i<nums.size(); i++){
        if(nums[i]==0){
            count++;
        }
        if(nums[i-numOnes]==0){
            count--;
        }
        ans=min(count,ans);
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
        cout<<minSwaps(v)<<endl;
    }
}