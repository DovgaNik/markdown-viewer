#include<iostream>
#include<fstream>

using namespace std;

string command,
       md_filename,
       html_filename;
int l,
    update_time;

void msleep(unsigned long milisec){
    struct timespec req={0};
    time_t sec=(int)(milisec/1000);
    milisec=milisec-(sec*1000);
    req.tv_sec=sec;
    req.tv_nsec=milisec*1000000L;
    while(nanosleep(&req,&req)==-1)
        continue;
}

int main(int argc, char *argv[]){
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
}
