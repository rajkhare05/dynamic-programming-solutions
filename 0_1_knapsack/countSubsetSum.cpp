// COUNT SUBSET SUM
// PERFECT SUM
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        int t[n + 1][sum + 1];
        unsigned int M = 1e9 + 7;
        // initialize t
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < sum + 1; ++j) {
                if (i == 0) t[i][j] = 0;
                if (j == 0) t[i][j] = 1;
            }
        }
        // cdc
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 0; j < sum + 1; ++j) {
                if (arr[i - 1] <= j) 
                    t[i][j] = (t[i - 1][j - arr[i - 1]] % M) + (t[i - 1][j] % M);
                else t[i][j] = t[i - 1][j] % M;
            }
        }
        // print t
        // for (int i = 0; i < n + 1; ++i) {
        //     for (int j = 0; j < sum + 1; ++j) {
        //         cout << t[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return t[n][sum] % M;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];
       
	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
