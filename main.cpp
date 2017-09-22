#include <iostream>
#include "rsa.h"
using namespace std;

int main()
{
	char cadena[100];
	bool band= true;
	long long int num;
	int opc, p, q;
	RSA T;
	system("clear");
	while(band)
	{
		cout << endl;
		cout << "******************************" << endl;
		cout << "** Algoritmo de Cifrado RSA **" << endl;
		cout << "******************************" << endl << endl;
		cout << "1.- Generar p y q aleatorios. " << endl;
		cout << "2.- Ingresar p y q desde el teclado. " << endl;
		cout << "3.- Salir del programa. " << endl;
		cin>> opc;
		switch(opc)
		{
			case 1:	T.generarPrimos();
					T.generarClaves();
					T.mostrar();
					cout << "Ingrese el texto a cifrar: ";
					getchar();
					cin.getline(cadena, 100);
					cout << "mensaje cifrado: " << T.cifrarTexto(cadena) << endl;
					
					cout << "Ingrese el texto a descifrar: ";
					cin.getline(cadena, 100);
					cout << "mensaje descifrado: " << T.descifrarTexto(cadena) << endl;
					break;
	
			case 2:	do
					{
						cout << "Ingrese p: ";
						cin>> p;
						cout << "Ingrese q: ";
						cin>> q;
					}while( p == q );

					T.insertarP(p);
					T.insertarQ(q);

					T.generarClaves();
					T.mostrar();
					cout << "Ingrese el texto a cifrar: ";
					getchar();
					cin.getline(cadena, 100);
					cout << "mensaje cifrado: " << T.cifrarTexto(cadena) << endl;

					cout << "Ingrese el texto cifrado para descifrarlo: ";
					cin.getline(cadena, 100);
					cout << "mensaje descifrado: " << T.descifrarTexto(cadena) << endl;
					break;
			case 3: cout << endl << "Programa Finalizado. " << endl << endl;
					band= false;
					break;
			default: cout<<"Opcion Incorrecta. " << endl;
		}
	}
	return 0;
}
