#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using ll = unsigned long long;

bool canSlay(ll h_c, ll d_c, ll h_m, ll d_m, ll coins, ll w, ll a) {
	h_c += coins * a;
	for (ll i = 0; i <= coins; i++) {
		ll n_attacks_for_monster = d_m <= 0 ? numeric_limits<ll>::max() : (ll)ceil(1.0 * h_c / d_m);
		ll n_attacks_for_character = d_c <= 0 ? numeric_limits<ll>::max() : (ll)ceil(1.0 * h_m / d_c);
		if (n_attacks_for_character <= n_attacks_for_monster) return true;
		h_c -= a;
		d_c += w;
	}
	return false;
}

void test() {
	cout << canSlay(25, 4, 9, 20, 1, 1, 10) << endl;
	cout << canSlay(25, 4, 12, 20, 1, 1, 10) << endl;
	cout << canSlay(100, 1, 45, 2, 0, 4, 10) << endl;
	cout << canSlay(9, 2, 69, 2, 4, 2, 7) << endl;

	cout << canSlay(25, 0, 0, 100, 1, 1, 1) << endl;
}

int main() {
	ll trials, h_c, d_c, h_m, d_m, coins, w, a;
	cin >> trials;
	while (trials) {
		cin >> h_c >> d_c;
		cin >> h_m >> d_m;
		cin >> coins >> w >> a;
		if (canSlay(h_c, d_c, h_m, d_m, coins, w, a)) cout << "YES" << endl;
		else cout << "NO" << endl;
		trials--;
	}
}