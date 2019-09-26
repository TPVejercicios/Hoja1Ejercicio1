#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>

using namespace std;

#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

void ModificaColor(HANDLE hConsole, int color)
{
	SetConsoleTextAttribute(hConsole, color);
}

void ImprimeVector(const vector<int> numeros)
{
	cout << "vector ";
	for (int aux : numeros)
	{
		cout << "[" << aux << "]";
	}
	cout << endl;
}

void GeneraVectorAleatorio(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] = (rand() % 99);
	}
}

void ModificaVector(vector<int>& numeros)
{
	bool aleatorio = false, parse = false;
	int eleccion, tamaño;
	string cadena;

	do
	{
		cout << "Presiona 0 para ingresar un vector manualmente o presiona 1 para generarlo aleatoriamente" << endl;
		cin >> eleccion;
		aleatorio = eleccion == 1;

	} while (eleccion != 1 && eleccion != 0);

	do
	{
		cout << "Cantidad de elementos en el vector" << endl;
		cin >> cadena;
		if (!isalpha(cadena[0]))
		{
			istringstream chain(cadena);
			chain >> tamaño;
			parse = true;
		}
		else
		{
			cout << "El numero ingresado es invalido" << endl;
		}

	} while (!parse);

	numeros.resize(tamaño);

	if (aleatorio)
	{
		GeneraVectorAleatorio(numeros);
	}
	else
	{
		for (int i = 0; i < tamaño; i++)
		{
			cout << "Ingrese el " << i << " valor del vector" << endl;
			cin >> numeros[i];
		}
	}

}

//Un subprograma que obtenga si alguno de los valores almacenados en el vector está
//repetido.
bool BuscaRepetido(const vector<int>& numeros)
{
	bool repetido = false;
	int  a = 0, b = 1;

	while (a < numeros.size() && !repetido)
	{
		while (b < numeros.size() && !repetido )
		{
			if (numeros[a] == numeros[b])
			{
				repetido = true;
			}
			b++;
		}
		a++;
		b = a + 1;
	}

	return repetido;
}

//Un subprograma que obtenga si alguno de los valores almacenados en el vector es igual
//a la suma del resto de los valores del mismo.
bool ComparaSumas(const vector <int> numeros)
{
	bool suma = false;
	int total = 0;
	int aux = 0;

	while (!suma && aux < numeros.size())
	{
		for (int i = 0; i < numeros.size(); i++)
		{
			if (aux != i)
			{
				total += numeros[i];
			}
		}

		if (numeros[aux] == total)
		{
			suma = true;
		}
		aux++;
	}

	return suma;
}

//Un subprograma que, dados dos vectores, devuelva un valor que indique si son iguales.
bool ComparaVectores(const vector<int>& primero)
{
	bool iguales = false;
	cout << "Este es tu actual ";
	ImprimeVector(primero);
	char choice;
	do
	{
		cout << "Quieres modificar el primer vector (y/n)" << endl;
		cin >> choice;
	} while (choice != 'y' && choice != 'n');

	vector<int> segundo;

	if (choice == 'y')
	{
		ModificaVector(primero);
	}
	cout << "Para el segundo vector" << endl;
	ModificaVector(segundo);
	cout << "Este es el primer  ";
	ImprimeVector(primero);
	cout << endl;
	cout << "Este es el segundo ";
	ImprimeVector(segundo);
	
	if (primero.size() == segundo.size())
	{
		int aux = 0;
		while (aux < primero.size() && primero[aux] == segundo[aux])
		{
			aux++;
		}
		if (aux == primero.size())
		{
			iguales = true;
		}
	}

	return iguales;
}


//Un subprograma que, dado un vector, encuentre y devuelva la componente de mayor
//valor.
int DevuelveMayor(const vector<int>& numeros)
{
	int mayor = numeros[0];
	for (int i = 1; i < numeros.size(); i++)
	{
		if (mayor < numeros[i])
		{
			mayor = numeros[i];
		}
	}

	return mayor;
}

//Un subprograma que, dado un vector, calcule y devuelva la suma de los elementos que
//se encuentran en las posiciones pares del vector.
int SumaPares(const vector<int>& numeros)
{
	int total = 0;
	for (int i = 0; i < numeros.size() ; i+=2)
	{
		total += numeros[i];
	}
	return total;
}

//Un subprograma que, dado un vector, mueva sus componentes un lugar a la derecha. El
//último componente se moverá al 1er lugar.
void MueveVector(vector<int>& numeros)
{
	int ultimo = numeros[numeros.size() - 1];
	for (int i = numeros.size() - 1; i > 0; i--)
	{
		numeros[i] = numeros[i - 1];
	}
	numeros[0] = ultimo;
}


int main()
{
	int tamaño, eleccion;
	string mensaje;
	vector <int> numeros;
	vector<string> cadenas = { "Mueve sus componentes un lugar a la derecha y el ultimo a la primera posicion","La suma de todos las posiciones pares del vector","Devuelve el maximo valor",
		"Comprueba si hay dos vectores iguales","¿Existe un elemento del vector que sea igual a la suma de todos los demas?","¿Existen dos elementos iguales?","Modifica el vector","Salir" };
	ModificaVector(numeros);
	bool running = true;
	int choice, currPos = 0;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (running)
	{
		system("Cls");

		for (int i = 0; i < cadenas.size(); i++)
		{
			if (i == currPos)
			{
				ModificaColor(hConsole,15);
			}
			else
			{
				ModificaColor(hConsole, 8);
			}
			cout << cadenas[i] << endl;
		}
		SetConsoleTextAttribute(hConsole, 1);
		ImprimeVector(numeros);
		ModificaColor(hConsole,9);
		cout << mensaje << endl;
		char tecla = _getch();
		switch (tecla)
		{
		case ARRIBA:
			if (currPos == 0)
			{
				currPos = cadenas.size() - 1;
			}
			else
			{
				currPos--;
			}
			break;
		case ABAJO:
			if (currPos == cadenas.size() - 1)
			{
				currPos = 0;
			}
			else
			{
				currPos++;
			}
			break;
		case ENTER:
			switch (currPos)
			{
			case 0:
				MueveVector(numeros);
				mensaje = "El vector ha sido desplazado";
				break;
			case 1:
				mensaje = "La suma de todas las posiciones pares es " + to_string(SumaPares(numeros));
				break;
			case 2:
				mensaje = "El numero mayor del vector es " + to_string(DevuelveMayor(numeros));
				break;
			case 3:
				if (ComparaVectores(numeros))
				{
					mensaje = "Ambos vectores son iguales";
				}
				else
				{
					mensaje = "Ambos vectores son diferentes";
				}
				break;
			case 4:
				if (ComparaSumas(numeros))
				{
					mensaje = "Hay un elemento que lo cumple";
				}
				else
				{
					mensaje = "No hay un elemento que lo cumpla";
				}
				break;
			case 5:
				if (BuscaRepetido(numeros))
				{
					mensaje = "Hay elementos repetidos en el vector";
				}
				else
				{
					mensaje = "No hay elementos repetidos en el vector";
				}
				break;
			case 6:
				mensaje = "El vector ha sido modificado";
				ModificaVector(numeros);
				break;
			case 7:
				running = false;
			default:
				mensaje = "Eleccion invalida";
				break;
			}
		default:
			break;
		}
	
	}

	return 0;
}