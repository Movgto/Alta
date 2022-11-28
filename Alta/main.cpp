#include<string>
#include<iostream>
#include<conio.h>

using namespace std;
bool run = true;
char op;
int juegosReg = 0;
char a;

struct videojuegos
{
	int id;
	string anio;
	string nombre;
	string clasificacion;
};
videojuegos juego[100];
void signos(int numeroSignos, char signo);
void modificar();
void main() 
{
	for(int i = 0; i < 100;i++)
	{
		juego[i].nombre = "no registrado";
		juego[i].anio = "0000";
		juego[i].clasificacion = "no registrada";
	}
	while(run)
	{
		signos(5,'*');
		cout << "MENU";
		signos(5, '*');
		cout << endl;
		cout << "\t1.Agregar\n\t2.Modificar\n\t3.Ver lista\n\t4.Limpiar\n\t5.Salir\n";
		op = _getche();
		cout << endl;
		
		switch (op) 
		{
		case '1':
			  juegosReg++;
			  juego[juegosReg - 1].id = juegosReg;
			  cout << "Ingresa el nombre del juego a agregar:\n";
			  getline(cin,juego[juegosReg - 1].nombre);
			  cout << "Ingresa el año de lanzamiento:\n";
			  cin >> juego[juegosReg - 1].anio;
			  cout << "Ingresa la clasificacion:\n";
			  cin.ignore();
			  getline(cin, juego[juegosReg - 1].clasificacion);
			  break;
		case '2':
			  modificar();
			  break;
		case '3':
			  if(juegosReg>0)
			  {
			    for(int i = 0;i<juegosReg;i++)
				{
					cout << "id: " << juego[i].id << "\nnombre: " << juego[i].nombre << "\nanio: " << juego[i].anio << "\nclasificacion: " << juego[i].clasificacion <<endl;
					
				}
				break;
			  }
			  else 
			  {
				  cout << "No hay juegos registrados, presione una tecla para continuar...\n";
				  _getch();
				  break;
			  }
		case '4':
			  system("cls");
			  break;
		case '5':
			cout << "Cerrando programa... Está seguro que desea salir?";
			cout << "\n\t1.Si\n\t2.No\n";
			a = _getche();
			switch(a)
			{
			 case '1':
				 run = false;
				 break;
			 case '2':
				 cout << "Volviendo al menu...\n";
				 break;
			}
			break;

		
		default:
			  cerr << "Opcion invalida, por favor intentelo de nuevo\n";
			  cin.ignore();
			  continue;
			  
		}
	}

	system("pause>null");
}

void signos(int numeroSignos, char signo) 
{
	for (int i = 0; i < numeroSignos; i++) 
	{
		cout << signo;
    }
}
void modificar()
{
		bool a = true;
		int id;
		int op;
		cout << "Que juego desea modificar de la lista? Ingrese el id: \n";
		cin >> id;
		cin.ignore();
		while (a)
		{
			cout << "Que dato desea cambiar?\n1.Nombre\n2.Anio\n3.Clasificación\n4.Regresar\n";
			op = _getche();
			switch (op)
			{
			case '1':
				cout << "Ingrese el nuevo nombre: \n";
				getline(cin,juego[id - 1].nombre);
				cin.ignore();
				cout << "MODIFICACION EXITOSA!";
				break;
			case '2':
				cout << "Ingrese el nuevo anio: \n";
				getline(cin,juego[id - 1].anio);
				cin.ignore();
				cout << "MODIFICACION EXITOSA!";
				break;
			case '3':
				cout << "Ingrese nueva clasificacion: \n";
				getline(cin, juego[id - 1].clasificacion);
				cin.ignore();
				cout << "MODIFICACION EXITOSA!";
				break;
			case '4':
				cout << "regresando...\n";
				a = false;
			}
		}
}