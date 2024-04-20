//Left rotate by D places 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute(int* arr, int n, int D)//O(D*n)  
   {
    D = D%n;
    for(int i=0;i<D;i++){
        int temp = arr[0];
        for(int i=1;i<n;i++){
            arr[i-1] = arr[i];
        }
        arr[n-1] = temp;
    }
}
void better(int* arr, int n, int k){
    int temp[k];
    k = k%n;
    for(int i=0;i<=k;i++){
        temp[i] = arr[i];
    }
    //shifting 
    for(int i=k;i<n;i++){
        arr[i-k] = arr[i];
    }
    //storing else
    for(int i=n-k;i<n;i++){
        arr[i] = temp[i-(n-k)];
    }
}
void optimal(int* arr, int n, int k)
{
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
}
void rtr_o(int* arr, int D, int n){
    D = D%n;
    reverse(arr,arr+n);
    reverse(arr+D,arr+n);
    reverse(arr,arr+n);
}
void traversal(int* arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
} 
int main()
{
    int arr[6] = {1,2,3,4,5,6}; //6 1 2 3 4 5 -> 1 6 5 4 3 2 -> 2 3 4 5 6 1  
    int n = sizeof(arr)/sizeof(arr[0]);
    rtr_o(arr,13,n);
    traversal(arr,n);
    return 0;
}