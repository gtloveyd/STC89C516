/**************************************************************************************
实验现象：下载程序后按下K1~K8按键可以对D1~D8小灯独立亮灭
接线说明： 1.单片机-->LED&交通灯模块
		   J22-->J19
		   2.单片机-->独立按键模块
		   J20-->JP1	
注意事项：按键消抖(软件程序消抖)																			  
***************************************************************************************/
#include "reg51.h"			 //此文件中定义了单片机的一些特殊功能寄存器

#define uint unsigned int	 //宏定义两个无符号数据类型
#define uchar unsigned char
//由于编码器的原因声明必须在函数前面
uint i = 1;
sbit led1 = P0^0;	//定义P0.0口是led1
sbit led2 = P0^1;	//定义P0.1口是led2
sbit led3 = P0^2;	//定义P0.2口是led3
sbit led4 = P0^3;	//定义P0.3口是led4
sbit led5 = P0^4;	//定义P0.4口是led5
sbit led6 = P0^5;	//定义P0.5口是led6
sbit led7 = P0^6;	//定义P0.6口是led7
sbit led8 = P0^7;	//定义P0.7口是led8
sbit k1 = P1^0;		//定义P1.0口是k1
sbit k2 = P1^1;		//定义P1.1口是k2
sbit k3 = P1^2;		//定义P1.2口是k3
sbit k4 = P1^3;		//定义P1.3口是k4
sbit k5 = P1^4;		//定义P1.4口是k5
sbit k6 = P1^5;		//定义P1.5口是k6
sbit k7 = P1^6;		//定义P1.6口是k7
sbit k8 = P1^7;	    //定义P1.7口是k8
//延时函数
void delay(uint i){
	while(i--);	
}

void keypros(){
	while(1){
	switch(i){
		  case 1:
		  	if(k1 == 0){		  //检测按键K1是否按下	
			delay(1000);   //消除抖动 抖动杂波一般大约10ms
			if(k1 == 0){	 //再次判断按键是否按下
				led1 = ~led1;	  //led状态取反
			}
			while(!k1);	 //检测按键是否松开
		}
		  case 2:
		  	if(k2 == 0){		  
			delay(1000);  
			if(k2 == 0){	
				led2 = ~led2;	 
			}
			while(!k2);	 
		}
		  case 3:
		  	if(k3 == 0){		  
			delay(1000);   
			if(k3 == 0){	 
				led3 = ~led3;	  
			}
			while(!k3);	 
		}
		  case 4:
		  	if(k4 == 0){		 
			delay(1000);   
			if(k4 == 0){	 
				led4 = ~led4;	 
			}
			while(!k4);	
		}
		  case 5:
		  	if(k5 == 0){		  	
			delay(1000);   
			if(k5 == 0){	 
				led5 = ~led5;	 
			}
			while(!k5);	 
		}
		  case 6:
		 	 if(k6 == 0){		  
			delay(1000);   
			if(k6 == 0){	 
				led6 = ~led6;	  
			}
			while(!k6);	 
		}
		  case 7:
		  	if(k7 == 0){		
			delay(1000);   
			if(k7 == 0){	 
				led7 = ~led7;	  
			}
			while(!k7);	 
		}
		  case 8:
		  	if(k8 == 0){		 	
			delay(1000);   
			if(k8 == 0){	
				led8 = ~led8;	 
			}
			while(!k8);	 
		}		
	}
}
}

void main(){	
	led1 = 1;	//初始使led1为高电平，灯不亮
	led2 = 1;	//初始使led2为高电平，灯不亮
	led3 = 1;	//初始使led3为高电平，灯不亮
	led4 = 1;	//初始使led4为高电平，灯不亮
	led5 = 1;	//初始使led5为高电平，灯不亮
	led6 = 1;	//初始使led6为高电平，灯不亮
	led7 = 1;	//初始使led7为高电平，灯不亮
	led8 = 1;	//初始使led8为高电平，灯不亮
	while(1){		
		keypros();  //按键处理函数	
	}		
}
