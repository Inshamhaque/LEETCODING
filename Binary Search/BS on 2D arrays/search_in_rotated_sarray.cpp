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
int optimal(vector<int> v, int target){
    int n = v.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid]==target){
            return mid;
        }
        //checking for sorted halves 
        //if lt half found 
        else if(v[low]<v[mid]){
            if(v[low]<=target&&v[mid]>=target){//element lies in the sorted half
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }
        //if right half is sorted 
        else{
            if(v[mid]<=target&&v[high]>=target){//element lies in the sorted half
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> v = {4,5,6,0,1,2,3};
    cout<<"Brute force method : "<<brute(v,0)<<endl;
    cout<<"Optimal method : "<<optimal(v,0);
    return 0;
}