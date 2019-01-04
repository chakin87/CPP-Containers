//			Keep Track of Landmark Pins on a Map
// 1. Coordinates will be expressed as latitude and longitude pairs
// 2. This will be similar to the coodinates that are used in GPS



#include <iostream>
#include <map>
#include <string>


int main() {
	//   We start with a map the key is a pair<int, int> for coords
	// and a value of string for the Name of the landmark
	std::map<std::pair<int, int>, std::string> pins;
	int temp = 0;
	std::string str;
	//   The below pair is our pair that we will use to insert
	// into the 'pins' map
	std::pair<std::pair<int, int>, std::string> p;
	//   This pair will be the pair we will insert into the 
	// pair that is above. There are multiple ways to achieve
	// what we are doing, but this way will work just fine.
	//(Although, it is quite verbose)
	std::pair<int, int> landmark;
	 
	std::cout << "Inserting...\n";
	while (temp >= 0) {
		std::cout << "Enter latitude: ";
		std::getline(std::cin, str);
		temp = std::stoi(str);
		if (temp >= 0) {
			landmark.first = temp;
			std::cout << "Enter longitude: ";
			std::getline(std::cin, str);
			temp = std::stoi(str);
			landmark.second = temp;
			p.first = landmark;
			std::cout << "Enter name: ";
			std::getline(std::cin, str);
			p.second = str;
			pins.insert(p);
		}
	}

	std::cout << "{   ";
	for (auto it = pins.begin(); it != pins.end(); it++)
		//   Below, we access the maps first set of the pair. That happens to be a pair, so we access
		// the first.first and first.second so that we can get to both of the keys.
		std::cout << it->first.first << "," << it->first.second << "->" << it->second << "   ";
	std::cout << "}\n";


	std::string pause;
	std::cin >> pause;
	return 0;
}
