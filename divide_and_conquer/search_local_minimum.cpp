#include <iostream>
#include <vector>
#include <limits>

using namespace std;

enum Slope {
	Maximum,
	Increasing,
	Decreasing,
	Minimum,
};

Slope determineIncreasing(vector<int>& guessed, int idx) {
	for (int i = idx - 1; i <= idx + 1; i++) {
		if (guessed[i] == -1) {
			cout << "? " << to_string(i) << endl;
			cin >> guessed[i];
		}
	}
	int l = guessed[idx-1];
	int r = guessed[idx+1];
	int c = guessed[idx];
	if (l > c && r > c) return Slope::Minimum;
	if (l < c && r < c) return Slope::Maximum;
	if (r > c) return Slope::Increasing;
	return Slope::Decreasing;
}

bool findLocalMinimum(vector<int> guessed, int l, int h) {
	while (l <= h) {
		int m = (l + h) / 2;
		switch (determineIncreasing(guessed, m)) {
			case Slope::Minimum:
				cout << "! " << m << endl;
				return true;
			case Slope::Increasing:
				h = m - 1;
				break;
			case Slope::Decreasing:
				l = m + 1;
				break;
			case Slope::Maximum:
				if (findLocalMinimum(guessed, l, m - 1)) return true;
				return findLocalMinimum(guessed, m + 1, h);
		}
	}
	return false;
}

void findLocalMinimum(int n) {
	vector<int> guessed(n+1, -1);
	guessed[0] = numeric_limits<int>::max();
	guessed.push_back(numeric_limits<int>::max());
	findLocalMinimum(guessed, 1, n);
}

// 4,2,3,1,5 : WORKS
// 1,2,3,4,5 : WORKS
// 5,4,3,2,1

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	findLocalMinimum(n);
}