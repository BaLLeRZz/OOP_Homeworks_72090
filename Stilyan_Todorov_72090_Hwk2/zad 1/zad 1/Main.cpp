#include "String.h"
int main()
{
	String test1, test2, test3;
	std::cout << "Default Constructor: " << std::endl;
	test1.print();
	std::cout << std::endl;
	std::cout << "String Setter: " << std::endl;
	test1.setString("Hello World");
	test1.print();
	std::cout << std::endl;
	std::cout << "Adding a Symbol at the End: " << std::endl;
	test1.add('W');
	test1.print();
	std::cout << std::endl;
	std::cout << "Inserting a Symbol: " << std::endl;
	test1.insertAt('-', 4);
	test1.print();
	std::cout << std::endl;
	std::cout << "Removing a Symbol: " << std::endl;
	test1.removeAt(2);
	test1.print();
	std::cout << std::endl;
	std::cout << "Trimming the first element: " << std::endl;
	test1.trimStart();
	test1.print();
	std::cout << std::endl;
	std::cout << "Trimming the last element: " << std::endl;
	test1.trimEnd();
	test1.print();
	std::cout << std::endl;
	std::cout << "Trimming the First Elements: " << std::endl;
	test1.trimStartElements(2);
	test1.print();
	std::cout << std::endl;
	std::cout << "Trimming the Last Elements: " << std::endl;
	test1.trimEndElements(2);
	test1.print();
	std::cout << std::endl;
	std::cout << "Setting second object: " << std::endl;
	test2.setString("Hey");
	test2.print();
	std::cout << std::endl;
	std::cout << "Combining the two objects by operator +: " << std::endl;
	std::cout << test1 + test2;
	std::cout << std::endl << std::endl;
	std::cout << "Combining the two objects by operator +=: " << std::endl;
	test1 += test2;
	test1.print();
	std::cout << std::endl;
	std::cout << "Comparing the two objects by operator ==: " << std::endl;
	if (test1 == test2)
		std::cout << "Yes";
	else
		std::cout << "No";
	std::cout << std::endl << std::endl;
	std::cout << "Comparing the two objects by operator !=: " << std::endl;
	if (test1 != test2)
		std::cout << "Yes";
	else
		std::cout << "No";
	std::cout << std::endl << std::endl;
	std::cout << "Getting a Symbol by Index: " << std::endl;
	std::cout << test1[3];
	
	return 0;
}