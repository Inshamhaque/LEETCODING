//Next greater permutation for a set of given integers
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute(vector<int> A){
    //normally print all the permutations in sorted array and return the one just after the given 
}
vector<int> better(vector<int> A){
    next_permutation(A.begin(),A.end());
    return A;
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<int> A){
    int IND = -1;
    int n = A.size();

    // Find the breakpoint index
    for(int i = n - 2; i >= 0; i--){
        if(A[i] < A[i + 1]){
            IND = i;
            break;
        }
    }
    
    // Handling the edge case when IND == -1
    if(IND == -1){
        reverse(A.begin(), A.end());
    } else {
        // Finding the minimum element larger than the element at IND
        for(int i = n - 1; i > IND; i--){
            if(A[i] > A[IND]){
                swap(A[i], A[IND]);
                break;
            }
        }
        // Reversing the elements after the breakpoint index
        reverse(A.begin() + IND + 1, A.end());
    }

    return A;
}

void traversal(vector<int> A){
    for(auto it : A){
        cout << it << " ";
    }
}

int main()
{
    vector<int> A = {1, 2, 3};
    vector<int> ans = optimal(A);
    traversal(ans);

    return 0;
}
