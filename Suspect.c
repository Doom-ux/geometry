


#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void Triangle(double x1, double x2, double x3, double y1, double y2, double y3) {


	double P;
	double S;
	double x, a, b, c;



	a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

	if (a < b + c && b < a + c && c < a + b) {
		P = a + b + c;
		x = P / 2 * (P / 2 - a) * (P / 2 - b) * (P / 2 - c);
		S = sqrt(x);
		printf("\tperimetr = %.3f", P);
		printf("\n\tarea = %.3f\n", S);
	}
	else printf("Wrong Triangle\n");

	
}

double* retTrin(double x1, double x2, double x3, double y1, double y2, double y3) {
	
	double* A;
	A =(double*) calloc(6,sizeof(double));

	A[0] = x1;
	A[1] = x2;
	A[2] = x3;
	A[3] = y1;
	A[4] = y2;
	A[5] = y3;

	return A;
}




void Circle(double R) {


	double P, S;


	P = 2 * M_PI * R;

	S = M_PI * R * R;

	printf("\tarea = %.3lf \n", S);
	printf("\tperimeter = %.3lf\n", P);


}

double* retCircle(double ox,double oy, double R) {
	double* A;
	A = (double*) calloc(3, sizeof(double));

	A[0] = ox;
	A[1] = oy;
	A[2] = R;

	return A;
}

void InterCT(double** D, int s, double* C) {

	double x, y, x0, y0;
	double d = 0;
	double A[3];
	double B[3];
	double F[3];
	double R;


	for (int j = 0; j < 3; j++)
		A[j] = D[s][j];

	for (int j = 3; j < 6; j++)
		B[j - 3] = D[s][j];

	x0 = C[0];
	y0 = C[1];
	R = C[2];

	for (int i = 0; i < 3; i++) {
		double xm = x0 - A[i];
		double ym = y0 - B[i];
		x = fabs(xm);

		y = fabs(ym);

		F[i] = sqrt(x * x + y * y);
	}

	d = F[0];

	for (int i = 0; i < 3; i++) {

		if (d > F[i]) {
			d = F[i];
		}

	}

	if (R > d)printf("\t  %d. triangle\n",s+1);
	else printf("\t  %d. not triangle\n",s+1);

}

void InterCC(double** C, int u, int k){
	
    double xo,yo,R;
	double xm,ym;
	double* F;
	
	F = (double*)calloc(k,sizeof(double));
    
    xo = C[u][0];
    yo = C[u][1];
    R = C[u][2];
    	
    for(int i = 0; i<k; i++){
		
		if(i != u){
			
				xm = fabs(xo - C[i][0]);
				ym = fabs(yo - C[i][1]);
				
				F[i] = sqrt(xm*xm+ym*ym);
				
			}
		if(i != u){
		  if(F[i] <= (R+C[i][2]))printf("\t  %d. circle\n",i+1);
		  else printf("\t  %d. not circle\n",i+1);
        }
			 
	}
	
	
}

