//   Stack Attack!
// Git ready to expand your knowledge of stacks!
// Increase your status as a developer!


#include <iostream>
//  First make sure you '#include <stack>' in your .cpp.
#include <stack>


int main() {

	//   A good way to initialize a stack allocated stack.  :p
	std::stack<int> numbers; 
	int temp;

	//   Pusing ints on to the stack {1, 2, 3, 4, 5}.
	std::cout << "Pushing...\n";
	while (temp >= 0) {
		std::cout << "Enter numbers: ";
		std::cin >> temp;
		if (temp >= 0)
			numbers.push(temp);
	}

	//   Printing the numbers in the stack.
	// Starting from 'top' to 'bottom'
	// This will print  '{ 5, 4, 3, 2, 1 }
	// It is in the reverse order that they were 
	// entered. LIFO - last in first out.
	std::cout << "{  ";
	while (numbers.size() > 0) {
		std::cout << numbers.top();
		numbers.pop();
		std::cout << "  ";
	}
	std::cout << "}";

	return 0;

