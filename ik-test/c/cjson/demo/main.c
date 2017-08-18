#include <stdio.h>
#include <stdlib.h>

#include "cJSON.h"

#define FILE_TEST_NAME  ("ddos-config.json")

char * makeJson(FILE* fp)
{
    cJSON *root = NULL;
    cJSON *def = NULL;

    root = cJSON_CreateObject();
    cJSON_AddNumberToObject(root, "auth_table_size", 1000);
    cJSON_AddNumberToObject(root, "source_table_child_num", 4);
    cJSON_AddItemToObject(root, "default", def = cJSON_CreateObject());
    cJSON_AddTrueToObject(def, "first_packet");
    cJSON_AddFalseToObject(def, "source_detect");
    cJSON_AddTrueToObject(def, "detect_ttl");

    /* Print to text */
    //if (print_preallocated(root) != 0) {
    //    cJSON_Delete(root);
    //    exit(EXIT_FAILURE);
    //}

    ///////////////////////////////memory free?
    char * p = cJSON_Print(root);
    if (NULL == p)
    {
        cJSON_Delete(root);
        return NULL;
    }

    cJSON_Delete(root);

    fprintf(fp, "%s", p);

    return p;
}

void parseJson(char *pMsg)
{
    //char *pMsg;
    if (NULL == pMsg)
    {
        return;
    }

    cJSON * pJson = cJSON_Parse(pMsg);
    if (NULL == pJson)                                                                                         
    {
        return;
    }

    // get string from json
    cJSON * pSub = cJSON_GetObjectItem(pJson, "auth_table_size");
    if (NULL == pSub)
    {
        return;
    }
    printf("obj_1 : %d\n", pSub->valueint);

    // get number from json
    pSub = cJSON_GetObjectItem(pJson, "source_table_child_num");
    if (NULL == pSub)
    {
        return;
    }
    printf("obj_2 : %d\n", pSub->valueint);

    // get bool from json
    pSub = cJSON_GetObjectItem(pJson, "default");
    if (NULL == pSub)
    {
        return;
    }

    cJSON * pSubSub = cJSON_GetObjectItem(pSub, "first_packet");
    if (NULL == pSubSub)
    {
        return;
    }
    printf("sub_obj_1 : %s\n", pSubSub->type == cJSON_True ? "true" : "false");

    pSubSub = cJSON_GetObjectItem(pSub, "source_detect");
    if (NULL == pSubSub)
    {
        return;
    }
    printf("sub_obj_2 : %s\n", pSubSub->type == cJSON_True ? "true" : "false");

    pSubSub = cJSON_GetObjectItem(pSub, "detect_ttl");
    if (NULL == pSubSub)
    {
        return;
    }
    //printf("sub_obj_3 : %s\n", pSubSub->type == cJSON_True ? "true" : "false");
    printf("sub_obj_3 : %s\n", pSubSub->type == cJSON_True ? "true" : "false");

    cJSON_Delete(pJson);
}

int main()
{
    int i;
    FILE* fp = fopen("ddos-config.json", "w+");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    char * p = makeJson(fp);
    if (NULL == p)
    {
        return 0;
    }
    printf("%s\n", p);

    parseJson(p);

    free(p); //千万不要忘记释放内存呀，cJSON_Print()函数或者cJSON_PrintUnformatted（）产生的内存，使用free(char *)进行释放
    fclose(fp);

    return 0;
}
