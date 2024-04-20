//Sorting array of 0's,1's and 2's
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> brute(vector<int> a){
    //by using mergesort 

}
void traversal(vector<int> a){
    int size = a.size();
    for(int i=0;i<size;i++){
        cout<<a[i];
    }
    cout<<endl;
}
vector<int> better(vector<int> a){
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    int n=a.size();
    //counting the nums of 0,1 & 2 <-:->
    for(int i=0;i<n;i++){
        if(a[i]==0){
            cnt0++;
        }
        else if(a[i]==1){cnt1++;}
        else {cnt2++;}
    }
    //placing the elements into the array by finalising <-:->
    int i=0;       
    while(cnt0!=0){
        a[i] = 0;
        i++;
        cnt0--;
    }
    while(cnt1!=0){
        a[i] = 1;
        i++;
        cnt1--;
    }
    while(cnt2!=0){
        a[i] = 2;
        i++;
        cnt2--;
    }
    traversal(a);
}
void optimal(vector<int> a){//TC -> O(N) SC-> O(1)
    int n  = a.size();
    //Dutch National Flag Algorithm(DNF) 
    int low  = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(a[mid]==0){
            swap(a[mid],a[low]);
            mid++;
            low++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else{
            swap(a[mid],a[high]);
            high--;
        }
    }
    traversal(a);
}
int main()
{
    vector<int> a = {1,0,2,0,1,0,2};
    optimal(a);                                 
    return 0;
}