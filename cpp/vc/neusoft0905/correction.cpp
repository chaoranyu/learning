#include "correction.h"
#include <cstdio>

int correct()
{
	NODE dig_buff[NN];   // ��һ��˫��ѭ�������ʾ13������ɵ�ԲȦ		
	int i, j;

	int head_id = -1;    // ���ֵ��˵Ķ���ͷ			
	int count = 0;       // ��ǰ�Ѿ����ֵ��˵ĸ���			

	//  ��ʼ������			
	for (i = 0; i < NN; i++) {
		dig_buff[i].data = 0;     // 0 ��ʾ��û�г���		
		dig_buff[i].next = (i + 1) % NN;
		dig_buff[i].pre = (i - 1 + NN) % NN;
	}

	i = 0;
	j = 0;
	while (count < NN)  // ֱ�������˶��Ѿ����־ͽ���		
	{
		j++;
		if (j == MM)  // ����4��		
		{
			// �� i ��������4��Ӧ�ó����ˣ���i �Ӷ�����ɾ��	
			count++;
			dig_buff[i].data = count;  // count��ʾ�ڼ�����	
			dig_buff[dig_buff[i].pre].next = dig_buff[i].next;
			dig_buff[dig_buff[i].next].pre = dig_buff[i].pre;

			int temp = dig_buff[i].next;
			// ��i ������ֶ���	
			if (head_id == -1)  // ���ֶ��л��ǿյģ�i���Ƕ�	
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

	// ������˳�������			
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