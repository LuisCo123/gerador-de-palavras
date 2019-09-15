#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int dissilaba(char alfabeto[], char vogais[]);
int trissilaba(char alfabeto[], char vogais[]);
void polissilaba (char alfabeto[], char vogais[]);
int validarpalavra (char palavra[], int quantidade);


void limpapalavraaux (char palavraaux[]){
	int i;
	int aux = strlen(palavraaux);
	for (i = 0; i < 6; i++)
		palavraaux[i] = '\0';
		
}
int validarpalavra (char palavra[], int quantidade){
		FILE *p;

		if(quantidade == 5)
			p = fopen("Dicionario\\Dissilaba4.txt","r");
		
		else if(quantidade == 6)
			p = fopen("Dicionario\\Dissilaba5.txt","r");
		else if(quantidade == 7)
			p = fopen("Dicionario\\Trissilaba6.txt","r");
		else if(quantidade == 8)
			p = fopen("Dicionario\\Trissilaba7.txt","r");

		if(!p){
			printf("arquivo nao abriu");
			return 0;
		}
		
		char palavraaux[quantidade];
		limpapalavraaux(palavraaux);
		int i=0, ret=2; 
		while(fgets(palavraaux, quantidade, p) != NULL){
			ret = strcmp (palavra, palavraaux);
			if(ret==0){
				return 1;
			}
		}
		fclose(p);
		return 0;
}
/*void validarpalavra (char palavra[], char letra){
	FILE *p;
	char palavraaux[20];
	int i = 0;
	int retorno;
	switch (letra){
		case 'a':
			p = fopen ("iniA.txt", "r");
			char aux;
			while ((aux = fgetc(p)) != EOF){
				if (aux == ';'){
					retorno = strcmp (palavra, palavraaux);
					if (retorno == 0)
						puts (palavra);
					limpapalavraaux (palavraaux);
					i = 0;
				}
				palavraaux[i] = aux;
				i++;
			}
	}
}*/
int main(){
	char alfabeto[26];
    char vogais[5] = {'a','e','i','o','u'};
    int num, k = 0, qtd, i=0, j=0,ret=0;
    //char palavra[4] = "aba";
    //validarpalavra (palavra, palavra[0]);
    srand(time(NULL));

    for (i = 0; i < 26; i++){
        alfabeto[k] = 'a'+ i;
        k++;
    }
	printf ("Informe o numero de palavras:\n");
    scanf("%d", &k);
   	
   while(j<k){
   	 qtd = rand()%2;
	   switch(qtd){
	   				case 0 : 
	   						ret = dissilaba(alfabeto, vogais);
	   						j+=ret;
	   						//printf ("\n");
	   					break;

	   				case 1 : 
	   						ret = trissilaba(alfabeto, vogais);
	   						//printf ("\n");
	   						j+= ret;
	   					break;
	   				case 2:
	   						polissilaba(alfabeto, vogais);
	   						//printf ("\n");
	   						j++;
	   					break;
	   }
	}
}

