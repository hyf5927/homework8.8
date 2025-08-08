#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	uint32_t result=0;
	srand((unsigned int)time(NULL));//初始化随机数种子
	
	int n;
	for(n=1;n<=32;n++){
		int num=rand();//生成32个随机数 
		
		if(num>100){
			n--;continue;
		}//保证生成的数在0-100间 
		
		if(num>50){
			result |=( 1<<(n-1));
		}//如果num>50,此次循环的result就是1从最低位左移n-1位
		 //然后再将此次的result与之前的result按位或 
	}
	printf("整数为：0x%08x\n",result);//输出该整数 
	return 0;
}