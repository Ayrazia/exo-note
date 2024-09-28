
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
int number1;
int number2;
char operateur;

printf("Bonjour, voici un mini calculatrice\n");
recommence:
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

{
printf("Le modulo de %d et de %d est %d\n", number1, number2, number1 % number2 );
}
break;

default:
printf("Operateur incorrect\n");
break;

}
char Oui;
char Non;
printf("Souhaitez-vous recommencer? Oui ou Non\n");
scanf("%s", &Oui);
if (Oui == 'O' || Oui == 'o' )

{
goto recommence;
} 
else if(Non == 'N' || Non == 'n')
{
return 0;
 }
}
