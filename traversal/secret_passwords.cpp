#include <unordered_set>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int findNumberKeys(vector<string>&& strs) {
	// Represent each str as a binary encoded integer
	// Find the number of connected components in the graph
	unordered_set<int> values;
	for (const auto& s : strs) {
		int encoded = 0;
		for (char c : s) {
			encoded |= 1 << (c-'a');
		}
		values.insert(encoded);
	}
	int groups = 0;
	queue<int> q;
	while (!values.empty()) {
		groups++;
		int begin = *values.begin();
		values.erase(begin);
		q.push(begin);
		while (!q.empty()) {
			int front = q.front(); q.pop();
			for (auto it = values.begin(); it != values.end();) {
				if (*it & front) {
					q.push(*it);
					it = values.erase(it);
				} else ++it;
			}
		}
	}
	return groups;
}

void test() {
	cout << findNumberKeys({"a", "b", "ab", "d", "abcd"}) << endl;
}

int main() {
	int n;
	cin >> n;
	vector<string> strings(n);
	for (int i = 0; i < n; i++) {
		cin >> strings[i];
	}
	cout << findNumberKeys(move(strings)) << endl;
}