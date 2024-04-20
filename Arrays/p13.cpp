#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int> arr){//TC-> O(N^2),SC->O(1)
    int n = arr.size();
    for(int i=1;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                count++;
            }
        }
        if(count==1){
            return i;
        }
    }
}
int better(vector<int> arr){
    int n = arr.size();
	int max = 0;
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	int hasharray[max+1] = {0};
	for(int i=0;i<n;i++){
		hasharray[arr[i]]++;
	}
	for(int i=1;i<=max;i++){
		if(hasharray[i]==1){
			return i;
		}
	}
}
int optimal(vector<int> arr){
    int xorr= 0;
    for(int i=0;i<arr.size();i++){
        xorr= xorr^arr[i];
    }
    return xorr;
}
int main()
{
    vector<int> a = {8,8,9,9,10,10,11};
    int ans = optimal(a);
    cout<<"element with single occurence is:  "<<ans;
    return 0;
}