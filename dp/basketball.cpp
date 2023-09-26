#include <vector>
#include <unordered_map>
#include <iostream>
 
using namespace std;
using ll = long long;
 
ll basketball(vector<vector<int>> const&& players) {
	int n = players[0].size();
	ll T, B, newT, newB;
	T = B = 0;
	for (int i = 0; i < n; i++) {
		newT = max(T, B + players[0][i]);
		newB = max(B, T + players[1][i]);
		T = newT;
		B = newB;
	}
	return max(T, B);
}

void test() {
	cout << basketball({
		{1,2,9},
		{10,1,1}
	}) << endl;
	cout << basketball({
		{0,9,3,5,7,3},
		{0,5,8,1,4,5}
	}) << endl;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> players(2, vector<int>(n+1, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> players[i][j];
        }
    }
		cout << basketball(move(players)) << endl;
}