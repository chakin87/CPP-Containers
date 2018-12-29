//		Stack and Queue use-case scenario
// 1. We are righting the code to keep track of URLs that a browser visits.
// 2. The program will allow the user to enter a URL to go to..
// 3. The program will create a stack to use for the back button in the browser.
//  - The back button stack will emulate pressing the back button in any browser.
// 4. The program will have another stack that will do the same for the browser forward button.




#include <iostream>
#include <stack>
#include <string>

int main() {

	// Here we instanciate the two stacks.
	std::stack<std::string> back_stack;
	std::stack<std::string> fwd_stack;
	std::string temp;

	while (temp != "exit") {
		std::cout << "[1] Visit URL   [2] Back    [3]Forward" << std::endl;
		std::cin >> temp;
		// If use types 'exit' then the program ends.
		if (temp == "exit")
			break;
		//   User enters a new URL. The forward_stack is 'reset' because
		// the URL starts a 'new branch'(for lack of a better explanation).
		if (temp == "1") {
			std::cout << "Enter URL: ";
			std::cin >> temp;
			back_stack.push(temp);
			fwd_stack = std::stack<std::string>();
		}
		//   If the user wants to go back, we push the top item
		// of the back stack to the forward stack and then pop it 
		// from the back_stack.
		else if (temp == "2") {
			std::cout << " Going back..." << std::endl;
			fwd_stack.push(back_stack.top());
			back_stack.pop();
		}
		//   If the user wants to go forward, we push the forward_stack.top()
		// to the back_stack, and  then pop it from forward_stack.
		else if (temp == "3") {
			if (fwd_stack.empty())
				std::cout << "No forward history!" << std::endl;
			else {
				std::cout << "Going forward... " << std::endl;
				back_stack.push(fwd_stack.top());
				fwd_stack.pop();
			}
		}
		if (back_stack.empty())
			break;
		std::cout << "\nCurrent URL: " << back_stack.top() << std::endl;
	}

	return 0;
}