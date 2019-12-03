// Author:           CHRIS ANTHONY
// Assignment:       Program_04
// Date:             26 November 2019
// Title:            Program 4 - Caeser Cipher Class
// Semester:         Fall 2019
// Course:           CMPS 1063 
// 
// Files:            cipher.cpp 
//                   encrypted.txt
//                   decrypted.txt
//					 EncryptionTestFile.txt
//					 DecryptionTestFile.txt
//
// Description:	This program uses a class which contains various functions to
//				encrypt/decrypt an encrypted/decrypted message. The decrypted
//				message is then printed to the output file.  

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
* CaeserCipher class
*
* Description:
*      contains functions and variables to encrypt/decrypt strings
*
* variables:
*     int s : value used to encrypt/decrypt 
*/

class CaeserCipher {
private:
	int s;
public:
	CaeserCipher();
	string Encrypt(string);					    // encrypts a string given a specific shift value
	string Decrypt(string);						// decrypts a string given a specific shift value
	string UpperCase(string);					// a method that uppercases a string 
	void SetShift(int);							// sets the shift amount for your class 
	string ReadCipherText(ifstream&);			// reads an encrypted file into a string
	void WriteCipherText(ofstream&, string);	// writes an encrypted message to a file
	string ReadPlainText(ifstream&);			// reads a plain text file into a string
	void WritePlainText(ofstream&, string);		// writes a plain text string to a file
};

CaeserCipher::CaeserCipher() { // default constructor
	s = 13;
}

/**
* UpperCase
*
* Description:
*       function used to uppercase a string
*
* Params:
*      string txt : string to be uppercased
*
* Returns:
*      string txt: uppercased string
*/
string CaeserCipher::UpperCase(string txt) {
	for (int i = 0; i < txt.length(); i++) {
		if (txt[i] >= 97 && txt[i] <= 122) {
			txt[i] = txt[i] - 32;
		}
	}
	return txt;
}

/**
* Encrypt
*
* Description:
*      encrypts a string given a specific shift value
*
* Params:
*      string txt : message to be encrypted
*
* Returns:
*      string txt: encrypted message
*/
string CaeserCipher::Encrypt(string txt) {

	// traverse text 
	for (int i = 0; i < txt.length(); i++)
	{
		// apply transformation to each character
		if (txt[i] >= 65 && txt[i] <= 90) {
			txt[i] = char(int(txt[i] + s - 65) % 26 + 65);
		}
	}
	// Return the resulting string 
	return txt;
}

/**
* Decrypt
*
* Description:
*      decrypts a string given a specific shift value
*
* Params:
*      string txt : message to be decrypted
*
* Returns:
*      string txt: decrypted message  
*/
string CaeserCipher::Decrypt(string txt) {

	txt = UpperCase(txt);
	// traverse text 
	for (int i = 0; i < txt.length(); i++)
	{
		if (txt[i] >= 65 && txt[i] <= 90) {
		char base = txt[i];
		char shifted = base - s;	// apply transformation to each character
		if (shifted < 65) {
			shifted = (90 + 1) - (65 - shifted);
		}
		txt[i] = shifted;
		}
	}
	// Return the resulting string 
	return txt;
}

/**
* SetShift
*
* Description:
*     sets the shift amount for the class
*
* Params:
*      int shift : represents the shift value 
*
* Returns:
*      none
*/
void CaeserCipher::SetShift(int shift) {
	s = shift;
}

/**
* ReadCipherText
*
* Description:
*      reads an encrypted file into a string
*
* Params:
*      ifstream& fin : Stream class to read from file
*
* Returns:
*      string txt: message to be decrypted
*/
string CaeserCipher::ReadCipherText(ifstream& fin) { // reads an encrypted file into a string
	string txt;
	fin.ignore(1000, '\n');
	getline(fin, txt);
	txt = UpperCase(txt);
	return txt;
}

/**
* ReadPlainText
*
* Description:
*      reads a plain text file into a string
*
* Params:
*      ifstream& fin : Stream class to read from file
*
* Returns:
*      string txt: message to be encrypted
*/
string CaeserCipher::ReadPlainText(ifstream& fin2) {
	string txt;
	fin2.ignore(1000, '\n');
	getline(fin2, txt);
	txt = UpperCase(txt);

	return txt;
}

/**
* WritePlainText
*
* Description:
*    writes a plain text string to the file
*
* Params:
*      string txt : decrypted message
*		ofstream & outfile : Stream class to write to file
*
* Returns:
*      none
*/
void CaeserCipher::WritePlainText(ofstream& outfile, string txt) {

	outfile << txt << "\n\n";
}

/**
* WriteCipherText
*
* Description:
*      writes an encrypted message to a file
*
* Params:
*      string txt : encrypted message 
*		ofstream & outfile : Stream class to write to file
*
* Returns:
*      none
*/
void CaeserCipher::WriteCipherText(ofstream& outfile2, string txt) {

	outfile2 << txt << "\n\n";
}


/**
 * Main Driver
 *
 */
int main() {
	ifstream fin;				 // Declare an input file
	ofstream out;			     // Declare an output file
	out.open("decrypted.txt");	 // Create "decrypted.txt" for writing
	fin.open("encrypted.txt");   // Open "encrypted.txt" for reading

	out << "CHRIS ANTHONY\n";		// Write my name to "decrypted.txt"
	out << "November 26th 2019\n";
	out << "Program 4 output\n\n";


	ifstream fin2;                        // Declare a second input file
	ofstream out2;						  // Declare a second output file
	out2.open("DecryptionTestFile.txt");  // Create "DecryptedTestFile.txt" for writing
	fin2.open("EncryptionTestFile.txt");  // Open "EncryptionTestFile.txt" for reading

	out2 << "CHRIS ANTHONY\n";		// Write my name to "DecryptedTestFile.txt"
	out2 << "November 26th 2019\n";
	out2 << "Program 4 output\n\n";


	int runs;		  // number of messages to run
	int shift = 13;	  // variable for shift value
	string message;   // variable to store message
	CaeserCipher C;

	fin >> runs;

	for (int i = 0; i < runs; i++) {

		fin >> shift;			
		C.SetShift(shift);						// set shift
		message = C.ReadCipherText(fin);		// read in the encrypted text
		message = C.Decrypt(message);			// decrypt the text
		C.WritePlainText(out, message);			// write decrypted text to file 
	}

	
	// Testing Encryption
	fin2 >> runs;

	for (int i = 0; i < runs; i++) {

		fin2 >> shift;
		C.SetShift(shift);						// set shift
		message = C.ReadPlainText(fin2);		// read in the encrypted text
		message = C.Encrypt(message);			// decrypt the text
		C.WriteCipherText(out2, message);			// write decrypted text to file 
	}

	out.close(); //command to close outfile
	out2.close(); //command to close outfile2

	return 0;
}