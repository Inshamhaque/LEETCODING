//find the missing number in given array:
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int> a, int n){ // TC-> O(n^2) in the worst case, SC-> O(1)
    int missing = -1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++){
            if(a[j]!=i){
                missing = i;
            }
            else{
                missing =-1;
                break;
            }
        }
        if(missing!=-1){
            break;
        }
   } 
   return missing;
}
int better(vector<int> a, int n){//using hashing TC-> O(N+1)+O(N+1); SC-> O(N+1)
    int hasharray[n+1] = {0};
    for(auto it:a){
        hasharray[it] = 1;
    }
    for(int i=1;i<n+1;i++){
        if(!hasharray[i]){
            return i;
        }
    }
}
int optimal1(vector<int> a, int n){ //TC -> O(n), sc-> O(1)
    int sum1 =  (n*(n+1))/2;
    int sum2 = 0;
    for(auto it:a){
        sum2 += it;
    }
    return sum1-sum2;
}
// int optimal2(vector<int> a,int n){//using xor 
//     int xor1 = 0;
//     int xor2 = 0;
//     for(int i=0;i<n-1;i++){
//         xor1 ^= i+1;
//         xor2 = a[i];
//     }
//     xor1^=n;
//     return xor1^xor2;
// }
int main()
{
    vector<int> a = {5,3,1,2,4,7};
    int ans = optimal2(a,7);
    cout<<"The missing element is:  "<<ans;
    return 0;
}