// lower bound refers to the smallest index >= target element 
// upper bound refers to the smallest index > target element 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute();
int better(vector<int> arr, int target){
    int l_b = lower_bound(arr.begin(),arr.end(),target);
    return l_b;
}
int optimal(vector<int> arr , int target){
    int n = arr.size();
    int ans = n;
    int low = 0;
    int high  = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]<target){
            low = mid+1;
        }
        else if(arr[mid]>=target){
            ans = mid;
            high =  mid-1;
        }
    }
    return ans;
}
int main()
{
    vector<int> a = {1,2,3,5,6,7};
    int ans = better(a,90);
    cout<<"the lower bound is: "<<ans;
    return 0;
}