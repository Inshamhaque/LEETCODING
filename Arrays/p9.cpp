//Union & intersection of Two arrays
#include<set>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute(int* arr1,int*arr2, int n){
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<n;i++){
        st.insert(arr2[i]);
    }
    //reverting back
    int i=0;
    for(auto& j:st){
        arr1[i] = j;
    }

}
vector<int> optimal(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int i=0;
    int j=0;
    vector<int> c;
    while(i<n1&&j<n2){
        if(a[i]<=b[j]){
            if(c.size()==0||c.back()!=a[i]){
                c.push_back(a[i]);
            }
            i++;
        }
        else{
            if(c.size()==0||c.back()!=b[j]){
                c.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(c.size()==0||c.back()!=a[i])
        {
            c.push_back(a[i]);
        }
        i++;
    }
    while(j<n2){
        if(c.size()==0||c.back()!=b[j])
        {
            c.push_back(b[j]);
        }
        j++;        
    }   
    return c; 
}
void traversal(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}
int main()
{
    set<int> s;
    vector<int> a = {1,2,3,4,5};
    vector<int> b=  {6,7,8,9};
    vector<int> c =sortedArray(a,b);
    traversal(c);
    
    return 0;
}