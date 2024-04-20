#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int> a, int s)
{
    int length = 0;
    int n = a.size();
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];
            if(sum==s){
                length = max(length, j-i+1);
            }
        }
    }
    return length;
}
int better(vector<int> a, int sum){
    map<int,int> presummap;
    
    
}
int optimal(vector<int> a, int k){
    int n = a.size();
    int left = 0;
    int right = 0;
    int sum = a[0];
    int maxLen = 0;
    while(right<n){
        while(left<=right&&sum>k){
            sum -=a[left++];
        }
        if(sum==k){
            maxLen = max(maxLen,right-left+1);  
        }
        right++;
        if(right<n){
            sum+=a[right];
        }
    }
    return maxLen;
}
int main()
{
    vector<int> v = {1,2,3,4,1,2};
    int ans = optimal(v,4);
    cout<<ans;
    return 0;
}