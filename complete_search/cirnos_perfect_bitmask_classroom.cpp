#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int compute(int x) {
	// Check if the number consists of all ones
	int y = 1;
	while (!(y & x) && y <= x) y <<= 1;
	if (y < x) return y;
	// Find the first value where x = 0
	int index = 1;
	while (index <= x && (x & index)) index <<= 1;
	return y + index;
}

void test() {
	cout << compute(1) << endl;
	cout << compute(2) << endl;
	cout << compute(5) << endl;
	cout << compute(16) << endl;
	cout << compute(114514) << endl;
	cout << compute(1000000) << endl;
}

int main() {
	int trials, x;
	cin >> trials;
	while (trials) {
		cin >> x;
		int y = compute(x);
		cout << y << endl;
		trials--;
	}
}

//  1
// 11

// 10
//  1

// 1001
//   1

// 10000
// 10001 

// 11011111101010010
//                10

// 11110100001001000000
//              1000000


// Count zeros until 1
// if the result < target return that value
// If the result is equal, add one
// 