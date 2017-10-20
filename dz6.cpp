//  Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков пирамиду.
//  Формат входных данных:
//  На вход подается количество кубиков N.
//  Формат выходных данных:
//  Вывести число различных пирамид из N кубиков.
//  Широкая пирамида. Каждый вышележащий слой пирамиды должен быть строго меньше нижележащего.

#include <iostream>

int mini(int a, int b) {
	return a < b ? a : b;
}

long long count_pyramid(int max) {

	long long **tab = new long long*[max + 1];
	for (int i = 0; i <= max; i++) {
		tab[i] = new long long[max + 1];
	}

	for (int i = 1; i <= max; i++) {
		tab[i][0] = 0;
	}
	tab[0][0] = 1;

	for (int n = 1; n <= max; n++) {
		for (int k = 1; k <= n; k++) {
			tab[n][k] = tab[n - k][mini((n - k), (k - 1))] + tab[n][k - 1];
		}
	}
	long long res = tab[max][max];
	for (int i = 0; i <= max; i++) {
		delete[] tab[i];
	}
	delete[] tab;
	return res;
}

int main() {
	int n;
	std::cin >> n;

	long long res = count_pyramid(n);
	std::cout << res << std::endl;

	return 0;
}
