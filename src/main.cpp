#include<iostream>

using namespace std;

string command;
int l;

int main(int argc, char *argv[]){
	command = "markdown -html5 " + string(argv[1]) + " >> " + string(argv[2]);
	l = command.length();
	char command_char[l];
	for(int i = 0; i < l; i++){
		command_char[i] = command[i];
	}
//	for(int i = 0; i < l; i++){
//		cout << command_char[i];	
//	}
	system(command_char);
}