void InterTT(double**D,int u, int k){
	
    double v1,v2,v3,v4;
	double** A;
	double B[4],C[4],F[4];
	A =(double**) calloc(3,sizeof(double*));
	int flag;
	
	
	B[0] = D[u][0];
	B[1] = D[u][3];
	B[2] = D[u][1];
	B[3] = D[u][4];
	
	C[0] = D[u][1];
	C[1] = D[u][4];
	C[2] = D[u][2];
	C[3] = D[u][5];
	
	F[0] = D[u][2];
	F[1] = D[u][5];
	F[2] = D[u][0];
	F[3] = D[u][4];
	
	A[0] = B;
	A[1] = C;
	A[2] = F;

	
     for(int j=0; j<k;j++){

		 if(j != u){
			 flag = 0;
		   for(int i=0; i<3;i++){
			
			v1 =(A[i][2]-A[i][0])*(D[j][3]-A[i][1])-(A[i][3]-A[i][1])*(D[j][0]-A[i][0]);
			
			v2 =(A[i][2]-A[i][0])*(D[j][4]-A[i][1])-(A[i][3]-A[i][1])*(D[j][1]-A[i][0]);
			
			v3 =(D[j][1]-D[j][0])*(A[i][1]-D[j][3])-(D[j][4]-D[j][3])*(A[i][0]-D[j][0]);
			
			v4 =(D[j][1]-D[j][0])*(A[i][3]-D[j][3])-(D[j][4]-D[j][3])*(A[i][2]-D[j][0]);
			
			 if((v1*v2<0) && (v3*v4<0)) flag = 1;
					 
				 
			}
			
			for(int i=0; i<3; i++){
			v1 =(A[i][2]-A[i][0])*(D[j][4]-A[i][1])-(A[i][3]-A[i][1])*(D[j][1]-A[i][0]);
				
			v2 =(A[i][2]-A[i][0])*(D[j][5]-A[i][1])-(A[i][3]-A[i][1])*(D[j][2]-A[i][0]);
				
			v3 =(D[j][2]-D[j][1])*(A[i][1]-D[j][4])-(D[j][5]-D[j][4])*(A[i][0]-D[j][1]);
				
			v4 =(D[j][2]-D[j][1])*(A[i][3]-D[j][4])-(D[j][5]-D[j][4])*(A[i][2]-D[j][1]);
			
			 if((v1*v2<0) && (v3*v4<0)) flag = 1;
			 
			}
			
			for(int i=0; i<3; i++){
			v1 =(A[i][2]-A[i][0])*(D[j][5]-A[i][1])-(A[i][3]-A[i][1])*(D[j][2]-A[i][0]);
				
			v2 =(A[i][2]-A[i][0])*(D[j][3]-A[i][1])-(A[i][3]-A[i][1])*(D[j][0]-A[i][0]);
				
			v3 =(D[j][0]-D[j][2])*(A[i][1]-D[j][5])-(D[j][3]-D[j][5])*(A[i][0]-D[j][2]);
				
			v4 =(D[j][0]-D[j][2])*(A[i][3]-D[j][5])-(D[j][3]-D[j][5])*(A[i][2]-D[j][2]);
			
			 if((v1*v2<0) && (v3*v4<0)) flag = 1;
			 
			}
			if(flag == 1)printf("\t  %d. triangle\n",j+1);
		  else printf("\t  %d. not triangle\n",j+1);
		 }

      }
      		 

}

void InterTC(double* D, int s, double** C) {

	double x, y, x0, y0;
	double d = 0;
	double A[3];
	double B[3];
	double F[3];
	double R;


	for (int j = 0; j < 3; j++)
		A[j] = D[j];

	for (int j = 3; j < 6; j++)
		B[j - 3] = D[j];

	x0 = C[s][0];
	y0 = C[s][1];
	R = C[s][2];

	for (int i = 0; i < 3; i++) {
		double xm = x0 - A[i];
		double ym = y0 - B[i];
		x = fabs(xm);

		y = fabs(ym);

		F[i] = sqrt(x * x + y * y);
	}

	d = F[0];

	for (int i = 0; i < 3; i++) {

		if (d > F[i]) {
			d = F[i];
		}

	}

	if (R > d)printf("\t  %d. circle\n",s+1);
	else printf("\t  not  %d. circle\n",s+1);

}


int main()
{   int t = 0, l = 0;
	double** D;
	double** C;
	double x1, x2, x3, x4, y1, y2, y3, y4;
	double ox, oy, R;
	
		printf("input number of triangle:");
	scanf("%d", &t);

	printf("input number of circle:");
	scanf("%d", &l);


	D = (double**)calloc(t,sizeof(double*));
	C = (double**)calloc(l,sizeof(double*));
	
	for (int i = 0; i < t; i++) {
		printf("\nTriangle:");
		scanf("%lf %lf,%lf %lf,%lf %lf,%lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		printf("\n");
		D[i] = retTrin(x1, x2, x3, y1, y2, y3);

	}
	
	for (int i = 0; i < l; i++) {
		printf("\nCircle:");
		scanf("%lf %lf, %lf", &ox, &oy, &R);
		printf("\n");
		C[i] = retCircle(ox, oy, R);

	}
	
	puts("\n");
	
	for(int i = 0; i < t; i++){
	  
printf("\n %d. Triangle:%.0lf %.0lf,%.0lf %.0lf,%.0lf %.0lf,%.0lf %.0lf\n",i+1,D[i][0],D[i][3],D[i][1],D[i][4],D[i][2],D[i][5],D[i][0],D[i][3]);

     Triangle(D[i][0], D[i][1], D[i][2], D[i][3], D[i][4], D[i][5]);
     printf("\tintersects:\n");
     InterTT(D,i,t);
     for (int j = 0; j < l; j++) {
			InterTC(D[i], j, C);
		}

		
	}
	
	for(int i = 0; i < l; i++){
		
		printf("\n %d. Circle:%.0lf %.0lf, %.2lf\n",i+1, C[i][0], C[i][1], C[i][2]);
		Circle(C[i][2]);
		printf("\tintersects:\n");
		InterCC(C, i, l);
		for (int j = 0; j < t; j++) {
			InterCT(D, j, C[i]);
		}
		
	}
	
	return 0;
}
