//Alternately arrange elements in an array by sign 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int> arr){//TC-> O(n) + O(n/2) + O(n/2) , SC-> O(n/2) + O(n/2)
    int n = arr.size();
    vector<int> positives;
    vector<int> negatives;
    //pushing elements into positives and negatives 
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            negatives.push_back(arr[i]);
        }
        else{
            positives.push_back(arr[i]);
        }
    }
    //retreiving back elements 
    for(int i=0;i<positives.size();i++){
        arr[2*i] = positives[i];
    }
    for(int i=0;i<negatives.size();i++){
        arr[2*i+1] = negatives[i];
    }
    return arr;
}
vector<int> better(vector<int> arr){//TC-> O(n) SC-> O(n)
    int n = arr.size();
    vector<int> res(n);
    //even -> 2*k //odd-> 2*l+1
    int k = 0;
    int l = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            res[2*l+1] = arr[i];
            l++;
        }
        else{
            res[2*k]= arr[i];
            k++;
        }
    }
    return res;
}
void optimal();
void traversal(vector<int> ans){
    for(auto it:ans){
        cout<<it<<" ";
    }
}
int main()
{
    vector<int> a  = {1,2,-3,-1,-2,3};
    vector<int> ans = brute(a);
    traversal(ans);
    return 0;
}