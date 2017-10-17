/*В большой IT - фирме есть только одна переговорная комната.Желающие посовещаться заполняют заявки с желаемым временем начала и конца.Ваша задача определить максимальное количество заявок, которое может быть удовлетворено.
Число заявок ≤ 100000.
Формат входных данных :
Вход содержит только пары целых чисел — начала и концы заявок.
Формат выходных данных :
Выход должен содержать натуральное число — максимальное число заявок.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Meeting {
private:
	int start;
	int end;
public:
	Meeting(int st_, int end_) : start(st_), end(end_) {}
	int getStart() { return start; }
	int getEnd() { return end; }
};

int compare(const void *x1, const void *x2) {
	Meeting **m1 = (Meeting**)x1;
	Meeting **m2 = (Meeting**)x2;
	return ((*m1)->getEnd() - (*m2)->getEnd());
}

//Решаем жадным алгоритмом. Сортируем по времени окончания и берем,
//если начало следующего не входит в отрезок предыдущего
size_t maxRequests(Meeting **mas, size_t max) {
	qsort(mas, max, sizeof(Meeting*), compare);
	size_t count = 1;


	for (size_t i = 1, j = 0; i < max; i++) {
		if (mas[i]->getStart() >= mas[j]->getEnd()) {
			j = i; 
			count++;
		}
	}
	return count;
}

size_t inputMeets(Meeting ***top) {
	Meeting **mas = NULL;
	Meeting **masBuf = NULL;
	int st = 0,
		en = 0;
	size_t newMasLen = 0;
	size_t meetNum = 0;

	while (cin >> st >> en) {
		if (newMasLen <= meetNum) {
			newMasLen = newMasLen ? newMasLen * 2 : 1;
			masBuf = new Meeting* [newMasLen];
			for (size_t i = 0; i < meetNum; i++) {
				masBuf[i] = mas[i];
			}
			delete[] mas;
			mas = masBuf;
		}
		Meeting *newMeet = new Meeting(st, en);
		mas[meetNum] = newMeet;
		meetNum++;
	}
	*top = mas;
	return meetNum;
}

int main() {
	Meeting **meets = NULL;
	size_t meetNum = inputMeets(&meets);
	size_t maxMeet = maxRequests(meets, meetNum);

	cout << maxMeet << endl;

	for (size_t i = 0; i < meetNum; i++)
		delete meets[i];
	delete[] meets;
	return 0;
}