#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
srand(time(NULL));
int random_number = rand()% 100 + 1 ;
int resultat_user = 0;
int nbre_vie = 4;
printf("Essaie de trouver le numero mystère entre 0 et 100 en 10 vie\n");
printf("Entrez un nombre : ");
scanf("%d", &resultat_user);

for(nbre_vie=9; nbre_vie>0; nbre_vie--)
{
  if(resultat_user > 100)
  {printf("j'ai dit entre 0 et 100! \nIl vous reste %d vie!\n", nbre_vie);}

  else if(resultat_user < random_number)
  {printf("c'est plus! \nIl vous reste %d vie!\n", nbre_vie);}

  else if(resultat_user > random_number)
  {printf("c'est moins! \nIl vous reste %d vie!\n", nbre_vie);}

else if(resultat_user == random_number) 
    {printf("Bravo! Vous avez gagné!\n");
        break;}

    printf("Entrez un nombre : ");
    scanf("%d",&resultat_user);
  }
  if(nbre_vie == 0)  {printf("Perdu! \nLe nombre mystère était %d", random_number);}

  return 0;
}
