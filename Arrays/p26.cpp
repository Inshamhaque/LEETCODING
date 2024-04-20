//Spiral Matrix
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> brute(vector<vector<int>> &a){
    vector<int> ans;
    int m = a.size();
    int n = a[0].size();
    int left = 0;
    int right = n - 1;
    int top = 0;
    int bottom = m - 1;

    while (left <= right && top <= bottom) {
        // left to right
        for (int i = left; i <= right; i++) {
            ans.push_back(a[top][i]);
        }
        top++;

        // top to bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(a[i][right]);
        }
        right--;

        // right to left
        if (top <= bottom) { // Check if there are remaining rows
            for (int i = right; i >= left; i--) {
                ans.push_back(a[bottom][i]);
            }
            bottom--;
        }

        // bottom to top
        if (left <= right) { // Check if there are remaining columns
            for (int i = bottom; i >= top; i--) {
                ans.push_back(a[i][left]);
            }
            left++;
        }
    }

    return ans;
}
void better();
void optimal();
void traversal(vector<int> &a){
    for(auto it:a){
        cout<<it<<" ";
    }
}
int main()
{
    vector<vector<int>> a = {
        {1},
        {2},
        {3}
    };
    vector<int> ans = brute(a);

    traversal(ans);

    return 0;
}