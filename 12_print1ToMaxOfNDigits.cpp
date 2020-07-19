bool Increment(char *number)
{
	if (number == NULL)
		return true;

	bool isOverflow = false;
	int nTakeOver = 0; 
	int len = strlen(number);

	for (int i = len - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == len - 1)
			nSum++;
		if (nSum >= 10)
		{
			if (i == 0)
			{
				isOverflow = true;
			}
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = nSum + '0';
			}
		}
		else
		{
			number[i] = nSum + '0';
			break;
		}
	}

	return isOverflow;
}


void PrintNumber(char *number)
{
	int i = 0;
	while (number[i] == '0')
		i++;

	while (number[i] != '\0')
		cout << number[i++];
}

<<<<<<< HEAD
void Print1ToMaxOfNDigitals(int n)
{
	if (n <= 0)
		return ;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}

	delete number;
}


/*
递归方法
 */
=======
>>>>>>> f99cbf0109806e202ea6e361cfaac11dd4aaef61
void Print1ToMaxOfNDigitalsRecursively(char *number, int len, int index)
{
	if (index == len - 1)
	{
		PrintNumber(number);
		return ;
	}

<<<<<<< HEAD
	// 打印次高位的0~9
=======
>>>>>>> f99cbf0109806e202ea6e361cfaac11dd4aaef61
	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitalsRecursively(number, len, index + 1);
	}
}

void Print1ToMaxOfNDigitals2(int n)
{
	if (n <= 0)
		return ;

	char *number = new char[n + 1];
	number[n] = '\0';

<<<<<<< HEAD
	// 打印最高位的0~9
=======
>>>>>>> f99cbf0109806e202ea6e361cfaac11dd4aaef61
	for (int i = 0; i < 10; i++)
	{
		number[i] = i + '0';
		Print1ToMaxOfNDigitalsRecursively(number, n, 0);
	}

	delete number;
<<<<<<< HEAD
=======
}

void Print1ToMaxOfNDigitals(int n)
{
	if (n <= 0)
		return ;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}

	delete number;
>>>>>>> f99cbf0109806e202ea6e361cfaac11dd4aaef61
}