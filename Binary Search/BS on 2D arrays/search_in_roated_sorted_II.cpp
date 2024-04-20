#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int> v, int target){//linear search 
    int n = v.size();
    int index;
    for(int i=0;i<n;i++){
        if(v[i]==target){
            return i;
        }
    }
    return -1;
}
bool optimal(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid =(low+high)/2;
            if(nums[mid]==target){//element found 
                return true;
            }
            if(nums[mid]==nums[low]&&nums[mid]==nums[high]){//shrinking search space
                low++;
                high--;
                continue;
            }
            //right part sorted 
            if(nums[high]>=nums[mid]){
                if(nums[mid]<target&&nums[high]>=target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            else{//lt part sorted
                if(nums[mid]>target&&nums[low]<=target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return false;
    }
int main()
{
    vector<int> v = {3,5,6,1,2,2,3,3};
    cout<<"Brute force method : "<<brute(v,3)<<endl;
    cout<<"Optimal method : "<<optimal(v,3);
    return 0;
} 