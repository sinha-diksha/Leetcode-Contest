#include <bits/stdc++.h>
using namespace std;

bool checkValid(vector<vector<int>>& matrix) {
        vector<unordered_map<int,bool> > row;
        vector<unordered_map<int,bool> > col;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                row[i][matrix[i][j]]=true;
            }
        }
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                col[i][matrix[i][j]]=true;
            }
        }
        bool rowTrue=true;
        bool colTrue=true;
        for(int i=0; i<n; i++){
            unordered_map<int,bool> mp=row[i];
            for(int j=1; j<=n; j++){
                if(mp.count(j)==0){
                    rowTrue=false;
                    break;
                }
            }
            if(rowTrue==false){
                break;
            }
        }
        for(int i=0; i<m; i++){
            unordered_map<int,bool> mp=col[i];
            for(int j=1; j<=n; j++){
                if(mp.count(j)==0){
                    colTrue=false;
                    break;
                }
            }
            if(colTrue==false){
                break;
            }
        }
        return (rowTrue && colTrue);
}