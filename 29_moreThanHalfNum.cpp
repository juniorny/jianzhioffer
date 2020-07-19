int MoreThanHalfNum(int *numbers, int length)
{
	if (CheckInvalidArray(numbers, length))
		return 0;

	int middle = length >> 1;
	int start = 0; 
	int end = length - 1;
	int index = partition(numbers, length, start, end);
	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = partition(numbers, length, start, end);
		}
		else
		{
			start = index + 1;
			index = partition(numbers, length, start, end);
		}
	}

	int result = numbers[middle];
	if (!CheckMoreThanHalf(numbers, length, result))
		result = 0;

	return result;
}


bool CheckInvalidArray(int *numbers, int length)
{
	return (numbers == NULL || length <= 0);
}

bool CheckMoreThanHalf(int *numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] == number)
			times++;
	}

	if (times * 2 > length)
		return true;
	else
		return false;
}

int MoreThanHalfNum2(int *numbers, int length)
{
	if (CheckInvalidArray(numbers, length))
		return 0;

	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < length; i++)
	{
		if (numbers[i] == result)
			times++;
		else
			times--;

		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
	}	

	if (!CheckMoreThanHalf(numbers, length, result))
		result = 0;

	return result;
}