#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    
    int maxCoinChange(int coin[], int N, int sum) {

        int t[N + 1][sum + 1];
        
        for (int i = 0; i < N + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (i == 0) t[i][j] = 0;
                if (j == 0) t[i][j] = 1; 
            }
        }

        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (coin[i - 1] <= j)
                    t[i][j] = t[i][j - coin[i - 1]] + t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        return t[N][sum];
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
        int res = ob.maxCoinChange(coin, N, sum);
        cout << res << "\n";
    }
    return 0;
}
