#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a ={1,2,1,3,4,3,2};
    int k = 3;
    int n = a.size();
    map<int,int> mpp;
    mpp[0] = 1;
    int presum = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        presum += a[i];
        int rem = presum-k;
        //if element found 
        if(mpp.find(rem)!=mpp.end()){
            count+=mpp[rem];
        }
        mpp[presum]++;
    }
    cout<<count<<endl;

}