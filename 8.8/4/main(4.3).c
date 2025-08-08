#include<stdio.h>
#include<string.h>

union FloatCharUnion{
//参数分别为第一个数，第二个数，要存入的目标数组的地址
	float f;
	char c[sizeof(float)];
};//使用联合体  

//将float类型的小数存入数组中
void FloatToChar(float x1,float x2,char arr[8]){
//参数分别为存入的数组的地址，取出的第一个数的指针，取出的第二个数的指针
	union FloatCharUnion u1,u2;
	u1.f=x1;
	u2.f=x2;
	int i;
	for(i=0;i<sizeof(float);i++){
		arr[i]=u1.c[i];
		arr[i+sizeof(float)]=u2.c[i];
	}
}

//从该数组中提取出这两个小数
void CharToFloat(char arr[8],float *p1,float *p2){
	union FloatCharUnion u1,u2;
	int i;
	for(i=0;i<sizeof(float);i++){
		u1.c[i]=arr[i];
		u2.c[i]=arr[i+sizeof(float)];
	}
	*p1=u1.f;
	*p2=u2.f;
}

int main(){
	float x1,x2,x3,x4;
	char arr[8];
	float *p1=&x3,*p2=&x4;
	
	printf("请输入两个小数");
	scanf("%f"  "%f",&x1,&x2);
	
	FloatToChar(x1,x2,arr);
	
	CharToFloat(arr,p1,p2);
	printf("转换后的两个小数是：%.8f  %.8f",x3,x4);
	return 0;
}