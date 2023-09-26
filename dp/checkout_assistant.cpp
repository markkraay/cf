#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int findMinPrice(vector<vector<int>>& pt, int i, int t, unordered_map<string, int> memo) {
	if (i >= pt.size()) return 0;
	string key = to_string(i) + "," + to_string(t);
	if (memo.contains(key)) return memo[key];
	int pay = pt[i][1] + findMinPrice(pt, i + 1, pt[i][0], memo);
	if (t == 0) { // No time remaining, we must pay
		return memo[key] = pay;
	}
	return memo[key] = min( // Time remaining, can either pay or steal
		pay,
		findMinPrice(pt, i + 1, t - 1, memo) // Steal;
	);
}

int findMinPrice(vector<vector<int>>&& pt) {
	int n = pt.size();
	int minimum_price = numeric_limits<int>::max();
	unordered_map<string, int> memo;
	for (int start = 0; start < pt.size(); start++) {
		minimum_price = min(minimum_price, findMinPrice(pt, start, 0, memo));
		memo.clear();
		// Shift PT
		pt.push_back(pt.front());
		pt.erase(pt.begin());
	}
	return minimum_price;
}

void test() {
	cout << findMinPrice({
		{2,10},
		{0,20},
		{1,5},
		{1,3}
	}) << endl;
}

int main() {
	test();
	// int n;
	// cin >> n;
	// vector<vector<int>> inputs(n, vector<int>(2));
	// for (int i = 0; i < n; i++) {
	// 	cin >> inputs[i][0] >> inputs[i][1];
	// }
}