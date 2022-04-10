#include "stm32f10x.h"
#include <string.h>
#include <iostream>
#include <map>


// telegram id --->    @eneeir
// github --->  https://github.com/embeddedsystemdesigner
// website  ---> www.enee.ir



using namespace std;

void delay_us(unsigned int time);
void delay_ms(unsigned int time);
void GPIO_INIT(void);



class flasher
{
	public:
	unsigned int speed;
  void GPIO_CONFIG(void);
	void set(void);
	void reset(void);
	void flash(void){ set();  delay_ms(speed);    reset();  delay_ms(speed); }
};



int main (void)
{
flasher flash;
map<string,int> student;
map<string,int>::iterator it;

	
float f1=3.4,f2=6.8;
	
char a='a',b='b';	
student["bijan"] = 18;
student["ali"]=12;	
student["shima"]=15;	



cout<<"first student is:"<<student["bijan"]<<endl;
it = student.begin();
cout<<it->first<<"--->"<<it->second<<endl;
cout<<"we have "<<student.size()<<" student here"<<endl;



for(it=student.begin(); it!=student.end(); it++)
	{	
	cout<<it->first<<"--->"<<it->second<<endl;
	delay_ms(500);		
	}


cout<<"*************************************"<<endl;
	

	
	
flash.GPIO_CONFIG();
flash.speed=300;

	
	
	
while(1)
	{
		
	flash.flash();	

	}


	
}



void flasher::set(void)
{

GPIO_SetBits(GPIOF,GPIO_Pin_4);	
	
}



void flasher::reset(void)
{
	
GPIO_ResetBits(GPIOF,GPIO_Pin_4);	
	
}


void flasher::GPIO_CONFIG(void)
{
GPIO_InitTypeDef GPIO;
	
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);	

	
GPIO.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO.GPIO_Pin = GPIO_Pin_4;
GPIO.GPIO_Speed = GPIO_Speed_2MHz;
GPIO_Init(GPIOF,&GPIO);		

}



void delay_us(unsigned int time)
{
	
	while(time--)	
		{
			
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();	
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();	
    __NOP();__NOP();	

		}
	
}




void delay_ms(unsigned int time)
{
	
	while(time--)	
		{
			
    delay_us(1000);
			
		}

}



