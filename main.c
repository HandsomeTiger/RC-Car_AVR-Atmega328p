/*
 * GccApplication1.c
 *
 * Created: 11/8/2023 12:32:50 AM
 * Author : Mark
 */

#include <avr/io.h>

//Switches/Receiver
//PORTB = 0x00
//DDRB = 0x03
#define SW_4			0x04 
#define SW_3			0x08
#define SW_2			0x10
#define SW_1			0x20

//Motor inputs
//PORTD: 0x3C
//DDRD = 0xFF
#define Motor4			0x04
#define Motor3			0x08
#define Motor2			0x10
#define Motor1			0x20


void set_up(){
	DDRB = 0x03; //00000000, ports for receiver are input
	PORTB = 0x00; //00111100, This is ports are for receiver
	
	DDRC = 0x3F; //Maybe use ADC later
	PORTC=0x00; //Maybe use ADC later
	
	DDRD = 0xFF; //00111100, ports for motor driver are output
	PORTD = 0x3C; //00111100, This ports are for motor driver
}



unsigned char Switch_1 (void){

	unsigned char iii = 0;
	unsigned char foo = 0;
	
	iii = PINB & SW_1;
	
	if ( iii == SW_1 )
		foo = 1;
	
	return foo;
	
}

unsigned char Switch_2 (void){

	unsigned char iii = 0;
	unsigned char foo = 0;
	
	iii = PINB & SW_2;
	
	if ( iii == SW_2 )
	foo = 1;
	
	return foo;
	
}

unsigned char Switch_3 (void){

	unsigned char iii = 0;
	unsigned char foo = 0;
	
	iii = PINB & SW_3;
	
	if ( iii == SW_3 )
	foo = 1;
	
	return foo;
	
}

unsigned char Switch_4 (void){

	unsigned char iii = 0;
	unsigned char foo = 0;
	
	iii = PINB & SW_4;
	
	if ( iii == SW_4 )
	foo = 1;
	
	return foo;
	
}
void Motor1_ON (void){
	PORTD = Motor1;
}

void Motor2_ON (void){
	PORTD = Motor2;
}

void Motor3_ON (void){
	PORTD = Motor3;
}

void Motor4_ON (void){
	PORTD = Motor4;
}



int main(void) {
	set_up(); 
//Motor1 = FR,BR Back
//Motor2 = FR.BR Front
//Motor3 = FL,BL Front
//Motor4 = FL,BL Back


void Go_Front (void){
	PORTD = Motor2 | Motor3;
}

void Go_Back (void){
	PORTD = Motor1 | Motor4;
}

void Turn_Left (void){
	PORTD = Motor2 | Motor4;
}

void Turn_Right (void){
	PORTD = Motor3 | Motor1;
}


	while (1) {
		
		if(Switch_1() == 1){
			Go_Front();	

		}
		else if(Switch_2() == 1){
			Go_Back();

		}
		else if(Switch_3() == 1){
			Turn_Left();
			
		}
		else if(Switch_4() == 1){
			Turn_Right();
		}
		else
		PORTD = 0x00; 
		
	}
	return 0;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
int Dfront = 10;
int Dback = 11;
int Dleft = 12;
int Dright = 13;

const int out1 = 2;
const int out2 = 3;
const int out3 = 4;
const int out4 = 5;

void setup()
{
	pinMode(out1, OUTPUT);
	pinMode(out2, OUTPUT);
	pinMode(out3, OUTPUT);
	pinMode(out4, OUTPUT);

	pinMode(Dfront, INPUT);
	pinMode(Dback, INPUT);
	pinMode(Dleft, INPUT);
	pinMode(Dright, INPUT);
}

void loop()
{
	 Dfront = digitalRead(10); //PINB 0000 0100 = 0x04
	 Dback = digitalRead(11); //PINB 0000 1000 = 0x08
	 Dleft = digitalRead(12); //PINB 0001 0000 = 0x10
	 Dright = digitalRead(13); //PINB 0010 0000 = 0x20
	 
	   if (Dfront == HIGH) {       //(PINB & 0x04)
		  digitalWrite(out2,HIGH); //PORTD 0000 1000 = 0x08
		  digitalWrite(out3,HIGH); //PORTD 0001 0000 = 0x10
		  digitalWrite(out1,LOW);  //PORTD 0000 0100 = 0x04
		  digitalWrite(out4,LOW);  //PORTD 0010 0000 = 0x20
		  
		  Final: PORTD = 0x18; 0001 1000
	  }
	  
	  else if(Dback == HIGH){      //(PINB & 0000 1000 = 0x08)
		  digitalWrite(out1,HIGH); //PORTD 0000 0100 = 0x04
		  digitalWrite(out4,HIGH); //PORTD 0010 0000 = 0x20
		  digitalWrite(out2,LOW);  
		  digitalWrite(out3, LOW);
		  
		  Final: PORTD = 0010 0100 = 0x24;
	  }

	  else if(Dleft == HIGH){		//(PINB & 0010 0000 = 0x20)
		  digitalWrite(out2,HIGH);  //PORTD 0000 1000 = 0x08
		  digitalWrite(out4,LOW);
		  digitalWrite(out1,LOW);
		  digitalWrite(out3,LOW);
		  
		  Final: PORTD 0000 1000 = 0x08
	  }

	  else if(Dright == HIGH){		(PINB & 0001 0000 = 0x10)
		  digitalWrite(out1,LOW);
		  digitalWrite(out3,HIGH); //PORTD 0001 0000 = 0x10
		  digitalWrite(out2,LOW);
		  digitalWrite(out4,LOW);
		  
		  Final: PORTD 0001 0000 = 0x10
	  }

	  else{
		  digitalWrite(out1,LOW);
		  digitalWrite(out2,LOW);
		  digitalWrite(out3,LOW);
		  digitalWrite(out4,LOW);
		  
		  Final:PORTD 0000 0000 = 0x00 
		  
	  }
  }
  */