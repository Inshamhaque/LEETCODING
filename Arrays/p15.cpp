#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string brute(int n, vector<int> book, int target)
{
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if((book[i] + book[j]) == target){
                return "yes";
            }
        }
    }
    return "no";
}
string better(int n,vector<int> book, int target){
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int a = book[i];
        int rem = target-a;
        if(mpp.find(rem)!=mpp.end()){
            cout<<"YEs, at index:   "<<i<<","<<mpp[a]<<endl;
            return "YES";
        }
        mpp[a] = i;
    }
    return "NO";
}
string optimal(int n, vector<int> book, int target){
    sort(book.begin(),book.end());
    int left = 0;
    int right = 0;
    while(left<right){
        int ans = book[left]+ book[right];
        if(ans==target){
            return "Yes";
        }
        if(ans>target){
            right--;
        }
        else{
            left ++;
        }
    }
    return "NO";
    
}
int main(){
    int n=5;
    vector<int> book={1,2,4,3,5};
    string ans = optimal(n,book,5);
    cout<<ans;
}