# include <stdio.h>
# include <stdlib.h>

struct tablero {
	
	int matriz [50][50],filas,columnas,x,y, dificultad; 
	
}tablero1,tablero2,tablero3; 

int main(){
	
	printf("escriba el numero de filas de su tablero\n");
	scanf("%i",&tablero1.filas);
	printf("digite el numero de columnas\n");
	scanf("%i",&tablero1.columnas);
	
	printf("\n\n");
	
	for(tablero1.x=0;tablero1.x<tablero1.filas;tablero1.x++){
		for(tablero1.y=0;tablero1.y<tablero1.columnas;tablero1.y++){
			
			printf("cual es el elemento de matriz[%i][%i]", tablero1.x+1,tablero1.y+1);
			scanf ("%i",&tablero1.matriz[tablero1.x][tablero1.y]); 
		}
	} 
	
	printf("\n\n");
	
	for(tablero1.x=0;tablero1.x<tablero1.filas;tablero1.x++){
		for (tablero1.y=0;tablero1.y<tablero1.columnas;tablero1.y++){
			
			printf("%i ", tablero1.matriz[tablero1.x][tablero1.y]);
		}
		printf("\n");
	}
	
	getch();
	return 0;
}
