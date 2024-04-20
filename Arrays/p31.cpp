//4 Sum Problem 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute();
vector<vector<int>> better(vector<int>& nums, int target) {//TC-> O(n^3) | SC-> O(n)
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long> hashset;
            for(int k=j+1;k<n;k++){
                long long sum = nums[i]+nums[j];
                sum += nums[k];
                long long fourth = target- (sum);
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int> temp = {nums[i],nums[j],nums[k],static_cast<int>(fourth)};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
vector<vector<int>> optimal(vector<int> v, int target){//TC-> O(n^3), SC-> O(1)
    int n = v.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        //skip duplicates
        while(i>0 && v[i]==v[i-1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            //skip duplicates 
            while(j>i+1 && v[j]==v[j-1]){
                continue;
            }
            int left = j+1;
            int right = n-1;
            while(left<right){
                int sum = v[i]+v[j]+v[left]+v[right];
                if(sum==target){
                    ans.push_back({v[i],v[j],v[left],v[right]});
                    while(left<right&&v[left]==v[left+1]){//skipping duplicates 
                        left++;
                    }
                    while(left<right&&v[right]==v[right-1]){//skipping duplicates 
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(sum>target){
                    right--;
                }
                else{
                    left--;
                }
            }

        }
    }
    return ans;
}
void traversal(vector<vector<int>>v){
    for(auto it:v){
        for(auto i:it){
            cout<<i<<" "; 
        }
        cout<<endl;
    }
}
int main()
{
    vector<int>v = {2,2,2,2,1,3};
    vector<vector<int>> ans = optimal(v,8);   
    traversal(ans);
    return 0;
}