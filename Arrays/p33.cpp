//Merge overlapping intervals
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> brute(vector<vector<int>> arr){//TC-> O(sorting)+ O(2n) , SC-> O(n)
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int start = arr[i][0];
        int end = arr[i][1];
        // if(!ans.empty()&&end<=ans.back()[1]){
        //     continue;
        // }
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end){
                end = max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}
vector<vector<int>> optimal(vector<vector<int>> a){//TC-> O(n) + O(sorting) | SC-> O(n)
    int n =a.size();
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        //if a new interval is to be added
        if(ans.empty()||ans.back()[1]<a[i][0]){
            ans.push_back(a[i]);
        }
        //expanding the interval
        else{
            ans.back()[1] = max(ans.back()[1],a[i][1]);
        }
    }
    return ans;
}
void traversal(vector<vector<int>> a){
    for(auto it:a){
        cout<<"["<<it[0]<<","<<it[1]<<"]"<<'\t';
    }
}
int main()
{
    vector<vector<int>> a = {{1,3},{2,4},{3,5},{6,7}};
    vector<vector<int>> b = optimal(a);
    traversal(b); 
    return 0;
}