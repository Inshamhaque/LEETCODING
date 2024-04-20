//Binary Search 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int iterative(vector<int> a, int element){
    int n = a.size();
    int low = 0;
    int high=  n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(mid<element){
            low = mid+1;
        }
        else if(mid>element){
            high = mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int recursive(vector<int> a, int element, int low, int high){
    //base condition
    if(low>high){
        return -1;
    }
    int mid = (low+high)/2;
    if(a[mid]==element){
        return mid;
    }
    else if(a[mid]>element){
        return recursive(a,element,low,mid-1);
    }
    else{
        return recursive(a,element,mid+1,high);
    }
    

}
void optimal();
int main()
{
    vector<int> a = {-1,0,3,4,9,20};
    // int ans = iterative(a,9);
    int ans = recursive(a,1,0,6);
    cout<<"it is at position: "<<ans;
    return 0;
}