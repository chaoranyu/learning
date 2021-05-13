// gcc sha1-test.c -lcrypto

// Compare the results of the below Linux commands:
// echo -e -n '\xab\xbe\xf3\xbf\x3d\x51\xaf\x31\x00\x00\x00\x00\x00\x00\x00\x00\x05\x01\x01\x02\x01\xf4' | sha1sum
// echo -e -n '\xab\xbe\xf3\xbf\x3d\x51\xaf\x31\0\0\0\0\0\0\0\0\x05\x01\x01\x02\x01\xf4' | sha1sum
// echo -n abbef3bf3d51af3100000000000000000501010201f4 | xxd -r -ps | sha1sum

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
    SHA_CTX s;
    int i, size;
    uint8_t buf[8+8+4+2];
    uint8_t res[20];

    // network order
    // abbef3bf3d51af31
    // 0000000000000000
    // 05010102  5.1.1.2
    // 01f4      500
    uint64_t ispi = 0x31af513dbff3beab;
    uint64_t rspi = 0x0;
    uint32_t sip = 0x2010105;
    uint16_t sport = 0xf401;

    memcpy(buf, &ispi, sizeof(ispi));
    memcpy(buf + sizeof(ispi), &rspi, sizeof(rspi));
    memcpy(buf + sizeof(ispi) + sizeof(rspi), &sip, sizeof(sip));
    memcpy(buf + sizeof(ispi) + sizeof(rspi) + sizeof(sip), &sport, sizeof(sport));

    printf("hexadecimal: ");
    for (i = 0; i < sizeof(buf); i++)
        printf("%02x", buf[i]);
    printf("\n");

    SHA1(buf, sizeof(ispi) + sizeof(rspi) + sizeof(sip) + sizeof(sport), res);
    // SHA1_Init(&s);
    // size =  sizeof(ispi) + sizeof(rspi) + sizeof(sip) + sizeof(sport);
    // SHA1_Update(&s, buf, size);
    // SHA1_Final(res, &s);

    printf("sha1sum: ");
    for (i = 0; i < sizeof(res); i++)
        printf("%02x", res[i]);
    printf("\n");

    return 0;
}
