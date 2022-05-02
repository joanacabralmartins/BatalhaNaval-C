#include <stdio.h>
#include <stdlib.h>


#define COR_VERDE 		printf("\33[32m");
#define COR_LARANJA 	printf("\33[33m");
#define COR_BRANCO 		printf("\33[37m");
#define TAM 5
#define LIM_VAZ 10
#define LIM_SUB 8
#define LIM_NAV 5
#define LIM_AVI 2

int main() {
	int lin, col, l, c, aux;
	int pts_player, pts_comp;
	int vazio, sub, nav, avi;
	int esp[TAM][TAM] = {{0},{0}};
	int campo[TAM][TAM];
	int campo_esp[TAM][TAM] = {{0},{0}};
	
	srand(time(NULL));
	
	vazio = 0; 
	while(vazio < LIM_VAZ) {
		lin = rand() % TAM; 
		col = rand() % TAM;
		if(esp[lin][col] != 1) {
			vazio++;
			campo[lin][col] = 0;
			esp[lin][col] = 1;
		}
	}
	
	sub = 0;
	while(sub < LIM_SUB) {
		lin = rand() % TAM;
		col = rand() % TAM;
		if(esp[lin][col] != 1) {
			sub++;
			campo[lin][col] = 1;
			esp[lin][col] = 1;
		}
	}
	
	nav = 0;
	while(nav < LIM_NAV) {
		lin = rand() % TAM;
		col = rand() % TAM;
		if(esp[lin][col] != 1) {
			nav++;
			campo[lin][col] = 3;
			esp[lin][col] = 1;
		}
	}
	
	avi = 0;
	while(avi < LIM_AVI) {
		lin = rand() % TAM;
		col = rand() % TAM;
		if(esp[lin][col] != 1) {
			avi++;
			campo[lin][col] = 5;
			esp[lin][col] = 1;
		}
	}
	
	pts_player = 0;
	pts_comp = 0;
	aux = 0;
	
	do {
		system("cls");
		printf("\n-----------------------------------------");
		printf("\n------------- BATALHA NAVAL -------------");
		printf("\n-----------------------------------------");
		printf("\n\t    | 0 | 1 | 2 | 3 | 4 |\n");
		
		for(lin=0; lin<TAM; lin++) {
			printf("\t| %i |", lin);
			
			for(col=0; col<TAM; col++) {
				COR_BRANCO
				
				if(campo_esp[lin][col] == 1) {
					COR_LARANJA
					printf(" %i ", campo[lin][col]);
				}
				else if(campo_esp[lin][col] == 2) {
					COR_VERDE
					printf(" %i ", campo[lin][col]);
				}		
				else {
					printf(" # ");
				}
				COR_BRANCO
				printf("|");
			}
			printf("\n");	
		}
		printf("-----------------------------------------");
		printf("\n--------");
		COR_LARANJA
		printf(" Player: %i", pts_player);
		COR_BRANCO
		printf(" | ");
		COR_VERDE
		printf("Computer: %i ", pts_comp);
		COR_BRANCO
		printf("--------");
		printf("\n-----------------------------------------");
		
		if(aux % 2 == 0) {
			
			do {
				printf("\n[Player]: ");
				fflush(stdin);
				scanf("%i %i", &l, &c); 
				
			} while(campo_esp[l][c] == 1 || campo_esp[l][c] == 2 || l > 4 || l < 0 || c > 4 || c < 0);
			campo_esp[l][c] = 1;
		
			pts_player = pts_player + campo[l][c];
		
		}
		
		if(aux % 2 != 0) {
			
			do {
				l = rand() % TAM;
				c = rand() % TAM;
			} while(campo_esp[l][c] == 1 || campo_esp[l][c] == 2);
			campo_esp[l][c] = 2;
			
			pts_comp = pts_comp + campo[l][c];
			
			printf("\n[Computer]:%i %i", l, c);
			fflush(stdout);
			sleep(2);
		}
		
		aux++;
	} while(aux < 8);
	
	system("cls");
	printf("\n");
	printf("\n-----------------------------------------");
	printf("\n------------- BATALHA NAVAL -------------");
	printf("\n-----------------------------------------");
	printf("\n\t    | 0 | 1 | 2 | 3 | 4 |\n");
		
	for(lin=0; lin<TAM; lin++) {
		printf("\t| %i |", lin);
			
		for(col=0; col<TAM; col++) {
			COR_BRANCO
			if(campo_esp[lin][col] == 1) {
				COR_LARANJA
				printf(" %i ", campo[lin][col]);
			}
			else if(campo_esp[lin][col] == 2) {
				COR_VERDE
				printf(" %i ", campo[lin][col]);
			}		
			else {
				printf(" # ");
			}
			
			COR_BRANCO
			printf("|");
		}
		printf("\n");	
	}
	
	printf("-----------------------------------------");
	printf("\n--------");
	COR_LARANJA
	printf(" Player: %i", pts_player);
	COR_BRANCO
	printf(" | ");
	COR_VERDE
	printf("Computer: %i ", pts_comp);
	COR_BRANCO
	printf("--------");
	printf("\n-----------------------------------------");
	
	if(pts_player == pts_comp) {
		printf("\n---------------- EMPATE -----------------");
		printf("\n-----------------------------------------");
	}
	else if(pts_player > pts_comp) {
		printf("\n------------- ");
		COR_LARANJA
		printf("PLAYER VENCEU ");
		COR_BRANCO
		printf("-------------");
		printf("\n-----------------------------------------");
	}
	else {
		printf("\n------------ ");
		COR_VERDE
		printf("COMPUTER VENCEU ");
		COR_BRANCO
		printf("------------");
		printf("\n-----------------------------------------");
	}
	
	return 0;
}
