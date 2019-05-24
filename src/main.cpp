#include<iostream>

using namespace std;

string command,
       md_filename,
       html_filename;
int l;

int main(int argc, char *argv[]){
	md_filename = string(argv[1]);
	html_filename = string(argv[2]);
//Debug code
//	cout << "Markdown filename is " << md_filename << endl;
//	cout << "Output html filename is " << html_filename << endl;

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
