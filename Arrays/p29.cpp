//to find the majority elements - II
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int> v){
    int n = v.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=i+1;j<n;j++){
            if(v[i] == v[j]){
                count++;
            }
        }
        if(count>floor(n/3)){
            ans.push_back(v[i]);
            auto it = find(ans.begin(),ans.end(),v[i]);
            if(it==ans.end()){//element not found 
                ans.push_back(v[i]);
            }
        }
    }
    return ans;
}
vector<int> better(vector<int> v){//TC-> O(n)|SC-> O(n)
    map<int,int> mpp;
    vector<int> ans;
    int n=v.size();
    for(int i=0;i<n;i++){
        mpp[v[i]]++;
        if(mpp[v[i]]>floor(n/3)){
            ans.push_back(v[i]);
        }
    }
    return ans;
}
vector<int> optimal(vector<int> v){
    int n = v.size();
    int cnt1 = 0, cnt2 = 0;
    int el1, el2;

    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != v[i]) {
            cnt1++;
            el1 = v[i];
        } else if (cnt2 == 0 && el1 != v[i]) {
            cnt2++;
            el2 = v[i];
        } else if (el1 == v[i]) {
            cnt1++;
        } else if (el2 == v[i]) {
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ans;
    int cnt_1 = 0;
    int cnt_2 = 0;

    for (int i = 0; i < n; i++) {
        if (el1 == v[i]) {
            cnt_1++;
        }
        if (el2 == v[i]) {
            cnt_2++;
        }
    }

    if (cnt_1 >= floor(n / 3)) {
        ans.push_back(el1);
    }

    if (cnt_2 >= floor(n / 3)) {
        ans.push_back(el2);
    }

    return ans;
}
void traversal(vector<int> v){
    for(auto it:v){
        cout<<it<<" ";
    }
}
int main()
{
    vector<int> v = {2,2,3,3,2,3};
    vector<int> ans = optimal(v);
    traversal(ans);
    return 0;
}