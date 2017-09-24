#include <iostream>
#include <cassert>
#include <iomanip>

using namespace std;

template <typename T>
class stack
{
private:
	T * array_;
	size_t array_size_;
	size_t count_;
public:
	stack() {
		array_size_ = 10;
		array_ = new T[array_size_];
	}

	stack(size_t n) {
		array_size_ = n;
		array_ = new T[array_size_];
		count_ = 0;
	}

	size_t count() const {
		return count_;
	}

	void push(T const &value) {
		if (count_ == array_size_) {
			T *array_2 = new T[2 * array_size_];
			for (size_t i = 0; i != array_size_; i++)
				array_2[i] = array_[i];
			delete[] array_;
			array_ = array_2;
		}
		array_[count_++] = value;
	}

	T pop() {
		assert(count_ > 0);
		array_[--count_];
		return array_[count_];

	}

	void print_stack() {
		for (size_t i = count_ - 1; i > 0; i--)
			cout << array_[i] << endl;
	}
};

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
