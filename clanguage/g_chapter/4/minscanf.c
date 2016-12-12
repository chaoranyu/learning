#include <stdio.h>
#include <stdarg.h>

int minscanf(char *fmt, ...);

main()
{
	int i;
	float f;

	minscanf("%d", &i);
	printf("scaned %d\n", i);
	minscanf("%f", &f);
	printf("scaned %f\n", f);
}

int minscanf(char *fmt, ...)
{
	va_list ap;
	char *p;
	int *ival;
	double *dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%')
			continue;

		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int *);
			scanf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double *);
			scanf("%f", dval);
			break;
		default:
			break;
		}
	}
	va_end(ap);
}
