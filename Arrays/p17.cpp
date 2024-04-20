//finding the majority element i.e element with freq greater than n/2
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int> v){
    int n = v.size();
    int cnt;
    for(int i=0;i<n;i++){
        cnt = 0;
        for(int j = i;j<n;j++){
            if(v[i]==v[j]){
                cnt++;
            }
        }
        if(cnt > (n / 2)){
            return v[i];
        }
    }
}
int better(vector<int> v){ //TC-> O(NlogN) as ordered map takes logN time for its operation + O(N) [traversal through map] 
                          // |  SC->O(N) in the worst case scenario 
    
    map<int,int> mpp;
    int n = v.size();
    // map has key -> the element ; value -> count of the element  
    for(int i=0;i<n;i++){
        mpp[v[i]]++;
    }
    //traversing through the map
    for(auto it:mpp){
        if(it.second > (n/2)){
            return it.first;
        }
    }
    return -1;
}
int optimal(vector<int> v){
    //MOORE"S VOTING ALGORITHm
    int n = v.size();
    int cnt = 0;
    int majority;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt++;
            majority = v[i];
        }
        else if(majority == v[i]){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    cout<<"majority:  " << majority<<endl;
    int freq = 0;
    for(int i=0;i<n;i++){
        if(v[i]==majority){
            freq++;
        }
    }
    if(freq>n/2){
        return majority;
    }
    return -1;
}
int main()
{
    vector<int> v = {1,7,7,7,7,7,0,1,0};
    int ans = optimal(v);
    if(ans ==-1){
        cout<<"there is no majority element";
    }
    else{
        cout<<"Majority element:  "<<ans;
    }
    return 0;
}