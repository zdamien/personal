/* My own macros.  Damien Sullivan */
#ifndef _MINE
#define _MINE

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define sign(X) ((X) > 0 ? 1 : -1)
#define abs(X) ((X) > 0 ? (X) : -(X))
#define not(X) (X)=~(X);
#define mabs(X) ((X)>0) ? (X) : (-X)
#define mynew(V,T,S) ( (V)= (T *) malloc ((S)*sizeof (T)) )
// #define mynew(VAR,TYPE,SIZE) (VAR)= (TYPE *) malloc (sizeof(TYPE)*(SIZE))
#define squ(X) ( (X)*(X) )
#define cube(X) ( (X)*(X)*(X) )

static const double PI = 3.14159265358979323846;

// degrees to radians
#define d2r(angle) ((angle)*PI/180)
// radians to degrees
#define r2d(radian) ((radian)*180/PI)

#endif

/* 

inline long int round(double x) {
        double f=floor(x);
        if (x<(f+0.5)) return f;
        else return (f+1);
}


#define sign(X) (X)>=0 ? 1 : -1
// Junk macros
#define varprompt(var) printf("Enter " #var"\n"); scanf("%f",\
        &var);
#define pcr printf("\n");

// #define varprompt(var) cout << "Enter " #var "\n"; cin >> var;

*/
