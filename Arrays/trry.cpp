#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int countKDifference(vector<int>& arr, int k) {
        int size = arr.size();
        int left = 0;
        int right = size-1;
        int count = 0;
        sort(arr.begin(),arr.end());
        while(left<=right){
            int diff = abs(arr[right]-arr[left]);
            if(diff>k){
                right--;
            }
            else if(diff<k){
                left++;
            }
            else{
                count++;
                left++;
            }
        }
        return count;
    }
int main(){
    vector<int> a= {1,2,2,1};
    int k = 1;
    int ans = countKDifference(a,k);
    cout<<ans;
}