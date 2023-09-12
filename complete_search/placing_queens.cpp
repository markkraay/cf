#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;
using vvb = vector<vector<bool>>;

string encode(vvb const& board) {
	string result;
	for (const auto& row : board) {
		for (bool value : row) { 
			result += to_string(value);
		}
	}
	return result;
}

bool canPlace(vvb& board, int i, int j) {
	int rows = board.size();
	int cols = board[0].size();
	for (int r = 0; r < rows; r++) if (board[r][j]) return false;
	for (int c = 0; c < cols; c++) if (board[i][c]) return false;
	for (int r = i, c = j; r < rows && c < cols; r++, c++) if (board[r][c]) return false;
	for (int r = i, c = j; r >= 0 && c < cols; r--, c++) if (board[r][c]) return false;
	for (int r = i, c = j; r < rows && c >= 0; r++, c--) if (board[r][c]) return false;
	for (int r = i, c = j; r >= 0 && c >= 0; r--, c--) if (board[r][c]) return false;
	return true;
}

int recurse(vvb& board, int r, int k, unordered_set<string>& visited) {
	if (k == 0) {
		string key = encode(board);
		if (visited.find(key) == visited.end()) {
			visited.insert(key);
			return 1;
		}
		return 0;
	}
	int rows = board.size();
	int cols = board[0].size();
	int total = 0;
	for (int new_r = r; new_r <= rows - k; new_r++) {
		for (int c = 0; c < cols; c++) {
			if (canPlace(board, new_r, c)) {
				board[new_r][c] = true;
				total += recurse(board, new_r + 1, k - 1, visited);
				board[new_r][c] = false;
			}
		}
	}
	return total;
}

int main() {
	int m,n,k;
	cin >> k >> n >> m;
	int total = 0;
	vvb board(n, vector<bool>(m, false));
	unordered_set<string> visited;
	for (int r = 0; r <= n - k; r++) {
		total += recurse(board, r, k, visited);
	}
	cout << total << endl;
}