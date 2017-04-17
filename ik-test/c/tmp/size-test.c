#include <stdio.h>
#include <stdint.h>

typedef struct table_data
{
    uint32_t    src_ip;         /* client ip when info=CLIENT; server ip when info=SERVER */
    uint32_t    valid_time;     /* In seconds. It's the time an entry becoming invalid or aging */
    /*uint32_t    aging_time;*/     /* In seconds. It's the time an entry becoming aging */
    uint32_t    dst_ip;
    uint16_t    dst_port;
    uint8_t     ttl;            /* */
    uint8_t     purpose  : 1;   /* CLIENT, SERVER */
    uint8_t     conn_num : 7;   /* Connection nums */
    uint32_t    next_index; /* the index of next entry which has the same hashvalue as the current entry */
} table_data_t;

main()
{
    printf("%d\n", sizeof(table_data_t));

    table_data_t tbl;
    tbl.src_ip = 11111;
    tbl.valid_time = 22222;
    tbl.dst_ip = 33333;
    tbl.dst_ip = 4;
    tbl.ttl = 55;
    tbl.purpose = 1;
    tbl.conn_num = 5;
    tbl.next_index = 2;

    printf("%d\n", sizeof(tbl));
}
