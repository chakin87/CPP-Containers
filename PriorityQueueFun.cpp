//   High Priority Containers!!!
// The Priority Queue - A container that prioritizes itself!

//   The priority queue container keeps its elemeents automatically ordered.
// It is implemented on the Heap and has the data stucture with the behavior of
// a binary tree. THe binary tree keeps its elements ordered, so the behavior 
// is suiting for the priority queue.
//   You use a priority queue by pushing elements in any order, but it will only
// pop the maximum element. Everything that is pop_back() will be the highest
// element in the priority queue.


#include <iostream>
#include <queue>
#include <string>

int main(int argc, char** argv) {

	// init a priority queue like this
	std::priority_queue<int> numbers;
	int temp =0;

	// say we push 1, 2, 3, 4, 5
	std::cout << "Pushing...\n";
	while (temp >= 0) {
		std::cout << "Enter numbers: ";
		std::cin >> temp;
		if (temp >= 0)
			numbers.push(temp);
	}
	// The order popped will be 5, 4, 3, 2, 1
	std::cout << "{  ";
	while (numbers.size() > 0) {
		std::cout << numbers.top();
		numbers.pop();
		std::cout << "  ";
	}
	std::cout << "}";


	std::string pause;
	std::cin >> pause;

	return 0;
}