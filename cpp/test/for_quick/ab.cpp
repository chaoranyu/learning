int a()
{
    int a[100];

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
    {
        a[i] = i * i;
    }
}
int b()
{
    int a[100];

    int iCount = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < iCount; ++i)
    {
        a[i] = i * i;
    }
}
int main()
{
    for (int i = 0; i < 2000000; ++i)
    {
        a();
        b();
    }

    return 0;
}
