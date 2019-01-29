#include <iostream>
#include <string>

using namespace std;

string convertAscii(int num) {
	/* driver function to convert character to binary ASCII */
	int value = num;
	string bin = "";
	while (value > 0) {
		if (value % 2 == 1) {
			bin.push_back('1');
		}
		else {
			bin.push_back('0');
		}
		value /= 2;
	}
	int len = bin.length();
	for (int i = 0; i < 8 - len; i++) {
		bin.push_back('0');
	}
	reverse(bin.begin(), bin.end());
	return bin;
}

string toBinary(string str) {
	/* function that converts text string to binary string */
	string newStr = str;
	string combineBinary = "";
	for (int i = 0; i < newStr.length(); i++) {
		/* convert each char to ASCII value */
		int value = int(newStr.at(i));

		// convert the ASCII value to 8 bit binary //
		string binaryValue = convertAscii(value);
		combineBinary += binaryValue;
	}
	return combineBinary;
}

string encodeDNA(string str) {
	string binary = str;
	string combine = "";
	for (int i = 0; i < str.length(); i+=2) {
		string curr = binary.substr(i, 2);
		if (curr == "00") {
			combine += "A";
		}
		else if (curr == "01") {
			combine += "T";
		}
		else if (curr == "10") {
			combine += "G";
		}
		else if (curr == "11"){
			combine += "C";
		}
	}
	return combine;
}

char toRNA(char DNA) {
	/* converts one DNA nucleotide to RNA nucleotide */
	switch (DNA) {
	case 'G':
		return 'C';
	case 'A':
		return 'U';
	case 'T':
		return 'A';
	case 'C':
		return 'G';
	default:
		return DNA;
	}
}

string encodeRNA(string str) {
	/* converts the string from DNA to RNA */
	string RNA = "";
	for (int i = 0; i < str.length(); i++) {
		RNA += toRNA(str.at(i));
	}
	return RNA;
}

int main() {
	/* Objective 1 and 2 */
	string input;
	string choice;
	cout << "Type any string" << endl;
	getline(cin, input);

	cout << "Type 1 to encode in DNA. Type 2 to encode in RNA" << endl;
	cin >> choice;

	string bin = toBinary(input);
	string DNA = encodeDNA(bin); 
	string RNA = encodeRNA(DNA);
	//cout << "The binary value of " << bin << " is " << bin << endl;
	if (choice == "1") {
		cout << "The DNA encoder of " << input << " is " << DNA << endl;
	}
	if (choice == "2") {
		cout << "The RNA encoder of " << DNA << " is " << RNA << endl;
	}

	
	return 0;
}