#include <stdio.h>
#include <math.h>

int mod(int a, int b) {
	int r = a % b;
	return r < 0 ? r + b : r;
}

int matinver(int a, int b, int c, int d) {
	if(a*d == b*c) {
		printf("Matriz no invertible\n");
		return 0;
	}
	return 1;
}

int modInverse(int a, int m) {
	for(int i = 1; i < m; i++) {
		if(((a%m) * (i%m)) % m == 1)
			return i;
	}
	return 0;
}

void encriptar(int mat[], int mensaje[], int key[2][2], int size) {
	//Encriptar
	int mensaje_encrip[size];
	for(int i = 0; i < size; i+=2) {
		mensaje_encrip[i] = ((mensaje[i] - 97) * key[0][0] + (mensaje[i+1] - 97) * key[0][1]) % 26;
		mensaje_encrip[i+1] = ((mensaje[i] - 97) * key[1][0] + (mensaje[i+1] - 97) * key[1][1]) % 26;
	}
	printf("Mensaje encriptado: ");
	for(int i = 0; i < size; i++) {
		printf("%c", mensaje_encrip[i]+97);
	}
	printf("\n");
}

void desencriptar(int mat[], int mensaje[], int key[2][2], int size) {
	int inverse_prod = modInverse((key[0][0] * key[1][1]) - (key[0][1] * key[1][0]), 26);
	printf("Inverse: %i\n", inverse_prod);
	int flip_key[2][2] = {{key[1][1], mod(-key[0][1], 26)}, {mod(-key[1][0], 26), key[0][0]}};
	int inverse_key[2][2];
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			inverse_key[i][j] = (inverse_prod * flip_key[i][j]) % 26;
		}
	}
	int mensaje_desencrip[size];
	for(int i = 0; i < size; i+=2) {
		mensaje_desencrip[i] = ((mensaje[i] - 97) * inverse_key[0][0] + (mensaje[i+1] - 97) * inverse_key[0][1]) % 26;
		mensaje_desencrip[i+1] = ((mensaje[i] - 97) * inverse_key[1][0] + (mensaje[i+1] - 97) * inverse_key[1][1]) % 26;
	}
	printf("Mensaje desencriptado: ");
	for(int i = 0; i < size; i++) {
		printf("%c", mensaje_desencrip[i]+97);
	}
	printf("\n");
}

