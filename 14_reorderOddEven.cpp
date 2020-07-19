<<<<<<< HEAD
// 利用函数指针提高程序拓展性
=======
>>>>>>> f99cbf0109806e202ea6e361cfaac11dd4aaef61
void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
	if (pData == NULL || length <= 0)
		return ;

	int *p1 = pData;
	int *p2 = pData + length - 1;
	while (p1 < p2)
	{
		while (p1 < p2 && !func(*p1))
			p1++;

		while (p1 < p2 && func(*p2))
			p2--;

		if (p1 < p2)
		{
			int tmp = *p1;
			*p1 = *p2;
			*p2 = tmp;
		}
	}	
}

bool isEven(int number)
{
	return  (number & 1) == 0
}

void ReorderOddEven(int *pData, unsigned int length)
{
	Reorder(pData, length, isEven);
}