//variety2 -> when pos>neg or neg>pos
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int> a){//TC -> O(n)+O(n1+n2)+O(n1)+O(n2) SC-> O(n)
    int n = a.size();
    vector<int> pos;
    vector<int> neg;
    int i=0;
    for(auto it:a){
        if(it>=0){
            pos.push_back(it);
        }
        else{
            neg.push_back(it);
        }
    }
    int k = 0;//for non-negative numbers
    int l = 0;//for negative numbers
    int n1 = pos.size();
    int n2 = neg.size();
    //retreiving elements at odd & even position
    while(k<n1 && l<n2){
        a[i++] = pos[k++];
        a[i++] = neg[l++];
    }
    //retreiving remaining elements
    while(k<n1){
        a[i++] = pos[k++];
    }
    while(l<n2){
        a[i++] = neg[l++];
    }
    return a;
}
void traversal(vector<int> a){
    for(auto it:a){
        cout<<it<<" ";
    }
}
//requires improvement ... some errors are there ...
void better(vector<int> a){
    int n = a.size();
    vector<int> pos;
    vector<int> neg;
    for(auto it: a){
        if(it>=0){
            pos.push_back(it);
        }
        else{
            neg.push_back(it);
        }
    }
    int n1 = pos.size();
    int n2 = neg.size();
    if(n1>n2){
        for(int i=0;i<n2;i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int rem = neg.size();
        for(int i=rem;i<n1;i++){
            a[i] = pos[i];
        }
    }
    else{
        for(int i=0;i<n1;i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int rem = pos.size();
        for(int i=0;i<n2;i++){
            a[i] = neg[i];
        }
    }
    return a;
}
void optimal();
int main()
{
    vector<int> a = {1,-1,2,-2,3,-3,4,5};
    vector<int> ans = optimal(a);
    traversal(ans);
    return 0;
}        