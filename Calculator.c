#include "stdio.h"
#include "math.h"
#include "stdlib.h"
void foursquare()
{
	double a,perimetr,area;
	printf_s("Пожалуйста,введите сторону вашего квадрата:");
	scanf_s("%lf", &a);
	perimetr = 4 * a;
	printf_s("Периметр = %lf\n",perimetr);
	area = pow(a, 2);
	printf_s("Площадь = %lf\n\n", area);
}
void righttriangle()
{
	double a, b,c,perimetr,area;
	printf_s("Пожалуйста, введите сторону A вашего ПРЯМОУГОЛЬНОГО треугольника: ");
	scanf_s("%lf", &a);
	printf_s("Пожалуйста, введите сторону B вашего ПРЯМОУГОЛЬОГО треугольника: ");
	scanf_s("%lf", &b);
	c = sqrt(pow(a, 2) + pow(b, 2));
	perimetr = a + b + c;
	printf_s("Периметр = %lf\n",perimetr);
	area = (a * b) / 2.0;
	printf_s("Площадь = %lf\n\n",area);
}
void isoscelestriangle()
{
	double a, h, b,perimetr,area;
	printf_s("Пожалуйта, введите основание вашего РАВНОБЕДРЕННОГО ТРЕУГОЛЬНИКА: ");
	scanf_s("%lf", &a);
	printf_s("Пожалуйста, введите высоту вашего РАВНОБЕДРЕННОГО ТРЕУГОЛЬНИКА: ");
	scanf_s("%lf", &h);
	b = sqrt(pow((a / 2), 2) + pow(h, 2));
	perimetr = 2 * b + a;
	printf_s("Периметр = %lf\n", perimetr);
	area = (a * h) / 2.0;
	printf_s("Площадь = %lf\n\n", area);
}
void isoscelestrapezoid()
{
	double a, b, h, triangleSide, trapezoidSide,perimetr,area;
	printf_s("Пожалуйста, введите основание A вашей РАВНОБЕДРЕННОЙ ТРАПЕЦИИ: ");
	scanf_s("%lf", &a);
	printf_s("Пожалуйста, введите основание B вашей РАВНОБЕДРЕННОЙ ТРАПЕЦИИ: ");
	scanf_s("%lf", &b);
	printf_s("Пожалуйста, введите высоту вашей РАВНОБЕДРЕННОЙ ТРАПЕЦИИ:");
	scanf_s("%lf", &h);		
	triangleSide = fabs(a - b) / 2.0;
	trapezoidSide = sqrt(pow(triangleSide, 2) + pow(h, 2));
	perimetr = a + b + trapezoidSide * 2.0;
	printf_s("Периметр = %lf\n",perimetr);
	area = ((a + b) * h) / 2.0;
	printf_s("Площадь = %lf\n\n",area);
}
void equilateraltriangle()
{
	double a,perimetr, area;
	printf_s("Пожалуйста, введите сторону вашего РАВНОСТОРОННЕГО ТРЕУГОЛЬНИКА: ");
	scanf_s("%lf", &a);
	perimetr = 3.0 * a;
	printf_s("Периметр = %lf\n", perimetr);
	area = pow(a, 2) * sqrt(3) / 4.0;
	printf_s("Площадь = %lf\n\n", area);

}
int main()
{	
	system("chcp 1251>nul");
	puts("Привет! Я калькулятор! :D");
	puts("Я умею вычислять ПЕРИМЕТР и ПЛОЩАДЬ геометрических фигур");
	puts("На данный момент в мой функционал поддерживает:");
	puts("(1) ПЕРИМЕТР и ПЛОЩАДЬ квадрата со стороной, равной а");
	puts("(2) ПЕРИМЕТР и ПЛОЩАДЬ прямоугольного треугольника с катетами a и b.");
	puts("(3) ПЕРИМЕТР и ПЛОЩАДЬ равнобедренного треугольника с основанием a и высотой h");
	puts("(4) ПЕРИМЕТР и ПЛОЩАДЬ равнобокой трапеции с длинами оснований a и b и высотой h");
	puts("(5) ПЕРИМЕТР и ПЛОЩАДЬ равностороннего треугольника со стороной, равной a");

	int x=1;
	while (x!=0)
	{		
		printf_s("Введи соответствующие цифры что бы запустить калькулятор.\nВведи  0  для выхода из программы: ");
		scanf_s("%i", &x);
		printf_s("\n");
		switch (x)
		{
		case 1:
			foursquare();
			break;
		case 2:
			righttriangle();
			break;
		case 3:
			isoscelestriangle();
			break;
		case 4:
			isoscelestrapezoid();
			break;
		case 5:
			equilateraltriangle();
			break;
		case 0:
			printf_s("Quit from calculator\n");
			break;
		default:			
			printf_s("Wrong input!\n");
			break;
		}
	}	
}