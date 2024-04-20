//best time to buy and sell stocks (you cant sell without buying first)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int> a){//SC-> O(1) TC-> O(n)
    int n = a.size();
    int left = 0;
    int right = n-1;
    int maximum = INT_MIN;
    int profit = a[right]-a[left];
    while(left<=right){
        profit = a[right]-a[left];
        maximum=max(maximum,profit);
        if(a[left]>a[right]){
            right--;
        }
        else{
            left++;
        }
    }
    return maximum;
}
int optimal(vector<int> a){//TC-> O(n) SC-> O(1)
    int maximum = INT_MIN;
    int profit = 0;
    int minimum = a[0];
    int n = a.size();
    for (int i = 0; i < n; i++) {
      profit = a[i] - minimum;
      maximum = max(profit, maximum);
      minimum = min(a[i], minimum);
    }
    return maximum;
}
void optimal();
int main()
{
    vector<int> a  = {17,20,11,9,12,6};
    int ans = optimal(a);
    cout<<ans;
    return 0;
}