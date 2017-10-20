//  5_2.Стековые анаграммы.
//  Пара слов называется стековой анаграммой, если одно слово можно получить из другого, проведя последовательность стековых операций с его буквами(взять очередную букву исходного слова и поместить ее в стек; взять букву из стека и добавить ее в конец выходного слова).
//  Для заданной пары слов требуется определить, можно ли выполнить последовательность стековых операций, переводящую первое слово во второе.Все буквы в слове различные.
//  Длина анаграммы ≤ 10000.
//  Формат входных данных.Пара слов, являющихся анаграммой.
//  Формат выходных данных.YES, если последовательность стековых операций существует и NO в противном случае.

#include <iostream>
#include <string>
#include <memory.h>

class MyStack {
private:
	char *line;
	size_t size;
	int top;
public:
	MyStack(size_t sz) : size(sz), top(-1) { line = new char[size]; }
	~MyStack() { delete[] line; }
	char getTop();
	char pop();
	void push(char);
	bool isEmpty();
};

bool MyStack::isEmpty() {
	if (top < 0)
		return true;
	return false;
}

char MyStack::getTop() {
	if (!isEmpty())
		return line[top];
	else
		return '\0';
}

char MyStack::pop() {
	if (!isEmpty()) {
		top--;
		return line[top + 1];
	}
	else
		return '\0';
}

void MyStack::push(char sym) {
	if (top != size) {
		top++;
		line[top] = sym;
	}
}

int is_anagram(char *str1, size_t len1, char *str2, size_t len2) {
	if (len1 != len2)
		return false;
	size_t ptr1 = 0;
	size_t ptr2 = 0;
	MyStack stack(len1);
	while (ptr1 < len1) {
		while (!(stack.isEmpty()) && (stack.getTop() == str2[ptr2])) {
			ptr2++;
			stack.pop();
		}
		stack.push(str1[ptr1]);
		ptr1++;
	}
	while (!(stack.isEmpty()) && (stack.getTop() == str2[ptr2])) {
		ptr2++;
		stack.pop();
	}

	if (stack.isEmpty())
		return 1;
	else
		return 0;
}

int main() {
	std::string str1;
	std::string str2;
	std::cin >> str1;
	std::cin >> str2;
	size_t len1 = str1.length();
	size_t len2 = str2.length();
	char *st1 = new char[len1 + 1];
	char *st2 = new char[len2 + 1];
	
	memcpy(st1, str1.c_str(), (len1 + 1) * sizeof(char));
	memcpy(st2, str2.c_str(), (len2 + 1) * sizeof(char));
	
	int res = is_anagram(st1, len1, st2, len2);
	
	if (res) {
		std::cout << "YES" << std::endl;
	}
	else
		std::cout << "NO" << std::endl;
	delete[] st1;
	delete[] st2;
	return 0;
}
