//left rotate an array
#include<iostream>
using namespace std;
void ltr(int* arr, int n){
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}
void rtr(int* arr, int n){
    int temp = arr[n-1];
    for(int i=0;i<n-1;i++)
    {
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
}
void traversal(int* arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[5] = {3,4,5,6,1}; //{4,5,6,1,3}}
    int n = sizeof(arr)/sizeof(arr[0]); 
    ltr(arr,n);
    traversal(arr,n);
    rtr(arr,n);
    traversal(arr,n);
    return 0;
}