#include "stdio.h"
#include "stdlib.h"

#include "cJSON.h"

#define TEST_FILE_NAME  ("hello-config.json")

char * makeJson(FILE* fp)
{
    cJSON *root = NULL;
    cJSON *question = NULL;
    cJSON *array = NULL;
    cJSON *item = NULL;
    cJSON *name = NULL;
    cJSON *value = NULL;
    size_t index = 0;

    root = cJSON_CreateObject();
    cJSON_AddNumberToObject(root, "table_size", 1000);
    cJSON_AddNumberToObject(root, "item_num", 4);
    cJSON_AddItemToObject(root, "question", question = cJSON_CreateObject());
    cJSON_AddTrueToObject(question, "is_happy");
    cJSON_AddFalseToObject(question, "is_sweet");
    cJSON_AddTrueToObject(question, "is_funny");

    array = cJSON_CreateArray();
    if (array == NULL)
    {
        goto end;
    }
    cJSON_AddItemToObject(root, "my_array", array);

    for (index = 0; index < 2; ++index)
    {
        item = cJSON_CreateObject();
        if (item == NULL)
        {
            goto end;
        }
        cJSON_AddItemToArray(array, item);

        name = cJSON_CreateString("hello");
        if (name == NULL)
        {
            goto end;
        }
        cJSON_AddItemToObject(item, "name", name);

        value = cJSON_CreateNumber(index + 100);
        if (value == NULL)
        {
            goto end;
        }
        cJSON_AddItemToObject(item, "value", value);
    }
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

end:
    cJSON_Delete(root);
    fprintf(fp, "%s", p);

    return p;
}

void parseJson(char *pMsg)
{
    cJSON * pJson = NULL;
    cJSON * pSub = NULL;
    cJSON * pSubSub = NULL;
    cJSON * item = NULL;
    int i = 0;

    if (NULL == pMsg)
    {
        goto end;
    }

    pJson = cJSON_Parse(pMsg);
    if (NULL == pJson)
    {
        goto end;
    }

    // get string from json
    pSub = cJSON_GetObjectItem(pJson, "table_size");
    if (NULL == pSub)
    {
        goto end;
    }
    printf("table_size: %d\n", pSub->valueint);

    // get number from json
    pSub = cJSON_GetObjectItem(pJson, "item_num");
    if (NULL == pSub)
    {
        goto end;
    }
    printf("item_num: %d\n", pSub->valueint);

    // get bool from json
    pSub = cJSON_GetObjectItem(pJson, "question");
    if (NULL == pSub)
    {
        goto end;
    }

    pSubSub = cJSON_GetObjectItem(pSub, "is_happy");
    if (NULL == pSubSub)
    {
        goto end;
    }
    printf("is_happy: %s\n", pSubSub->type == cJSON_True ? "true" : "false");

    pSubSub = cJSON_GetObjectItem(pSub, "is_sweet");
    if (NULL == pSubSub)
    {
        goto end;
    }
    printf("is_sweet: %s\n", pSubSub->type == cJSON_True ? "true" : "false");

    pSubSub = cJSON_GetObjectItem(pSub, "is_funny");
    if (NULL == pSubSub)
    {
        goto end;
    }
    printf("is_funny : %s\n", pSubSub->type == cJSON_True ? "true" : "false");

    pSub = cJSON_GetObjectItem(pJson, "my_array");
    if (NULL == pSub)
    {
        goto end;
    }

    cJSON_ArrayForEach(item, pSub)
    {
        printf("#item %d\n", i++);

        pSubSub = cJSON_GetObjectItem(item, "name");
        if (NULL == pSubSub)
        {
            goto end;
        }
        printf("name: %s\n", pSubSub->valuestring);

        pSubSub = cJSON_GetObjectItem(item, "value");
        if (NULL == pSubSub)
        {
            goto end;
        }
        printf("value: %d\n", (int)pSubSub->valuedouble);
    }

end:
    cJSON_Delete(pJson);
}

int main()
{
    FILE* fp = fopen(TEST_FILE_NAME, "w+");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    char * p = makeJson(fp);
    if (NULL == p)
    {
        return 0;
    }
    printf("%s\n\n", p);

    parseJson(p);

    free(p); //千万不要忘记释放内存呀，cJSON_Print()函数或者cJSON_PrintUnformatted（）产生的内存，使用free(char *)进行释放
    fclose(fp);

    return 0;
}
