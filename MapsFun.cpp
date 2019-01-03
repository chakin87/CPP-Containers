//			STD::MAPS
//   The map of the std::map.
// Let's take a look and see where maps
// can take us!





#include <iostream>
#include <string>
#include <map>
#include <unordered_map>



int main() {
	//   Maps store a key and value. 
	// as seen below std::map<int, std::string> map,
	// declares a map that has an integer key and a std::string value.
	// std::map<key, value> map

	// The four types of maps.
	// std::map has unique keys and is self ordering.
	std::map<int, std::string> this_map;
	// std::multimap has mult-keys and is self ordering.
	std::multimap<int, std::string> this_multimap;
	// std::unordered_map has unique keys and is NOT self ordering.
	std::unordered_map<int, std::string> this_unordered_map;
	// std::unordered_multimap has multi-keys and is NOT self ordering.
	std::unordered_multimap<int, std::string> this_unordered_multimap;
		
	int temp = 0;
	std::string str;
	// std::pair is what we will insert into std::map.
	std::pair<int, std::string> p;

	std::cout << "Inserting...\n";
	while (temp >= 0) {
		std::cout << "Enter key: ";
		std::getline(std::cin, str);
		temp = std::stoi(str);
		if (temp >= 0) {
			p.first = temp;
			std::cout << "Enter name: ";
			std::getline(std::cin, str);
			p.second = str;
			//   We fill the pair and the use the insert() function
			// to insert it into the std::map. This method is not
			// the only way to insert into maps.
			this_map.insert(p);
			//   Other ways to insert into map:
			// this_map.insert(std::make_Pair(temp, str));
			// this_map[temp] = str;

		}
	}

	std::cout << "{   ";
	for (auto it = this_map.begin(); it != this_map.end(); it++)
		std::cout << it->first << "->" << it->second << "   ";
	std::cout << "}\n";

	temp = 0;
	std::cout << "Removing...\n";
	while (temp >= 0) {
		std::cout << "Enter key: ";
		std::getline(std::cin, str);
		temp = stoi(str);
		if (temp >= 0)
			this_map.erase(temp);
	}

	std::cout << "{   ";
	for (auto it = this_map.begin(); it != this_map.end(); it++)
		std::cout << it->first << "->" << it->second << "   ";
	std::cout << "}";


	return 0;
}