int numberOf1Between1AndN(unsigned int n)
{
	if (n <= 0)
		return 0;

	char strN[50];
	sprintf(strN, "%d", n);

	return numberOf1(strN);
}


int numberOf1(const char *strN)
{
	if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
		return 0;

	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));
	if (first == 0 && length == 1)
		return 0;
	if (first > 0 && length == 1)
		return 1;

	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = powerBase10(length - 1);
	else if (first == 1)
		numFirstDigit = atoi(strN + 1) + 1;

	int numOtherDigits = first * (length - 1) * powerBase10(length - 2);

	int numberRecursive = numberOf1(strN + 1);

	return numFirstDigit + numOtherDigits + numberRecursive;

}

int powerBase10(unsigned int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
		result *= 10;

	return result;
}