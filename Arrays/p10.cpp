//Intersection of two sorted arrays
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    vector<int> visited = {0};
    vector<int> intersection;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a[i] == b[j] && visited[j]==0){
                intersection.push_back(a[i]);
                visited[j]=1;
            }
            if(b[j]>a[i]){
                break;
            }
        }
    }
    return intersection;
}
vector<int> optimal(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int i=0;
    int j=0;
    vector<int> c;
    while(i<n1&&j<n2){
        if(a[i]>b[j]){
            j++;
        }
        if(a[i]<b[j]){
            i++;
        }
        if(a[i]==b[j]){
            c.push_back(a[i]);
            i++;
            j++;
        }
    }
    return c;
}
void traversal(vector<int> a){
    for(auto it:a){
        cout<<it<<" ";
    }
}
int main()
{
    vector<int> a = {1,2,2,3,3,4,5,6};
    vector<int> b = {2,3,3,5,6,6,7};
    vector<int> c = optimal(a,b);
    traversal(c);
    
    return 0;
}