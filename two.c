#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include "one_meth.h"
#include "sec_meth.h"
#include "br_meth.h"

int iter_method()
{
	float** matrix;
	float* min;
	float* max;
	//int SIZE;
	int N;
	static float* loss_of_B;
	static float* win_of_A;
	float* p;  // стратегии игрока А
	float* q; // стратегии игрока B
	gamer_A objA;
	gamer_A* ptrObjA = &objA;
	gamer_B objB;
	gamer_B* ptrObjB = &objB;
	float game_number;

	printf("\n\n%s", "2. Численное решение:");
	for (SIZE = 3, N = 2; SIZE < 12, N < 11; SIZE++, N++)
	{
		//printf("\n\n");
		printf("\n\n%s %d\n\n", "N = ", N);

		ptrObjA->strategy_number_of_A = 1; // пусть стратегия игрока А равна 1
		game_number = 1;

		loss_of_B = (float*)malloc(SIZE * sizeof(float));
		win_of_A = (float*)malloc(SIZE * sizeof(float));

		for (int i = 0; i < SIZE; i++)
		{
			loss_of_B[i] = 0;
			win_of_A[i] = 0;
		}

		// Выделение памяти
		p = (float*)malloc(SIZE * sizeof(float));
		q = (float*)malloc(SIZE * sizeof(float));


		for (int j = 0; j < SIZE; j++)
		{
			p[j] = 0;
			q[j] = 0;
		}

		min = (float*)malloc(SIZE * sizeof(float));
		max = (float*)malloc(SIZE * sizeof(float));

		matrix = (float**)malloc(SIZE * sizeof(float*));

		for (int i = 0; i < SIZE; i++)
		{

			matrix[i] = (float*)malloc(SIZE * sizeof(float));
			
			for (int j = 0; j < SIZE; j++)
			{
				matrix[i][j] = a * i / N * i / N + b * j / N * j / N + c * i / N * j / N + d * i / N + e * j / N;
			}

		}

		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				printf("%.3f\t", matrix[i][j]);
			printf("\n");
		}

		
		for (int i = 0; i < SIZE; i++)
		{
			min[i] = matrix[i][0];
			for (int j = 0; j < SIZE - 1; j++)
			{
				if (matrix[i][j + 1] < min[i])
					min[i] = matrix[i][j + 1];
			}

		}

		for (int j = 0; j < SIZE; j++)
		{
			max[j] = matrix[0][j];
			for (int i = 0; i < SIZE - 1; i++)
			{
				if (matrix[i+1][j] > max[j])
					max[j] = matrix[i+1][j];
			}

		}

		low_price = min[0];
		row = 0;
		up_price = max[0];
		column = 0;
		for (int k = 0; k < SIZE - 1; k++)
		{
			if (min[k + 1] > low_price)
			{
				low_price = min[k + 1];
				row = k + 1;
			}
		
			if (max[k + 1] < up_price)
			{
				up_price = max[k + 1];
				column = k + 1;
			}
		}

		if (low_price == up_price)
		{
			printf("\n%s\n", "Есть седловая точка:");
			printf("%s %.3f %s %.3f %s %.3f", "x = ", row / N, "y = ", column / N, "H = ", low_price);
		}
		else
		{
			printf("\n%s\n", "Седловой точки нет, решение методом Брауна-Робинсон:");
			do
			{
				search_of_min_element(matrix, ptrObjA, loss_of_B, ptrObjB);
				search_of_max_element(matrix, ptrObjB, win_of_A, ptrObjA);
				lower_price = ptrObjB->min_element / game_number;
				upper_price = ptrObjA->max_element / game_number;
				average_price = (lower_price + upper_price) / 2;
				accuracy = upper_price - lower_price;
				game_number++;
				for (int i = 0; i < SIZE; i++)
				{
					if (ptrObjA->strategy_number_of_A == (i + 1))
					{

						p[i] = p[i] + 1;
						break;
					}
				}

				for (int j = 0; j < SIZE; j++)
				{
					if (ptrObjB->strategy_number_of_B == (j + 1))
					{
						q[j] = q[j] + 1;
						break;
					}
				}
				
			}
			while (accuracy > 0.0001);

			
			temp_a = fabs(matrix[0][0]);
			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 1; j < SIZE; j++)
				{
					temp_b = fabs(matrix[i][j]);
					if (fabs(temp_b - fabs(average_price)) < fabs(temp_a - fabs(average_price))) 
					{
						price = matrix[i][j];
						temp_a = fabs(matrix[i][j]);
						row = i;
						column = j;
					}
				}
			}


			printf("%s %.3f %.3f %.3f", "H = ", row / N, column / N, price);
		} 

		for (int k = 0; k < SIZE; k++)
			free(matrix[k]);
		free(matrix);

		free(min);
		free(max);
		free(p);
		free(q);
		free(loss_of_B);
		free(win_of_A);
	}


	return 0;
}