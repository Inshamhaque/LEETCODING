//implement the ceil and floor function in O(logn) time 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute();
pair<int,int> better(vector<int> nums, int x){
    int low = 0;
	int high = n-1;
	int floor = -1;
	int ceil = -1;
	pair<int,int> ans;
	while(low<=high){
		int mid = (low+high)/2;
		if(a[mid]<x){
			floor = mid;
			low = mid+1;
		}
		else if(a[mid]>x){
			high = mid-1;
			ceil = mid;
    	} 
		else {
	          ceil = mid;
              floor = mid;
              return{x,x};
        }
    }
    int floorval = (floor!=-1)?a[floor]:-1;
    int ceilval = (ceil!=-1)?a[ceil]:-1;
	return{floorval,ceilval};
}
void optimal();
int main()
{
     
    return 0;
}