class Temp
{
public:
	Temp() {++N; Sum += N;}

	static void Reset() {N = 0; Sum = 0;}
	static unsigned int GetSum() {return Sum;}

private:
	// static类间共享
	static unsigned int N;
	static unsigned int Sum;
};

// 类外初始化
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_solution1(unsigned int n)
{
	Temp::Reset();

	Temp *a = new Temp[n];
	delete []a;
	a = NULL;

	return Temp::GetSum();
}


class A;
A* Array[2];

class A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
};

class B: public A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};


int Sum_solution2(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	int value = Array[1]->Sum(n);

	return value;
}


typedef unsigned int (*fun)(unsigned int);

unsigned int Solution3_teminator(unsigned int n)
{
	return 0;
}

unsigned int Sum_solution3(unsigned int n)
{
	static fun f[2] = {Solution3_teminator, Sum_solution3};
	return n + f[!!n](n - 1);
}



template <unsigned int n> struct Sum_solution4
{
	enum Value { N = Sum_solution4<n - 1>::N + n};
};

template <> struct Sum_solution4<1>
{
	enum Value {N = 1};
};