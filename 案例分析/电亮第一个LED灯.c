/**************************************************************************************
实验现象：下载程序后"LED&交通灯模块"的D1指示灯点亮
接线说明： 单片机-->LED&交通灯模块(具体接线图可见开发攻略对应实验的“实验现象”章节)
		   P00-->D1	
注意事项：无									  
***********
****************************************************************************/

/*******************************************************************************
* 第一种电亮方法(sbit特殊功能位声明)       : 
*******************************************************************************/
#include "reg51.h"    //此文件中定义了单片机的一些特殊功能寄存器（头文件导入）

sbit led=P0^0;	   //将单片机的P0.0端口定义为led  sbit(特殊功能位声明)

void main(){
	
	while(1){  //while(1)保证程序一直执行下去	
		led=0;	//P0.0端口设置为低电平  单片机上电默认为高电平，端口为低电平时出现电平差从而灯亮
	}		
}
/*******************************************************************************
* 第二种电亮方法(总线法)       :
*******************************************************************************/
#include "reg51.h" //此文件中定义了单片机的一些特殊功能寄存器（头文件导入）

void main(){
	while(1){  //while(1)保证程序一直执行下去	
		P0 = 0x7f;  //8个IO端口看成二进制的01正好构成一个16进制数，为0的一位输出低电平
	}
}