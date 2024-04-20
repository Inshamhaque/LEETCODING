#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int> arr){//TC-> O(n) , SC-> 
    int n = arr.size();
    int max = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            cnt +=1;
        }
        if(arr[i]!=1&arr[i+1]==1){
            if(max<cnt){
                max = cnt;
            }
            
            cnt = 0;
        }
    }
    if(max>cnt){
        return max;
    }
    return cnt;
}
int main()
{
    vector<int> arr = {1,1,1,0,0,0,1,1,0,1};
    int ans = brute(arr);
    cout<<"The maximum number of consecutive ones is: "<<ans;
    return 0;
}