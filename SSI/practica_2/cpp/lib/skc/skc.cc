#include "skc.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

Vector Skc::s_to_v(string s){
	Vector aux;
	//cout << "SS: " << s << endl;
	stringstream ss;
	ss << s << endl;
	int number;
	while (ss.peek() != '\n') {
		ss >> number;
		//cout << "Number: " << number << endl;
		aux.push_back(number);
	}
	return aux;
}

string Skc::int2bin(int number) {
	if ( number == 0 ) return "0";
	if ( number == 1 ) return "1";

	if ( number % 2 == 0 )
		return int2bin(number / 2) + "0";
	else
		return int2bin(number / 2) + "1";
}
string Skc::int2hex(int number) {
	stringstream ss;
	ss << hex << number;
	string hexn;
	ss >> hexn;
	return hexn;
}

string Skc::to_s(const char MODE) {
	stringstream ss;
	if (_message.size() > 0) {
		switch (MODE) {
			case BIN: {
				for (int i = 0; i < _message.size() -1; i++) {
					ss << int2bin(_message[i]) << " ";
				}
				ss << int2bin(_message[_message.size() -1]);
				break;
			}
			case HEX: {
				for (int i = 0; i < _message.size() -1; i++) {
					ss << int2hex(_message[i]) << " ";
				}
				ss << int2hex(_message[_message.size() -1]);
				break;
			}
			case DEC: {
				for (int i = 0; i < _message.size() -1; i++) {
					ss << _message[i] << " ";
				}
				ss << _message[_message.size() -1];
				break;
			}
		}
	}
	string msg = "";
	ss << endl;
	while (ss.peek() != '\n') {
		string aux;
		ss >> aux;
		msg.append(aux);
		msg.append(" ");
	}
	return msg;
}
