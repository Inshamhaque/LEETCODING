//Number of sub-arrays with sum k in an array 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int> a, int k){//TC-> O(n^2) | SC-> O(1)
    int n = a.size();
    int count = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum==k){
                count++;
            }
        }
    }
    return count;
}
int optimal(vector<int> a, int k){//TC-> O(n*logn)|SC->O(n)
    map<int,int> mpp;
    mpp[0] = 1;
    int presum = 0;
    int count = 0;
    int n = a.size();
    for(int i=0;i<n;i++){
        presum += a[i];
        int rem = presum-k;
        if(mpp.find(rem)!=mpp.end()){
            count+=mpp[rem];
        }
        mpp[presum]++;
    }
    return count;
}
int main()
{
    vector<int> a = {1,2,1,3,4,3,2};
    int ans = optimal(a,3);
    cout<<"the number of sub-arrays are:  "<<ans;
    return 0;
}