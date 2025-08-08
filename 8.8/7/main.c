#include<stdio.h>
#include<stdint.h>

//大小端转化函数 
//返回转化后的数 
uint32_t swap(uint32_t a){
	
return	(a<<24)//低八位移到高八位 （此外别的位数本来就填充为0了，不用作与运算） 
	| 	((a<<8) & 0x00FF0000)//次低八位移到次高八位，同时保证只改变次高八位
	|	((a>>8) & 0x0000FF00)//次高八位移到次低八位，同时保证只改变次低八位
	|	(a>>24);//高八位移到低八位 （此外别的位数本来就填充为0了，不用作与运算） 
	
}


int main(){
	uint32_t num=0x12253647;
	uint8_t* bytes=(uint8_t*)&num;//定义一个uint8_t* bytes的指针可以直观感受字节序的变化 
	
	uint32_t little_endian=num;//小端模式就是原来的num 
	bytes=(uint8_t* )&little_endian;
	printf("在小端模式下的数据是：");
	int i;
	for(i=0;i<4;i++){
		printf("0x%02x",bytes[i]);
	}

    printf("\n");
	
	uint32_t large_endian=swap(num);//大端模式要大小端转化 
	bytes=(uint8_t* )&large_endian;
	printf("在大端模式下的数据是：");
	int j;
	for(j=0;j<4;j++){
		printf("0x%02x",bytes[j]);
	}
	
	return 0;
}
