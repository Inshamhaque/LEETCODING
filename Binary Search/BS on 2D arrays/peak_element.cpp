#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute();
int better(vector<int> &nums){
    int n = nums.size();
    //if size is 1 
    if(n==1){
        return 0;
    }
    //checking 
    if(nums[0]>nums[1]){
        return 0;
    }
    if(nums[n-1]>nums[n-2]){
        return n-1;
    }
    //check for element between 1->n-2
    for(int i=1;i<n-1;i++){
        if(nums[i]>nums[i+1]&&nums[i]<nums[i-1]){
            return i;
        }
    }
    return -1;
}
int optimal(vector<int>&nums ){
    int n =nums.size();
    if(n==1){
        return 0;
    }
    if(nums[0]>nums[1]){
        return 0;
    }
    if(nums[n-1]>nums[n-2]){
        return n-1;
    }
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
            return mid;
        }
        //if mid lies on the increasing side
        else if(nums[mid]>nums[mid-1]&&nums[mid]<nums[mid+1]){
            low = mid+1;
        }
        //if mid lies on the decreasing side and if there are multiple peaks
        else{
            high  = mid-1;
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {1,4,3,6,5};
    cout<<"the peak element index is: "<< better(nums)<<endl; 
    cout<<"the peak element index is: "<< optimal(nums); 
    return 0;
}