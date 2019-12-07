char firstNotRepeatingChar(char *pString)
{
	if (pString == NULL)
		return '\0';

	const int table_size = 256;
	unsigned int hashTable[table_size];

	for (unsigned int i = 0; i < table_size; i++)
		hashTable[i] = 0;

	char *pHashKey = pString;
	while (*pHashKey != '\0')
		hashTable[*(pHashKey++)]++;

	pHashKey = pString;
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;

		pHashKey++;
	}

	return '\0';
}