//  Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k.
//  Найти количество таких пар индексов(i, j), что A[i] + B[j] = k.Время работы O(n + m).
//  n, m ≤ 100000.
//  Указание.Обходите массив B от конца к началу.

#include <iostream>
#include <assert.h>
using namespace std;



int main() {
	int n, m, k;
	int count = 0;
	int i, j;

	cin >> n;
	assert(n > 0);
	int* masA = new int[n];
	for (i = 0; i < n; i++) {
		cin >> masA[i];
	}

	cin >> m;
	assert(m > 0);
	int* masB = new int[m];
	for (i = 0; i < m; i++) {
		cin >> masB[i];
	}

	cin >> k;

	int key = 1;
	i = 0;
	j = m-1;
	while (key == 1) {
		if (masA[i] + masB[j] == k) {
			count++;
		}
		else
			if (masA[i] + masB[j] > k) {
				j--;
				if (j >= 0) {
					while ((key == 1) && (masA[i] + masB[j] > k)) {
						j--;
						if (j < 0)
							key = 0;
					}
					if ((key == 1) && (masA[i] + masB[j] == k))
						count++;
					else
						j++;
				}
				else
					key = 0;
			}
		i++;
		j--;
		
		if ((i >= n) || (j < 0))
			key = 0;
	}

	cout << count << endl;

	delete[] masA;
	delete[] masB;
	return 0;
}
