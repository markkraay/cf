#include <vector>
#include <unordered_map>
#include <iostream>
 
using namespace std;
 
int basketball(vector<vector<int>> const&& players) {
	int n = players[0].size();
	int prevprev_t = 0;
	int prevprev_b = 0;
	int prev_t = players[0][0];
	int prev_b = players[1][0];
	if (n == 1) return max(prev_t, prev_b);
	int	current_t = max(prev_b, max(prevprev_b, prevprev_t)) + players[0][1];
	int	current_b = max(prev_t, max(prevprev_b, prevprev_t)) + players[1][1];
	for (int i = 2; i < n; i++) {
		cout << prev_t << " " << prev_b << endl;
		prevprev_t = prev_t;
		prevprev_b = prev_b;
		prev_t = current_t;
		prev_b = current_b;
		current_t = max(prev_b, max(prevprev_b, prevprev_t)) + players[0][i];
		current_b = max(prev_t, max(prevprev_b, prevprev_t)) + players[1][i];
	}
	return max(current_t, current_b);
}

void test() {
	cout << basketball({
		{1,2,9},
		{10,1,1}
	}) << endl;
	cout << basketball({
		{9,3,5,7,3},
		{5,8,1,4,5}
	}) << endl;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> players(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> players[i][j];
        }
    }
		cout << basketball(move(players)) << endl;
}