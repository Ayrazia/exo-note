#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
int number1;
int number2;
char operateur;
int recommencer;
recommence:
printf("Bonjour, voici un mini calculatrice\n");
printf("Choissisez un opérateur(+, *, -, /,%)\n");
scanf("%s", &operateur);

printf("Choisissez le premier nombre\n");
scanf("%d", &number1);
printf("Choisissez le deuxième nombre\n");
scanf("%d", &number2);

switch(operateur)
{
case '/' :
if (number2 == 0)
{

printf("La division par zero est impossible!\n");
}
else
{

printf("%d / %d = %d\n",number1, number2, number1 / number2);
}
break;

case'+':
printf("%d + %d = %d\n",number1, number2, number1 + number2);
break;

case '-':
printf("%d - %d = %d\n", number1, number2, number1 - number2);
break;

case '*':
printf("%d * %d = %d\n", number1, number2, number1 * number2);
break;

case '%':
if (number2 == 0 || number1 == 0)
{
printf("Le modulo de 0 n'existe pas\n");
}
else
{
printf("Le modulo de %d et de %d est %d\n", number1, number2, number1 % number2 );
}
break;

default:
printf("Operateur incorrect\n");
break;

}
printf("Souhaitez-vous recommencer? 1.Oui 2.Non\n");
scanf("%d", &recommencer);
if(recommencer == 1) 

{
goto recommence;
}
else
{
return 0;
 }
}
