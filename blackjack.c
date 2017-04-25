#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declaración de funciones
void definicion();
void reglas();
void opciones(int *,char *);
void imprimirCarta(int);
int sacarCarta();
void juego(int, char);

int main() //Funcion principal
{
	int opc, dinero=20;
	char dific='d';
	srand(time(NULL));

	printf("\E[0;1m-------\E[0;4mBLACKJACK\E[00m\E[0;1m------\E[00m");

	do //Inicio bucle Menu
	{
		printf("\n\E[1;33m-MENU-\E[00m\n\E[1;33m1.\E[00m Jugar\n\E[1;33m2.\E[00m ¿Qué es el blackjack?\n\E[1;33m3.\E[00m Reglas\n\E[1;33m4.\E[00m Opciones\n\E[1;33m5.\E[00m Salir\n");
		printf("\nIntroduzca una opción valida: ");
		scanf("%d", &opc);
		switch(opc)
		{
			case 1: juego(dinero, dific);
				break;
			case 2: definicion();
				break;
			case 3: reglas();
				break;
			case 4: opciones(&dinero, &dific);
				break;
			case 5: printf("\E[0;31mSaliendo...\E[00m\n");
				break;
			default: printf("ERROR (Opción no valida)\n");
		}
	}while(opc!=5); //Fin bucle Menu
	return 0;
}

void definicion() //Funcion para mostrar la definicion del blackjack
{
	printf("\n\E[0;36m¿QUÉ ES EL BLACKJACK?\E[00m\n");
	printf("El blackjack es un juego de cartas que trata de acercarse lo máximo posible al 21 sumando el valor de las cartas.\n");
	printf("Se empieza con una carta aleatoria y se le preguntará al jugador si desea otra carta aleatoria. ");
	printf("Se han de sumar el valor de las cartas hasta tener 21, hasta pasarse de 21 o hasta que el jugador no quiera pedir mas cartas para no pasarse de 21.\n");
}

void reglas() //Funcion para mostrar las reglas que rigen el juego
{
	printf("\n\E[0;36mREGLAS:\E[00m\n");
	printf("- Las cartas tendrán un valor entre 2 y 10 excepto el As que puede ser 1 o 11, a decisión del jugador\n");
	printf("- En este juego, se usan un número de barajas infinitas, de manera que la probabilidad de que salga una carta en concreto no varía nunca\n");
	printf("- El jugador gana si llega a 21 o consigue un número más proximo a 21 que la banca.\n");
	printf("- Ganará la banca si el jugador se pasa de 21 o si tiene un número mayor o igual al del jugador.\n");
	printf("- El número de la banca dependerá del nivel de dificultad que se puede modificar en las opciones (dificil por defecto: 17<=numero de la banca<=21).\n");
	printf("- El jugador empezará con 20$ o con la cantidad establecida en las opciones y puede apostar en cada partida.\n");
	printf("- Si el jugador se queda sin dinero perderá.\n");
	printf("- Las apuestas se pagan a el doble del dinero apostado.\n");
}

void opciones(int *pdinero,char *pdific) //Funcion para las opciones
{	
	char opcDin , opcDif, dif;
	int din;
	srand(time(NULL));

	printf("\n\E[0;36mOpciones:\E[00m\n");

	//Cambiar dinero inicial
	printf("¿Desea coambiar el dinero inicial (20$)? (Y/N)\n");
	scanf(" %c", &opcDin);
	while(opcDin!='n' && opcDin!='N' && opcDin!='y' && opcDin!='Y') //Caracter erroneo
	{
		printf("No ha intoducido una opcion valida (Y/N)\n");
		scanf(" %c", &opcDin);
	}
	if(opcDin=='y' || opcDin=='Y')
	{
		printf("¿Con cuanto dinero desea empezar? (1<=dinero<=100): ");
		scanf("%d", &din);
		while(din<=0 || din>100) //Numero de dinero no permitido
		{
			printf("El dinero ha de ser un número postivo y el máximo es 100\nIntorduzca una cantidad correcta: ");
			scanf("%d", &din);
		}
	*pdinero=din; //Cambiar valor dinero de main por referencia
	}

	//Cambiar dificultad
	printf("\n¿Desea cambiar la dificultad (Dificil por defecto) (Y/N)?\n");
	scanf(" %c", &opcDif);
	while(opcDif!='n' && opcDif!='N' && opcDif!='y' && opcDif!='Y') //Caracter erroneo
	{
		printf("No ha intoducido una opcion valida (Y/N)\n");
		scanf(" %c", &opcDif);
	}
	if(opcDif=='y' || opcDif=='Y')
	{
		printf("Escriba D para dificil (numero de la banca entre 17 y 21)\n");
		printf("Escriba M para medio (numero de la banca entre 15 y 19)\n");
		printf("Escriba F para facil (numero de la banca entre 12 y 18)\n");
		scanf(" %c", &dif);
		while(dif!='d' && dif!='D' && dif!='m' && dif!='M' && dif!='f' && dif!='F')
		{
			printf("Introduce una opcion valida (D/M/F):\n");
			scanf(" %c", &dif);
		}
		*pdific=dif;
	}
}

