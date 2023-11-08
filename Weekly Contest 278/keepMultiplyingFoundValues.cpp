#include <bits/stdc++.h>
using namespace std;

int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        while(binary_search(nums.begin(),nums.end(),original)){
            original*=2;
        }
        return original;
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
        int original; cin>>original;
        cout<<findFinalValue(nums,original)<<endl;
    }
}