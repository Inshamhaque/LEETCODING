#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void optimal(vector<int> a){
    int n = a.size();
    int count;
    for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){
            count++;
        }
    }
    if(a[n-1]>a[0]){
        count++;
    }
    if(count<=1){
        cout<<"yes it is sorted and rotated";
    }
    else{
        cout<<"it is unsorted";
    }
}
int main()
{
    vector<int> a = {3,4,5,1,2};
    optimal(a);
    return 0;
}