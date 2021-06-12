/*
 * tools.h
 *
 * Created: 6/9/2021 2:21:04 AM
 *  Author: dilsh
 */ 


#ifndef TOOLS_H_
#define TOOLS_H_


int len = 0;
/*
char* intos(int num){
	char* c =  itos(num,1);
}*/


char* itos(int num,int count){
	char* st;
	if(num<10){
		//st = new char[len];
		st = (char*)malloc(len*sizeof(char));
		st[len] = (char)(num+(int)'0');
		
		}else{
		int rem = num%10;
		st = itos(num/10,count+1);
		st[len] = 	(char)(rem+(int)'0');
	}
	
	len++;

	return st;
	
}




#endif /* TOOLS_H_ */