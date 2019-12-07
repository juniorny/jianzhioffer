int min(int *numbers, int length)
{
	if (numbers == NULL || length <= 0)
		throw new std::exception("Invaild parameters");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;

	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;

		if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[indexMid])
		{
			return minInOrder(numbers, index1, index2);
		}

		if (numbers[indexMid] > numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] < numbers[index2])
			index2 = indexMid;
	}

	return numbers[indexMid];
}

int minInOrder(int *numbers, int index1, int index2)
{
	int min = numbers[index2];
	for (int i = index1; i < index2; i++)
	{
		if (numbers[i] < min)
			min = numbers[i];
	}

	return min;
}