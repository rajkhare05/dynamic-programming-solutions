// NOTE: Solution is not for target sum problem
// It is just to remind me that total 7 questions are done in 01KS
#include <bits/stdc++.h>
using namespace std;

int t[100][1001];
int N = 0, w = 0;

void print() {
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < w + 1; j++) {
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin >> N;
	int arr[N];
    for(int i = 0;i < N;i++)
        cin>>arr[i];

    for (int i = 0; i < N; ++i) 
    	w += arr[i];

    // init
    for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < w + 1; j++) {
			if(i == 0) t[i][j] = false;
			if(j == 0) t[i][j] = true;
		}
	}

    print();
    for (int i = 1; i < N + 1; ++i) {
	    for (int j = 1; j < w + 1; ++j) {
	        if (arr[i - 1] <= j) 
	            t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
	        else t[i][j] = t[i - 1][j];
	    }
	}
	cout << "\n";
    print();
    cout << t[N][w];

	return 0;
}
