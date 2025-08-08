#ifndef __MATH_H__
#define __MATH_H__

typedef struct{
	
	float x;//x坐标 
	float y;//y坐标 
	float z;//z坐标 
	
}vector3f;

vector3f Vector3Add(vector3f a,vector3f b);
vector3f Vector3Sub(vector3f a,vector3f b);
float Vector3Dot(vector3f a,vector3f b);
vector3f Vector3Cross(vector3f a,vector3f b);
float Vector3Mod(vector3f a);
vector3f Vector3Nor(vector3f a);

#endif