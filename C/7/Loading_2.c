#define _CRT_SECURE_NO_WARNINGS

// The program calculates the area and the perimeter of a triangle
#include "stdio.h"
#include "windows.h"
#include "math.h"

#define sizeofTriangle 6

// Conditions
int choiseTriangle(int choice); 
void rightTriangle(int value);
void isoscelesTriangle(int value);
void equilateralTriangle(value);
void TrianglePicture1(int size);
void TrianglePicture23(int size);

// Operations
float operationofRightTriangle(float cathet, float cathet2);
float operationofIsoscelesTriangle(float base, float height);
float operationofEquilateralTriangle(float sizes);

void color(color);

int main()
{
	int choice;
	color(14);
	printf("Choose which triangle you need!\n");
	// 1) Прямоугольный треугольник с катетами a и b
	printf("1) Right triangle with legs 'a' and 'b'\n");  
	// 2) Равнобедренный треугольник с основанием а и высотой h
	printf("2) Isosceles triangle with base 'a' and height 'h'\n"); 
	// 3) Равностороннего треугольника со стороной равной a
	printf("3) An equilateral triangle with side equal to a\n");
	color(15);
	printf("Choose which triangle you can calculate the area (from 1 to 3): ");
	scanf("%d",&choice);
	system("cls");
	choiseTriangle(choice);
}

int choiseTriangle(int choice)
{
	if (choice == 1)
	{
		rightTriangle(choice);
		return 0;
	}
	else if (choice == 2)
	{
		isoscelesTriangle(choice);
		return 0;
	}
	else if (choice == 3)
	{
		equilateralTriangle(choice);
		return 0;
	}
	return 0;
}

void rightTriangle(int value)
{
	color(6);
	printf("--------Your choise--------\n"
		   "1) Right triangle with cathetus 'a' and 'b'\n");
	TrianglePicture1(sizeofTriangle);
	float cathet, cathet2;
	color(5);
	printf("\nFirst Cathet = ");
	scanf("%f",&cathet);
	printf("Second Cathet = ");
	scanf("%f", &cathet2);
	operationofRightTriangle(cathet,cathet2);
	return;
}

void isoscelesTriangle(int value)
{
	color(6);
	printf("--------Your choise--------\n"
		   "2) Isosceles triangle with base 'a' and height 'h'\n");
	TrianglePicture23(sizeofTriangle);
	float base, height;
	color(5);
	printf("\nBase = ");
	scanf("%f", &base);
	printf("Height = ");
	scanf("%f", &height);
	operationofIsoscelesTriangle(base, height);
	return;
}

void equilateralTriangle(int value)
{
	color(6);
	printf("--------Your choise--------\n"
		   "3) An equilateral triangle with side equal to a\n");
	TrianglePicture23(sizeofTriangle);
	color(5);
	float sizes;
	printf("\n Sizes = ");
	scanf("%f",&sizes);
	operationofEquilateralTriangle(sizes);
	return;
}

void TrianglePicture1(int size )
{
	color(10);
	for (int i = 1; i <= size; ++i)
	{
		for (int j = 1; j < 2 * i; ++j)
			printf("*");
		printf("\n");
	}
}

void TrianglePicture23(int size)
{
	color(10);
	for (int i = 1; i <= size; ++i)
	{
		for (int j = size; j > i; --j)
			putchar(' ');
		for (int j = 1; j < 2 * i; ++j)
			printf("*");
		printf("\n");
	}
}

float operationofRightTriangle(float cathet, float cathet2)
{
	float hypotenuse,P,S;
	hypotenuse = sqrt(cathet * cathet + cathet2 * cathet2);
	P = cathet + cathet2 + hypotenuse;
	S = cathet * cathet2 / 2;
	printf("\n1)The perimeter is %.1f\n2)The area is %.1f\n ", P, S);
	return 0;
}

float operationofIsoscelesTriangle(float base, float height)
{
	float hypotenuse, P, S, halfofBase;
	halfofBase = base / 2;
	hypotenuse = sqrt(halfofBase * halfofBase + height * height);
	P = 2 * hypotenuse + base;
	S = base * height;
	printf("\n1)The perimeter is = %1f\n2)The area is = %1f\n", P, S);
	return 0;
}

float operationofEquilateralTriangle(float sizes)
{
	float P, S;
	P = 3 * sizes;
	S = sizes * sizes*sqrt(3)/4;
	printf("\n1)The perimeter is=%.1f\n2)The area is = %.1f\n", P, S);
	return 0;
}

void color(color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}