//Number of subarrays with Sum k using xor
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector < int > a, int b) {
    int n = a.size();
    int count=0;
    for(int i=0;i<n;i++){
        int sum = a[i];
        if(sum==b){
            count++;
        }
        for(int j=i+1;j<n;j++){
            sum = sum ^ a[j]; 
            if(sum==b){
                count++;
            }
        } 
    }
    return count;
}
int optimal(vector<int> v, int target){//TC-> O(n) | SC-> O(n)
    int xr = 0;
    int n = v.size();
    int count = 0;
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        xr = xr^v[i];
        int x = xr^target;
        count+= mpp[x];
        mpp[xr]++;
    }
    return count;
}
int main()
{
    vector<int> v= {1,1,2,3,2};
    // int ans = optimal(v,2);
    // cout<<ans;
    int ans = 2^3;
    cout<<ans;
    return 0;
}
