void Permutation(char *pStr)
{
	if (pStr == NULL)
		return;

	PermutationRecurively(pStr, pStr);
}

void PermutationRecurively(char *pStr, char *pBegin)
{
	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char *ch = pBegin; *ch != '\0'; ch++)
		{
			char tmp = *ch;
			*ch = *pBegin;
			*pBegin = tmp;

			PermutationRecurively(pStr, pBegin + 1);

			tmp = *ch;
			*ch = *pBegin;
			*pBegin = tmp;
		}
	}
}