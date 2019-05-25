#include<iostream>

using namespace std;

string command,
       md_filename,
       html_filename;
int l;

void msleep(unsigned long milisec)
{
    struct timespec req={0};
    time_t sec=(int)(milisec/1000);
    milisec=milisec-(sec*1000);
    req.tv_sec=sec;
    req.tv_nsec=milisec*1000000L;
    while(nanosleep(&req,&req)==-1)
        continue;
}

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
	while(true){
		system(command_char);
		msleep(10000);
	}
}
