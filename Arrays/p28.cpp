//To print the pascal's triangle, find element and print entire row in a Pascal's triangle 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int nCr(int n, int r){//minimum time to find nCr i.e of time complexity just O(r)
    int ans = 1;
    for(int i=0;i<=r;i++){
        ans*=(n-i+1);
        ans/=(i+1);
    }
    return ans;
}
vector<vector<int>> printpascaltraingle(int n){
    vector<vector<int>> vect(n,vector<int>(n));
    for(int i=0;i<n;i++){
        vect[i].resize(i+1);
        vect[i][0] = vect[i][i] = 1;
        for(int j=1;j<i;j++){
            vect[i][j] = vect[i-1][j-1] + vect[i-1][j]; 
        }
    }
    return vect;
}
vector<int> printanyrow(int row){
    int el = 1;
    cout<<el<<" ";
    for(int i=1;i<row-1;i++){
        el*=(row-i);
        el/=i;
        cout<<el<<" ";
    }
    cout<<1;
}
int element(int row, int column){
    cout<<"element at row: "<<row<<" & column: "<<column<<" is: "<<nCr(row-1,column-1);
}
//matrix traversal 
void traversal(vector<vector<int>> a){
    for(auto it: a){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    //vector<vector<int>> ans = brute(7);
    //traversal(ans);
    // element(4,2);
    printanyrow(4);

    return 0;
}