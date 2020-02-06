/* file mymod.c */
#include <R.h>
#include <math.h>
static double parms[3];
#define ka parms[0]
#define ke parms[1]
#define CL parms[2]

/* initializer */
void initmod(void (* odeparms)(int *, double *))
{
   int N=2;
   odeparms(&N, parms);
}

/* names for states and derivatives */
#define y1 y[0]
#define y2 y[1]
#define dy1 ydot[0]
#define dy2 ydot[1]
#define c1 yout[0]
#define c2 yout[1]

/* Derivatives and 1 output variable */
void derivs (int *neq, double *t, double *y, double *ydot, double *yout, int *ip)
{
    if (ip[0] <1) error("nout should be at least 1");
    dy1 = -exp(ka)*y1;
    dy2 = exp(ka)*y1-exp(ke)*y2;
    c1 = 0.0;
    c2 = y2/exp(CL)*exp(ke);
}

/* END file mymod.c */