int strcmp_test(const char *s, const char *d)
{
	while(*s == *d)
	{
		if( *s == NULL)
			break;
		s++;
		d++;
	}

	return *s-*d;
/*
	while(s != NULL)
		if(s++ != d++)
		{
			ret = 1;
			break;
		}

	if(d != NULL)
		ret = 1;
	return ret;
*/
}
