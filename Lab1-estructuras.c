/**********************************************************************************************************************
 // FileName:        Lab1-estructuras.c
 // Program version: Dev-C++ 6.3
 // Company:         TECNM - ITCH - Departamento Electrica Electronica - Especialidad de sistemas embebidos
 // Description:     Clasificacion de microcontroladores por el tamaño de su arquitectura.
 // Authors:         Jesus Adrian Guerra Delgado
 // Updated:         09/2022
 //Nota: Resumen de lo visto hasta el momento
 ************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/************************************************
    DECLARACION DE ESTRUCTURA
************************************************/
typedef struct{
	char nombre[20];
	char fabricante[20];
}Datos_S;
typedef struct{
	int nbits;
	Datos_S datos;
}Micros_S;
/************************************************
    PROTOTIPO DE FUNCION
************************************************/
void portada(void);
void cleanBuffIn(void); 
void registro(Micros_S *micros,int i);
int checador(Micros_S *micros,int arqui);
void printclas(Micros_S *micros,int i);

/************************************************
    FUNCION  MAIN
************************************************/
int main() {
/*Declaracion de variables*/		
	int i,j=0,k;
	int cantidad, cant8=0, cant16=0, cant32=0;
	int x=0;
	
	portada();
	/*Se piden cuantos microcontroladores se registraran*/
	printf(" Introduzca la cantidad de microcontroladores:");
	scanf("%d",&cantidad);
	Micros_S General[cantidad];
	
	/*Funcion de registro de datos*/
	for(i=0;i<cantidad;i++){
		registro(&General[i],i);
	}
	
	/*Se realiza un conteo de cuantos microcontroladores de cada tipo hay*/
	for(i=0;i<cantidad;i++){	
		x=checador(&General[i],8);
		if(x==1){
			cant8++;
		}
	}
	Micros_S bits8[cant8];	/*Se crea un arreglo de estructuras para los*/
							/*microcontroladores de 8 bits*/
	for(i=0;i<cantidad;i++){	
		x=checador(&General[i],16);
		if(x==1){
			cant16++;
		}
	}
	Micros_S bits16[cant16];/*Se crea un arreglo de estructuras para los*/
							/*microcontroladores de 16 bits*/
	
	for(i=0;i<cantidad;i++){	
		x=checador(&General[i],32);
		if(x==1){
			cant32++;
		}
	}
	Micros_S bits32[cant32];/*Se crea un arreglo de estructuras para los*/
							/*microcontroladores de 32 bits*/
	
	/*Se clasifican los datos de acuerdo al tipo de arquitectura*/
	for(i=0;i<cantidad;i++){	
		x=checador(&General[i],8);												/*Se revisa que microcontroladores son de 8 bits*/
		if(x==1){																/*de entre todos los registrados*/
			for(k=0;k<20;k++){													/*Se pasan el nombre y fabricante de cada*/
				bits8[j].datos.nombre[k]=General[i].datos.nombre[k];			/*microcontrolador caracter por caracter*/
				bits8[j].datos.fabricante[k]=General[i].datos.fabricante[k];	/*Del arreglo principal al arreglo particular*/
			}
			bits8[j].nbits=General[i].nbits;									/*Se pasa el dato del tipo de arquitectura de un arreglo a otro*/
			j++;
		}
	}
	j=0;
	
	for(i=0;i<cantidad;i++){	
		x=checador(&General[i],16);												/*Se revisa que microcontroladores son de 8 bits*/
		if(x==1){																/*de entre todos los registrados*/
			for(k=0;k<20;k++){													/*Se pasan el nombre y fabricante de cada*/
				bits16[j].datos.nombre[k]=General[i].datos.nombre[k];			/*microcontrolador caracter por caracter*/
				bits16[j].datos.fabricante[k]=General[i].datos.fabricante[k];	/*Del arreglo principal al arreglo particular*/
			}
			bits16[j].nbits=General[i].nbits;									/*Se pasa el dato del tipo de arquitectura de un arreglo a otro*/
			j++;
		}
	}
	j=0;
	
	for(i=0;i<cantidad;i++){	
		x=checador(&General[i],32);												/*Se revisa que microcontroladores son de 8 bits*/
		if(x==1){																/*de entre todos los registrados*/
			for(k=0;k<20;k++){													/*Se pasan el nombre y fabricante de cada*/
				bits32[j].datos.nombre[k]=General[i].datos.nombre[k];			/*microcontrolador caracter por caracter*/
				bits32[j].datos.fabricante[k]=General[i].datos.fabricante[k];	/*Del arreglo principal al arreglo particular*/
			}
			bits32[j].nbits=General[i].nbits;									/*Se pasa el dato del tipo de arquitectura de un arreglo a otro*/
			j++;
		}
	}
	j=0;
	/*Se imprime un inventario de los microcontroladores registrados*/
	printf("\n Se tienen %d microcontroladores de 8 bits",cant8);
	printf("\n Se tienen %d microcontroladores de 16 bits",cant16);
	printf("\n Se tienen %d microcontroladores de 32 bits",cant32);
	
	/*Se imprime una lista detallada de cada arquitectura*/
	printf("\n Los Microcontroladores de 8 bits son:");
	for(i=0;i<cant8;i++){
		printclas(&bits8[i],i);
	}
	printf("\n Los Microcontroladores de 16 bits son:");
	for(i=0;i<cant16;i++){
		printclas(&bits16[i],i);
	}
	printf("\n Los Microcontroladores de 32 bits son:");
	for(i=0;i<cant32;i++){
		printclas(&bits32[i],i);
	}
	
	return 0;
}
/***********FUNCION printclas********/
void printclas(Micros_S *micros,int i){
	printf("\n %d.- %s fabricado por %s",i+1,micros->datos.nombre,micros->datos.fabricante);
}
/***********FUNCION checador********/
int checador(Micros_S *micros,int arqui){
/*Declaracion de variables*/
	int si_es=0;
	if(micros->nbits==arqui){
		si_es=1;
	}
	return si_es;
}
/***********FUNCION registro********/
void registro(Micros_S *micros,int i){
/*Declaracion de variables*/
	int x=0;
	micros->nbits=0;
	/*Se leen los datos*/
	printf("\n Introduzca el nombre del microcontrolador %d:",i+1);
	cleanBuffIn();
	scanf("%s",micros->datos.nombre);
	printf("\n Introduzca el nombre de su fabricante:");
	cleanBuffIn();
	scanf("%s",micros->datos.fabricante);
	printf("\n Introduzca el tipo de arquitectura(8, 16 o 32):");
	/*Se verifica que se introduzca un dato valido en el tipo de arquitectura*/
	/*ademas de que sea una de las tres arquitecturas aceptadas*/
	while(x==0 || (micros->nbits!=8 && micros->nbits!=16 && micros->nbits!=32)){	
		cleanBuffIn();
		x=scanf("%d",&micros->nbits);
		if(x==0){
			printf("\n Error, la entrada es incorrecta");
			printf("\n Introduzca el tipo de arquitectura otra vez(8, 16 o 32):");	
		}
		if(x==1 && (micros->nbits!=8 && micros->nbits!=16 && micros->nbits!=32)){
			printf("\n Error, tipo de arquitectura no soportada");
			printf("\n Introduzca el tipo de arquitectura otra vez(8, 16 o 32):");	
		}						
	}		
}
/***********FUNCION portada********/
void portada(void){
	printf("\t  Tecnologico Nacional de Mexico\n");
	printf("\t INSTITUTO TECNOLOGICO DE CHIHUAHUA\n");
	printf("\tDepartamento Electrica - Electronica\n");
	printf("\t  Especialidad: Sistemas Embebidos\n");
	printf("\tArquitectura de Prog. Para Hardware\n");
	printf("\t   Docente: Alfredo Chacon Aldama \n");
	printf("\t    Jesus Adrian Guerra Delgado\n");
	printf("\t           7mo Semestre\n");	
	printf("\t\tLab1 Estructuras\n");
	printf("\tClasificador de microcontroladores\n");
}
/***********FUNCION cleanBuffIn********/
void cleanBuffIn(void){     /*FUNCION PARA LIMPIAR EL BUFFER DE ENTRADA EN SUSTITUCION DE fflush(stdin)*/
	int ch;
	while ((ch = fgetc(stdin)) != EOF)  /* Brinca o descarta todos los caracteres de stdin, */
	{                                   /* hasta que se encuentra con EOF, llegado al final del buffer.*/
	  if( ch == '\n' ) break;           /* o si encuentra un salto de linea */
	}
}