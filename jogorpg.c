#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "gamedata.c"

void combate();

int main(void){
	int opcao = 0;
	
	
	while(opcao!=3){
		printf("1- Comecar jogo.\n2- Historia.\n3- Fechar jogo.\n");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:{
				//adversario do combate sera aleatorio
				//atacar,defender e usar pot
				//atacar = ataque-def = dano na vida
				//defender dobra valor da defesa por 1 round
				//pot recupera hp soma da rolagem de 3 dados de 6 lados
				//na vez do adversario eh o mesmo esquema porem quem decide eh o pc
				
				break;
			}
			case 2:{
				printf("Historia\n");
				combate();
			}
		}
	}
	
	return 0;
}

void criar(){
	int pontos = 15;
	printf("Insira o nome do personagem:\n");
	scanf("%s",(*ptrP1->nome));//set do nome do personagem
	printf("Agora vc deve distribuir 15 pontos entre os atributos:\n");
	printf("Forca,Constituicao,Agilidade e Destreza.\n");
	printf("Forca:\n");
	scanf("%d",ptrP1->str);
}

void combate(){
	
	
}
