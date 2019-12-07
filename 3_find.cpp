bool find(int *matrix, int rows, int columns, int number)
{
	if (matrix == NULL || rows <= 0 || columns <=0)
		throw new std::exception("Invaild parameters");

	int r = 0;
	int l = columns - 1;

	while (r < rows && l >= 0)
	{
		int pos = r * columns + l;
		if (matrix[pos] == number)
		{
			return true;
		}
		else if (matrix[pos] > number)
		{
			l--;
		}
		else if (matrix[pos] < number)
		{
			r++;
		}
	}	

	return false;
}