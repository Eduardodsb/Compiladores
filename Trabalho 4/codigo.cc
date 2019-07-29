#include<stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(){
char a[257], b[257];
int temp_B_0;
int temp_B_1;
int temp_I_0;
int temp_I_1;
int temp_I_2;
int temp_I_3;
int temp_I_4;
int temp_I_5;
int temp_I_6;
char temp_S_0[257];

temp_I_0 = strlen("uma frase");
strncpy(a,"",257);
strncpy(a,"uma frase",temp_I_0);
cin >> b;
temp_I_1= strcmp(b,a);
temp_B_0 = temp_I_1 >= 0;
temp_I_5 = !temp_B_0;
temp_I_2 = strlen("uma ");
temp_I_3 = strlen("frase");
strncpy(temp_S_0,"",257);
strncpy(temp_S_0,"uma ",temp_I_2);
strncat(temp_S_0,"frase",temp_I_3);
temp_I_4= strcmp(a,temp_S_0);
temp_B_1 = temp_I_4 == 0;
temp_I_6 = !temp_B_1;
if(temp_I_5) goto Local0;
cout << "b é maior";
cout << endl;

goto Local1;
Local0:
if(temp_I_6) goto Local1;
cout << "a é maior";
cout << endl;

Local1:

return 0;
}
