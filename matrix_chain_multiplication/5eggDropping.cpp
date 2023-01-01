#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int t[201][201];
    
    int solve(int e, int f) {
        if (f == 0 || f == 1) return f;
        if (e == 1) return f;
        if (t[e][f] != -1) return t[e][f];
        
        int mn = INT_MAX;
        int low, high;
        
        for (int k = 1; k <= f; k++) {
            if (t[e - 1][k - 1] != -1) low = t[e - 1][k - 1];
            else t[e - 1][k - 1] = low = eggDrop(e - 1, k - 1);
            
            if (t[e][f - k] != -1) high = t[e][f - k];
            else t[e][f - k] = high = eggDrop(e, f - k);
            
            int temp = 1 + max(low, high);
            mn = min(temp, mn);
            
        }
        return t[e][f] = mn;
    }
    
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        memset(t, -1, sizeof(t));
        return solve(n, k);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
