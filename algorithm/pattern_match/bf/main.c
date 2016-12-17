#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int index_bf(char *s, char *t, int pos);
int index_bf_self(char *s, char *t, int index);

/*
BF算法 示例
*/
int main()
{
    char s[] = "6he3wor"; //标准BF算法中，s[0]和t[0]存放的为字符串长度。
    char t[] = "3wor";
    int m = index_bf(s,t,2); //标准BF算法
    printf("index_bf:%d\n", m);
    m = index_bf_self(s,t,2); //修改版BF算法，s和t中，不必再存放字符串长度。
    printf("index_bf_self:%d\n", m);
    exit(0);
}

/*
字符串S和T中，s[0],t[0]存放必须为字符串长度
例：s[]="7hi baby!"  T[]="4baby"  index_bf(s,t,1);
pos：在S中要从下标pos处开始查找T
(说明：标准BF算法中，为研究方便，s[0],t[0]中存放的为各自字符串长度。)
*/
int index_bf(char *s, char *t, int pos)
{
    int i,j;
    if(pos >= 1 && pos <= s[0]-'0')
    {
        i = pos;
        j = 1;
        while( i<=s[0]-'0' && j <= t[0] - '0' )
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
            }
            else 
            {
                j=1;
                i=i-j+2;
            }
            if(j>t[0]-'0')
            {
                return i-t[0]+'0';
            }
        }
        return -1;
    }
    else 
    {
        return -1;
    }
}

/*
修改版，字符串s和t中，不必再包含字符串长度。
例：s[]="hi baby"  t[]="baby"  index_bf_self(s,t,0);
index:在s中，从几号下标开始查找
*/
int index_bf_self(char *s,char *t,int index)
{
    int i=index,j=0;
    while(s[i]!='\0')
    {
        while(*(t+j)!='\0' && *(s+i+j)!='\0')
        {
            if(*(t+j)!=*(s+i+j))
                break;
            j++;
        }
        if(*(t+j)=='\0')
        {
            return i;
        }
        i++;
        j=0;
    }
    return -1;
}
