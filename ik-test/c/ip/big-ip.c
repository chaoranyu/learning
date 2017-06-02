#include <stdio.h>
#include <string.h>

#ifndef X86_PLATFORM
#define X86_PLATFORM
#endif

#if defined(X86_PLATFORM) || defined(DEC_PLATFORM)
/* Get one byte of ip which is in big-endian */
#define ip_h0(ip)  ((unsigned)ip & 0xFF)
#define ip_h1(ip)  (((unsigned)ip >> 8) & 0xFF)
#define ip_h2(ip)  (((unsigned)ip >> 16) & 0xFF)
#define ip_h3(ip)  ((unsigned)ip >> 24)

/* Convert byte order of port number */
#define cnv_port(port)  ((uint16_t)(port << 8 | port >> 8))
#else
#define ip_h0(ip)  ((unsigned)ip >> 24)
#define ip_h1(ip)  (((unsigned)ip >> 16) & 0xFF)
#define ip_h2(ip)  (((unsigned)ip >> 8) & 0xFF)
#define ip_h3(ip)  ((unsigned)ip & 0xFF)

/* Convert byte order of port number */
#define cnv_port(port)  (port)
#endif

int ip_s2n(char *s_ip, unsigned int *n_ip)
{
    if (strlen(s_ip) > 15)
    {
        return -1;
    }

    char *tmp = NULL;
    unsigned int n = 0;
    int i = 0;

    while (tmp = strsep(&s_ip, "."))
    {
        // fprintf(stdout, "%s\n", tmp);
        if (strlen(tmp) > 0 && strlen(tmp) < 4)
        {
            //n <<= 8;
            if (*tmp < '0' || *tmp > '9')
                return -1;
            unsigned m = atoi(tmp);
            if (m > 255)
                return -1;

            n <<= 8;
            n |= m;
            i++;
        }
        else
        {
            return -1;
        }
    }

    if (i > 4)
        return -1;

    *n_ip = n;
    return 0;
}

int main()
{
    char s_ip[20];
    fprintf(stdout, "input ip: ");
    scanf("%s", s_ip);

    unsigned int n_ip;
    if (ip_s2n(s_ip, &n_ip) == 0)
    {
        fprintf(stdout, "ip = 0x%08x\n", n_ip);
        fprintf(stdout, "ip = %u.%u.%u.%u\n", ip_h0(n_ip), ip_h1(n_ip), ip_h2(n_ip), ip_h3(n_ip));
    }
    else
    {
        fprintf(stderr, "invalid ip, cannot convert it\n");
    }

    return 0;
}
