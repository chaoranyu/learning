#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    int one = 123;
    int *test_ptr[1];

    test_ptr[0] = &one;

    printf("%d\n", *test_ptr[0]);
    printf("%d\n", *(test_ptr[0]));

    enum { NONE=0, FIELD, VALUE } last_header_element;

    printf("%d\n", last_header_element);
    printf("%010d\n", INT32_MAX);
    printf("%d\n", INT32_MAX);
    printf("%010d\n", 123);

    char *s = "<html><body><br><br><br><script>window.location=\"/?xxfwkey=uumvh2\";</script><script>var u=2;for(;u==1;u++);</script><br><br><br><center><h3><a href=\"/?jdfwkey=uumvh2\"></a></h3></center></body></html>";
    printf("%s\n", s);

    char *ss = "<html><body><br><br><br><script>window.location=\"/?xxfwkey="
        "1234567890"
        "\";</script><script>var u=2;for(;u==1;u++);</script><br><br><br><center><h3>Hello, I'm Garfiled! Who are you?</h3></center></body></html>";

    printf("len=%d, %s\n", strlen(ss), ss);

    return 0;
}
