// dequefun.cpp

//  Check out DequeFun.cpp Very nice and helpful file!

//   A Deque (double-ended Queue) is a sequence container
// that supports pushing and popping data, along with random acces.  


#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> numbers;
	int temp = 0;


	//   We push ints to the beck of the deque.
	cout << "Pushing Back...\n";
	while (temp >= 0) {
		cout << "Enter Number: ";
		cin >> temp;
		if (temp >= 0)
			numbers.push_back(temp);
	}

	//   We are iterating through the deque and printing contents
	deque<int>::iterator it;
	cout << "{  ";
	for (it = numbers.begin(); it != numbers.end(); it++)
		cout << *it << "  ";
	cout << "}";

	//   We are pushing ints to the back of the deque.
	temp = 0;
	cout << endl;
	cout << "Pushing Front...\n";
	while (temp >= 0) {
		cout << "Enter Number: ";
		cin >> temp;
		if (temp >= 0)
			numbers.push_front(temp);
	}

	//   Now we iterate through the deque again, using the same iterator.
	// We do need to reinitialize the iterator.
	cout << "{  ";
	for (it = numbers.begin(); it != numbers.end(); it++)
		cout << *it << "  ";
	cout << "}";



	return 0;
}