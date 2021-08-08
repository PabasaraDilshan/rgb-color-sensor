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
double theta[3][11] = {{ 7.80644240e+02, -4.13541438e+00,  1.59315003e+00, -3.45407759e+00,
	-9.54168462e-04, -2.08982170e-03,  2.71439925e-03, -6.38481761e-06,
	7.25086177e-03,  5.62079704e-03, -6.56728901e-04}, { 5.17850799e+03, -7.95412008e+00, -8.00483746e+00, -7.77173139e+00,
	-6.37863401e-04, -2.08148107e-04, -4.29135121e-03, -1.52957332e-05,
	9.63670908e-03,  1.34797074e-02,  1.59249269e-02}, { 2.40181999e+03, -5.53947782e+00, -2.49122749e+00, -4.34062003e+00,
	-4.89891584e-04,  1.92371330e-03,  4.32416302e-03, -9.86222636e-06,
6.19024560e-03,  9.65242368e-03, -1.46407617e-03}};*/
double theta[3][11] = {{ 8.39659089e+03, -1.43387799e+01, -1.24025925e+01, -1.21804079e+01,
-1.36744710e-03, -1.10227697e-03, -1.60541527e-03, -2.99189254e-05,
2.20019394e-02,  2.27728415e-02,  1.91967524e-02}, { 1.21126887e+04, -1.72854849e+01, -1.81688637e+01, -2.00784018e+01,
3.65574715e-04,  5.03305236e-03,  1.95367770e-04, -3.94800877e-05,
2.00262057e-02,  3.23329961e-02,  2.43869542e-02}, { 5.94820519e+03, -1.08256412e+01, -1.01770232e+01, -6.25221774e+00,
-3.37371722e-04,  4.60728185e-03,  2.74393213e-03, -2.01412798e-05,
1.31040478e-02,  1.73541278e-02,  3.94189474e-03}};
double prediction[3];


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
char* intos(int num){
	char* c =  itos(num,1);
	len = 0;
	return c;
}
double* readingtorgb(double red,double blue,double green){
	double Xarr[] = {1,red,green,blue,red*red,green*green,blue*blue,red*green*blue,red*green,red*blue,green*blue};
	double redscaled = 0;
	double greenscaled = 0;
	double bluescaled = 0;
	for(int i=0;i<11;i++){
		//Serial.print(Xarr[i]);
		//Serial.print(" ");
		redscaled+=theta[0][i]*Xarr[i];
		
	}
	for(int i=0;i<11;i++){
		greenscaled+=theta[1][i]*Xarr[i];
		
	}
	for(int i=0;i<11;i++){
		bluescaled+=theta[2][i]*Xarr[i];
		
	}
	prediction[0] = redscaled;
	prediction[1] = greenscaled;
	prediction[2] = bluescaled;
	return prediction;
	
}


#endif /* TOOLS_H_ */