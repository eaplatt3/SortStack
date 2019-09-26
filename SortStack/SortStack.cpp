#include <iostream>
#include <stack>

using namespace std;

stack<int> sortStack(stack<int> &inputStack)
{
	//Create Temp Stack 
	stack<int> tmpStack;

	while (!inputStack.empty())
	{
		// pop out the first element 
		int tmp = inputStack.top();
		inputStack.pop();

		cout << "tmp is: " << tmp << endl;

		// while temporary stack is not empty and top 
		// of stack is greater than temp 
		while (!tmpStack.empty() && tmpStack.top() > tmp)
		{
			// pop from temporary stack and push 
			// it to the input stack 
			inputStack.push(tmpStack.top());
			tmpStack.pop();
		}
		// push temp in tempory of stack 
		tmpStack.push(tmp);
	}

	return tmpStack;
}

int main()
{
	//Variables
	int rNum;

	//Orginal Stack
	stack<int> inputStack;

	cout << "Unsorted Stack" << endl;

	//Random ints and populates stack 
	while (inputStack.empty()) {

		for (int i = 0; i < 10; i++) {

			rNum = 1 + rand() % 1000; //Random Gen Stack numbers -> Temp problem

			cout << rNum << " ";

			inputStack.push(rNum);
		}
	}

	cout << " " << endl;

	// This is the temporary stack 
	stack<int> tmpStack = sortStack(inputStack);
	cout << "Sorted numbers are:\n";

	//Prints orginal stack in sorted order
	while (!tmpStack.empty())
	{
		cout << tmpStack.top() << " ";
		tmpStack.pop();
	}
}

