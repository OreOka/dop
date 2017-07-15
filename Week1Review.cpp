/*
Cpp in 21 Review of week 1's Work. This would be a really long one...
Let's go
*/
#include "stdafx.h"
#include <iostream>

//Let's add some variables
typedef unsigned short int USHORT;
typedef unsigned long int ULONG;
enum BOOL { FALSE, TRUE };
enum Choice {
	DrawRect = 1, GetArea,
	GetPerim, ChangeDimensions, Quit
};
//REctangle class Declaration
class Rectangle
{
public:
	//constructors
	Rectangle(USHORT width, USHORT height);
	~Rectangle();

	//accessors
	USHORT GetHeight() const { return itsHeight; }
	USHORT GetWidth() const { return itsWidth; }
	ULONG GetArea() const { return itsHeight * itsWidth; }
	ULONG GetPerim() const { return 2 * (itsHeight + itsWidth); }

	void SetSize(USHORT newWidth, USHORT newHeight);

	//Misc Methods
	void DrawShape() const;

private:
	USHORT itsHeight, itsWidth;
};
//now, implementing the methods
Rectangle::Rectangle(USHORT width, USHORT height)
{
	itsWidth = width;
	itsHeight = height;
}

void Rectangle::SetSize(USHORT newWidth, USHORT newHeight) {
	itsHeight = newHeight;
	itsWidth = newWidth;
}

Rectangle::~Rectangle() {}

USHORT DoMenu();
void DoDrawRect(Rectangle);
void DoGetPerim(Rectangle);
void DoGetArea(Rectangle);



using namespace std;
void main() {
	Rectangle theRect(30, 5);
	USHORT choice = DrawRect;
	USHORT fQuit = FALSE;

	while (!fQuit)
	{
		choice = DoMenu();
		if (choice < DrawRect || choice > Quit) {
			cout << "Invalid choice, please try again.\n\n";
			continue;
		}
		switch (choice)
		{
		case DrawRect:
			DoDrawRect(theRect);
			break;
		case GetArea:
			DoGetArea(theRect);
			break;
		case GetPerim:
			DoGetPerim(theRect);
			break;
		case ChangeDimensions:
			USHORT newLength, newWidth;
			cout << "\nNew Height: ";
			cin >> newLength;
			cout << "\nNew Width: ";
			cin >> newWidth;
			theRect.SetSize(newWidth, newLength);

			DoDrawRect(theRect);
			break;
		case Quit:
			fQuit = TRUE;
			cout << "Exiting...";
			break;
		default:
			cout << "Error in Choice\n";
			fQuit = TRUE;
			break;
		}
	}

	//int fert;
	//	cin >> fert;

}

USHORT DoMenu()
{
	USHORT choice;
	cout << "\n\n  ****Menu****\n";
	cout << "(1) Draw Rectangle\n";
	cout << "(2) Area\n";
	cout << "(3) Perimeter\n";
	cout << "(4) Resize\n";
	cout << "(5) Quit\n\t";

	cin >> choice;
	return choice;
}

void DoDrawRect(Rectangle theRect)
{
	USHORT height = theRect.GetHeight();
	USHORT width = theRect.GetWidth();

	for (USHORT i = 0; i < height; i++) {
		for (USHORT j = 0; j < width; j++) {
			cout << "0";
		}cout << "\n";
	}
}

void DoGetArea(Rectangle theRect)
{
	cout << "Area: " << theRect.GetArea() << endl;
}

void DoGetPerim(Rectangle theRect)
{
	cout << "Perimeter: " << theRect.GetPerim() << endl;
}
