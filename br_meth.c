#include <stdio.h>
#include <math.h>
#include "br_meth.h"


int search_of_min_element(float** matrix, gamer_A* ptrObjA, static float* loss_of_B, gamer_B* ptrObjB)
{
	for (int i = 1, k = 0; i <= SIZE; i++, k++)
	{
		if (ptrObjA->strategy_number_of_A == i)
		{
			for (int j = 0; j < SIZE; j++)
				loss_of_B[j] = loss_of_B[j] + matrix[k][j];
		}
	}

	float temp = loss_of_B[0];
	float index = 1;
	for (int i = 1; i < SIZE; i++)
	{

		if (loss_of_B[i] < temp)
		{
			temp = loss_of_B[i];
			index = i + 1;
		}

	}
	ptrObjB->strategy_number_of_B = index;
	ptrObjB->min_element = temp;

	return 0;
}

int search_of_max_element(float** matrix, gamer_B* ptrObjB, static float* win_of_A, gamer_A* ptrObjA)
{
	for (int i = 1, k = 0; i <= SIZE; i++, k++)
	{
		if (ptrObjB->strategy_number_of_B == i)
		{
			for (int j = 0; j < SIZE; j++)
				win_of_A[j] = win_of_A[j] + matrix[j][k];
		}
	}

	float temp = win_of_A[0];
	float index = 1;
	for (int i = 1; i < SIZE; i++)
	{

		if (win_of_A[i] > temp)
		{
			temp = win_of_A[i];
			index = i + 1;
		}

	}
	ptrObjA->strategy_number_of_A = index;
	ptrObjA->max_element = temp;


	return 0;
}