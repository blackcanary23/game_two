#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "one_meth.h"


	void display()
	{
			printf("%s\n\n", "Введите данные: ");
			printf("%s", "a = ");
			scanf("%f", &a);
			
			printf("%s", "b = ");
			scanf("%f", &b);
			
			printf("%s", "c = ");
			scanf("%f", &c);
			
			printf("%s", "d = ");
			scanf("%f", &d);
			
			printf("%s", "e = ");
			scanf("%f", &e);


		if ((2 * a < 0) && (2 * b > 0))
			printf("\n%s\n\n", "Игра выпукло-вогнутая");
		else
			return 1;

			printf("%s", "Функция ядра: H(x, y) = ");
			printf("%.0f%s", a, "x*x"); //
		if (b < 0)
			printf("%.0f%s", b, "y*y"); //
		if (b > 0)
			printf("%s%.0f%s", "+", b, "y*y"); //
		if (c < 0)
			printf("%.0f%s", c, "x*y"); //
		if (c > 0)
			printf("%s%.0f%s", "+", c, "x*y"); // 
		if (d < 0)
			printf("%.1f%s", d, "x");
		if (d > 0)
			printf("%s%.1f%s", "+", d, "x");
		if (e < 0)
			printf("%.1f%s", e, "y");
		if (e > 0)
			printf("%s%.1f%s", "+", e, "y");

		return 0;
	}

	int derivative()
	{
		temp_a1 = 2 * a;
		temp_b1 = 2 * b;

			printf("\n\n%s", "Первая производная по x равна: H = ");
			printf("%.0f%s", temp_a1, "x"); //
		if (c < 0)
			printf("%.0f%s", c, "y"); //
		if (c > 0)
			printf("%s%.0f%s", "+", c, "y"); //
		if (d < 0)
			printf("%.1f", d);
		if (d > 0)
			printf("%s%.1f", "+", d);

			printf("\n%s", "Первая производная по y равна: H = ");
			printf("%.0f%s", temp_b1, "y"); //
		if (c < 0)
			printf("%.0f%s", c, "x"); //
		if (c > 0)
			printf("%s%.0f%s", "+", c, "x"); //
		if (e < 0)
			printf("%.1f", e);
		if (e > 0)
			printf("%s%.1f", "+", e);

		return 0;
	}

	int equation()
	{
		temp_a1 = temp_a1 * (-1);
		temp_c1 = c / temp_a1;
		temp_d1 = d / temp_a1;
		
			printf("\n\n%s", "x = ");
			printf("%.0f%s", temp_c1, "y"); //
		if (temp_d1 < 0)
			printf("%.1f", temp_d1);
		if (temp_d1 > 0)
			printf("%s%.1f", "+", temp_d1);
		
		double y = (temp_d1 * (-1) / temp_c1); //проверка
		printf("\t%s%.1f", "y >= ", y);
		

		temp_b1 = temp_b1 * (-1);
		temp_c2 = c / temp_b1;
		temp_e1 = e / temp_b1;
		
			printf("\n%s", "y = ");
			printf("%.0f%s", temp_c2, "x"); //
		if (temp_e1 < 0)
			printf("%.1f", temp_e1);
		if (temp_e1 > 0)
			printf("%s%.1f", "+", temp_e1);

		double x = (temp_e1 * (-1) / temp_c2); //проверка
		printf("\t%s%.1f", "x <= ", x);

		return 0;

	}

	int decision()
	{
		printf("\n\n%s", "y = ");
		
		temp_c3 = 1 - (temp_c2 * temp_c1);
		temp_d2 = (temp_d1 * temp_c2 + temp_e1) / temp_c3; // y

		printf("%.1f", temp_d2);

		printf("\n%s", "x = ");

		temp_c1 = temp_c1 * temp_d2 + temp_d1; //x
		
		printf("%.1f", temp_c1); 

		printf("\n\n%s", "Подставим получившееся значение x в выражение для y для проверки: ");

		temp_c2 = temp_c2 * temp_c1 + temp_e1;
		printf("%s %.1f", "y = ", temp_c2);

		printf("\n\n%s", "Седловая точка: H(x, y) = ");
		point = a * temp_c1 * temp_c1 + b * temp_d2 * temp_d2 + c * temp_d2 * temp_c1 + d * temp_c1 + e * temp_d2;
		printf("%.2f", point);

		return 0;
	}
	

