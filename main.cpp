//Rafel Flores
//31 de Enero del 2020

#include <iostream>
#include <string>


using namespace std;

int eNum1, eNum2, tamanio, powers[4] = {1000, 100, 10, 1};
int *arrKaraprekar = new int[4];

int getRand(){
	int num = rand() % 100;
	return num;
}

bool chkEquality(string buff){
	int const tam = 4;
	int num, intBuff[tam] = {-1,-1,-1,-1};
	for(int i = 0; i < tam; i++){
		num = (int)buff[i] - 48;
		cout << num;
		for(int j = 0; j < tam; j++){
			if (num == intBuff[j]){
				return true;
			}
		}
		intBuff[i] = num;
		cout << intBuff[i];
		arrKaraprekar[i] = intBuff[i];
	}
	return false; 
}

int arrayToNumber(){
	int num = 0;
	for(int i = 0; i < 4; i++){
		num += arrKaraprekar[i] * powers[i];
	}
	return num;
}

void numberToArray(int num){
	for(int i = 0; i < 4; i++){
		arrKaraprekar[i] =  num / powers[i];
		num = num % powers[i];
	}
}

void BubbleSort(){
	for(int i = 0; i < (4-1); i++){
		for(int j = 0; j < (4-i-1); j++){
			if (arrKaraprekar[j] < arrKaraprekar[j + 1] ){
				int temp = arrKaraprekar[j];
				arrKaraprekar[j] = arrKaraprekar[j + 1];
				arrKaraprekar[j+1] = temp;	
			}	
		}
	}
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


void karaprekar(){
	int res, num, numI, cont = 1;
	while (cont < 8){
		num = arrayToNumber();
		BubbleSort();
		imprimir(arrKaraprekar, 4);
		numI = arrayToNumber();
		res = numI - num;
		cout << cont << " | " << numI << " - " << num << " = " << res << "\n";
		cont++;
		numberToArray(res);
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
			if (chkEquality(buff)){
				cout << "Todos los digitos deben ser diferentes!!\n";
			}
			else{
				break;
			}
		}
	}
	karaprekar();
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
