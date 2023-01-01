#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Memoization: Top Down Approach
    int helper(int length[], int size, int price[], int n, int t[][1001]) {
        if (n == 0 || size == 0) return 0;
        if (t[n][size] != -1) {
            return t[n][size];
        }
        if (length[n - 1] <= size) {
          return t[n][size] = max(
            price[n - 1] + helper(size - length[n - 1], length, price, n - 1, t),
            helper(size, length, price, n - 1, t)
          );
        } else if (length[n - 1] > size) {
            return t[n][size] = helper(size, length, price, n - 1, t);
        }
    }
    // Function to return max value that can be put in knapsack of capacity size.
    int unboundedKnapSack(int length[], int size, int price[], int n) 
    { 
       int t[1001][1001];
       memset(t, -1, sizeof(t));
       return helper(length, size, price, n, t);
    }

    // Tabulation: Bottom Up Approach
    int bottomUpUBKnapSack(int length[], int size, int price[], int n) {
        int t[1001][1001];
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < size + 1; ++j)
            {
                if (i == 0 || j == 0) t[i][j] = 0;
            }
        }

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < size + 1; ++j)
            {
                if (length[i - 1] <= j) {
                    t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][size];

    }

};

int main()
 {
    // taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        // reading number of elements and weight
        int n, size;
        cin>>n>>size;
        
        int price[n];
        int length[n];
        
        // inserting the values
        for(int i=0;i<n;i++)
            cin>>price[i];
        
        // inserting the weights
        for(int i=0;i<n;i++)
            cin>>length[i];

        Solution ob;

        cout<<ob.bottomUpKnapSack(length, size, price, n)<<endl;
        
    }
    return 0;
}
