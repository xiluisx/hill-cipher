#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include "hill-cipher.h"

int sizecadena(string cadena){
	int i = 0;
    while(cadena[i] != '\0'){
        i++;
    }
    return i;
}

int revisacter(string cadena){
    int i = 0;
    int a = 0;
    while(cadena[i] != '\0'){
        if(cadena[i] > 64 && cadena[i] < 91){
            a = 0;
        }else if(cadena[i] > 96 && cadena[i] < 123){
            a = 0;
        }else if(cadena[i]==32){
            a = 0;
        }else{
            printf("Solo usa A-Z a-z para la expresion.\n");
            return 0;
        }
        i++;
    }
    return 1;
}

string checadena(){
    string cadena;
    cadena = get_string("Introduce mensaje MAX 140 caracteres: ");
    while(sizecadena(cadena) > 140 || revisacter(cadena)==0){
        cadena = get_string("Expresion invalida\nIntroduce mensaje MAX 140 caracteres: ");
    }
    return cadena;
}

int conversion(char caracter){
    return (int)(caracter);
}


void get_key(int key[2][2]) {
	int x = 2, y = 2;
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < y; j++) {
			key[i][j] = get_int("Inserta el valor %i, %i de la llave: ", i+1, j+1);
		}
	}
}



int main(){
    string mensaje;
	int opcion = 1;

	do {
		printf("Elige una opcion:\n");
		printf("1. Cifrar mensaje\n2. Descifrar mensaje\n3. Salir\n");
		opcion = get_int("[1-2-3]: ");

		switch(opcion) {
			case 1: {
				mensaje = checadena();
    			printf("Mensaje a cifrar: %s\n", mensaje);
				int key[2][2];
				get_key(key);
				int mensaje_dec[sizecadena(mensaje)];
				for(int i = 0; i < sizecadena(mensaje); i++) {
					mensaje_dec[i] = conversion(mensaje[i]);
				}

				int resultado[sizecadena(mensaje)];
				encriptar(resultado, mensaje_dec, key, sizecadena(mensaje));
				break;
			}
			case 2: {
					mensaje = checadena();
					printf("Mensaje a descifrar: %s\n", mensaje);
					int key[2][2];
					get_key(key);
					int mensaje_dec[sizecadena(mensaje)];
					for(int i = 0; i < sizecadena(mensaje); i++) {
						mensaje_dec[i] = conversion(mensaje[i]);
					}

					int resultado[sizecadena(mensaje)];
					desencriptar(resultado, mensaje_dec, key, sizecadena(mensaje));
					
				break;
			}
			case 3:
				printf("Saliendo del programa!\n");
				break;		
			default:
				printf("Opcion no valida!\n");
				break;
		}
	} while(opcion != 3);

    return 0;
}

