#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;

auto num2s(int n) {
	ull c = 0;
	while (n % 2 == 0) {
		c++;
		n /= 2;
	}
	return c;
}

auto calculateNum2s(vector<ull> const&& nums) {
	ull n = nums.size();
	ull twos = 0;
	ull extra_amt = 0;
	vector<ull> extras;
	for (ull i = 1; i <= n; i++) {
		twos += num2s(nums[i-1]);
		if (i % 2 == 0) {
			auto extra = num2s(i);
			extras.push_back(extra);
			extra_amt += extra;
		}
	}
	if (twos >= n) return ll(0);
	if (twos + extra_amt < n) return ll(-1);
	ll steps = 0;
	sort(extras.rbegin(), extras.rend());
	for (auto i : extras) {
		if (twos >= n) break;
		twos += i;
		steps++;
	}
	return twos < n ? ll(-1) : steps;
}

void test() {
	cout << calculateNum2s({3, 2, 4, 6}) << endl;
	cout << calculateNum2s({2}) << endl;
	cout << calculateNum2s({3, 2}) << endl;
	cout << calculateNum2s({10, 6, 11}) << endl;
	cout << calculateNum2s({13, 17, 1, 1}) << endl;
	cout << calculateNum2s({1, 1, 12, 1, 1}) << endl;
	cout << calculateNum2s({20, 7, 14, 18, 3, 5}) << endl;
}

int main() {
	int t,n;
	cin >> t;
	while (t) {
		cin >> n;
		vector<ull> nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		cout << calculateNum2s(move(nums)) << endl;
		t--;
	}
}

// 3, 2, 4, 6
// 3, 2^1, 2^2, 3*2^1
// 2^4

// 10, 6, 11
// 5*2^1, 3*2^1, 11
// 2^3
// 5*3*11*(2^2)
// So just add one 2^1

// 13, 17, 1, 1
// 13,17,1,1
// 2^4