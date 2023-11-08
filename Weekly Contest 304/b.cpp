/*Maximum Number of Groups Entering a Competition
User Accepted:7531
User Tried:8404
Total Accepted:7902
Total Submissions:13029
Difficulty:Medium
You are given a positive integer array grades which represents the grades of students in a university. You would like to enter all these students into a competition in ordered non-empty groups, such that the ordering meets the following conditions:

The sum of the grades of students in the ith group is less than the sum of the grades of students in the (i + 1)th group, for all groups (except the last).
The total number of students in the ith group is less than the total number of students in the (i + 1)th group, for all groups (except the last).
Return the maximum number of groups that can be formed.

 

Example 1:

Input: grades = [10,6,12,7,3,5]
Output: 3
Explanation: The following is a possible way to form 3 groups of students:
- 1st group has the students with grades = [12]. Sum of grades: 12. Student count: 1
- 2nd group has the students with grades = [6,7]. Sum of grades: 6 + 7 = 13. Student count: 2
- 3rd group has the students with grades = [10,3,5]. Sum of grades: 10 + 3 + 5 = 18. Student count: 3
It can be shown that it is not possible to form more than 3 groups.
Example 2:

Input: grades = [8,8]
Output: 1
Explanation: We can only form 1 group, since forming 2 groups would lead to an equal number of students in both groups.
 

Constraints:

1 <= grades.length <= 105
1 <= grades[i] <= 105*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mid, vector<int>& graded, int n){
        int countPrev=1;
        int currSum=graded[0];
        int numGroups=1;
        int currNum=0;
        int r=0;
        int i=1;
        while(i<n){
            if(r>currSum && countPrev<currNum) {
                countPrev=currNum;
                currSum=r;
                numGroups++;
                r=0;
                currNum=0;
            }else{
                r+=graded[i];
                currNum++;
                i++;
            }

        }
        if(r>currSum && countPrev<currNum){
            numGroups++;
        }

        return numGroups>=mid;
    }

    int maximumGroups(vector<int>& grades) {
        int n=grades.size();
        sort(grades.begin(),grades.end());
       
        int low=1;
        int high=n/2+1;
        int ans=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(mid, grades,n)){
                low=mid+1;
                ans=mid;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> grades(n);
        for(int i=0; i<n; i++){
            cin>>grades[i];
        }
        cout<<maximumGroups(grades)<<endl;
    }
}


/*b1.cpp uses greedy approach to solve the following question, which is much better that this, though the time complexity for both the solution
is O(n log n) still greedy approach is better as we are not doing a binary search there


if the array is given sorted (not in this case)
1) greedy will give solution in O(n)
2) Binary search will still take O(n log n)

so it's good if you refer to the code b1.cpp in the same folder of contest 304

*/