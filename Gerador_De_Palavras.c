#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int dissilaba(char alfabeto[], char vogais[]);
int trissilaba(char alfabeto[], char vogais[]);
int polissilaba (char alfabeto[], char vogais[]);
int validarpalavra (char palavra[], int quantidade);


void limpapalavraaux (char palavraaux[]){
	int i;
	int aux = strlen(palavraaux);
	for (i = 0; i < aux; i++)
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
		else if (quantidade == 9)
			p = fopen("Dicionario\\Polissilaba8.txt", "r");
		else if (quantidade == 11)
			p = fopen("Dicionario\\Polissilaba10.txt", "r");
		else if (quantidade == 13)
			p = fopen("Dicionario\\Polissilaba12.txt", "r");
		if(!p){
			printf("falha ao abrir o arquivo");
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

int main(){
	char alfabeto[26];
    char vogais[5] = {'a','e','i','o','u'};
    int num, k = 0, qtd, i=0, j=0,ret=0;
    srand(time(NULL));

    for (i = 0; i < 26; i++){
        alfabeto[k] = 'a'+ i;
        k++;
    }
	printf ("Informe o numero de palavras:\n");
    scanf("%d", &k);
   	
   while(j<k){
   	 qtd = 0;//utilizar (rand()%3) caso queira gerar as 3 possibilidades de uma so vez;
	   switch(qtd){
	   				case 0 : 
	   						ret = dissilaba(alfabeto, vogais);
	   						j+=ret;
	   					break;

	   				case 1 : 
	   						ret = trissilaba(alfabeto, vogais);
	   						j+= ret;
	   					break;
	   				case 2:
	   						ret = polissilaba(alfabeto, vogais);
	   						j+=ret;
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
int polissilaba (char alfabeto[], char vogais[]){

 	char palavra[13];
	int i, qtd = 0;
	int ret=0;
	
	for(i=0; i < 13; i++)
		palavra[i]='\0';
				 	
	qtd = rand() % 11;
	switch(qtd){
				case 0:
						palavra[0]=vogais[rand() % 5];
						palavra[1]=alfabeto[rand() % 26];
						palavra[2]=vogais[rand() % 5];
						palavra[3]=alfabeto[rand() % 26];
						palavra[4]=alfabeto[rand() % 26];
						palavra[5]=vogais[rand() % 5];
						palavra[6]=alfabeto[rand() % 26];
						palavra[7]=vogais[rand() % 5];
						ret = validarpalavra(palavra, 9);
				 		if(ret==1){
				 			printf("%s\n", palavra);
				 			return ret;
				 		}
						else return 0;
					break;
				case 1:
						palavra[0]=vogais[rand() % 6];
						palavra[1]=alfabeto[rand() % 26];
						palavra[2]=vogais[rand() % 6];
						palavra[3]=alfabeto[rand() % 26];
						palavra[4]=vogais[rand() % 5];
						palavra[5]=alfabeto[rand() % 26];
						palavra[6]=alfabeto[rand() % 26];
						palavra[7]=vogais[rand() % 5];
						ret = validarpalavra(palavra, 9);
				 		if(ret==1){
				 			printf("%s\n", palavra);
				 			return ret;
				 		}
						else return 0;
					break;
					
				case 2:
						palavra[0]=vogais[rand() % 5];
						palavra[1]=alfabeto[rand() % 26];
						palavra[2]=alfabeto[rand() % 26];
						palavra[3]=vogais[rand() % 5];
						palavra[4]=vogais[rand() % 5];
						palavra[5]=alfabeto[rand() % 26];
						palavra[6]=vogais[rand() % 5];
						palavra[7]=alfabeto[rand() % 26];
						ret = validarpalavra(palavra, 9);
				 		if(ret==1){
				 			printf("%s\n", palavra);
				 			return ret;
				 		}
						else return 0;
					break;
					
				case 3:
						palavra[0]=vogais[rand() % 4];
						palavra[1]=alfabeto[rand() % 26];
						palavra[2]=vogais[rand() % 4];
						palavra[3]=alfabeto[rand() % 26];
						palavra[4]=vogais[rand() % 4];
						palavra[5]=alfabeto[rand() % 26];
						palavra[6]=vogais[rand() % 4];
						palavra[7]=alfabeto[rand() % 26];
				 		ret = validarpalavra(palavra, 9);
				 		if(ret==1){
				 			printf("%s\n", palavra);
				 			return ret;
				 		}
						else return 0;
					break;
					
				case 4:
						palavra[0]=vogais[rand() % 5];
						palavra[1]=alfabeto[rand() % 26];
						palavra[2]=vogais[rand() % 5];
						palavra[3]=vogais[rand() % 5];
						palavra[4]=alfabeto[rand() % 26];
						palavra[5]=alfabeto[rand() % 26];
						palavra[6]=vogais[rand() % 5];
						palavra[7]=vogais[rand() % 5];
						palavra[8]=alfabeto[rand() % 26];
						palavra[9]=vogais[rand() % 5];
						ret = validarpalavra(palavra, 11);
						if(ret==1){
			 			printf("%s\n", palavra);
			 			return ret;
			 			}
			 			else return 0;
					break;
					
				case 5://açoitasses
				 		palavra[0]=vogais[rand() % 5];
				 		palavra[1]=alfabeto[rand() % 26];
				 		palavra[2]=vogais[rand() % 5];
				 		palavra[3]=vogais[rand() % 5];
				 		palavra[4]=alfabeto[rand() % 26];
				 		palavra[5]=vogais[rand() % 5];
				 		palavra[6]=alfabeto[rand() % 26];
				 		palavra[7]=alfabeto[rand() % 26];
				 		palavra[8]=vogais[rand() % 5];
				 		palavra[9]=alfabeto[rand() % 26];
				 		ret = validarpalavra(palavra, 11);
				 		if(ret==1){
				 			printf("%s\n", palavra);
				 			return ret;
				 		}
				 		else return 0;
				 	break;
				 	
				 case 6:
						palavra[0]=vogais[rand() % 5];
				 		palavra[1]=alfabeto[rand() % 26];
				 		palavra[2]=alfabeto[rand() % 26];
						palavra[3]=vogais[rand() % 5];
				 		palavra[4]=alfabeto[rand() % 26];
						palavra[5]=vogais[rand() % 5];
						palavra[6]=vogais[rand() % 5];
				 		palavra[7]=alfabeto[rand() % 26];
				 		palavra[8]=alfabeto[rand() % 26];
						palavra[9]=vogais[rand() % 5];
						ret = validarpalavra(palavra, 11);
						if(ret==1){
			 			printf("%s\n", palavra);
			 			return ret;
			 			}
			 			else return 0;
			 		break;
			 	case 7:
						palavra[0]=vogais[rand() % 5];
				 		palavra[1]=alfabeto[rand() % 26];
						palavra[2]=vogais[rand() % 5];
				 		palavra[3]=alfabeto[rand() % 26];
				 		palavra[4]=alfabeto[rand() % 26];
						palavra[5]=vogais[rand() % 5];
				 		palavra[6]=alfabeto[rand() % 26];
						palavra[7]=vogais[rand() % 5];
				 		palavra[8]=alfabeto[rand() % 26];
						palavra[9]=vogais[rand() % 5];
						ret = validarpalavra(palavra, 11);
						if(ret==1){
			 			printf("%s\n", palavra);
			 			return ret;
			 			}
			 			else return 0;
			 		break;
			 		
			 	case 8:
						palavra[0]=vogais[rand() % 5];
				 		palavra[1]=alfabeto[rand() % 26];
						palavra[2]=vogais[rand() % 5];
				 		palavra[3]=alfabeto[rand() % 26];
						palavra[4]=vogais[rand() % 5];
				 		palavra[5]=alfabeto[rand() % 26];
						palavra[6]=vogais[rand() % 5];
				 		palavra[7]=alfabeto[rand() % 26];
						palavra[8]=vogais[rand() % 5];
						palavra[9]=alfabeto[rand() % 26];
						ret = validarpalavra(palavra, 11);
						if(ret==1){
			 			printf("%s\n", palavra);
			 			return ret;
			 			}
			 			else return 0;
			 		break;
			 	case 9:
						palavra[0]=vogais[rand() % 5];
				 		palavra[1]=alfabeto[rand() % 26];
				 		palavra[2]=alfabeto[rand() % 26];
						palavra[3]=vogais[rand() % 5];
						palavra[4]=vogais[rand() % 5];
						palavra[5]=vogais[rand() % 5];
				 		palavra[6]=alfabeto[rand() % 26];
						palavra[7]=vogais[rand() % 5];
				 		palavra[8]=alfabeto[rand() % 26];
						palavra[9]=vogais[rand() % 5];
						palavra[10]=vogais[rand() % 5];
						palavra[11]=alfabeto[rand() % 26];
						ret = validarpalavra(palavra, 13);
						if(ret==1){
			 			printf("%s\n", palavra);
			 			return ret;
			 			}
			 			else return 0;
			 		break;
			 	case 10:
						palavra[0]=vogais[rand() % 5];
				 		palavra[1]=alfabeto[rand() % 26];
				 		palavra[2]=alfabeto[rand() % 26];
						palavra[3]=vogais[rand() % 5];
						palavra[4]=vogais[rand() % 5];
				 		palavra[5]=alfabeto[rand() % 26];
						palavra[6]=vogais[rand() % 5];
				 		palavra[7]=alfabeto[rand() % 26];
						palavra[8]=vogais[rand() % 5];
				 		palavra[9]=alfabeto[rand() % 26];
						palavra[10]=vogais[rand() % 5];
						palavra[11]=vogais[rand() % 5];
						ret = validarpalavra(palavra, 13);
						if(ret==1){
			 			printf("%s\n", palavra);
			 			return ret;
			 			}
			 			else return 0;
			 		break;
			 	
	}
}
