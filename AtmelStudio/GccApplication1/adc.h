/*
 * adc.h
 *
 * Created: 6/9/2021 2:17:27 AM
 *  Author: dilsh
 */ 


#ifndef ADC_H_
#define ADC_H_

void initAdc(){
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
}

uint16_t readAdc(uint8_t channel){
	ADMUX = (ADMUX&0xF0)|(channel & 0x0F);
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	return ADC;
}



#endif /* ADC_H_ */