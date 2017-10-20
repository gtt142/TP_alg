//  Найти, на сколько нулей оканчивается n! = 1 * 2 * 3 * … * n.
#include <iostream>

int main() {
	int n;
	int count = 0;
	int ost;
	int i;
	int newNum;
	
	std::cin >> n;
	
	for (i = 5; i <= n; i += 5) {
		newNum = i;
		do {
			ost = newNum % 5;
			newNum = newNum / 5;
			count++;
		} while (ost == 0);
		count--;
	}

	std::cout << count;
	return 0;
}
