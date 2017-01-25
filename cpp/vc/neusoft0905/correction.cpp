#include "correction.h"
#include <cstdio>

int correct()
{
	NODE dig_buff[NN];   // 用一个双向循环链表表示13个人组成的圆圈		
	int i, j;

	int head_id = -1;    // 出局的人的队列头			
	int count = 0;       // 当前已经出局的人的个数			

	//  初始化链表			
	for (i = 0; i < NN; i++) {
		dig_buff[i].data = 0;     // 0 表示还没有出局		
		dig_buff[i].next = (i + 1) % NN;
		dig_buff[i].pre = (i - 1 + NN) % NN;
	}

	i = 0;
	j = 0;
	while (count < NN)  // 直到所有人都已经出局就结束		
	{
		j++;
		if (j == MM)  // 数到4了		
		{
			// 第 i 人数到了4，应该出局了，把i 从队列中删除	
			count++;
			dig_buff[i].data = count;  // count表示第几个出	
			dig_buff[dig_buff[i].pre].next = dig_buff[i].next;
			dig_buff[dig_buff[i].next].pre = dig_buff[i].pre;

			int temp = dig_buff[i].next;
			// 把i 加入出局队列	
			if (head_id == -1)  // 出局队列还是空的，i就是队	
			{
				head_id = i;  //
				dig_buff[i].next = dig_buff[i].pre = i;  //
			}
			else
			{
				dig_buff[i].next = head_id;
				dig_buff[dig_buff[head_id].pre].next = i;
				dig_buff[i].pre = dig_buff[head_id].pre;
				dig_buff[head_id].pre = i;
			}

			i = temp; //
			j = 0; // j = 1;
		}
		else
			i = dig_buff[i].next;
	}

	// 按出局顺序输出人			
	i = head_id;
	count = 0;
	while (count < NN)
	{
		printf("%02d ", i + 1);
		i = dig_buff[i].next;
		count++;
	}
	printf("\n");

	return 0;
}