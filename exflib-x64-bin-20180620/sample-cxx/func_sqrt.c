/* -*- C -*- */
/* Time-stamp: "2008-11-20 12:25:44 fujiwara" */

/**********************************************************************/
/*  Copyright (C) 2005, FUJIWARA Hiroshi                              */
/*        <fujiwara@acs.i.kyoto-u.ac.jp>                              */
/**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "exfloat.h"

/*
  y[]   : sqrt(x),  	(1+pr64) elements
  x[]   : input,    	(1+pr64) elements

  w[] : work area, 	(1+pr64+guard)*3 elements
*/  

exflib_ulong exflib_float_sqrt_old(exflib_uQword y[], exflib_cuQword x[], const long pr64, exflib_uQword w[])
{
    exflib_Qword m;
    long k;
    exflib_uQword* alpha = w;		/* extended number */
    exflib_ulong ret;

    const long guard = 1;		/* guard element */
    const long pr64g = pr64 + guard;	/* extended precision */
    exflib_uQword *x_n = w + (1+pr64g);
    exflib_uQword *tmp = w + (1+pr64g)*2;

    long i;
    double a, initial;
    exflib_uQword *pa;

    /* domain check */
    if(x[0] & EXFLIB_MASK_SGN){
	printf("%016llx\n", x[0]);
	fprintf(stderr, "sqrt : domain error\n");
	exit(1);
    }

    /* zero check */
    if(x[0] == 0){
	y[0] = 0;
	return 0;
    }

    /* decompose the argument                           */
    /* x = 2^e x 1.F = 2^(2m) x (1.F x 2^k), k = 0 or 1 */
    /*   i.e., e = 2m+k, m \in Z, k \in {0,1}.          */
    m = x[0] - EXFLIB_BIAS;
    k = m & 1;
    m >>= 1;

    /* zero extension of the argument x */
    /* alpha = (1.F x 2^k) */
    alpha[0] = EXFLIB_BIAS + k;
    for(i = 1; i <= pr64; i++)
	alpha[i] = x[i];
    for(; i <= pr64g; i++)
	alpha[i] = 0;

    /* Finding an initial value with the build-in double sqrt function   */
    /* Chopping the MP number 'alpha' to the double precision number 'a'. */
    pa = reinterpret_cast<exflib_uQword *>(&a);
    *pa = alpha[1] >> 12;
    *pa += (exflib_uQword)(0x3ff + k) << 52;
    initial = sqrt(a);

    /* set initial value of Newton method */
    pa = reinterpret_cast<exflib_uQword *>(&initial);
    x_n[0] = EXFLIB_BIAS + ((exflib_uQword)*pa >> 52) - 0x3ff;
    x_n[1] = *pa << 12;
    for(i = 2; i <= pr64g; i++)
	x_n[i] = 0;

    /* Newton iteration */
    /* i is a number of correct bits */

    /* x_new = (x_n + (alpha / x_n)) / 2 */
    for(i = 50; i < pr64g*64; i *= 2){
	exflib_float_div(tmp, alpha, x_n, pr64g);
	exflib_float_add(x_n, x_n, tmp, pr64g);
	x_n[0] -= 1;
    }

    /* set return value */
    y[0] = m + EXFLIB_BIAS;
    for(i = 1; i <= pr64; i++)
	y[i] = x_n[i];

    if(sizeof(long) == 8)	/* 64-bit architecture */
	ret = x_n[pr64+1];
    else if(sizeof(long) == 4)	/* 32-bit architecture */
	ret = x_n[pr64+1] >> 32;

    return ret;
}

exfloat sqrt_old(const exfloat& x)
{
    exflib_ulong hint;
    hint = exflib_float_sqrt_old(exflib::work.num, x.num, exfloat::precision64, exflib::mem);
    exfloat::round(exflib::work.num, hint, exfloat::precision64);
    return exflib::work;
}

/* End of func_sqrt.c */
