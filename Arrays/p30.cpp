#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> brute(vector<int> a){
    int n = a.size();
    vector<vector<int>> ans;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int left = i+1;
        int right = n-1;
        while(left<right){
            int sum = a[i]+a[left]+a[right];
            if(sum>0){
                right--;
            }
            else if(sum<0){
                left++;
            }
            else{
                while(left<right && a[left] == a[left+1]){
                    left++;
                }
                while(left<right && a[right] == a[right-1]){
                    right--;
                }
                auto it = find(ans.begin(),ans.end(),vector<int>{a[i],a[left],a[right]});
                if(it == ans.end()){
                     ans.push_back({a[i],a[left],a[right]});
                }
                left++;
                right--;
            }
        }
    }
    return ans;
}
// vector<vector<int>> better(vector<int> v){
//     int n = v.size();
//     set<vector<int>> st;
//     for(int i=0;i<n;i++){
//         set<int> hashset;
//         for(int j=i+1;j<n;j++){
//             int third = -(v[i]+v[j]);
//             if(hashset.find(third)!=hashset.end()){
//                 vector<int> temp = {arr[i],arr[j],third};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
                
//             }
//             hashset.insert(v[j]);
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }
vector<vector<int>> optimal(vector<int> &a)
{
    int n = a.size();
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1]){
            continue;
        }
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = a[i]+a[j]+a[k];
            if(sum>0){
                k--;
            }
            else if(sum<0){
                j++;
            }
            else{
                vector<int> temp = {a[i],a[j],a[k]};
                auto it = find(ans.begin(),ans.end(),temp);
                if(it==ans.end()){//element not found
                    ans.push_back(temp);
                }
                j++;
                k--;
            }
        }
    }
    return ans;

}
void traversal(vector<vector<int>> a){
    for(auto it:a){
        for(auto c : it){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    vector<int> q = {-1,-1,2,0,1};
    vector<vector<int>> ans = optimal(q);
    traversal(ans); 
    return 0;
}