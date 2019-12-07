bool g_invalid_input = false;


double power_unsigned_exponent(double base, int exponent)
{
	if (exponent == 0)
		return 1.0;
	else if (exponent == 1)
		return base;

	double result = power_unsigned_exponent(base, exponent >> 1);
	result *= result;

	if (exponent & 1)
		result *= base;

	return result;
}

bool equal(double x, double y)
{
	if ((x - y > -0.0000001) && (x - y < 0.0000001))
		return true;
	else
		return false;
}

double power(double base, int exponent)
{
	g_invalid_input = false;

	if (equal(base, 0.0) && exponent < 0)
	{
		g_invalid_input = true;
		return 0.0;
	}

	unsigned int abs_exponent;
	if (exponent < 0)
		abs_exponent = -exponent;
	else
		abs_exponent = exponent;

	double result = power_unsigned_exponent(base, abs_exponent);

	if (exponent < 0)
		result = 1.0 / result;

	return result;
}