//Longest consecutive sequence
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int> a){//TC-> O(n^2); SC-> O(1)
    int n = a.size();
    int cnt;
    int largest = 1;
    for(int i=0;i<n;i++){
        cnt = 1;
        int el = a[i];
        while(find(a.begin(),a.end(),el+1)!=a.end()){
            cnt++;
            el++;
        }
        largest = max(largest,cnt);
    }
    return largest;
}
int better(vector<int> a){//distorting the array by sorting TC-> O(n), Sc-> O(1);
    int n = a.size();
    sort(a.begin(),a.end());
    int count = 1;
    int largest = 1;
    int el = a[0];
    for(int i=0;i<n;i++){
        if(a[i]==el+1){
            count++;
            el = a[i];
        }
        else if(el!=a[i]){
            count = 1;
            el = a[i];
        }
        largest = max(largest,count);
    }
    return largest;
}
int optimal(vector<int> a){//TC-> O(n+2n) SC-> O(n)
    int n = a.size();
    int largest = 1;
    unordered_set<int> st;
    //inserting all elements of vector into array
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }
    for(auto it:st){
        //if previous element does not exist then search for the sequence
        if(st.find(it-1)==st.end()){
            int cnt = 1;
            while(st.find(it+1)!=st.end()){
                it++;
                cnt++;
            }
            largest = max(largest,cnt);
        }
    }
    return largest;
}
int main()
{
    vector<int> a = {1,2,2,1};
    int ans = optimal(a);
    cout<<"largest consecutive sequence is:  "<<ans;
    return 0;
}