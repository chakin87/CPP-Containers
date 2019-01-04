//				Create a Hotel Registry
// + Keep track of the Room number and Name of guest
// + Do not accept duplicates rooms
// + Enter rooms and guests into program
// + Make modifications and check that duplicate rooms are not accepted
// + Delete any rooms that have 'checked out'




#include <iostream>
#include <map>
//#include <unordered_map>
#include <string>


int main() {
	std::map<int, std::string> hotel;
	int temp = 0;
	std::string str;
	std::pair<int, std::string> p;

	std::cout << "Inserting...\n";
	while (temp >= 0) {
		std::cout << "Enter room number: ";
		std::getline(std::cin, str);
		temp = stoi(str);
		if (temp >= 0) {
			p.first = temp;
			std::cout << "Enter name: ";
			std::getline(std::cin, str);
			p.second = str;
			hotel.insert(p);
		}
	}

	std::cout << "{   ";
	for (auto it = hotel.begin(); it != hotel.end(); it++)
		std::cout << it->first << "->" << it->second << "   ";
	std::cout << "}\n";


	std::cout << "Enter an existing room number: ";
	std::getline(std::cin, str);
	temp = stoi(str);
	p.first = temp;
	std::cout << "Enter a name: ";
	std::getline(std::cin, str);
	p.second = str;
	hotel.insert(p);

	std::cout << "Enter an existing room number to delete: ";
	std::getline(std::cin, str);
	temp = stoi(str);
	hotel.erase(temp);

	std::cout << "{   ";
	for (auto it = hotel.begin(); it != hotel.end(); it++)
		std::cout << it->first << "->" << it->second << "   ";
	std::cout << "}\n";

	std::string pause;
	std::cin >> pause;

	return 0;
}