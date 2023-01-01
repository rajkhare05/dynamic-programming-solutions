#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    
    int minCoinChange(int coin[], int N, int sum) {

        int t[N + 1][sum + 1];

        const int INF = INT8_MAX - 1;
        
        // init t
        for (int j = 0; j < sum + 1; j++) {
            t[0][j] = INF;
        }

        for (int i = 1; i < N + 1; i++) {
            t[i][0] = 0;
        }

        // this step can be skipped by
        // assigning i = 1 in the next loop
        for (int j = 1; j < sum + 1; j++) {
            int x = j % coin[0];
            if (x == 0) t[1][j] = j / coin[0];
            else t[1][j] = INF;
        }

        for (int i = 2; i < N + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (coin[i - 1] <= j)
                    t[i][j] = min(t[i][j - coin[i - 1]] + 1, t[i - 1][j]);
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        // print t
        // for (int i = 0; i < N + 1; i++) {
        //     for (int j = 0; j < sum + 1; j++) {
        //         cout << t[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        return t[N][sum] == INF ? -1 : t[N][sum];
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;

        int coin[N];

        for(int i = 0; i < N; i++) {
            cin >> coin[i];
        }

        cin >> sum;
        
        Solution ob;
        int res = ob.minCoinChange(coin, N, sum);
        cout << res << "\n";
    }
    return 0;
}
