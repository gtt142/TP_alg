//  Формат входных данных.
//  В первой строке количество команд n. n ≤ 1000000.
//  Каждая команда задаётся как 2 целых числа: a b.
//  a = 1 - push front
//  a = 2 - pop front
//  a = 3 - push back
//  a = 4 - pop back
//  Команды добавления элемента 1 и 3 заданы с неотрицательным параметром b.
//  Для очереди используются команды 2 и 3. Для дека используются все четыре команды.
//  Если дана команда pop*, то число b - ожидаемое значение. Если команда pop вызвана для пустой структуры данных, то ожидается “-1”. 
//  Формат выходных данных.
//  Требуется напечатать YES - если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.
//  4_1. Реализовать очередь с динамическим зацикленным буфером

#include <iostream>
#include <memory.h>
#define BUF 16

class MyQueue {
private:
	int head;
	int tail;
	int	bufSize;
	int size;
	int *buf;
public:
	MyQueue() : head(0), tail(0), size(0), bufSize(BUF) { buf = new int[bufSize]; }
	~MyQueue() { delete[] buf; }
	void pushBack(int);
	int popFront();

};

int MyQueue::popFront() {
	if (size == 0) {
		return -1;
	}
	int rez = buf[head];
	head = (head + 1) % bufSize;
	size--;
	return rez;
}

void MyQueue::pushBack(int val) {
	if (size >= bufSize - 1) {
		int *newBuf = new int[bufSize * 2];
		memcpy(newBuf, (buf + head), (bufSize - head) * sizeof(int));
		if (head != 0) {
			memcpy((newBuf + (bufSize - head)), buf, tail * sizeof(int));
		}
		delete[] buf;
		buf = newBuf;
		head = 0;
		tail = size;
		bufSize *= 2;
	}
	buf[tail] = val;
	tail = (tail + 1) % bufSize;
	size++;
}

int main() {
	int k = 0,
		com = 0,
		num = 0;
	int key = 1;
	MyQueue queue;
	std::cin >> k;
	for (int i = 0; i < k; i++) {
		std::cin >> com >> num;
		if (com == 2) {
			int res = queue.popFront();
			if (res != num) {
				key = 0;
				i = k;
			}
		}
		if (com == 3) {
			queue.pushBack(num);
		}
	}
	if (key == 1)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
	return 0;
}
