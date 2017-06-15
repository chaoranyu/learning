#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
//#include <bool.h>

#define true 1
#define false 0

#define IS_IP_VALID(src, dst)\
	do{\
		return inet_pton(AF_INET, src, (void *)dst);\
	}while(0)

int IsSubnetMask(char* subnet);
int if_a_string_is_a_valid_ipv4_address(const char *str, struct in_addr dst)  ;

#pragma comment(lib,"Ws2_32")

void  main()
{
	if (IsSubnetMask("255.255.255.192"))
	{
		printf("succeed\n");
	} 
	else
	{
		printf("failed\n");
	}


		
} 

/****************************************************************************/
/* 下面给的例子是这样的：先验证是否为合法IP，然后将掩码转化成32无符号整型， */
/*取反为000...00111...1，然后再加1为00...01000...0，此时为2^n，			    */
/*如果满足就为合法掩码。													*/
/*或者，查找字符串中的子串“01”，若查不到就合法，否则不合法。				*/	
/****************************************************************************/
int IsSubnetMask(char* subnet)  
{ 
	struct in_addr dst;
	if (1 == inet_pton(AF_INET, subnet,(void *)&dst))
	{
		unsigned int b = 0, i, n[4];  
		sscanf(subnet, "%u.%u.%u.%u", &n[3], &n[2], &n[1], &n[0]);  
		printf("%d,%d,%d,%d, dst:0x%x\n", n[3], n[2], n[1], n[0],dst.s_addr);
		dst.s_addr = ~(dst.s_addr) + 1;
		printf("dst=~dst + 1 = 0x%x\n", dst.s_addr);

		if((dst.s_addr & (dst.s_addr - 1)) == 0)   //判断是否为2^n   
		{
			printf("----------dst---\n");
			return true;

		}
		else
		{
			printf("子网掩码前边的二进制的1必须是连续的！\n");
			return false;
		}
	} 
	else
	{
		printf("子网掩码的格式不正确！\n");
		return false;
	}
			
}

/************************************************************************/
/*	判断IP合法的方法						                           */
/**********************************************************************/
int if_a_string_is_a_valid_ipv4_address(const char *str, struct in_addr dst)  
{    
    if (inet_pton(AF_INET,str,(void *)&dst))    
        return true;  
    else  
        return false;  


    /*if (inet_aton(str,&dst))    
        return false;  
    else  
        return true;  */
}
