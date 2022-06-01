#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Personagem
{
	char nome[20];
	int hp;
	int str;
	int cons;
	int agi;
	int dex;
} character;



typedef struct Armas
{
	char categoria[20];
	int dano;
} weapon;

void armaset(){
	weapon W1;
	weapon W2;
	weapon W3;

	strcpy(W1.categoria,"Leve");
	strcpy(W2.categoria,"Pesada");
	strcpy(W3.categoria,"Leve");

}

typedef struct Armadura
{
	int defesa;
} armor;

int dado(int lados){
	srand(time(NULL));
	int val = rand()%lados+1;
	return val;

}

void armor_set(){
	armor A1;
	armor A2;
	armor A3;
	
	A1.defesa = 7;
	A2.defesa = 10;
	A3.defesa = 13;
}

void combate(int vida,int evida, int agi, int eagi,int tipo,int dex,int forca,int edano,int cts,int edef){
	int vez;
	int opcao,dmg,deft;
	int defesa = 3+(1.5*cts);
	int aux;
	int auxdef = defesa;
	int dice;
	int pot = 3,epot = 3;
	if(agi>eagi){
		vez = 0;		
	}else{
		vez = 1;		
	}
		while(vida>0 && evida>0){
			deft = edef;
			if(vez==1){
				printf("Vida do inimigo:%d\n",evida);
				dice = dado(3);
				if(dice==1){
					 aux = edano - auxdef;
					 vida -= aux;
					 printf("Inimigo ataca em %d\n",aux);
				}else if(dice==2){
					 deft = edef*2;
					 printf("Defesa do inimido dobrada por 1 rodada!\n");
				}else{
					 if(epot>0){
						 evida += dado(6)+dado(6)+dado(6);
						 epot --;
					 }else{
						 printf("Inimigo sem pots!\n");
					 }
				}
				vez = 0;
			}
			printf("Vida: %d\n",vida);
			auxdef = defesa;
			printf("1-Atacar\n");
			printf("2-Defender\n");
			printf("3-Usar pot\n");
			scanf("%d",&opcao);
			switch(opcao){
				case 1:{
					printf("Ataca!!!\n");
					if(tipo==0){
						dmg=(15+dado(6)+dado(6)+dado(4)+dex);
					}else{
						dmg=(15+dado(12)+(1.5*forca));
					}
					aux = dmg - deft;
					printf("Voce tira %d da vida do inimigo!\n",aux);
					evida -= aux;
					vez = 1;
					break;
				}
				case 2:{
					auxdef *= 2;
					printf("Defesa dobrada!\n");
					vez = 1;
					break;
				}
				case 3:{
					if(pot>0){
						 vida += dado(6)+dado(6)+dado(6);
						 pot --;
						 printf("Inimigo usou potion!\n");
					 }else{
						 printf("Sem pots!\n");
					 }	
					 vez = 1;
					break;
				}
			}
		}
		if(evida>vida){
			printf("Voce foi derrotado '_'\n");
			exit(0);
		}else{
			printf("Voce ganhou o combate!!!\n");
		}
	}



	

typedef struct Adversarios
{
	char nome[20];
	int hp;
	int dmg;
	int def;
	int agi;
} enemy;

	enemy Zombie;
	enemy Creeper;
	enemy Skeleton;
	enemy Spider;
	enemy Scorpion;
	enemy Dragon;
	
void enemyset(){
	
	
	strcpy(Zombie.nome,"Zombie");
	Zombie.hp = 100;
	Zombie.dmg =10;
	Zombie.def = 5;
	Zombie.agi =10; 
	
	strcpy(Creeper.nome,"Creeper");
	Creeper.hp=100;
	Creeper.dmg=10;
	Creeper.def=10;
	Creeper.agi=10;
     
    strcpy(Skeleton.nome,"Skeleton");
    Skeleton.hp=100;
    Skeleton.dmg=10;
    Skeleton.def=10;
    Skeleton.agi=10;
    
    strcpy(Spider.nome,"Spider");
    Spider.hp=100;
    Spider.dmg=10;
    Spider.def=10;
    Spider.agi=10;
    
    strcpy(Scorpion.nome,"Scorpion");
    Scorpion.hp=100;
    Scorpion.dmg=10;
    Scorpion.def=10;
    Scorpion.agi=10;
    
    strcpy(Dragon.nome,"Dragon");
    Dragon.hp=400;
    Dragon.dmg=20;
    Dragon.def=10;
    Dragon.agi=20;
 
}





