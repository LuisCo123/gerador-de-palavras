#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void monossilabica(char vogais[], char alfabeto[], int *i);
void dissilabicas(char vogais[], char alfabeto[], int *i);
void trissilabicas(char vogais[], char alfabeto[], int *i);
int main(){

    char alfabeto[23];
    char vogais[5] = {'a','e','i','o','u'};
    int num, k = 0, qtd, i=0;
    srand(time(NULL));




    for (int i = 0; i < 26; i++){
        if( ('a'+i == 'k' ) || ('a'+i == 'y') || ('a'+i == 'w'))
        	continue;
        alfabeto[k] = 'a'+ i;
        k++;
    }
   
    scanf ("%d", &num);
    
    while (i < num){
        
        qtd = 1;
        switch(qtd){
            case 1 : 
                    monossilabica(vogais, alfabeto, &i); 
                break;
            case 2 :
                    //dissilabicas(vogais, alfabeto, &i);
                break;
            case 3 :
                    //trissilabicas(vogais, alfabeto, &i);
                break;

        }
    }

    return 0;
}

void monossilabica(char vogais[], char alfabeto[], int *i){
    char palavra[3];
    int opcao, k = 0, j;

    for(j=0; j<3; j++)
        palavra[j] = '\0';
    do{
        palavra[0] = alfabeto[rand()%23];
        switch(palavra[0]){
        
        case 'a' :
                    palavra[1] = 'v'; 
                    palavra[2] = 'o';
                    *i+=1;
                    k++;
                break;

        case 'b' : 

                    opcao = rand() % 2;
                    if(opcao == 1){
                        palavra[1] = 'a';
                        palavra[2] = vogais[rand() % 5];
                    }else{
                        palavra[1] = 'o';
                        palavra[2] = vogais[rand()% 4];
                    }
                    *i+=1;
                    k++;
                break;
        case 'c' :
                    palavra[1] = 'h';
                    palavra[2] = 'a';
                    *i+=1;
                    k++;
                break;
        case 'd' :
                    palavra[1] = vogais[rand() % 5];
                    palavra[2] ='\0';
                    *i+=1;
                    k++;
                break;
        case 'l':
                    opcao = rand() % 3;
                    if(opcao == 1){
                        palavra[1] = 'h';
                        palavra[2] = vogais[rand() % 5];
                    }else if(opcao == 2){
                        palavra[1] = 'u';
                        palavra[2] = 'a';
                    }else{
                        palavra[1] = 'u';
                        palavra[2] = 'z';
                    }
                    *i+=1;
                    k++;
                break;
        case 'm':
                    opcao = rand() % 2; 
                    if(opcao == 1){
                        palavra[1] = vogais[rand() % 5];
                        palavra[2] = vogais[rand() % 5];
                    }else{
                        palavra[1] = vogais[rand() % 5];
                        palavra[2] = alfabeto[rand() % 23];
                    }
                    *i+=1;
                    k++;
                break;
        case 'n': 
                    palavra[1]='a';
                    palavra[2]='o';
                    *i+=1;
                    k++;
                break;
        case 'p':
                    palavra[1]= vogais[rand() % 4];
                    opcao = rand() % 3;
                    if(opcao == 1){
                        palavra[2]= vogais[rand() % 5];
                    }else if(opcao== 2){
                        palavra[2] ='\0';
                    }else{
                        palavra[2]= alfabeto[rand() % 23];
                    }
                    *i+=1;
                    k++;
                break;
        }

    }while(k != 1);
    k = strlen(palavra);
    printf("%d\n%s\n",k,palavra);
}
