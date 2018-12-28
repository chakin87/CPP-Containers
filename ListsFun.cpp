//      Lists - all their glory!

#include <iostream>
#include <list>



//   Function to print the contents of 
// a list.
void print(const std::list<int>& my_list) {
	std::cout << "List content: {  ";
	for (const int& num : my_list)
		std::cout << num << "  ";
	std::cout << "}\n\n";
}

//   Template function of the above.
// This function will print a Lists'
// contents with a List of any type

template<typename T>
void print(const std::list<T>& my_list) {
	std::cout << "List content: {";
	for (const <T>& val : my_list) {
		std::cout << val << " ";
	}
	std::cout << "}\n\n";
}


int main(int argc, char** argv) {
	std::list<int> numbers;
	int value = 0;

	std::cout << "Pushing back...\n";
	while (value >= 0) {
		std::cout << "Enter number: ";
		std::cin >> value;
		if (value >= 0)
			numbers.push_back(value);
	}
	print(numbers);

	value = 0;
	std::cout << "Pushing front...\n";
	while (value >= 0) {
		std::cout << "Enter number: ";
		std::cin >> value;
		if (value >= 0)
			numbers.push_front(value);
	}
	print(numbers);


	return 0;