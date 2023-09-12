#include <vector>
#include <string>
#include <iostream>

using namespace std;
using ll = unsigned long long;

int main() {
	string response;
	ll l = 1; 
	ll h = 1000000000000000000;
	while (l <= h) {
		ll m = (l + h) / 2;
		cout << m << endl;
		cin >> response; 
		if (response == "HIGHER") l = m + 1;
		else if (response == "LOWER") h = m - 1;
		else return 1;
	}
	return 1;
}