void imprimirCarta(int numRand) //Funcion para dibujar la carta
{
	printf("------------\n");
	if(numRand==1 || numRand==10 || numRand==11 || numRand==12) //Caso de carta A, J, Q, K
	{
		switch(numRand)
		{
			case 1:	printf("|A\E[0;31m  *   *  \E[00m|\n");
				break;
			case 10: printf("|J\E[0;31m  *   *  \E[00m|\n");
				break;
			case 11: printf("|Q\E[0;31m  *   *  \E[00m|\n");
				break;
			case 12: printf("|K\E[0;31m  *   *  \E[00m|\n");
				break;
		}
	}
	else //Caso de carta con valor numérico
		printf("|%d\E[0;31m  *   *  \E[00m|\n", numRand);

	printf("|\E[0;31m  *  *  * \E[00m|\n");
	printf("|\E[0;31m   *   *  \E[00m|\n");
	printf("|\E[0;31m    * *   \E[00m|\n");
	printf("|\E[0;31m     *    \E[00m|\n");
	printf("------------\n");
}

int sacarCarta() //Funcion que devuelve valor de la carta
{
	int numRand=rand()%12+1;
	int valorAs, valorCarta;
	if(numRand==1) //Caso de la carta A
	{
		printf("Ha salido un As\t¿Qué valor le quieres dar (1 o 11)?: ");
		scanf("%d", &valorAs);
		while(valorAs!=1 && valorAs!=11)
		{
			printf("Valor no válido. Introduzca uno válido (1 o 11): ");
			scanf("%d", &valorAs);
		}
		valorCarta=valorAs;
	}
	else if(numRand==10 || numRand==11 || numRand==12) //Caso de las cartas J, Q, K
	{
		switch(numRand)
		{
			case 10: printf("Ha salido una J ");
				break;
			case 11: printf("Ha salido una Q ");
				break;
			case 12: printf("Ha salido una K ");
				break;
		}
		printf("cuyo valor es 10\n");
		valorCarta=10;
	}
	else //Caso de las cartas numéricas
	{
		printf("Ha salido un %d\n", numRand);
		valorCarta=numRand;
	}
	imprimirCarta(numRand); //Llama a la funcion para dibujar la carta
	
	return valorCarta;
}

void juego(int dinero, char dific) //Funcion del juego
{
	int numJug, numAl, apuesta, numBanc;
	char preg, plant, menu;

	printf("\n\E[0;36mCOMENCEMOS\E[00m\n");
	printf("Empiezas %d$, apuestalos con inteligencia.\n", dinero);
	do //Inicio bucle Juego
	{
		if(dific=='d' || dific=='D') //Numero de banca en dificil
			numBanc=rand()%5+17;
		else if(dific=='m' || dific=='M') //Numero de banca en medio
			numBanc=rand()%5+15;
		else //Numero de banca en facil
			numBanc=rand()%7+12;

		printf("\E[0;1mTienes %d$\E[00m\n", dinero);
		do //Inicio bucle Apuestas
		{
			printf("¿Cuanto dinero desea apostar? ");
			scanf("%d", &apuesta);
			if(apuesta>dinero)
				printf("No tiene tanto dinero\n");
			else if(apuesta<=0)
				printf("Ha de apostar algo de dinero\n");
			else
				printf("Ha apostado %d$. ", apuesta);
		}while(apuesta>dinero || apuesta<=0); //Fin bucle Apuestas

		dinero-=apuesta;
		printf("Te han quedado %d$ sin apostar\n", dinero);
		printf("\n\E[1;34mPrimera tirada: \E[00m\n");
		numJug=sacarCarta(); //Carta inicial
		do //Inicio bucle Pedir cartas
		{
			printf("¿Quieres otra carta? (Y/N)\n");
			scanf(" %c", &preg);
			if (preg=='y' || preg=='Y') //Dar una carta nueva
			{
				printf("\E[1;34mSiguiente tirada: \E[00m\n");
				numAl=sacarCarta();
				numJug+=numAl;
				printf("\E[1;34mTienes un %d\E[00m\n\n", numJug);
			}
			else if(preg!='n' && preg!='N') //Mensaje de error por caracter no permitido
				printf("Opcion no valida. Escriba Y o N.\n");
		}while(preg!='n' && preg!='N' && numJug<21); //Fin bucle Pedir cartas

		printf("\n\E[0;37mEl número de la banca es %d\E[00m\n\n", numBanc); //Imprimir número de la banca

		//Imprimir resultado
		if(numJug==21)
		{
			printf("\E[0;32m¡¡ENHORABUENA!!\E[00m\nHas llegado a 21 y ¡¡¡has ganado!!!\n");
			dinero+=(apuesta*2);
		}
		else if(numJug>21)
			printf("\E[0;31m¡¡HAS PERDIDO!!\E[00m\nLo siento, te has pasado de 21\n");
		else if(numJug<=numBanc)
			printf("\E[0;31m¡¡PERDISTE!!\E[00m\nLa banca gana esta vez\n");
		else
		{
			printf("\E[0;32m¡¡ENHORABUENA!!\E[00m\nHas ganado a la banca\n");
			dinero+=(apuesta*2);
		}

		printf("\E[0;1mTe quedan %d$\E[00m\n", dinero); //Dinero resultante

		if(dinero>0) //Si al jugador le queda dinero
		{
			printf("Introduzca P para plantarse o J para seguir jugando\n");
			do //Pedir caracter para plantarse o seguir jugando
				scanf(" %c", &plant);
			while(plant!='p' && plant!='P' && plant!='j' && plant!='J');
			if(plant=='p' || plant=='P')
				printf("Te has plantado con %d$.\n", dinero);
		}
		else //Si no le queda dinero
			printf("Te has quedado sin dinero\n");

	}while((plant=='j' || plant=='J') && dinero>0); //Fin bucle Juego

	do //Pedir caracter para salir al menu
	{
		printf("\nIntroduzca M para salir al menu\n");
		scanf(" %c", &menu);
	}while(menu!='m' && menu!='M');
}