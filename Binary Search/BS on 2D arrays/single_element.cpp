#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int better(vector<int> &nums){
    int n = nums.size();
    //if size is 1
    if(n==1){
        return nums[0];
    }
    //starting and ending element to check 
    if(nums[0]!=nums[1]){
        return nums[0];
    }
    if(nums[n-1]!=nums[n-2]){
        return nums[n-1];
    }
    //checking other within elements 
    for(int i=1;i<n-1;i++){
        if(nums[i]!=nums[i+1]&&nums[i]!=nums[i-1]){
            return nums[i];
        }
    }
    return -1;
}
int optimal(vector<int> &nums){
    int n = nums.size();
    if(n==1){
        return nums[0];
    }
    //checking first and last element 
    if(nums[0]!=nums[1]){
        return nums[0];
    }
    if(nums[n-1]!=nums[n-2]){
        return nums[n-1];
    }
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]){
            return nums[mid];
        }
        //eliminate left half
        if((mid%2==1&&nums[mid]==nums[mid-1])||(mid%2==0&&nums[mid]==nums[mid+1])){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {1,1,2,3,3,4,4,5,5};
    cout<<"single element is:   "<<better(nums)<<endl;
    cout<<"single element is:   "<<optimal(nums);
    return 0;
}