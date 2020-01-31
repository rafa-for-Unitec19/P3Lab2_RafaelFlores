//Rafel Flores
//31 de Enero del 2020

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>


using namespace std;

int eNum1, eNum2;

int getRand(){
	int num = rand() % 100;
	return num;
}

int getNumber(int serie){
	int num;
	while (true){
		if (serie){
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
		}else{
			string buff;
			cout << "Ingrese un Numero de cuatro cifras: \n";
			cin >> buff;
			if ( buff.length() != 4){
				cout << "Debe ingresar un numero de 4 digitos!!!";
			}else{
				
			}
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
	int tam = arrTam();
	int *arr = new int[tam];
	for(int i = 0; i < tam; i++){
		arr[i] = getRand(); 
	}
	return arr;
}

int sortear(int* arr, int tam){
	bool flag = false;
	int ref = -1, compare;
	while(!flag){
		ref++;
		compare = arr[ref];
		for(int i = ref; i < tam; i++){
			if (compare > arr[i]){
				compare = arr[i]; 
			}
			if (ref == (tam-1)){
				flag = true;
			}
		}
	}
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
				cout << "El 3";
				break;
			case 3:
				cout << "El 4";
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
