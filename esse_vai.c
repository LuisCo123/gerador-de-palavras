#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void dissilaba(char alfabeto[], char vogais[]);
void trissilaba(char alfabeto[], char vogais[]);
int main(){
	char alfabeto[17];
    char vogais[5] = {'a','e','i','o','u'};
    int num, k = 0, qtd, i=0, j=0;
    srand(time(NULL));

    for (int i = 0; i < 26; i++){
        if( ('a'+i == 'a' ) || ('a'+i == 'e') || ('a'+i == 'i') || ('a'+i == 'o')
        	|| ('a'+i == 'u') || ('a'+i == 'k' ) || ('a'+i == 'y') || ('a'+i == 'w') || ('a'+i == 'q'))
        	continue;
        alfabeto[k] = 'a'+ i;
        k++;
    }
   scanf("%d", &k);
   while(j<k){
   	 qtd = rand() % 2;
	   switch(qtd){
	   				case 0 : 
	   						dissilaba(alfabeto, vogais);
	   						j++;
	   					break;

	   				case 1 : 
	   						trissilaba(alfabeto, vogais);
	   						j++;
	   					break;
	   }
	}
}

void dissilaba(char alfabeto[], char vogais[]){
	char palavra[6];
	int i, qtd = 0;
	for(i=0; i < 6; i++)
		palavra[i]='\0';

	//lh, nh, qu, gu, ss
	qtd = rand() % 2;
	switch(qtd){
				 case 0:
				 		palavra[0]=alfabeto[rand() % 17];
				 		palavra[1]=vogais[rand() % 5];
				 		palavra[2]=alfabeto[rand() % 17];
				 		palavra[3]=vogais[rand() % 5];
				 		printf("%s\n", palavra);
				 	break;
				 case 1:
				 		qtd = rand() % 5;
				 		switch(qtd){
				 					case 0:
				 							palavra[0]=alfabeto[rand() % 17];
				 							palavra[1]=vogais[rand() % 5];
				 							palavra[2]= 'l';
				 							palavra[3]= 'h';
				 							palavra[4]=vogais[rand() % 5];
				 							printf("%s\n", palavra);
				 						break;
				 					case 1:
				 							palavra[0]=alfabeto[rand() % 17];
				 							palavra[1]=vogais[rand() % 5];
				 							palavra[2]= 'n';
				 							palavra[3]= 'h';
				 							palavra[4]=vogais[rand() % 5];
				 							printf("%s\n", palavra);
				 						break;
				 					case 2:
				 							palavra[0]=alfabeto[rand() % 17];
				 							palavra[1]=vogais[rand() % 5];
				 							palavra[2]= 'q';
				 							palavra[3]= 'u';
				 							palavra[4]=vogais[rand() % 4];
				 							printf("%s\n", palavra);
				 						break;
				 					case 3:
				 							palavra[0]=alfabeto[rand() % 17];
				 							palavra[1]=vogais[rand() % 4];
				 							palavra[2]= 'g';
				 							palavra[3]= 'u';
				 							palavra[4]=vogais[rand() % 5];
				 							printf("%s\n", palavra);
				 						break;
				 					case 4:
				 							palavra[0]=alfabeto[rand() % 17];
				 							palavra[1]=vogais[rand() % 5];
				 							palavra[2]= 's';
				 							palavra[3]= 's';
				 							palavra[4]=vogais[rand() % 5];
				 							printf("%s\n", palavra);
				 						break;

				 		}
	}
}
void trissilaba(char alfabeto[], char vogais[]){
	char palavra[8];
	int i, qtd = 0;
	for(i=0; i < 8; i++)
		palavra[i]='\0';

	qtd = rand() % 2;
	switch(qtd){
				 case 0:
				 		palavra[0]=alfabeto[rand() % 17];
				 		palavra[1]=vogais[rand() % 5];
				 		palavra[2]=alfabeto[rand() % 17];
				 		palavra[3]=vogais[rand() % 5];
				 		palavra[4]=alfabeto[rand() % 17];
				 		palavra[5]=vogais[rand() % 5];
				 		printf("%s\n", palavra);
				 	break;
				 case 1:
				 		qtd = rand() % 5;
				 		switch(qtd){
				 					case 0:
				 							palavra[0]=alfabeto[rand() % 17];
				 							palavra[1]=vogais[rand() % 5];
				 							palavra[2]= 'l';
				 							palavra[3]= 'h';
				 							palavra[4]=vogais[rand() % 5];
				 							palavra[5]=alfabeto[rand() % 17];
				 							palavra[6]=vogais[rand() % 5];
				 							printf("%s\n", palavra);
				 						break;
				 					case 1:
				 							palavra[0]=alfabeto[rand() % 17];
				 							palavra[1]=vogais[rand() % 5];
				 							palavra[2]= 'n';
				 							palavra[3]= 'h';
				 							palavra[4]=vogais[rand() % 5];
				 							palavra[5]=alfabeto[rand() % 17];
				 							palavra[6]=vogais[rand() % 5];
				 							printf("%s\n", palavra);
				 						break;
				 					case 2:
				 							palavra[0]=alfabeto[rand() % 17];
				 							palavra[1]=vogais[rand() % 5];
				 							palavra[2]= 'q';
				 							palavra[3]= 'u';
				 							palavra[4]=vogais[rand() % 5];
				 							palavra[5]=alfabeto[rand() % 17];
				 							palavra[6]=vogais[rand() % 5];
				 							printf("%s\n", palavra);
				 						break;
				 					case 3:
				 							palavra[0]=alfabeto[rand() % 17];
				 							palavra[1]=vogais[rand() % 4];
				 							palavra[2]= 'g';
				 							palavra[3]= 'u';
				 							palavra[4]=vogais[rand() % 5];
				 							palavra[5]=alfabeto[rand() % 17];
				 							palavra[6]=vogais[rand() % 5];
				 							printf("%s\n", palavra);
				 						break;
				 					case 4:
				 							palavra[0]=alfabeto[rand() % 17];
				 							palavra[1]=vogais[rand() % 5];
				 							palavra[2]= 's';
				 							palavra[3]= 's';
				 							palavra[4]=vogais[rand() % 5];
				 							palavra[5]=alfabeto[rand() % 17];
				 							palavra[6]=vogais[rand() % 5];
				 							printf("%s\n", palavra);
				 						break;

				 		}
	}
}