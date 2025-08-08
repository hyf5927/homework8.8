#include<stdio.h>
#include<math.h>

typedef struct{
	
	float x;//x坐标 
	float y;//y坐标 
	float z;//z坐标 
	
}vector3f;

//三维向量的加 
//参数：两个相加的向量a,b
//返回值：两个向量相加的结果 
vector3f Vector3Add(vector3f a,vector3f b){
	
	vector3f result;
	result.x=a.x+b.x;
	result.y=a.y+b.y;
	result.z=a.z+b.z;
	return result;
	
}

//三维向量的加减 
//参数：被减向量a,减向量b 
//返回值：两个向量相减的结果 
vector3f Vector3Sub(vector3f a,vector3f b){
	
	vector3f result;
	result.x=a.x-b.x;
	result.y=a.y-b.y;
	result.z=a.z-b.z;
	return result;
	
}

//三维向量的点乘 
//参数：两个点乘的向量a,b
//返回值：两个向量点乘的结果 
float Vector3Dot(vector3f a,vector3f b){
	
	float result;
	result=a.x*b.x+a.y*b.y+a.z*b.z;
	return result;
	
}

//三维向量的叉乘 
//参数：两个叉乘的向量a,b
//返回值：叉乘出的新向量 
vector3f Vector3Cross(vector3f a,vector3f b){
	
	vector3f result;
	result.x=a.y*b.z-a.z*b.y;
	result.y=a.z*b.x-a.x*b.z;
	result.z=a.x*b.y-a.y*b.x;
	return result;
	
}

//三维向量的模长 
//参数：目标向量a
//返回值：目标向量的模长 
float Vector3Mod(vector3f a){
	
	float result;
	result=sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
	return result;
	
}

//三维向量的单位化 
//参数：目标向量a 
//返回值：目标向量a的单位化 
vector3f Vector3Nor(vector3f a){
	
	vector3f result;
	float mod=Vector3Mod(a);
	
	if(mod!=0){	
	result.x=a.x/mod;
	result.y=a.y/mod;
	result.z=a.z/mod;
	}
	else{
	result.x=0;
	result.y=0;
	result.z=0;
	}
	

	return result;
	
}

