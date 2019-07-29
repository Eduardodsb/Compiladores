#include<stdio.h>
#include <iostream>
using namespace std;

int main(){
int  a, b, i, j, t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
cin >> a;
cin >> b;
i = 3;
Local3:
t10 = i > a;
if( t10) goto Local4;
t0 = i*2;
t1 = b*b;
j = t0;
Local1:
t8 = j > t1;
if( t8) goto Local2;
t2 = i*i;
t3 = t2+1;
t4 = t3%j;
t5 = t4*j;
t6 = t5==0;
t7 = !t6;
if(t7) goto Local0;
cout << "[";
cout << i;
cout << ",";
cout << j;
cout << "] ";

Local0:
j = j + 1;
goto Local1;
Local2:
cout << "(";
t9 = i*i;
cout << t9;
cout << ")";
cout << endl;
i = i + 1;
goto Local3;
Local4:

return 0;
}
