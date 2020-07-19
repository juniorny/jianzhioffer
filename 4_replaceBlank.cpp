void replaceBlank(char *string, int length)
{
	if (string == NULL || length <= 0)
		return;

	int old_len = 0;
	int num_of_blank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
			num_of_blank++;
		i++;
	}
	old_len = i;
	int new_len = old_len + 2 * num_of_blank;
	if (new_len > length)
		return;

	int p1 = old_len - 1;
	int p2 = new_len - 1;

	while (p1 >= 0)
	{
		if (string[p1] != ' ')
		{
			string[p2--] = string[p1];
		}
		else
		{
			string[p2--] = '0';
			string[p2--] = '2';
			string[p2--] = '%';
		}
		p1--;
	}
}