int dissilaba(char alfabeto[], char vogais[]){
	char palavra[6];
	int i, qtd = 0;
	int ret=0;
	for(i=0; i < 6; i++)
		palavra[i]='\0';

	//lh, nh, qu, gu, ss
	qtd = rand() % 2;
	switch(qtd){
				 case 0:
				 		palavra[0]=alfabeto[rand() % 26];
				 		palavra[1]=vogais[rand() % 5];
				 		palavra[2]=alfabeto[rand() % 26];
				 		palavra[3]=vogais[rand() % 5];
				 		ret = validarpalavra(palavra, 5);
				 		if(ret==1){
				 			printf("%s\n", palavra);
				 			return ret;
				 		}
				 		else return 0;
				 	break;
				 case 1:
				 		qtd = rand() % 7;
				 		switch(qtd){
				 					case 0:
				 							palavra[0]=alfabeto[rand() % 26];
				 							palavra[1]=vogais[rand() % 5];
				 							palavra[2]= 'l';
				 							palavra[3]= 'h';
				 							palavra[4]=vogais[rand() % 5];
				 							ret = validarpalavra(palavra, 6);
									 		if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 		}
				 							else return 0;
				 						break;
				 					case 1:
				 							palavra[0]=alfabeto[rand() % 26];
				 							palavra[1]=vogais[rand() % 6];
				 							palavra[2]= 'n';
				 							palavra[3]= 'h';
				 							palavra[4]=vogais[rand() % 5];
				 							ret = validarpalavra(palavra, 6);
									 		if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 		}
				 							else return 0;
				 						break;
				 					case 2:
				 							palavra[0]=alfabeto[rand() % 26];
				 							palavra[1]=vogais[rand() % 5];
				 							palavra[2]= 'q';
				 							palavra[3]= 'u';
				 							palavra[4]=vogais[rand() % 4];
				 							ret = validarpalavra(palavra, 6);
									 		if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 		}
				 							else return 0;
				 						break;
				 					case 3:
				 							palavra[0]=alfabeto[rand() % 26];
				 							palavra[1]=vogais[rand() % 4];
				 							palavra[2]= 'g';
				 							palavra[3]= 'u';
				 							palavra[4]=vogais[rand() % 5];
									 		ret = validarpalavra(palavra, 6);
									 		if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 		}
				 							else return 0;
				 						break;
				 					case 4:
				 							palavra[0]=alfabeto[rand() % 26];
				 							palavra[1]=vogais[rand() % 5];
				 							palavra[2]= 's';
				 							palavra[3]= 's';
				 							palavra[4]=vogais[rand() % 5];
				 							ret = validarpalavra(palavra, 6);
				 							if(ret==1){
								 			printf("%s\n", palavra);
								 			return ret;
								 			}
								 			else return 0;
				 						break;
				 					case 5:
				 							palavra[0]=alfabeto[rand() % 26];
									 		palavra[1]=vogais[rand() % 5];
									 		palavra[2]=alfabeto[rand() % 26];
									 		palavra[3]=vogais[rand() % 5];
									 		palavra[2]=alfabeto[rand() % 26];
									 		ret = validarpalavra(palavra, 6);
									 		if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 		}
									 		else return 0;
									 	break;
									 case 6:
				 							palavra[0]=alfabeto[rand() % 26];
				 							palavra[1]=vogais[rand() % 5];
				 							palavra[2]= 'r';
				 							palavra[3]= 'r';
				 							palavra[4]=vogais[rand() % 5];
				 							ret = validarpalavra(palavra, 6);
				 							if(ret==1){
								 			printf("%s\n", palavra);
								 			return ret;
								 			}
								 			else return 0;
								 		break;

						}
	}
}
int trissilaba(char alfabeto[], char vogais[]){
	char palavra[8];
	int i, qtd = 0, ret=0;
	for(i=0; i < 8; i++)
		palavra[i]='\0';

	qtd = rand() % 2;
	switch(qtd){
				 case 0:
				 		palavra[0]=alfabeto[rand() % 26];
				 		palavra[1]=vogais[rand() % 5];
				 		palavra[2]=alfabeto[rand() % 26];
				 		palavra[3]=vogais[rand() % 5];
				 		palavra[4]=alfabeto[rand() % 26];
				 		palavra[5]=vogais[rand() % 5];
				 		ret = validarpalavra(palavra, 7);
							if(ret==1){
								printf("%s\n", palavra);
								return ret;
							}
				 			else return 0;
				 	break;
				 case 1:
				 	qtd = rand() % 2;
				 	switch(qtd){
				 		case 1:
					 		qtd = rand() % 5;
					 		switch(qtd){
					 					case 0:
					 							palavra[0]=alfabeto[rand() % 26];
					 							palavra[1]=vogais[rand() % 5];
					 							palavra[2]= 'l';
					 							palavra[3]= 'h';
					 							palavra[4]=vogais[rand() % 5];
					 							palavra[5]=alfabeto[rand() % 26];
					 							palavra[6]=vogais[rand() % 5];
					 							ret = validarpalavra(palavra, 8);
					 							if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 			}
									 			else return 0;

					 						break;
					 					case 1:
					 							palavra[0]=alfabeto[rand() % 26];
					 							palavra[1]=vogais[rand() % 5];
					 							palavra[2]= 'n';
					 							palavra[3]= 'h';
					 							palavra[4]=vogais[rand() % 5];
					 							palavra[5]=alfabeto[rand() % 26];
					 							palavra[6]=vogais[rand() % 5];
					 							ret = validarpalavra(palavra, 8);
					 							if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 			}
									 			else return 0;
					 						break;
					 					case 2:
					 							palavra[0]=alfabeto[rand() % 26];
					 							palavra[1]=vogais[rand() % 5];
					 							palavra[2]= 'q';
					 							palavra[3]= 'u';
					 							palavra[4]=vogais[rand() % 5];
					 							palavra[5]=alfabeto[rand() % 26];
					 							palavra[6]=vogais[rand() % 5];
					 							ret = validarpalavra(palavra, 8);
					 							if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 			}
									 			else return 0;
					 						break;
					 					case 3:
					 							palavra[0]=alfabeto[rand() % 26];
					 							palavra[1]=vogais[rand() % 4];
					 							palavra[2]= 'g';
					 							palavra[3]= 'u';
					 							palavra[4]=vogais[rand() % 5];
					 							palavra[5]=alfabeto[rand() % 26];
					 							palavra[6]=vogais[rand() % 5];
					 							ret = validarpalavra(palavra, 8);
					 							if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 			}
									 			else return 0;
					 						break;
					 					case 4:
					 							palavra[0]=alfabeto[rand() % 26];
					 							palavra[1]=vogais[rand() % 5];
					 							palavra[2]= 's';
					 							palavra[3]= 's';
					 							palavra[4]=vogais[rand() % 5];
					 							palavra[5]=alfabeto[rand() % 26];
					 							palavra[6]=vogais[rand() % 5];
					 							ret = validarpalavra(palavra, 8);
					 							if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 			}
									 			else return 0;
					 						break;
					 					case 5:
					 							palavra[0]=alfabeto[rand() % 26];
					 							palavra[1]=vogais[rand() % 5];
					 							palavra[2]= 'r';
					 							palavra[3]= 'r';
					 							palavra[4]=vogais[rand() % 5];
					 							palavra[5]=alfabeto[rand() % 26];
					 							palavra[6]=vogais[rand() % 5];
					 							ret = validarpalavra(palavra, 8);
					 							if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 			}
									 			else return 0;
					 						break;
					 					case 6:
									 		palavra[0]=alfabeto[rand() % 26];
									 		palavra[1]=vogais[rand() % 5];
									 		palavra[2]=alfabeto[rand() % 26];
									 		palavra[3]=vogais[rand() % 5];
									 		palavra[4]=alfabeto[rand() % 26];
									 		palavra[5]=vogais[rand() % 5];
									 		palavra[6]=alfabeto[rand() % 26];
									 		ret = validarpalavra(palavra, 8);
												if(ret==1){
													printf("%s\n", palavra);
													return ret;
												}
									 			else return 0;
									 	break;

							}
						case 2:
							qtd = rand() % 5;
					 		switch(qtd){
					 					case 0:
					 							palavra[0]=alfabeto[rand() % 26];
					 							palavra[1]=vogais[rand() % 5];
					 							palavra[2]=vogais[rand() % 5];
					 							palavra[3]=alfabeto[rand() % 26];
					 							palavra[4]= 'l';
					 							palavra[5]= 'h';
					 							palavra[6]=vogais[rand() % 5];
					 							ret = validarpalavra(palavra, 8);
					 							if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 			}
									 			else return 0;

					 						break;
					 					case 1:
					 							palavra[0]=alfabeto[rand() % 26];
					 							palavra[1]=vogais[rand() % 5];
					 							palavra[2]=vogais[rand() % 5];
					 							palavra[3]=alfabeto[rand() % 26];
					 							palavra[4]= 'n';
					 							palavra[5]= 'h';
					 							palavra[6]=vogais[rand() % 5];
					 							ret = validarpalavra(palavra, 8);
					 							if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 			}
									 			else return 0;
					 						break;
					 					case 2:
					 							palavra[0]=alfabeto[rand() % 26];
					 							palavra[1]=vogais[rand() % 5];
					 							palavra[2]=vogais[rand() % 5];
					 							palavra[3]=alfabeto[rand() % 26];
					 							palavra[4]= 'q';
					 							palavra[5]= 'u';
					 							palavra[6]=vogais[rand() % 5];
					 							ret = validarpalavra(palavra, 8);
					 							if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 			}
									 			else return 0;
					 						break;
					 					case 3:
					 							palavra[0]=alfabeto[rand() % 26];
					 							palavra[1]=vogais[rand() % 4];
					 							palavra[2]=vogais[rand() % 5];
					 							palavra[3]=alfabeto[rand() % 26];
					 							palavra[4]= 'g';
					 							palavra[5]= 'u';
					 							palavra[6]=vogais[rand() % 5];
					 							ret = validarpalavra(palavra, 8);
					 							if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 			}
									 			else return 0;
					 						break;
					 					case 4:
					 							palavra[0]=alfabeto[rand() % 26];
					 							palavra[1]=vogais[rand() % 5];
					 							palavra[2]=vogais[rand() % 5];
					 							palavra[3]=alfabeto[rand() % 26];
					 							palavra[4]= 's';
					 							palavra[5]= 's';
					 							palavra[6]=vogais[rand() % 5];
					 							ret = validarpalavra(palavra, 8);
					 							if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 			}
									 			else return 0;
					 						break;
					 					case 5:
					 							palavra[0]=alfabeto[rand() % 26];
					 							palavra[1]=vogais[rand() % 5];
					 							palavra[2]=vogais[rand() % 5];
					 							palavra[3]=alfabeto[rand() % 26];
					 							palavra[4]= 'r';
					 							palavra[5]= 'r';
					 							palavra[6]=vogais[rand() % 5];
					 							ret = validarpalavra(palavra, 8);
					 							if(ret==1){
									 			printf("%s\n", palavra);
									 			return ret;
									 			}
									 			else return 0;
					 						break;
					 					case 6:
									 		palavra[0]=alfabeto[rand() % 26];
									 		palavra[1]=vogais[rand() % 5];
									 		palavra[2]=alfabeto[rand() % 26];
									 		palavra[3]=vogais[rand() % 5];
									 		palavra[4]=alfabeto[rand() % 26];
									 		palavra[5]=vogais[rand() % 5];
									 		palavra[6]=alfabeto[rand() % 26];
									 		ret = validarpalavra(palavra, 8);
												if(ret==1){
													printf("%s\n", palavra);
													return ret;
												}
									 			else return 0;
									 	break;
							}
						break;
					}
				}
}
void polissilaba (char alfabeto[], char vogais[]){

 	int qtd = 0;
		
	qtd = rand() % 3;
	switch(qtd){
		case 0:	
			//printf ("\t\tentrou\n");
			dissilaba(alfabeto, vogais);
			dissilaba(alfabeto, vogais);
		break;
		
		case 1:
			//printf ("\tentrou\n");
			trissilaba(alfabeto, vogais);
			dissilaba(alfabeto, vogais);
		break;
		
		case 2:
			//printf ("entrou\n");
			dissilaba(alfabeto, vogais);
			trissilaba(alfabeto, vogais);
	}
}
