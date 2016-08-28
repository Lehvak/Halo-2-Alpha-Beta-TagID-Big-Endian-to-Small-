#include<stdio.h>
#include<iostream>
#include<conio.h> 

using namespace std;

unsigned int small_endian_calculate(unsigned int x, int endian), little, place = 0, lay, shift_amount;
int myPause(), help, small_endian_output(), small_endian_calculate();

int main()
{
	cout << "[Xbox] Halo 2 Alpha/Beta Ident Assist// Big Endian To little Endian";
	cout << "\n\nEnter 1 To Understand How To Find The Decimal Ident. Enter 2 to Skip. ";
	cin >> help;
	switch (help)
	{
	case 1:
		cout << "Open the tool Nova and navigate to the tag and note it's ident (tag Id/File Identification will be in base 10). The Fusion Coil on Zanzabar is -388102295 convert this to base 16 (with the negative sign) you will get FFFFFFFFE8DE0769 from here you will see the first 8 bytes are null and the second 8 bytes, E8DE0769, are the big endian raw tagID ";
		small_endian_output();
		break;
	case 2:
		small_endian_output();
		break;
	default:
		cout << "Invaild Key" << endl;
		break;
	}
	myPause();
}
unsigned int small_endian_calculate(unsigned int x, int endian)
{
	switch (endian)
	{
	case 1:
		lay = 0xff;
		shift_amount = 8;
		break;

	default:
		return 0x0;
	}

	while (x)
	{
		place <<= shift_amount;
		place |= (x & lay);
		x >>= shift_amount;
	}
	return place;
}
int myPause()
{
	cout << "\n\nEnter Any Key To Close" << endl;
	_getch(); //leaves terminal open untill user inputs a key                           
	return 0;
}
int small_endian_output()
{
	cout << "\n\nRaw Big Endian: ";
	scanf_s("%x", &little);
	printf("\nLittle Endian (Reverse Endian) : %X",
		small_endian_calculate(little, 1));
	return little;
}



