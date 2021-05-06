#include "Command.h"
int main()
{
	//char* command = new char[25];
	//std::cout << "Choose Command: ";
	//std::cin.getline(command, 25, '\n');
	//std::cout << command;
	Command test;
	test.commandList();
	test.chooseCommand();
	test.executeCommand();
	return 0;
}