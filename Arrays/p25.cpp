//Rotate matrix by 90
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void traversal(vector<vector<int>>a ){
    for(auto it:a){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
void brute(vector<vector<int>> &a){
	int m = a.size();
	int n = a[0].size();
	vector<vector<int>> demo(n,vector<int>(m));
	int column = m-1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			demo[j][column] = a[i][j];
		}
		column--;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			a[i][j] = demo[i][j];
		}
	}
	return;
	
}
void better(vector<vector<int>> &a){//TC-> O(n/2*n/2) + O(n*n/2)|
    int m = a.size();
    int n = a[0].size();
    //transposing the matrix
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(a[i][j],a[j][i]);
        }
    }
    //reversing each row 
    for(int i=0;i<m;i++){
        reverse(a[i].begin(),a[i].end());
    }
    
}
void optimal();

int main()
{
    vector<vector<int>> a = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    //traversal(a);
    better(a);
    traversal(a);
    return 0;
}