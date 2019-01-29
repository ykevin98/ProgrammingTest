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

string decryptDNA(string str) {
	string DNA = str;
	string binary = "";
	for (int i = 0; i < str.length(); i++) {
		char curr = DNA.at(i);
		if (curr == 'A') {
			binary += "00";
		}
		else if (curr == 'T') {
			binary += "01";
		}
		else if (curr == 'G') {
			binary += "10";
		}
		else if (curr == 'C') {
			binary += "11";
		}
	}
	return binary;
}

int binaryCalculator(string str) {
	/* Calculates the decimal value of the binary number */
	int value = 0;
	int indexCounter = 0;
	for (int i = str.length() - 1; i > -1; i--) {
		char curr = str.at(i);
		if (curr == '1') {
			value += pow(2, indexCounter);
		}
		indexCounter++;
	}
	//cout << "The deciminal value of " << str << " is " << value << endl;
	return value;
}

string returnStr(string str) {
	/* returns the text string of a given DNA strand */
	string temp = str;
	string combine = "";
	for (int i = 0; i < str.length(); i += 8) {
		string current = str.substr(i, 8);
		int integerValue = binaryCalculator(current);
		char ASCIIVAlue = char(integerValue);
		combine += ASCIIVAlue;
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

char toDNA(char compDNA) {
	/* converts one DNA nucleotide to match the other */
	// A and T
	// C and G
	switch (compDNA) {
	case 'A':
		return 'T';
	case 'T':
		return 'A';
	case 'C':
		return 'G';
	case 'G':
		return 'C';
	default:
		return compDNA;
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

string inverseDNA(string str) {
	/* creates a second strand of DNA that mataches every A to T and G to C */
	string DNA = "";
	for (int i = 0; i < str.length(); i++) {
		DNA += toDNA(str.at(i));
	}
	return DNA;
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

	/* converts the string to DNA */
	string DNA = encodeDNA(bin); 
	
	/* encodes an exisiting DNA to RNA */
	string RNA = encodeRNA(DNA);
	//cout << "The binary value of " << bin << " is " << bin << endl;

	if (choice == "1") {
		cout << "The DNA encoder of " << input << " is " << DNA << endl;
	}
	if (choice == "2") {
		cout << "The RNA encoder of " << DNA << " is " << RNA << endl;
	}

	/* Objective 4 */

	string compDNA = "ACTGACTAAGAT"; // using the given DNA strand from the prompt
	string newDNA = inverseDNA(compDNA);

	cout << "The matched DNA to each nucleotide for " << compDNA << " is " << newDNA << endl;

	string binary = decryptDNA(newDNA);
	cout << "The binary number of " << newDNA << " is " << binary << endl;

	string text = returnStr(binary);
	cout << "The DNA strand is " << text << endl;

	return 0;
}
