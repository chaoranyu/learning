void func1()
{
	int i, j;
	for (i = 0; i < 100000; i++)
		j += i;
}

void func2()
{
	int i, j;
	/* func1(); */
	for (i = 100000; i > 0; i--)
		j += i;
}

void main()
{
	int i;
	for (i = 0; i < 1000; i++)
		func1();

	for (i = 1000; i > 0; i--)
		func2();
}
