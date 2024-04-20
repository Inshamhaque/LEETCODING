//Minimum element in a sorted rotated array using binary search 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int optimal(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high =  n-1;
        int element = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            //left part is sorted 
            if(nums[low]<=nums[mid]){
                element = min(element,nums[low]);
                low = mid+1;
            }
            else{
                element = min(element,nums[mid]);
                high = mid-1;
            }
        }
        return element;
    }
int main()
{
    vector<int> nums= {4,5,1,2,3,3};
    cout<<"minimum element is:  "<<optimal(nums);
    return 0;
}