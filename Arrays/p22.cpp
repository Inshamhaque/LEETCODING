//Leaders in an Array
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int> a){//TC -> O(n^2), SC-> O(n)
    int n = a.size();
    vector<int> leaders;
    for(int i=0;i<n;i++){
        int flag =1;
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                flag = 0;
                break;
            }
        }
        if(flag==1){
            leaders.push_back(a[i]);
        }
        
    }
    return leaders;
}
//void better();
vector<int> optimal(vector<int> a){
    int n = a.size();
    int max = INT_MIN;
    vector<int> leaders;
    for(int i=n-1;i>=0;i--){
        if(a[i]>max){
            max = a[i];
            leaders.push_back(a[i]);
        }
    }
    return leaders;
}
void traversal(vector<int> a){
    for(auto it:a){
        cout<<it<<" ";
    }
}
int main()
{
    vector<int> a = {1,12,3,4,10,9};
    vector<int> ans = optimal(a);
    traversal(ans);
    return 0;
}