int main(void){
	enemyset();
	
	character P1;
	P1.hp = 100;
	int pontos = 15;
	char anome[20];
	int opcao = 0;
	int arma,armadura,dice;
	
	while(opcao!=3){
		printf("1- Comecar jogo.\n2- Historia.\n3- Fechar jogo.\n");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:{
				printf("Insira seu nome: \n");
				scanf("%s",anome);
				strcpy(P1.nome,anome);
				printf("Distribua 15 pontos entre os atributos: Forca, Constituicao, Agilidade e Destreza.\n");
				printf("Forca:\n");
				scanf("%d",&P1.str);
				pontos -= P1.str;
				if(pontos>0){
					printf("Pontos restantes:%d\n",pontos);
					printf("Constituicao:\n");
					scanf("%d",&P1.cons);
					pontos -= P1.cons;
				}
				
				if(pontos>0){
					printf("Pontos restantes:%d\n",pontos);
					printf("Agilidade:\n");
					scanf("%d",&P1.agi);
					pontos -= P1.agi;
				}
				
				if(pontos>0){
					printf("Pontos restantes:%d\n",pontos);
					printf("Destreza:\n");
					scanf("%d",&P1.dex);
					pontos -= P1.dex;
				}else{printf("Sem pontos restantes\n");}
				
				printf("Escolha sua arma:\n");
				printf("1- Soulbreaker, arma leve\n2- Soulcrusher,arma pesada\n3-Soulfall,arma leve\n");
				scanf("%d",&arma);
				if(arma ==1 || arma ==3){
					arma = 0;
				}else{
					arma = 1;
				}
				
				printf("Escolha sua armadura:\n");
				printf("1- Heavy Armor\n2- Ghost Chestplate\n3-Soulbound\n");
				scanf("%d",&armadura);
				if(armadura ==1 || armadura ==3){
					armadura = 0;
				}else{
					armadura = 1;
				}
				
				printf("Seu inimigo eh: ");
				dice = dado(3);
				if(dice==1){
					printf("%s\n",Creeper.nome);
					combate(P1.hp,Creeper.hp,P1.agi,Creeper.agi,arma,P1.dex,P1.str,Creeper.dmg,P1.cons,Creeper.def);
				}else if(dice==2){
					printf("%s\n",Skeleton.nome);
					combate(P1.hp,Skeleton.hp,P1.agi,Skeleton.agi,arma,P1.dex,P1.str,Skeleton.dmg,P1.cons,Skeleton.def);
				}else{
					printf("%s\n",Zombie.nome);
					combate(P1.hp,Zombie.hp,P1.agi,Skeleton.agi,arma,P1.dex,P1.str,Zombie.dmg,P1.cons,Zombie.def);
				};
				
		
				printf("Voce upou de nivel!!!\n");
				P1.hp += 50;
				printf("Escolha sua nova arma:\n");
				printf("1- Mingauzera, arma leve\n2- Pexera,arma pesada\n3-Trabuco,arma pesada\n");
				scanf("%d",&arma);
				if(arma ==1){
					arma = 0;
				}else{
					arma = 1;
				}
				
				printf("Seu inimigo eh: ");
				dice = dado(2);
				if(dice==1){
					printf("%s\n",Scorpion.nome);
					combate(P1.hp,Scorpion.hp,P1.agi,Scorpion.agi,arma,P1.dex,P1.str,Scorpion.dmg,P1.cons,Scorpion.def);
				}else{
					printf("%s\n",Spider.nome);
					combate(P1.hp,Spider.hp,P1.agi,Spider.agi,arma,P1.dex,P1.str,Spider.dmg,P1.cons,Spider.def);
				}
				
			
				printf("Voce upou 2 niveis!!!\n");
				P1.hp += 50;
				printf("Escolha nova armadura:\n");
				printf("1- Armadillo's hooves\n2- Alligator Skin\n3- Turtle Shell\n");
				scanf("%d",&armadura);
				
				
				printf("Seu inimigo eh: ");
				printf("%s\n",Dragon.nome);
				combate(P1.hp,Dragon.hp,P1.agi,Dragon.agi,arma,P1.dex,P1.str,Dragon.dmg,P1.cons,Dragon.def);
				
				printf("Parabens, sua jornada foi concluida champs!!!\n\n");
				
				break;
			}
			case 2:{
				printf("Historia\n");
				printf("AGORA VOCE SABERA O QUE LEVOU O NOSSO HEROI PARA O INICIO DE SUA JORNADA EPICA\n");
				printf("HA 15 ANOS, O NOSSO HEROI PERTENCIA A NOBREZA DE ANDROS, MAS  A SEDE DE SEU TIO O REI POR PODER\n");
				printf("O LEVOU AO ENCONTRO DE UMA BRUXA QUE HAVIA MUITO TEMPO FOI A PRINCIPAL CONSELHEIRA DOS REINOS DO DUCADO\n");
				printf("MAS O REI FOI MORTO, E DESCOBRIR QUEM TRAIU O REI É O SEU DEVER");
			}
		}
	}
	
	
	
	return 0;
}
