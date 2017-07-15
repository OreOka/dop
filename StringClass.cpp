/*
String class
*/
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

/*Rudimentary String class : not really what
I expect you would want to see. But, oh well!!
*/

class String
{
public:
	String();
	String(const char *const);
	String(const String &);
	~String();

	//overloaded operators
	char & operator[](unsigned short offset);
	char operator[](unsigned short offset) const;
	String operator+(const String&);
	void operator+=(const String&);
	String & operator= (const String &);

	//General accessors
	unsigned short GetLen() const { return itsLen; }
	const char * GetString() const { return itsString; }

private:
	String(unsigned short);				//this is a private constructor
	char * itsString;
	unsigned short itsLen;
};
//default constructor creates String of 0 bytes
String::String()
{
	itsString = new char[1];
	itsString[0] = '\0';
	itsLen = 0;
}

//private helper constructor: used by only class methods
//for creating new String of required size
String::String(unsigned short len)
{
	itsString = new char[len + 1];
	for (unsigned short i = 0; i <= len;i++)
		itsString[i] = '\0';
	itsLen = len;
}

//Converts character array to a string
String::String(const char * const cString)
{
	itsLen = strlen(cString);
	itsString = new char[itsLen + 1];
	for (unsigned short i = 0; i < itsLen; i++)
		itsString[i] = cString[i];
	itsString[itsLen] = '\0';
}

//copy constructor
String::String(const String & rhs)
{
	itsLen = rhs.GetLen();
	itsString = new char[itsLen + 1];
	for (unsigned short i = 0; i <itsLen;i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
}

//destructor used to free allocated memory
String::~String()
{
	delete[] itsString;
	itsLen = 0;
}

//operator equals, frees existing memory
//then copies string size

String& String ::operator=(const String& rhs)
{
	if (this == &rhs)
		return *this;
	delete[] itsString;
	itsLen = rhs.GetLen();
	itsString = new char[itsLen + 1];
	for (unsigned short i = 0; i <= itsLen;i++)
		itsString[i] = rhs[i];
	itsString[itsLen] = '\0';
	return *this;
}

//non constant offset operator, returns reference
//to character so that it can be changed!
char & String::operator[](unsigned short offset)
{
	if (offset > itsLen)
		return itsString[itsLen - 1];
	else
		return itsString[offset];
}

//constant offset operator  for use
//on constant obj(ie the copy constructor upwards)
char String::operator[](unsigned short offset)const
{
	if (offset > itsLen)
		return itsString[itsLen - 1];
	else
		return itsString[offset];
}

//creates new string by adding
//current String to rhs
String String::operator+(const String&rhs)
{
	unsigned short i;
	unsigned short totalLen = itsLen + rhs.GetLen();
	String temp(totalLen);
	for (i = 0; i < itsLen; i++)
		temp[i] = itsString[i];
	for (unsigned short j = 0; j < rhs.GetLen(); j++, i++)
		temp[i] = rhs[j];
	temp[totalLen] = '\0';
	return temp;
}

void String::operator+=(const String& rhs)
{
	unsigned short i;
	unsigned short rhsLen = rhs.GetLen();
	unsigned short totalLen = itsLen + rhsLen;
	String temp(totalLen);
	for (i = 0; i < itsLen;i++)
		temp[i] = itsString[i];
	for (unsigned short j = 0; j < rhs.GetLen(); j++, i++)
		temp[i] = rhs[i - itsLen];
	*this = temp;
}

int main()
{
	String s1("Initial Test");
	cout << "S1:\t" << s1.GetString() << endl;

	char * temp = "Hello World";
	s1 = temp;
	cout << "S!:\t" << s1.GetString() << endl;

	char tempTwo[20];
	strcpy_s(tempTwo, "nice to be here!");
	s1 += tempTwo;
	cout << "tempTwo:\t" << tempTwo << endl;
	cout << "S1:\t" << s1.GetString() << endl;

	cout << "S1[4]:\t" << s1[4] << endl;
	s1[4] = 'x';
	cout << "S1:\t" << s1.GetString() << endl;

	cout << "S![999]" << s1[999] << endl;

	String s2("Another String");
	String s3;
	s3 = s1 + s2;
	cout << "S3:\t" << s3.GetString() << endl;

	String s4;
	s4 = "Why does this work?";
	cout << "S4:\t" << s4.GetString() << endl;
	int fer;
	cin >> fer;
	return 0;
}
