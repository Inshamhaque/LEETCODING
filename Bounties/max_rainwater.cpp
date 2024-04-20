#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
        int n = height.size();
        int ht= INT_MIN;
        pair<int,int> p;
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                int diff = height[j]-height[i];
                if(diff>ht){
                    p.first = i;
                    p.second = j;
                }
                ht = max(height[j]-height[i],ht);
            }
        }
        cout<<p.second;
        cout<<p.first;
        int area = ht*(p.second-p.first);
        return area;
    }
int main(){
    vector<int> ht =  {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<"answer is : "<<trap(ht); 
}