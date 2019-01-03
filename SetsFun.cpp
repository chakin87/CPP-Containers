//    Lets Learn about Sets!
//   ordered or unordered sets
//   can accept duplicates or not

//   Sets are associative containers. This means that
// it addresses elements by their content rather than location or index.

// SetsFun.cpp will go over the 4 combinations of sets.

#include <iostream>
#include <set>
#include <unordered_set>
#include <string>



int main(int argc, char** argv) {

	std::set<int> this_set;
	//std::unordered_set<int> this_set;
	//std::multiset<int> this_set;
	//std::unordered_multiset<int> this_set;

	int temp = 0;

	// std::set will not take duplicates and orders its elements automatically.
	// std::multiset will take duplicates and orders its elements automatically.
	// std::unordered_set will take duplicates and does not order its elements.
	// std::unordered_multiset will take duplicates and does not order its elements.
	std::cout << "Inserting...\n";
	while (temp >= 0) {
		std::cout << "Enter number: ";
		std::cin >> temp;
		if (temp >= 0)
			this_set.insert(temp);
	}

	std::cout << "{  ";
	for (auto it = this_set.begin(); it != this_set.end(); it++)
		std::cout << *it << "  ";
	std::cout << "}\n";

	temp = 0;
	//   Here we ask for the number that the user wants
	// to delete. Elements in sets are also keys, so in
	// this section if the number entered by the user is
	// present in the set, then it will be deleted.
	std::cout << "Removing...\n";
	while (temp >= 0) {
		std::cout << "Enter number: ";
		std::cin >> temp;
		if (temp >= 0)
			this_set.erase(temp);
	}
	std::cout << "{  ";
	for (auto it = this_set.begin(); it != this_set.end(); it++)
		std::cout << *it << "  ";
	std::cout << "}\n";


	std::string pause;
	std::cin >> pause;

	return 0;
}