#include"../lib/msleep/msleep.hpp"
#include<iostream>
#include<fstream>

using namespace std;

string command,
       md_filename,
       html_filename,
       token;
int l,
    update_time;

string parser(string input){
	string delimiter = ".md";
	string token = input.substr(0, input.find(delimiter));
	return token;	
}

int main(int argc, char *argv[]){
	switch(argc){
		case 2:{
			md_filename = string(argv[1]); //Markdown filename
			html_filename = parser(md_filename) + ".html";
			command = "markdown -html5 " + md_filename + " >> " + html_filename; //Command that will compile markdown code to html5 code

			l = command.length(); //Length of the command
			char command_char[l]; //Command but in char array
		
			//Converting string to char array	
			for(int i = 0; i < l; i++)
				command_char[i] = command[i];
		
			ofstream clear; //Creating ofstream object for clearing the file
			while(true){
				clear.open(html_filename); //Opening output (html5) file
				clear.close(); //Closing output (html5) file for clearing output file
				
				system(command_char); //Performing command
			}

			break;
		}
		case 3:{
			//if argc = 3
			md_filename = string(argv[1]); //Markdown filename
			html_filename = string(argv[2]); //Output (html5) filename
			command = "markdown -html5 " + md_filename + " >> " + html_filename; //Command that will compile markdown code to html5 code
			
			l = command.length(); //Length of the command
			char command_char[l]; //Command but in char array
		
			//Converting string to char array	
			for(int i = 0; i < l; i++)
				command_char[i] = command[i];
		
			ofstream clear; //Creating ofstream object for clearing the file
			while(true){
				clear.open(html_filename); //Opening output (html5) file
				clear.close(); //Closing output (html5) file for clearing output file
				
				system(command_char); //Performing command
			}
			break;
		}
		case 4:{
			//if argc = 4
			md_filename = string(argv[1]); //Markdown filename
			html_filename = string(argv[2]); //Output (html5) filename
			update_time = atof(argv[3]) * 1000; //Time between output file updates
			command = "markdown -html5 " + md_filename + " >> " + html_filename; //Command that will compile markdown code to html5 code
			
			l = command.length(); //Length of the command
			char command_char[l]; //Command but in char array

			//Converting string to char array	
			for(int i = 0; i < l; i++)
				command_char[i] = command[i];

			ofstream clear; //Creating ofstream object for clearing the file
			while(true){
				clear.open(html_filename); //Opening output (html5) file
				clear.close(); //Closing output (html5) file for clearing output file
			
				system(command_char); //Performing command
				msleep(update_time); //Delay between updates
			}
			break;
		}
		default:{
			cout << "Error too many or not enough arguments" << endl;
		}
	}
}
