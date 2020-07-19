bool FindNumbersWithSum(int *data, int length, int sum, int *num1, int *num2)
{
	bool found = false;
	if (data == NULL || length < 1 || num1 == NULL || num2 == NULL)
		return found;

	int ahead = length - 1;
	int behind = 0;

	while (ahead > behind)
	{
		long long curSum = data[ahead] + data[behind];

		if (curSum == sum)
		{
			*num1 = data[behind];
			*num2 = data[ahead];
			found = true;
			break;
		}
		else if (curSum > sum)
			ahead--;
		else
			behind++;
	}

	return found;
}


void FindContinuousSequence(int sum)
{
	if (sum < 3)
		return;

	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;

	while (small < middle)
	{
		if (curSum == sum)
		{
			printContinuousSequence(small, big);
		}

		while (curSum > sum && small < middle)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
				printContinuousSequence(small, big);
		}

		big++;
		curSum += big;
	}
}

void printContinuousSequence(int small, int big)
{
	for (int i = small; i <= big; i++)
		printf("%d ", i);
	printf("\n");
}