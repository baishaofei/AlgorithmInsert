// Algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Algoritm.h"
#include "iostream"
using namespace std;

template<class T>
INT32 GetArrayLength(T& arrayT)
{
	return (sizeof(arrayT) / sizeof(arrayT[0]));
}

void insert_sort(int* to_Sort, UINT32 array_len, BOOL bAsc)
{
	if (NULL == to_Sort)
	{
		return;
	}
	if (array_len <= 1)
	{
		return;
	}

	for (UINT32 indexi = 1; indexi < array_len; indexi++)
	{
		int CurValue = to_Sort[indexi];
		INT32 indexj = indexi - 1;
		while (indexj >= 0 && to_Sort[indexj] > CurValue)
		{
			to_Sort[indexj + 1] = to_Sort[indexj];
			indexj--;
		}
		to_Sort[indexj + 1] = CurValue;

	}

}

void PrintArray(INT32 ArrayPrint[], UINT32 array_len)
{
	if (NULL == ArrayPrint)
		return;
	for (UINT32 i = 0; i < array_len; i ++)
	{
		cout << ArrayPrint[i] << endl;
	}
}

INT32 main()
{
	INT32 ArrayTest[] ={1,6,3,6,5,4,3,8};

	UINT32 arrayLen = GetArrayLength(ArrayTest);

	insert_sort(ArrayTest, arrayLen, true);

	PrintArray(ArrayTest, arrayLen);

	return 0;
}

