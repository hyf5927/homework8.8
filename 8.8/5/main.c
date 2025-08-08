#include<stdio.h>
#include<math.h>
#include"mymath.h"

int main(void){
    vector3f a={1,0,1},c1={0,1,0},b={1,1,1},e={1,0.5,0},c={0,1,1};//输入基本坐标
    vector3f m1=Vector3Sub( a, c1 );
    vector3f m2=Vector3Sub( a, b );
    vector3f j=Vector3Cross( m1, m2);
    float d1= Vector3Mod(j)/ Vector3Mod( m1 );//|AC1×AB|/|AC1|

    printf("第一小问的答案是%f\n",d1);

    vector3f m3=Vector3Sub( a, e );
    vector3f n=Vector3Cross( m1,m3 );//计算AEC1法向量

    float k=-n.y;//解出平面方程的常数项
    float i1=Vector3Dot(c,n)+k;
    float i2=Vector3Mod(n);

    float d2=((i1/i2)>0 ? i1/i2:-i1/i2);//|Ax0+By0+Cz0+D|/平面方向向量模长
    printf("第二小问的答案是%f",d2);
    

    return 0;
}