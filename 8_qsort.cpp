int partition(int *data, int length, int start, int end)
{
	if (data == NULL || length <= 0; || start <= 0 || end <= 0 || end < start)
		throw new std::exception("invaild parameters!");

	int index = ramdomRange(start, end);
	swap(&data[index], &data[end]);

	int small = start - 1;
	for (index = start; index < end; index++)
	{
		if (data[index] < data[end])
		{
			small++;
			if (index != small)
				swap(&data[index], &data[small]);
		}
	}

	small++;
	swap(&data[small], &data[end]);

	return small;
}

void qsort(int *data, int length, int start, int end)
{
	if (start == end)
		return;

	int mid = partition(data, length, start, end);
	if (mid > start)
	{
		qsort(data, length, start, mid - 1);
	}
	if (mid < end)
	{
		qsort(data, length, mid + 1, end);
	}
}
