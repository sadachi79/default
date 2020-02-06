/*Supplementary Text: The Program for Plasmid Positioning Written in C*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



main(){
	
	int x;
	int i= 0;
	int kx = 10;
	
	double a[100], b[100], c[100];
	double Adif[100], Bdif[100];
	double rhoAdifBdifC[100], rhoAdifA[100], rhoBdifB[100];
	
	int KP = 32000; /*Number of displays 450*/
	int KP_2 = 2000; 
	int KTKP = 100000 + 1280000; /*number of iterations between the displays 36000*/
	/* KT*KP = number of iterations in total */
	
	int idx = 440; /* kx' Pixelsper spatial element*/
	
	double aleft, bleft, cleft, Adifleft, Bdifleft;
	double alocal, blocal, clocal, Adiflocal, Bdiflocal;
	double prodC, prodB, prodA; 
	
	int num = 0;
	int num2 = 0;
	
	/*constants used (first letter(s) D=diffusion, mu=removal, kappa couplings*/
	
	double DA = .009;
	double muA = .002;
	double sigmaA = .05;
	double rhoABAdif = .0004; /* SopA, bound */
	
	double DAdif = .09;
	double muAdif = .0;
	double sigmaAdif = .0035; /*SopA, diffusible*/
	
	double DB = .00018;
	double muB = .0005;
	double sigmaB = .1;
	double kappaA = .15;
	double kappaB = .02; /* SopB, bound */
	
	double DBdif = .09;
	double muBdif = .0002;
	double sigmaBdif = .0029; /* SopB, diffusible */
	
	double DC = .0009;
	double muC = .004;
	double sigmaC = .1;
	double rhoCABdif = .002; 
	double kappaC = .0; /* core */
	
	double kp = 0.1;
	double kn = 0.001;
	
	double size = 1.0;
	
	char filename[20] = "data0000.txt";
	char filename2[20] = "pic0000.txt";	
	
	double totA, totB, totC, totAdif, totBdif;
	
	FILE* fpa;
	FILE* fpb;
	FILE* fpc;
	FILE* fp;
	FILE* fpp;
	FILE* fpt;
	
	/* Initial condition */
	for(x = 0; x < 100; x++){
		c[x] = (.995 + .01 * ((double)rand() / (double)(RAND_MAX + 1)));;
		a[x] = (.995 + .01 * ((double)rand() / (double)(RAND_MAX + 1)));
		b[x] = (.995 + .01 * ((double)rand() / (double)(RAND_MAX + 1)));;
		Adif[x] = 1.0;
		Bdif[x] = 1.0;
		rhoAdifBdifC[x] = muC; /* * (.995 + .01 * ((double)rand() / (double)(RAND_MAX + 1)));*/
		rhoAdifA[x] = muA; /* * (.995 + .01 * ((double)rand() / (double)(RAND_MAX + 1)));*/
		rhoBdifB[x] = muB; /* * (.995 + .01 * ((double)rand() / (double)(RAND_MAX + 1)));*/
	}
	
	
	fpa = fopen("data-a.txt", "w");
	fpb = fopen("data-b.txt", "w");
	fpc = fopen("data-c.txt", "w");
	fpp = fopen("plot.plt", "w");
	fpt = fopen("amount.txt", "w");
	
	totA = 0.0;
	totB = 0.0;
	totC = 0.0;
	totAdif = 0.0;
	totBdif = 0.0;
	
	for(x = 1; x < kx + 1; x++){
		/*		fprintf(fpa,"%6.5lf \t %6.5lf \t %6.5lf \t %6.5lf\n",30.0 + size * (- ((double)kx + 1.0) * 0.5 + (double)x),  a[x]/2 - 5.0 * num ,size * 0.5, a[x]/2);
		 fprintf(fpb,"%6.5lf \t %6.5lf \t %6.5lf \t %6.5lf\n",30.0 + size * (- ((double)kx + 1.0) * 0.5 + (double)x), 0.4 * b[x]/2 - 5.0 * num ,size * 0.5,  0.4 * b[x]/2);
		 fprintf(fpc,"%6.5lf \t %6.5lf \t %6.5lf \t %6.5lf\n", 30.0 + size * (- ((double)kx + 1.0) * 0.5 + (double)x), 50.0 * c[x], size * 0.5, 50.0 * c[x]/2);
		 */
		totA = totA + a[x];
		totB = totB + b[x];
		totC = totC + c[x];
		totAdif = totAdif + Adif[x];
		totBdif = totBdif + Bdif[x];
	}
	
	fprintf(fpt, "#i, A , B , C , Adif , Bdif \n");
	fprintf(fpt, "%4d, %6.5lf, %6.5lf, %6.5lf, %6.5lf, %6.5lf, %6.5lf \n", i, totA, totB, totC, totAdif, totBdif);
	
	sprintf(filename, "data%04d.txt", num);
	fp = fopen(filename, "w");
	fprintf(fp, "#num=%4d\n",num);
	printf("#num=%4d\n",num);
	for(x = 1; x < kx + 1; x++){
		fprintf(fp,"%3d\t%6.5lf\t%6.5lf\t%6.5lf\t%6.5lf\t%6.5lf\t%6.5lf\t%6.5lf\n",x,(double)(x + 30) - (double)(kx - 1) / 2.0,a[x],b[x],c[x],Adif[x],Bdif[x]);
	}
	fclose(fp);	
	fprintf(fpp, "unset key\n");
	fprintf(fpp, "set noxtics\n");
	fprintf(fpp, "set noytics\n");
	fprintf(fpp, "set terminal png\n");
	fprintf(fpp, "set xrange [0:60]\n");
	fprintf(fpp, "set yrange [0:5]\n");
	
	
	
	sprintf(filename2, "pic%04d.png", num2);
	fprintf(fpp, "set output \"%s\"\n", filename2);
	fprintf(fpp, "plot \"%s\" using 2:3 with boxes lt 2 fs solid,", filename);
	fprintf(fpp, "\"%s\" using 2:($4 * 0.4) with boxes lt 1 fs solid,", filename);
	fprintf(fpp, "\"%s\" using 2:($5 * 50) with boxes lt 3 fs solid\n", filename);						
	
	
	for(i = 1; i < KTKP; i++){
		
		if(i % 64000 == 0){
			
			kx = kx + 1;
			a[kx] = 0.0;
			b[kx] = 0.0;
			c[kx] = 0.0;
			Adif[kx] = 0.0;
			Bdif[kx] = 0.0;
			
			for(x = kx; x > 1; x--){
				a[x] = (a[x] * (double)(kx - x) + a[x-1] * (double)(x - 1)) / (double)(kx - 1);
				b[x] = (b[x] * (double)(kx - x) + b[x-1] * (double)(x - 1)) / (double)(kx - 1);
				c[x] = (c[x] * (double)(kx - x) + c[x-1] * (double)(x - 1)) / (double)(kx - 1);
				Adif[x] = (Adif[x] * (double)(kx - x) + Adif[x-1] * (double)(x - 1)) / (double)(kx - 1);
				Bdif[x] = (Bdif[x] * (double)(kx - x) + Bdif[x-1] * (double)(x - 1)) / (double)(kx - 1);
			}
			
			
		}
		
		/* Boundary Condition */
		aleft = a[1];
		bleft = b[1];
		cleft = c[1];
		Adifleft = Adif[1];
		Bdifleft = Bdif[1];
		a[kx + 1] = a[kx];
		b[kx + 1] = b[kx];
		c[kx + 1] = c[kx];
		Adif[kx + 1] = Adif[kx];
		Bdif[kx + 1] = Bdif[kx];

			
		a[x] = kp*a[x] - kn*(a[x]*a[x]);
		printf("%lf\n", a[x]);

		
		if(i % 100 == 0){
			totA = 0.0;
			totB = 0.0;
			totC = 0.0;
			totAdif = 0.0;
			totBdif = 0.0;
			
			for(x = kx; x > 1; x--){
				totA = totA + a[x];
				totB = totB + b[x];
				totC = totC + c[x];
				totAdif = totAdif + Adif[x];
				totBdif = totBdif + Bdif[x];
			}			
			
			fprintf(fpt, "%4d, %6.5lf, %6.5lf, %6.5lf, %6.5lf, %6.5lf, %6.5lf \n", i, totA, totB, totC, totAdif, totBdif);
		}
		
		if(i % KP == 0){
			num++;
			for(x = 1; x < kx + 1; x++){
				fprintf(fpa,"%6.5lf \t %6.5lf \t %6.5lf \t %6.5lf\n",30.0 + size * (- ((double)kx + 1.0) * 0.5 + (double)x), a[x]/2 - 5.0 * num ,size * 0.5 ,  a[x]/2);
				fprintf(fpb,"%6.5lf \t %6.5lf \t %6.5lf \t %6.5lf\n",30.0 + size * (- ((double)kx + 1.0) * 0.5 + (double)x), 0.4 * b[x]/2 - 5.0 * num ,size * 0.5 , 0.4 * b[x]/2);
				fprintf(fpc,"%6.5lf \t %6.5lf \t %6.5lf \t %6.5lf\n",30.0 + size * (- ((double)kx + 1.0) * 0.5 + (double)x), 50.0 * c[x]/2 - 5.0 * num ,size * 0.5 , 50.0 * c[x]/2);
			}
			
		}
		
		if(i % KP_2 == 0){
			num2++;
			sprintf(filename, "data%04d.txt", num2);
			fp = fopen(filename, "w");
			printf("#num=%4d\n",num2);
			for(x = 1; x < kx + 1; x++){
				fprintf(fp,"%3d\t%6.5lf\t%6.5lf\t%6.5lf\t%6.5lf\t%6.5lf\t%6.5lf\t%6.5lf\n",x,(double)(x + 30) - (double)(kx - 1) / 2.0,a[x],b[x],c[x],Adif[x],Bdif[x]);
			}
			fclose(fp);
			
			sprintf(filename2, "pic%04d.png", num2);
			fprintf(fpp, "set output \"%s\"\n", filename2);
			fprintf(fpp, "plot \"%s\" using 2:3 with boxes lt 2 fs solid,", filename);
			fprintf(fpp, "\"%s\" using 2:($4 * 0.4) with boxes lt 1 fs solid,", filename);
			fprintf(fpp, "\"%s\" using 2:($5 * 50) with boxes lt 3 fs solid\n", filename);						
		}
		
		
	}
	fprintf(fpp, "pause(-1)\n");
	fclose(fpa);
	fclose(fpb);
	fclose(fpc);
	fclose(fpp);
	fclose(fpt);
	
}



