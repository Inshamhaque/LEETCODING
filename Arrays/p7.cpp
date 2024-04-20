//moving zeroes to end
#include<iostream>
using namespace std;
void brute(int* arr, int n){
    int* temp;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp[i] = arr[i];
            cnt ++;
        }
    }
}
void better(int* arr, int n){
    int start = 0;
    int end = n-1;
    while(start<=end){
        if(arr[start] == 0){
            if(arr[end]==0){
                end--;
            }
            swap(arr[start],arr[end]);
            end--;
        }
        start++;
    }
}
void optimal(int* arr, int n){
    int i=0;
    int j = 1;
    while(i<j&&j<n){
        if(arr[i]==0&&arr[j]!=0){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
        else if(arr[i]==0 && arr[j]==0){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
}
void traversal(int* arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[10] = {1,0,2,3,2,0,0,4,5,1}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    optimal(arr,n);
    traversal(arr,n);
    return 0;
}