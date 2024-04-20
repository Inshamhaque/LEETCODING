//to find the missing and repeating elements 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute();
vector<int> better(vector<int> a){
    int n = a.size();
    //declaring a hasharray
    int hasharray[n+1] = {0};
    for(int i=0;i<n;i++){
        hasharray[a[i]]++;
    }
    int missing = -1;
    int repeating = -1;
    for(int i=1;i<=n;i++){
        if(hasharray[i]==2){
            repeating  = i;
        }
        else if(hasharray[i]==0){
            missing = i;
        }
        if(missing!=-1&&repeating!=-1){
            break;
        }
    }
    return {repeating,missing};
}
vector<int>  optimal(vector<int> a){
    long long n = a.size();
    long long Sn, S2n;
    Sn = (n*(n+1))/2;
    S2n = (n*(n+1)*(2*n+1))/6;
    long long S=0,S2=0;
    for(int i=0;i<n;i++){
        S+=a[i];
        S2+=(long long)a[i]*(long long)a[i];
    }
    long long val1 = S-Sn;
    long long val2 = S2-S2n;
    long long val3 = val2/val1;
    long long repeating = (val1+val3)/2;
    long long missing = repeating - val1;
    return{(int)repeating,(int)missing};
}
 
void traversal(vector<int> a){
    for(auto it:a){
        cout<<it<<" ";
    }
}
int main()
{
    vector<int> a = {1,2,2,3,5};
    vector<int> ans = optimal(a);
    traversal(ans);
    return 0;
}