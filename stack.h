#ifndef STACK_H
#define STACK_H

#include <iostream>

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
		count_ = 0;
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
		if (count_ != 0) {
			return array_[--count_]; }
		else 
			throw runtime_error("stack() is empty");
	}

	void print_stack() {
		for (size_t i = count_ -1; i < array_size_; i--)
			cout << array_[i] << endl;
	}
};

#endif /*STACK_H*/
