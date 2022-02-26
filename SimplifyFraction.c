#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	printf("1. Fraction\n2. Decimal\n");
	int opt, ok = 0, prec;
	long long num, den;
	double dec, decout;
	while(ok != 1) {
		printf("Select Option : ");
		scanf("%d", &opt);
		if(opt == 1) {
			printf("Enter Fraction :- ");
			scanf("%llu/%llu", &num, &den);
			ok = 1;
		}
		else if(opt == 2) {
			printf("Enter Decimal :- ");
			scanf("%lf", &dec);
			ok = 1;
		}
		else {
			printf("\nInvalid Option ...\nPlease Enter again ...\n");
		}
	}
	printf("Enter Precision : ");
	scanf("%d", &prec);
	long long powp = pow(10, prec);
	long long numf, denn;
	if(opt == 1) {
		numf = num;
		denn = den;
	}
	else {
		numf = dec * powp;
		denn = powp;
	}
	long long whl, numn;
	whl = numf / denn;
	numn = numf % denn;
	long long eqt = ((double)numn / (double)denn) * powp;
	long long sol, nump, denp, i, snum;
	while(numn != 0) {
		sol = ((double)numn / (double)denn) * powp;
		if(sol > eqt) {
			--numn;
		}
		else if(sol < eqt) {
			--denn;
		}
		else {
			snum = sqrt(numn);
			for(i = 2; i <= snum; ++i) {
				int o = 0;
				while(o != 1) {
					if(numn % i == 0 && denn % i == 0) {
                        numn /= i;
                        denn /= i;
					}
					else {
						o = 1;
					}
				}
			}
			if(denn % numn == 0) {
				numn = 1;
				denn /= numn;
			}
			nump = numn, denp = denn;
			printf("%llu / %llu\n", nump, denp);
			--denn;
		}
	}
	decout = (double) whl + (double) nump / (double)denp;
	if(whl != 0) {
		printf("\nPrecise Fraction : %d %llu / %llu\nPrecise Decimal  : %.15f", whl, nump, denp, decout);
 	}
 	else {
		printf("\nPrecise Fraction : %llu / %llu\nPrecise Decimal  : %.15f", nump, denp, decout);
	 }
	 getch();
	return 0;
}
