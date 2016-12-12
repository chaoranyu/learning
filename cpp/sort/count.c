/*计数排序maxk是要排序数据中最大的数，con是存放排序数据中每个数出现的个数*/
void CountingSort(uint16_t num, uint16_t maxk, uint16_t *dat, uint16_t *con) {
	uint16_t i, j, tmp;
	for(i=0; i<=maxk; i++)/*计数清0*/{
		con[i]=0;
	}
	for(i=0; i<num; i++)/*统计排序个数，并放到对应值的位置处*/{
		tmp = dat[i];
		con[tmp]++;
	}
	j=0;
	for(i=0; i<=maxk; i++) {
		tmp=con[i];
		while(tmp-->0) {
			dat[j++]=i;/*i就是排序数据中的数*/
		}
	}
}
