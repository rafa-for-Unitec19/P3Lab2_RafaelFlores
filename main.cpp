//Rafel Flores
//31 de Enero del 2020

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>


using namespace std;

int eNum1, eNum2, tamanio, powers = {1, 10, 100, 100};
int *arrKaraprekar;.

int getRand(){
	int num = rand() % 100;
	return num;
}

bool chkEquality(string buff){
	int const tam = 4;
	int num, intBuff[tam] = {-1,-1,-1,-1};
	for(int i = 0; i < tam; i++){
		num = stoi(buff[i]);
		for(int j = 0; j < tam j++){
			if (num == intBuff[j]){
				return true;
			}
		}
		intBuff[i] = num;
		arrKaraprekar[i] = intBuff[i];
	}
	return false; 
}

void karaprekar(){
	int res, num, numFalse;
	while (res != 6174){
		
	}
}

int getDigits(){
	while(true){
		string buff;
		cout << "Ingrese un Numero de cuatro cifras: \n";
		cin >> buff;
		if ( buff.length() != 4){
			cout << "Debe ingresar un numero de 4 digitos!!!\n";
		}else{
			if (chkEquality){
				cout << "Todos los digitos deben ser diferentes!!\n"
			}
			else{
				break;
			}
		}
	}
	karaprekar();
}

int getNumber(int serie){
	int num;
	while (true){
		cout << "Ingrese el " << serie << " numero para el MCD de Euclides: ";
		cin >> num;
		if (num > 1){
			if(serie == 2 && eNum1 < num){
				cout << "El " << serie << " debe ser menor que el " << serie -1 << " numero\n";
			}else{
				break;
			}		
		}else{
			cout << "Ingrese un numero NATURAL!!!\n";
		}
	}
	return num;
}

int euclides(int num1, int num2){
	if(num2 == 0){
		return num1;
	}else{
		int buff = num1 % num2;
		return euclides(num2, buff);
	}
}

void imprimir(int *arr, int tam){
	for(int i = 0; i < tam; i++){
		cout << "[ " << arr[i] << " ] ";
	}
	cout << "\n";
}

int arrTam(){
	int tam;
	while(true){
		cout << "Ingrese el tamanio del arreglo: \n";
		cin >> tam;
		if (tam < 1){
			cout << "No puede crear arreglos de tamanio 0 o negativo\n";
		}else{
			return tam;
		}
	}
}

int  *llenar(){
	tamanio = arrTam();
	int *arr = new int[tamanio];
	for(int i = 0; i < tamanio; i++){
		arr[i] = getRand(); 
	}
	return arr;
}

void sortear(){
	int *arr = llenar();
	imprimir(arr, tamanio);
	bool flag = false;
	int ref = -1, compare[2];
	while(!flag){
		ref++;
		compare[0] = arr[ref];
		compare[1] = ref;
		for(int i = ref; i < tamanio; i++){
			if (compare[0] > arr[i]){
				compare[0] = arr[i];
				compare[1] = i;	
			}
			if (ref == (tamanio-1)){
				flag = true;
			}
		}
		arr[compare[1]] = arr[ref];
		arr[ref] = compare[0];
		imprimir(arr, tamanio);
	}
	delete[] arr;
}

int menu(){
	int op;
	while (true){
		cout << "Bienvenido\n"
			<< "Elija la opcion que desee:\n"
			<< "\t1. Euclides\n"
			<< "\t2. Sort\n"
			<< "\t3. Karaprekar constant\n"
			<< "\t0. Salir\n";
		cin >> op;
		if (op >= 0 && op < 4){
			break;
		}else{
			cout << "Debe ingresar una opcion valida!!!!!\n";
		}
	}
}


void selector(){
	bool flag = false;
	while(!flag){
		int res;
		switch(menu()){
			case 1:
				eNum1 = getNumber(1);
	       			eNum2 = getNumber(2);
	 			res = euclides(eNum1, eNum2);
				cout << "El MCD resultante es: " << res << "\n";		
				break;
			case 2:
				sortear();
				break;
			case 3:
				getDigits();
				break;
			case 0:
				flag = true;
				break;
		}
	}
}

int main(){
	selector();
	cout << "Nos vemos!";
	return 0;
}
