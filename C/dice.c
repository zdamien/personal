#include <stdio.h>
#include <time.h>

int d10() {
  return rand() % 10 +1;
}
int dX() {
    int d = d10();
    if (d < 7)
        return 0;
    else if (d < 10)
        return 1;
    else return 2;
}
int hundreddX() {
    int sum=0;
    int i;
    for (i=0; i<100; i++) {
        sum+= dX();
    }
    return sum;
}

int d6() {
  return rand() % 6 +1;
}
int d20() {
  return rand() % 20 +1;
}
int dF() {
  return rand() % 3 -1;
}
int dFx() {
  // flatter Fudge die
  int i= d6();
  if (i==1)
    return -1;
  else if (i==6)
    return 1;
  else
    return 0;
}
int fourdF() {
  return dF()+dF()+dF()+dF();
}
int fourdFx() {
  return dFx()+dFx()+dFx()+dFx();
}

int compd20() {
  /*takes middle of 3 rolls */
  int a, b, c, temp; 
  a = d20();
  temp = d20();
  if (temp > a) {
    b = temp;
  } else {
    b = a;
    a = temp;
  }
  temp = d20();
  if (temp > b) {
    c = temp;
  } else {
    c = b;
    if (temp > a) {
      b = temp;
    } else {
      b = a;
      a = temp;
    }
  }
  return b;
}

int max2d20 () {
  int a,b;
  a = d20();
  b = d20();
  if (a > b) return a; else return b;
}

int becmi() {
  // 3d6, giving modifier on BECMI scale
  int sum=0;
  sum = raw3d6();
  if (sum==3) return -3;
  else if (sum<6) return -2;
  else if (sum<9) return -1;
  else if (sum<13) return 0;
  else if (sum<16) return 1;
  else if (sum<18) return 2;
  else return 3;
}

int threed6() {
  // 3d6 giving modifier via hand-rolled
  int sum=0;
  sum = raw3d6();
  if (sum<5) return -4;
  else if (sum==5) return -3;
  else if (sum<8) return -2;
  else if (sum<10) return -1;
  else if (sum<12) return 0;
  else if (sum<14) return 1;
  else if (sum<16) return 2;
  else if (sum==16) return 3;
  else return 4;
}
int threednd() {
  // 3d6 giving modifier vs. D&D 3.x
  int sum=0;
  sum = raw3d6();
  if (sum==3) return -4;
  else if (sum<6) return -3;
  else if (sum<8) return -2;
  else if (sum<10) return -1;
  else if (sum<12) return 0;
  else if (sum<14) return 1;
  else if (sum<16) return 2;
  else if (sum<18) return 3;
  else return 4;
}
int raw3d6() {
  int sum=0;
  sum = d6()+d6()+d6();
  return sum;
}

int dF1() {
  return d6()-d6();
}
int dF2() {
  // d6-d6 with more 0s
  int d1, d2;
  d1=d6();
  d2=d6();
  if (d1 == 6 || d2 == 6)
    return 0;
  else 
    return d1-d2;
}

int DS=1000000;
int dataF[11];
int dataF1[11];
int dataF2[11];
int dataFx[11];
int databecmi[11];
int datadnd3[11];
int datathree[11];
int datad20[20];
int dataraw3[20];

int main() {
  int i, j, sum;
  srand(time(NULL));
  for (j=0; j<DS; j++) {
    dataF[fourdF()+5]++;
    dataFx[fourdFx()+5]++;
    dataF1[dF1()+5]++;
    dataF2[dF2()+5]++;
    databecmi[becmi()+5]++;
    datadnd3[threednd()+5]++;
    datathree[threed6()+5]++;

    datad20[compd20()-1]++;
    dataraw3[raw3d6()-1]++;
  }
  printf("n roll\t4dF\t4dFlat\td6-d6\t6 zero\tBECMI\tDnD3\t3d6w\n\n");
  for (i=0; i<11; i++) {
    printf("%d %+d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i, i-5, dataF[i], dataFx[i],
        dataF1[i], dataF2[i], databecmi[i], datadnd3[i], datathree[i]);
  }
  printf("\nn roll\td20\t3d6\n\n");
  for (i=0; i<20; i++) {
    printf("%d %d\t%d\t%d\n",i,i+1,datad20[i],dataraw3[i]);
  }

}

