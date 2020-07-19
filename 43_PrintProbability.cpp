int g_maxValue = 6;

void PrintProbability(int number)
{
	if (number < 1)
		return;
	// number 个骰子的点数之和的最大值
	int maxSum = number * g_maxValue;
	// 分配一个数组，下标表示骰子点数和的一种情况，存储的值为出现某个点数和的次数，初始化为 0
	int *pProbabilities = new int[maxSum - number + 1];
	for (int i = number; i <= maxSum; i++)
		pProbabilities[i - number] = 0;

	// 每一种点数和出现的次数存于 pProbabilities 数组中
	Probability(number, pProbabilities);

	int total = pow((double)g_maxValue, number);
	for (int i = number; i <= maxSum; i++)
	{
		double ratio = (double)pProbabilities[i - number] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities;
}

void Probability(int number, int *pProbabilities)
{
	// 将 n 个骰子分成两部分，第一部分只有一个，另一部分有 n-1 个（递归）
	for (int i = 1; i <= g_maxValue; i++)
		Probability(number, number, i, pProbabilities);
}


void Probability(int original, int current, int curSum, int *pProbabilities)
{
	// 当只有一个骰子的时候，点数和即为该数字，使其次数加1.
	if (current == 1)
	{
		pProbabilities[curSum - original]++;
	}
	else
	{
		for (int i = 1; i <= g_maxValue; i++)
		{
			//递归
			Probability(original, current - 1, i + curSum, pProbabilities);
		}
	}

}


void PrintProbability2(int number)
{
	if (number < 1)
		return;

	//构建两个数组 分别存储前一次和后一次的和出现的次数
	int *pProbabilities[2];
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];

	for (int i = 0; i < g_maxValue * number + 1; i++)
	{
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}

	int flag = 0;
	//初始化第一个数组（一个骰子）
	for (int i = 1; i <= g_maxValue; i++)
		pProbabilities[flag][i] = 1;
	//初始化第二个数组
	for (int k = 2; k <= number; k++)
	{
		//有k 个骰子时，出现数字的和（数组下标）小于骰子个数 k 的均不会出现，所以设为0
		for (int i = 0; i < k; i++)
			pProbabilities[1 - flag][i] = 0;

		for (int i = k; i <= g_maxValue * k; i++)
		{
			// 下标大于 k 的初始化为 0
			pProbabilities[1 - flag][i] = 0;
			//当前数字之和 = 前一次出现1的次数 + 前一次出现 2 的次数 + ... + 前一次出现 6 的次数
			for (int j = 1; j <= i && j <= g_maxValue; j++)
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];		//当前和 - 1~6
		}
		//两个数组进行交替更新
		flag = 1 - flag;
	}

	double total = pow((double)g_maxValue, number);
	for (int i = number; i <= number * g_maxValue; i++)
	{
		double ratio = (double)pProbabilities[flag][i] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
}

