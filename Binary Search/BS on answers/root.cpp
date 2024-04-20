//to find root of a number using binary search :-> 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute();
void better();
int optimal(int n){
    int low = 1;
    int high = n;
    int ans = 1;
    while(low<=high){
        long long mid = (low+high)/2;
        long long val = mid*mid;
        if(val<=n){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int main()
{
    cout<<"root of "<<28<<" is "<<optimal(28); 
    return 0;
}