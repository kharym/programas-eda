#include <stdio.h>
#include<conio.h>

int main(){
	
	int matriz [50][50],filas,columnas,x,y;
	
	printf("escriba el numero de filas de su tablero\n");
	scanf("%i",&filas);
	printf("digite el numero de columnas\n");
	scanf("%i",&columnas);
	
	printf("\n\n");
	
	for(x=0;x<filas;x++){
		for(y=0;y<columnas;y++){
			
			printf("cual es el elemento de matriz[%i][%i]", x+1,y+1);
			scanf ("%c",&matriz[x][y]); 
		}
	} 
	
	printf("\n\n");
	
	for(x=0;x<filas;x++){
		for (y=0;y<columnas;y++){
			
			printf("%c ", matriz[x][y]);
		}
		printf("\n");
		
	}
	
	getch();
	return 0;
}
