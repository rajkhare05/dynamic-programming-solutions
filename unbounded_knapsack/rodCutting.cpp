#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    
    int rodCutting(int length[], int size, int price[], int N) {

        int t[size + 1][N + 1];
        
        for (int i = 0; i < size + 1; i++) {
            for (int j = 0; j < N + 1; j++) {
                if (i == 0 || j == 0)
                    t[i][j] = 0;
            }
        }

        for (int i = 1; i < size + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                if (length[i - 1] <= j)
                    t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        // Step 3: Return
        return t[size][N];
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int size, N;

        cin >> size;
        int length[size];
        for(int i = 0; i < size; i++) {
            cin >> length[i];
        }

        cin >> N;
        int price[N];
        for (int i = 0; i < N; i++) {
            cin >> price[i];
        }
        
        Solution ob;
        int res = ob.rodCutting(length, size, price, N);
        cout << res;
    }
    return 0;
}
