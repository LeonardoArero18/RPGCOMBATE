#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int pontos_disponiveis=15;
int res=0;



typedef struct personagem
{
	
//status básico
char nome[50];
int pontos_vida;

//atributos 
int forca;
int constituicao;
int agilidade;
int destreza;

//equipamentos
int arma;
int armadura;

} PERSONAGEM;


typedef struct arma
{
 char nome_arma[20];
 int id_arma;
 int dano;
 
} ARMA;

typedef struct armadura
{
	char nome_armadura[20];
	int id_armadura;
	int defesa;
	
} ARMADURA;	

//declarações das variaveis struct
PERSONAGEM personagem[6];
ARMADURA armadura[2];
ARMA arma[2];


void criar_personagem(){
	int a;
	char res;
	int k;
	
    system("cls || clear");
	printf("Criacao de personagem\n\n");
	
	//nome
	printf("Digite o nome do seu personagem:");
	scanf("%s",&personagem[0].nome);
	printf("\n");
	printf("o seu nome eh:%s\n\n",personagem[0].nome);
	
    //atributos 
    
    while(k!=1){
    printf("Voce tem %d pontos para distribuir em 4 categorias de atributos\n\n",pontos_disponiveis);
	printf("As categorias sao:\n");
	printf("A-Forca\nB-Constituicao\nC-Agilidade\nD-Destreza\nE-Continuar\n\n");
	printf("Digite letra da categoria desejada:");
	scanf("%s",&res);

	switch(res)
	{
		case 'a':
		case 'A':
        //força
         if(pontos_disponiveis>0){
          printf("Digite os pontos que deseja colocar em Forca,voce tem %d pontos disponiveis:",pontos_disponiveis);
      	  scanf("%d",&a);
         if(a<=pontos_disponiveis){
          personagem[0].forca=a;
	      pontos_disponiveis=pontos_disponiveis-a;
	     }else{
          printf("voce nao possui pontos o suficiente!\n");
	     }
	     }
		 break;
			
		case 'b':
		case 'B':
        //constituicao
        if(pontos_disponiveis>0){
         printf("Digite os pontos que deseja colocar em Constituicao,voce tem %d pontos disponiveis:",pontos_disponiveis);
	     scanf("%d",&a);
        if(a<=pontos_disponiveis){
	     personagem[0].constituicao=a;
	     pontos_disponiveis=pontos_disponiveis-a;
	    }else{
         printf("voce nao possui pontos o suficiente!\n");
	    }
	    }
		break;
			
		case 'c':
		case 'C':
		
	    //agilidade
        if(pontos_disponiveis>0){
         printf("Digite os pontos que deseja colocar em Agilidade,voce tem %d pontos disponiveis:",pontos_disponiveis);
       	 scanf("%d",&a);
	    if(a<=pontos_disponiveis){
	     personagem[0].agilidade=a;
	     pontos_disponiveis=pontos_disponiveis-a;
	    }else{
         printf("voce nao possui pontos o suficiente!\n");
	    }
     	}
		break;
			
		case 'd':
		case 'D':
			
     	//destreza
        if(pontos_disponiveis>0){
	     printf("Digite os pontos que deseja colocar em Destreza,voce tem %d pontos disponiveis:",pontos_disponiveis);
	     scanf("%d",&a);
     	if(a<=pontos_disponiveis){
	     personagem[0].destreza=a;
	     pontos_disponiveis=pontos_disponiveis-a;
        }else{
         printf("voce nao possui pontos o suficiente!\n");
	    }
      	}
	
			
			
		default:
		 printf("Valor invalido\n");
	
	
     	break;
     
        case 'e':
		case 'E':
         k=1;
	     break;
	}	
   
     if((pontos_disponiveis==0)){
	  k=1;
	  printf("Seus pontos para distribuit acabaram continue a criacao de personagem\n");	 
     }
	}
	
	system("pause");
	system("cls || clear");
    printf("Status atributos:\n");
    printf("Forca:%d\n",personagem[0].forca);
    printf("Constituicao:%d\n",personagem[0].constituicao);
    printf("Agilidade:%d\n",personagem[0].agilidade);
    printf("Destreza:%d\n",personagem[0].destreza);
    printf("\n");
	//escolher arma
	printf("Escolha seus equipamentos iniciais:\n\n");
	printf("Armas:\n\n");
	printf("0-Martelo(pesado)\n1-machado(pesado)\n2-Adaga(leve)\n\n");
	printf("digite o numero da sua escolha:");
	fflush(stdin);
	scanf("%d",&a);
	personagem[0].arma=a;
	printf("\n");
	printf("A arma que voce escolheu foi: %s\n\n",arma[a].nome_arma);

	//escolher armadura
	printf("Armaduras:\n\n");
	printf("0-Armadura acolchoada\n1-Corselete de couro\n2-Couro batido\n\n");
	printf("digite o numero da sua escolha:");
	fflush(stdin); 
    scanf("%d",&a);
    personagem[0].arma=a;
    printf("\n");
    printf("A armadura que voce escolheu foi: %s\n\n",armadura[a].nome_armadura);
	
}

void historia(){
	system("cls || clear");
	printf("Numa toca no chao vivia um hobbit. Nao uma toca desagradavel, suja e umida...\n\n");
}

void menu_principal(){
	char escolha;
    printf("Bem vindo ao JRPG\n\n");
	printf("A- Comecar jogo\nB- Contar historia da aventura\nC- Fechar jogo\n\n");
	printf("Digite a sua resposta:");
	fflush(stdin); 
	scanf("%c", &escolha);
	
	switch(escolha)
	{
		case 'a':
		case 'A':
			criar_personagem();
			break;
			
		case 'b':
		case 'B':
			break;
			
		case 'c':
		case 'C':
			historia();
			printf("Retornar para o menu principal?\n\n");
            printf("Digite  1 voltar ao menu principal:");
            scanf("%d",&res);
			break;

		default:
			printf("Valor invalido");
	}
	
}

int main(int argc, char** argv)
{
strcpy( armadura[0].nome_armadura, "Armadura acolchoada");
strcpy( armadura[1].nome_armadura, "Corselete de couro");
strcpy( armadura[2].nome_armadura, "Couro batido");
strcpy( arma[0].nome_arma, "Martelo");
strcpy( arma[1].nome_arma, "Machado");
strcpy( arma[2].nome_arma, "Adaga");
arma[0].id_arma=0;
arma[1].id_arma=1;
arma[2].id_arma=2;
armadura[0].id_armadura=0;
armadura[1].id_armadura=1;
armadura[2].id_armadura=2;
    menu_principal();
	return 0;
}

void set_adversarios(){
	
int i;
	for(i=1;i<7;i++){
		//status básico
		personagem[i].pontos_vida=100;
		//atributos
		personagem[i].forca=10;	
		personagem[i].constituicao=10;
		personagem[i].agilidade=10;
		personagem[i].destreza=10;
		//equipamentos
		personagem[i].arma=1;
		personagem[i].armadura=1;
	}
	strcpy( personagem[i].nome, "1");
	strcpy( personagem[i].nome, "2");
	strcpy( personagem[i].nome, "3");
	strcpy( personagem[i].nome, "4");
	strcpy( personagem[i].nome, "5");
	strcpy( personagem[i].nome, "6");

}



void combate(){
	
}

void premiacao(){
	
}

void vitoria(){
	
}