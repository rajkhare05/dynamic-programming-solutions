// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    // subset sum 1 = s1
    // subset sum 2 = s2
    // range = sum of a[i] elements
    // Since abs(s1 - s2) = minimum
    // i.e. abs(s1 - s2) >= 0
    // s2 = range - s1
    // Keeping s1 in b/w 0 and range / 2
    // range - s1 - s1 = range - 2 * s1
    // find only s1

    vector<int> subsetIndexVector(int arr[], int N, int range) {
        bool t[N + 1][range + 1];
        // initialize
        for (int i = 0; i < N + 1; ++i) {
            for (int j = 0; j < range + 1; ++j) {
                if (i == 0) t[i][j] = false;
                if (j == 0) t[i][j] = true;
            }
        }
        for (int i = 1; i < N + 1; ++i) {
            for (int j = 1; j < range + 1; ++j) {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                else 
                    t[i][j] = t[i - 1][j];
            }
        }

        // print t
        // for (int i = 0; i < N + 1; ++i) {
        //     for (int j = 0; j < range + 1; ++j) {
        //         cout << t[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        vector<int> v;
        for (int j = 0; j <= range / 2; ++j) {
            if (t[N][j]) {
                v.push_back(j);
            }
        }

        // print v
        // for (int x: v) cout << x << " ";
        // cout << "\n";

        return v;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
        }
        vector<int> V = subsetIndexVector(arr, n, sum);
        int mn = 1e7 + 10;
        for (int s1: V) {
            mn = min(mn, (sum - 2 * s1));
        }
        return mn;
	} 
};


// { Driver Code Starts.
int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
