#include"parser.hpp"

string parser(string input){
	string delimiter = ".md";
	string token = input.substr(0, input.find(delimiter));
	return token;	
}
