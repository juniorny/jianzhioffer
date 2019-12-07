long long fibonacci(unsigned int n)
{
	long long result[2] = {0, 1};
	if (n < 2)
		return result[n];

	long long fn_1 = 1;
	long long fn_2 = 0;
	long long r = 0;
	for (int i = 2; i <= n; i++)
	{
		r = fn_1 + fn_2;

		fn_2 = fn_1;
		fn_1 = r;
	}

	return r;
}