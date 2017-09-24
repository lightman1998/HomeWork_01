#include <iostream>
#include "stack.h"
using namespace std;

int main() {
	stack<int> stack_A(10);
	size_t A = 0;
	int element_A;

	while (A++ < 10) {
		cin >> element_A;
		stack_A.push(element_A);
	}
	cout << "stack elements:" << endl;
	cout << endl;
	stack_A.print_stack();
	for (int i = 10; i > 5; i--)
		stack_A.pop();
	cout << "after removing: " << endl;
	stack_A.print_stack();
	system("pause");
	return 0;
}
