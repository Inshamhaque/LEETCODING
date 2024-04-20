//Second largest element in an array
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int bruteforce(int *arr, int n)
{ //sorting and then finding --> O(nlogn+n)
    sort(arr,arr+n);
    int largest = arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]!=largest){
            return arr[i];
        }
    }
}
int better(int* arr, int n){
    //using two passes -> O(n+n)
    int largest = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    int s_largest = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<largest&&arr[i]>s_largest){
            s_largest = arr[i];
        }
    }
    return s_largest;
}
int optimal(int* arr, int n){
    //using single pass-> O(n)
    int largest = arr[0];
    int s_largest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            s_largest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>s_largest){
            s_largest = arr[i];
        }
    }
    return s_largest;
}
int main()
{
    int arr[7] = {1,3,7,4,7,6,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = optimal(arr,n);
    cout<<"second largest element is: "<<ans;
    return 0;
}