#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int long_jumps(vector<int> const&& nums) {
	vector<int> dp(nums.size(), 0);
	for (int i = nums.size() - 1; i >= 0; i--) {
		if (i + nums[i] >= dp.size()) dp[i] = nums[i];
		else dp[i] = nums[i] + dp[i + nums[i]];
	}
	return *max_element(dp.begin(), dp.end());
}

void test() {
	cout << long_jumps({0,7,3,1,2,3}) << endl;
	cout << long_jumps({0,2,1,4}) << endl;
	cout << long_jumps({0,2,1000,2,3,995,1}) << endl;
	cout << long_jumps({0,1,1,1,1,1}) << endl;
}

int main() {
	int t, n, tmp;
	cin >> t;
	while (t) {
		cin >> n;
		vector<int> nums = {0};
		while (n) {
			cin >> tmp;
			nums.push_back(tmp);
			n--;
		}
		cout << long_jumps(move(nums)) << endl;
		t--;
	}
}