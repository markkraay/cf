#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

using vvb = vector<vector<bool>>;

bool valid(vvb& classes, int c1, int c2)  {
	int cnt1 = 0;
	int cnt2 = 0;
	int combo = 0;
	for (int i = 0; i < classes.size(); i++) {
		if (classes[i][c1] && classes[i][c2]) {
			combo++;
		} else if (classes[i][c1]) {
			cnt1++;
		} else if (classes[i][c2]) {
			cnt2++;
		} else return false;
	}
	return abs(cnt1 - cnt2) <= combo;
}

bool valid(vvb& classes, vector<int> const& cnts, int n) {
	for (int c1 = 0; c1 < 5; c1++) {
		for (int c2 = c1 + 1; c2 < 5; c2++) {
			if (cnts[c1] >= n / 2 && cnts[c2] >= n / 2 && valid(classes, c1, c2)) return true;
		}
	}
	return false;
}

void test() {
	vvb classes = {
		{true, false, false, true, false},
		{false, true, false, false, true},
		{false, false, false, true, false},
		{false, true, false, true, false},
	};
	vector<int> cnts = {1, 2, 0, 3, 1};
	cout << valid(classes, cnts, 5) << endl;
}

int main() {
	int trials, students;
	cin >> trials;
	while (trials) {
		cin >> students;
		vector<int> counts(5, 0);
		vector<vector<bool>> graph(students, vector<bool>(5, false));
		while (students) {
			bool tmp;
			for (int i = 0; i < 5; i++) {
				cin >> tmp;
				graph[students-1][i] = tmp;
				if (tmp) counts[i]++;
			}
			students--;
		}
		if (valid(graph, counts, students)) cout << "YES" << endl;
		else cout << "NO" << endl;
		trials--;
	}
}