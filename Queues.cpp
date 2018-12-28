//   Queues, and not the kind from Star Trek NG!

//   Queues and Stacks are pretty similar.
// Queues will push types the same as a stack,
// but the queue will access them from the 'front'
// FIFO - first in first out


#include <iostream>
#include <queue>



int main() {

	//   Initialize a queue just like a stack
	std::queue<int> numbers;
	int temp;

	//   We push the data type. 1, 2, 3, 4, 5
	std::cout << "Pushing...\n";
	while (temp >= 0) {
		std::cout << "Enter numbers: ";
		std::cin >> temp;
		if (temp >= 0)
			numbers.push(temp);
	}

	//   This will print { 1, 2, 3, 4, 5 }
	std::cout << "{  ";
	while (numbers.size() > 0) {
		std::cout << numbers.front();
		numbers.pop();
		std::cout << "  ";
	}
	std::cout << "}";

	return 0;
}
