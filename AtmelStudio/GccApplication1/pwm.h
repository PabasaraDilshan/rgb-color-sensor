/*
 * pwm.h
 *
 * Created: 6/9/2021 2:27:38 AM
 *  Author: dilsh
 */ 


#ifndef PWM_H_
#define PWM_H_

void initPwm(int id){
	DDRD |= 1<<id;
	switch (id)
	{
	case 6:
		TCCR0A |= 1<<COM0A1|1<<WGM01|1<<WGM00;
		TCCR0B |= 1<<CS01;
		
		break;
		
	case 5:
		TCCR0A |= 1<<COM0B1|1<<WGM01|1<<WGM00;
		TCCR0B |= 1<<CS01;
		break;
	case 3:
		TCCR2A |= 1<<COM0B1|1<<WGM01|1<<WGM00;
		TCCR2B |= 1<<CS01;
		break;
	}
	
	
}
void pwm(int id,uint8_t value){
	switch (id)
	{
		case 6:
			
			OCR0A =value;
			break;
		
		case 5:
			
			OCR0B = value;
			break;
		case 3:
			OCR2B = value;
			break;
	}
}



#endif /* PWM_H_ */