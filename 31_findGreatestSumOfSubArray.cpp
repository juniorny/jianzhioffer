int findGreatestSumOfSubArray(int *pData, int length)
{
	if (pData == NULL || length <= 0)
		return 0;

	int curSum = 0;
	int maxSum = 0;

	for (int i = 0; i < length; i++)
	{
		if (curSum <= 0)
		{
			curSum = pData[i];
		}
		else
			curSum += pData[i];

		if (curSum > maxSum)
			maxSum = curSum;
		
	}

	return maxSum;
}