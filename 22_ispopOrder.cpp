bool IsPopOrder(const int *pPush, const int *pPop, int length)
{
	bool bPossible = false;

	if (pPush != NULL && pPop != NULL && length > 0)
	{
		int *nextPush = *pPush;
		int *nextPop  = *pPop;

		std::stack<int> data;
		while (nextPop - pPop < length)
		{
			while (data.size() == 0 || data.top() != *nextPop)
			{
				if (nextPush - pPush == length)
					break;

				data.push(*nextPush);
				nextPush++;
			}

			if (data.top() != *nextPop)
				break;
			else
			{
				data.pop();
				nextPop++;
			}
		}
		
		if (data.empty() && nextPop - pPop == length)
			bPossible = true;
	}


	return bPossible;
}