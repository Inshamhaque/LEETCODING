//check if sorted or not
#include<iostream>
using namespace std;
int bruteforce(int* arr, int n){
    int flag = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>=arr[i-1]){
            flag =1 ;
        }
        else{
            flag = 0;
            break;
        }
        
    }
    if(flag==1){
        return 1;
    }
    return 0;
}
int main()
{
    int arr[7] = {1,2,3,8,9,2,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = bruteforce(arr,n);
    if(ans==1){
        cout<<"sorted!!!";
    }
    else
    {
        cout<<"unsorted";
    }
    return 0;
}