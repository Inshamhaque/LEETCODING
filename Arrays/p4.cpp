//remove duplicates from sorted array and return the number of unique elements 
#include<iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
void bruteforce(int* arr, int &n){ //O(n^3)
    for(int i=0;i<n;i++)
    {
        int temp = arr[i];
        for(int j=i+1;j<n;j++){
            if(temp==arr[j])
            {
                for(int k=j;k<n;k++)
                {
                    arr[k] = arr[k+1];
                }
                n--;
                j--;
            }
            
        }
    }
}
int better(int* arr, int n){
    stack<int> s;
    for(int i=0;i<n;i++){
        if(arr[i]!=s.top()){
            s.push(arr[i]);
        }
    }
    //inserting unique elements into the array
    int index = 0;
    while(s.size()!=0){
        arr[index++] = s.top();
        s.pop();
    }
    n = index;
    return n;
}
int optimal(int *arr, int n){
    int i=0;
    for(int j=0;j<n;j++){
        if(arr[i]!=arr[j]){
            arr[i+1] = arr[j];
            i++;        
        }
    }
    return i+1;
}
void traversal(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[10] = {1 ,2 ,2 ,3 ,3 ,3 ,4 ,4 ,5 ,5 };

    int n = sizeof(arr)/sizeof(arr[0]); 
    n = optimal(arr,n);
    traversal(arr,n);
    return 0;
}