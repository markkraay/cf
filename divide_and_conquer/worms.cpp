#include <iostream>
#include <vector>

using namespace std;
int main() {
	int piles, n_juicy, juicy_worm;
	cin >> piles;
	vector<int> worms(piles);
	for (int i = 0; i < piles; i++) {
		cin >> worms[i];
		if (i > 0) worms[i] += worms[i-1];
	}
	cin >> n_juicy;
	for (int i = 0; i < n_juicy; i++) {
		cin >> juicy_worm;
		// Find the first element that is greater than the juicy_worm, it falls into that group
		int index = lower_bound(worms.begin(), worms.end(), juicy_worm) - worms.begin() + 1; 
		cout << index << endl;
	}
}