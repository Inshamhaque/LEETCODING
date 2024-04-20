//set Matrix zero ie set rows and columns of the cell which contains zero
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> brute(vector<vector<int>> a, int m, int n){//TC-> O(nm+m+n+mn), SC-> O(1)
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0){
                for(int k=0;k<m;k++){
                    if(a[k][j]!=0){
                        a[k][j] = -1;
                    }
                }
                for(int b=0;b<n;b++){
                    if(a[i][b]!=0){
                        a[i][b] = -1;
                    }
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==-1){
                a[i][j] = 0;
            }
        }
    }
    return a;
}
vector<vector<int>> better(vector<vector<int>> a, int m, int n){//TC-> O(2mn), SC-> O(m+n)
    vector<bool> zeroRow(m,false); 
    vector<bool> zeroColumn(n,false); 
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0){
                zeroRow[i] = true;
                zeroColumn[j] = true;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(zeroRow[i]==1||zeroColumn[j]==1){
                a[i][j]=0;
            }
        }   
    }
    return a;
}
vector<vector<int>> optimal(vector<vector<int>> a){
    
}
void traversal(vector<vector<int>> a){
    for(auto it:a){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    vector<vector<int>> a = {{1,0,1},
                             {1,1,1},
                             {1,1,1}
                            };  
    cout<<"original matrix:   "<<endl;
    traversal(a);
    cout<<endl;
    int m = a.size();
    int n = a[0].size();  // Assuming all rows have the same number of columns
    vector<vector<int>> ans = better(a, m, n);
    traversal(ans);k
    return 0;
}
