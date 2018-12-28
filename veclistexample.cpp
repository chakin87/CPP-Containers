

//		This program uses either list of vector to keep track of party guests

//   ** NOTE ** This program uses the my_guests.txt.
// Make sure that my_guests.txt is in the correct folder :)


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <typeinfo>

//   The defines below allow the use of either vector or list
// to store the guest list that is read in from the text file
// 'my_guests.txt'.


#define USE_VECTOR 
//#define USE_LIST 


// The guest class stores the information of the guests.
class guest {
public:
	guest() {}
	~guest() {}
	void set_gender(std::string in) {
		char i = in.c_str()[0];
		if (i == 'b' || i == 'B' || i == 'm' || i == 'M')
			gender = "Boy";
		else
			gender = "Girl";
	}
	std::string name;
	std::string gender;
	int age;
};

// If the macro USE_VECTOR is defined, we use a vector<guest>.
#ifdef USE_VECTOR
typedef std::vector<guest> my_container;
// If the macro USE_LIST is defined, we use a list<guest>.
#elif defined USE_LIST
typedef std::list<guest> my_container;
#endif

//  As you can see below, the vector and list containers
// can be used in similar ways, although the behavior of
// them behind the scenes is different.
void read_file(my_container* my_guests) {
	std::string in_str;
	std::ifstream in_file("src/my_guests.txt");
	if (in_file.is_open()) {
		guest temp;
		while (getline(in_file, in_str)) {
			temp.name = in_str;
			std::getline(in_file, in_str);
			temp.set_gender(in_str);
			std::getline(in_file, in_str);
			temp.age = stoi(in_str);
			my_guests->push_back(temp);
		}
		in_file.close();
	}
	else
		std::cout << "Unable to open file!\n\n";
}

void print_guests(my_container* my_guests) {
	auto it = my_guests->begin();

	std::cout << "\n\n-- Container Content Start --\n";
	std::cout << "-----------------------------\n";
	while (it != my_guests->end()) {
		std::cout << "Name: " << it->name << std::endl;
		std::cout << "Gender: " << it->gender << std::endl;
		std::cout << "Age: " << it->age << std::endl;
		std::cout << "-----------------------------\n";
		++it;
	}
	std::cout << "--  Container Content End  --\n\n\n";
}

//   This functions returns a bool, which tells if the index is found.
// A temperary guest is passed by ref to the function, and if the index
// is availiable, then the temp guest points to the guest at the index.
// since the function must work for either a vector or a list,
// we iterate through the container sequentially
bool get_guest(my_container* container, int index, guest &ret) {
	auto it = container->begin();
	for (int i = 0; i < index; ++i, ++it)
		if (it == container->end())
			return false;
	ret = *it;
	return true;
}

//   This functions deletes a guest at index.
// since the function must work for either a vector or a list,
// we iterate through the container sequentially
bool delete_guest(my_container* container, int index) {
	auto it = container->begin();
	for (int i = 0; i < index; ++i, ++it)
		if (it == container->end())
			return false;
	container->erase(it);
	return true;
}

float average_guest_age(const my_container& container) {
	float avg = 0.0f;
	for (guest g : container)
		avg += g.age;
	avg = avg / container.size();
	return avg;
}

int main(int argc, char** argv) {
	my_container* my_guests = new my_container;
	std::cout << "my_container* created of type: " << typeid(my_container).name() << "\n\n";
	read_file(my_guests);
	print_guests(my_guests);

	//   Create a guest obj to use for the get_guest() function.
	// Since the temp guest points to the 'real' guest at said index,
	// you can modify the guest through this temp guest.
	guest temp;
	if (get_guest(my_guests, 3, temp)) {
		std::cout << "\n----------------------" << std::endl;
		std::cout << "Name: " << temp.name << std::endl;
		std::cout << "Gender: " << temp.gender << std::endl;
		std::cout << "Age: " << temp.age << std::endl;
		std::cout << "----------------------\n" << std::endl;
	}
	else
		std::cout << "get_guest failed!!!" << std::endl;

	if (!delete_guest(my_guests, 3))
		std::cout << "delete_guest failed!!!" << std::endl;

	print_guests(my_guests);

	std::cout << "\n\nThe average age is " << average_guest_age(*my_guests) << std::endl;

	delete_guest(my_guests, 2);
	print_guests(my_guests);


	delete my_guests;
	std::cout << "\nmy_container* deleted." << std::endl;

	std::string pause;
	std::cin >> pause;

	return 0;
}