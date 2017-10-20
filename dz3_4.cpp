/*Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1]. 
Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k], ближайшего по значению к B[i]. Время работы поиска для каждого элемента B[i]: O(log(k)).
n ≤ 110000, m ≤ 1000.
*/

#include <iostream>
#include <assert.h>
using namespace std;

int minNearNum(int* mas, int count, int num) {
	int last = count - 1;
	int first = 0;

	if (num <= mas[first])
		return 0;
	if (num >= mas[last])
		return last;

	for (int ind = 1; ind < last; ind <<= 1) {
		if (mas[ind] < num)
			first = ind;
		else
			last = ind;
	}

	while (first < last - 1) {
		int middle = (last + first) / 2;
		if (mas[middle] < num)
			first = middle;
		else
			last = middle;
	}

	int d_left = num - mas[first];
	int d_right = mas[last] - num;

	if (d_left > d_right)
		return last;
	else
		return first;
}

void print_near_num_min_indexes(int *masA, int n, int *masB, int m) {
	
	for (int i = 0; i < m; i++) {
		int k = minNearNum(masA, n, masB[i]);
		cout << k << " ";
	}
	cout << endl;
}

int main() {
	int n = 0, m = 0;

	cin >> n;
	assert(n > 0);
	int* masA = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> masA[i];
	}

	cin >> m;
	assert(m > 0);
	int* masB = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> masB[i];
	}

	print_near_num_min_indexes(masA, n, masB, m);

	delete[] masA;
	delete[] masB;
	return 0;
}
