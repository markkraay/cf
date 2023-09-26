long beacon_signal(int x1, int y1, int x2, int y2, int xl, int yl, int R) {
	long result = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (pow(i - xl, 2) + pow(j - yl, 2) <= pow(R, 2)) result++;
		}
	}
	return result;
}

int main() {
	int x1, y1, x2, y2, xl, yl, R;
	x1 =  0 ;
	cout << beacon_signal(x1, y1, x2, y2, xl, yl, R);
}