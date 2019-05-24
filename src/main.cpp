#include<iostream>

using namespace std;

string command;

//string arg1;
//string arg2;

int main(int argc, char *argv[]){
	command = "markdown -html " + string(argv[1]) + " >> " + string(argv[2]);
//	system("markdown -html " + string(argv[1]) + " >> " + string(argv[2]));
	cout << command << endl; //For debug
	char command_char[command.length];
	for(int i = 0; i < command.length; i++){
		command_char[i] = command[i];
	} 
//	arg1 = string(argv[1]);
//	arg2 = string(argv[2]);
}
