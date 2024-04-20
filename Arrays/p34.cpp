//Merge sorted arrays without using extra space 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute();//simple merge algorithm as in mergesort using an extra temp array and copying back elements to the original array 
void better();
void optimal(vector<long long> &a, vector<long long> &b){
	int n = a.size();
	int m = b.size();
	int left = n-1;
	int right = 0;
	while(left>=0&&right<m){
		if(a[left]>b[right]){
			swap(a[left],b[right]);
			left--;right++;
		}
		else{
			break;
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
}

int main()
{
    vector<int> a = {};
    vector<int> b = {};
    optimal(a,b);
    return 0;
}