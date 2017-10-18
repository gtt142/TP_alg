//  Широкая пирамида

#include <iostream>

int mini(int a, int b) {
	return a < b ? a : b;
}

void fill_d_table(long long **tab, int max) {

	for (int i = 1; i <= max; i++) {
		tab[i][0] = 0;
	}
	tab[0][0] = 1;

	for (int n = 1; n <= max; n++) {
		for (int k = 1; k <= n; k++) {
			tab[n][k] = tab[n - k][mini((n - k), (k - 1))] + tab[n][k - 1];
		}
	}
}

int main() {
	int n;
	std::cin >> n;

	long long **d_table = new long long* [n + 1];
	for (int i = 0; i <= n; i++) {
		d_table[i] = new long long [n + 1];
	}

	fill_d_table(d_table, n);
	std::cout << d_table[n][n] << std::endl;

	for (int i = 0; i <= n; i++) {
		delete[] d_table[i];
	}
	delete[] d_table;

	return 0;
}
