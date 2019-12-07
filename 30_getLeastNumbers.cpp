void GetLeastNumbers(int *input, int n, int *output, int k)
{
	if (input == NULL || n <= 0 || output == NULL || k <= 0 || k > n)
		return;

	int start = 0;
	int end = n - 1;
	int index = partition(input, n, start, end);

	while (index != k - 1)
	{
		if (index < k - 1)
		{
			start = index + 1;
			index = partition(input, n, start, end);
		}
		else
		{
			end = index - 1;
			index = partition(input, n, start, end);
		}
	}

	for (int i = 0; i < k; i++)
		output[i] = input[i];
}