#include<stdio.h>
#include<string.h>

//将float类型的小数存入数组中
void FloatToChar(float x1,float x2,char arr[8]){
//参数分别为第一个数，第二个数，要存入的目标数组的地址
	char *p1=(char *)&x1;
	char *p2=(char *)&x2;//将两个小数的地址存入中间变量char类型的数组中 
	
	int i;
	for(i=0;i<sizeof(float);i++){
		arr[i]=p1[i];
		arr[i+sizeof(float)]=p2[i];
	}//用循环将两个中间变量数组中的元素存入目标数组中 
}

//从该数组中提取出这两个小数
void CharToFloat(char arr[8],float *p1,float *p2){
//参数分别为存入的数组的地址，取出的第一个数的指针，取出的第二个数的指针
	char temp1[4];
	char temp2[4];
	
	int i;
	for(i=0;i<sizeof(float);i++){
		temp1[i]=arr[i];
		temp2[i]=arr[i+sizeof(float)];
	}//将数组中的元素分别对应存入两个中间变量数组 
	
	*p1=*(float *)temp1;
	*p2=*(float *)temp2;//解引用将中间变量数组中的元素分别写入两个小数对应的指针变量中 
}

int main(){
	float x1,x2,x3,x4;
	char arr[8];
	float *p1=&x3,*p2=&x4;//不要定义空指针，要指向某个变量 
	
	printf("请输入两个小数");
	scanf("%f"  "%f",&x1,&x2);
	
	FloatToChar(x1,x2,arr);
	
	CharToFloat(arr,p1,p2);
	printf("转换后的两个小数是：%.8f  %.8f",x3,x4);
	return 0;
}