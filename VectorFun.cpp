//		VECTORS - pushing, inserting, indexing
// + Implementation and use cases
// + Explanations


#include <iostream>
#include <vector>
#include <string>


// Function to print the contents of a vector<int>
void print(const std::vector<int>& my_vector) {
	std::cout << "Vector content: {  ";
	for (const int& num : my_vector)
		std::cout << num << "  ";
	std::cout << "}\n\n";
}

// Function to print the contents of any vector<type>.
template<typename T>
void print(const std::vector<T>& my_vector) {
	std::cout << "Vector content: {  ";
	for (const T& num : my_vector)
		std::cout << num << "  ";
	std::cout << "}\n\n";
}



int main(int argc, char** argv) {
	std::vector<int> numbers;
	int value = 0;

	//   Demonstration on pushing ints to the back of a vector.
	std::cout << "Pushing back...\n";
	while (value >= 0) {
		std::cout << "Enter number: ";
		std::cin >> value;
		if (value >= 0)
			numbers.push_back(value);
	}
	print(numbers);

	value = 0;

	//  Demonstration on pushing ints to the front of vector
	// using the .begin() iterator to select the position in
	// which the int will be inserted.
	std::cout << "Pushing front...\n";
	while (value >= 0) {
		std::cout << "Enter number: ";
		std::cin >> value;
		if (value >= 0)
			numbers.insert(numbers.begin(), value);
	}
	print(numbers);

	int index = 0;

	//   Demonstration on using insert ints into vector by index.
	std::cout << "Inserting by index...\n";
	while (index >= 0) {
		std::cout << "Enter index: ";
		std::cin >> index;
		if (index >= 0) {
			std::cout << "Enter value: ";
			std::cin >> value;
			//   Using the .begin iterator + the index, inserts int to 
			// desired vecto index.
			numbers.insert(numbers.begin() + index, value);
		}
	}
	print(numbers);
	index = 0;

	//   Demonstration on using insert floats into vector by index.
	// This one makes use of the template print function.
	std::cout << "-std::vector<float> demo-" << std::endl;
	std::vector<float> strvec;
	float fval = .0f;
	while (fval >= .0f) {
		std::cout << "Enter float value: ";
		std::cin >> fval;
		//   Using the .begin iterator + the index, inserts int to 
		// desired vecto index
		strvec.push_back(fval);	
	}
	print<float>(strvec);


	index = 0;
	//   Using the [] to modify values at desired index
	std::cout << "Modifying existing elements...\n";
	while (index >= 0) {
		std::cout << "Enter index: ";
		std::cin >> index;
		if (index >= 0) {
			std::cout << "Enter value: ";
			std::cin >> value;
			numbers[index] = value;
		}
	}
	print(numbers);
	 

	return 0;
}

