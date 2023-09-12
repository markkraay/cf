#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int max_conseq_subsequences(vector<int> const& nums, int i, int prev, vector<int>& memo) {
	if (i == nums.size()) return 0;
	if (memo[i] != -1) return memo[i];
	if (nums[i] > prev)  { 
		return memo[i] = max(
			max_conseq_subsequences(nums, i + 1, nums[i], memo) + 1, // Include the character
			max_conseq_subsequences(nums, i + 1, prev, memo) // Do not include the character
		);
	}
	return memo[i] = max_conseq_subsequences(nums, i + 1, prev, memo);
}

void max_conseq_subsequences(vector<int> const&& nums) {
	vector<vector<int>> subsequences;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = subsequences.size(); j >= 0; j--) {
			subseq.push_back()
		}
	}
}

void test() {
	vector<int> nums = {3,3,4,7,5,6,8};
	vector<int> memo(nums.size(), -1);
	cout << max_conseq_subsequences(nums, 0, -1, memo) << endl;
}

int main() {
	test();
}