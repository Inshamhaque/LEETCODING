//Max sum of a subarray 
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
long long brute(vector<int> a, int n){
    long long maximum  = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            long long sum = 0;
            for(int k=i;k<n;k++){
                sum+=a[k];
            }
            maximum = max(maximum ,sum);
        }
    }
    return maximum;
}
long long better(vector<int> a, int n){
    long long maximum = INT_MIN;
    for(int i=0;i<n;i++){
        long long sum = 0;
        for(int j=i;j<n;j++){
            sum+=a[j];
        }
        maximum = max(sum,maximum);
    }
    return  maximum;
}
long long optimal(vector<int> a, int n){//TC -> O(n)  SC-> O(1)
    long long maximum = INT_MIN;
    long long sum = 0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum<0){
            sum = 0;
        }
        maximum = max(sum,maximum);
    }
    return maximum;
}
vector<int> array(vector<int> a, int n){
    long long maximum = INT_MIN;
    long long sum = 0;
    int ansStart = -1;
    int ansEnd = -1;
    for(int i=0;i<n;i++){
        int start;
        if(sum==0){
            start  = i;
        }
        sum+=a[i];
        if(sum<0){
            sum = 0;
        }
        maximum = max(sum,maximum);
        if(sum>maximum){
            ansStart = start;
            ansEnd = i;
        }
    }
    vector<int> ans;
    int j=0;
    for(i=ansStart;i<=ansEnd;i++){
        ans[j++]= a[i];
    }
    return ans;

}
int main()
{
    vector<int> a = {10,-30,40,-50,};
    int n = a.size();
    vector<int> ans = array(a,n);
    cout<<ans;
    return 0;
}