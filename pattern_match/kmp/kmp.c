#include <stdio.h>
#include <stdlib.h>

void get_next(char *t,int *next);
int index_kmp(char *s,char *t,int pos);

int main(int argc,char *argv[])
{
/*
    char t[]="6ababcd";
    int next[7];
    get_next(t,next);
    int i;
    for(i=0;i<7;i++)
        printf("%d,",next[i]);
    printf("\n");
*/
    char s[]="6helwor";
    char t[]="3wor";
    int m=index_kmp(s,t,1);
    printf("%d\n",m);
    exit(0);

}

/*
利用KMP算法，求解字符串t在s中的开始位置。
pos：在字符串S中，从下标pos开始查找是否含有t子串
如果含有，返回t在s中的下标起始位置。否则，返回-1.
注意：s和t中首元素保存的都是字符串的长度。
*/
int index_kmp(char *s,char *t,int pos)
{
    int next[sizeof(t)]; 
    get_next(t,next);
    int i=pos;
    int j=1;
    while(i<=s[0]-'0'&&j<=t[0]-'0')
    {
        if(0==j || s[i]==t[j])
        {
            i++;
            j++;
        }
        else 
        {
            j=next[j];
        }
    }
    if(j>t[0]-'0')
    {
        return i-t[0]+'0';
    }
    else
        return -1;
}

void get_next(char *t,int *next)
{
    int i=0;
    int j=1;
    next[1]=0;
    while(j<t[0]-'0')
    {
        if(0==i || t[i]==t[j])
        {
            i++;
            j++;
            if(t[i]!=t[j])
                next[j]=i;
            else
                next[j]=next[i];
        }
        else 
        {
            i=next[i];
        }
    } 
}

