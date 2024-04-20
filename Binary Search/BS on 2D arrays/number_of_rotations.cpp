#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int optimal(vector<int> &nums){
    int n = nums.size();
        int low = 0;
        int high =  n-1;
        int element = INT_MAX;
        int  k = -1;
        while(low<=high){
            int mid = (low+high)/2;
            //left part is sorted 
            if(nums[low]<=nums[mid]){
                element = min(element,nums[low]);
                if(element==nums[low]){
                    k = low;
                }
                low = mid+1;
            }
            else{//rt part is sorted
                element = min(element,nums[mid]);
                if(element==nums[mid]){
                    k = mid;
                }
                high = mid-1;
            }
        }
        return k;
}
int main()
{
    vector<int> v = {3,4,5,1,2};
    cout<<"The number of rotations is : "<<optimal(v);
    return 0;
}