#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:

    int subsets(int arr[], int N, int sum) {
        int t[N + 1][sum + 1];
        // init t
        for (int i = 0; i < N + 1; ++i) {
            for (int j = 0; j < sum + 1; ++j) {
                if (i == 0) t[i][j] = 0;
                if (j == 0) t[i][j] = 1;
            }
        }
        for (int i = 1; i < N + 1; ++i) {
            for (int j = 1; j < sum + 1; ++j) {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
                else 
                    t[i][j] = t[i - 1][j];
            }
        }

        // print t
        // for (int i = 0; i < N + 1; ++i) {
        //     for (int j = 0; j < sum + 1; ++j) {
        //         cout << t[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        return t[N][sum];
    }
	int countMin(int arr[], int n, int k)  { 
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
        }
        // sum(s1) - sum(s2) = diff      (1)
        // sum(s1) + sum(s2) = sum(S)    (2)
        // eq(1) + eq(2)
        // 2 * sum(s1) = diff + sum(S)
        // sum(s1) = (diff + sum(S)) / 2
        int s = (k + sum) / 2;

        int c = subsets(arr, n, s);
        return c;
	}
};


int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];       

	    Solution ob;
	    cout << ob.countMin(a, n, k) << "\n";
	     
    }
    return 0;
}
