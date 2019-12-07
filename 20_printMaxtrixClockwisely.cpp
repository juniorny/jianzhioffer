void PrintMatrixClockwisely(int **numbers, int columns, int rows)
{
	if (numbers == NULL || columns <= 0 || rows <= 0)
		return;

	int start = 0;
	while (columns > start * 2 && rows > start * 2)
	{
		printClockwisely(numbers, columns, rows, start);
		start++
	}
}

void printClockwisely(int **numbers, int columns, int rows, int start)
{
	int endX = columns - start - 1;
	int endY = rows - start - 1;

	for (int i = start; i <= endX; i++)
	{
		int number = numbers[start][i];
		printNumber(number);
	}

	if (endY > start)
	{
		for (int i = start + 1; i <= endY; i++)
		{
			int number = numbers[i][endX];
			printNumber(number);
		}
	}

	if (endY > start && endX > start)
	{
		for (int i = endX - 1; i >= start; i--)
		{
			int number = numbers[endY][i];
			printNumber(number);
		}
	}

	if (endY > start + 1 && endX > start)
	{
		for (int i = endY - 1; i > start; i--)
		{
			int number = numbers[i][start];
			printNumber(number);
		}
	}
}