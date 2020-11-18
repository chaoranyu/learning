#include <stdio.h>
#include <string.h>

struct bool_flag_t {
		_Bool a : 1,
			  b : 1;
};

struct char_flag_t {
		unsigned char a : 2,
					  b : 3;
};

// struct short_flag_t {
// 		unsigned short a : 2,
// 					   b : 3;
// };

struct short_flag_t {
		unsigned short a : 7,
					   b : 10;
};

struct int_flag_t {
		int a : 2,
			b : 3;
};

struct char_test
{
		char a;
};

		void
dump_native_bits_storage_layout(unsigned char *p, int bytes_num)
{

		union flag_t {
				unsigned char c;
				struct base_flag_t {
						unsigned int p7:1,
									 p6:1,
									 p5:1,
									 p4:1,
									 p3:1,
									 p2:1,
									 p1:1,
									 p0:1;
				} base;
		} f;

		int i;
		for (i = 0; i < bytes_num; i++) {
				f.c = *(p + i);
				printf("%d%d%d%d %d%d%d%d ",
								f.base.p7,
								f.base.p6, 
								f.base.p5, 
								f.base.p4, 
								f.base.p3,
								f.base.p2, 
								f.base.p1, 
								f.base.p0);
		}
		printf("\n");
}

int
main()
{
		printf("%ld\n", sizeof(struct bool_flag_t));
		printf("%ld\n", sizeof(struct char_flag_t));
		printf("%ld\n", sizeof(struct short_flag_t));
		printf("%ld\n", sizeof(struct int_flag_t));

		printf("%ld\n", sizeof(struct char_test));

		struct short_flag_t s;
		memset(&s, 0, sizeof(s));
		s.a = 113; /* 0111 0001 */
		s.b = 997; /* 0011 1110 0101 */

		dump_native_bits_storage_layout((unsigned char*)&s, sizeof(s));

		return 0;
}
