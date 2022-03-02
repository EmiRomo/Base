#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {

	int operador = 0, hrs = 0, ct = 0, opcion = 0, cita = 0;
	string nombre, nt, desc;
	float put = 0.0, pu = 0.0, t = 0.0;

	do {

		system("cls");

		cout << "*+*Hola, bienvenido al menu*+*" << endl;
		cout << "*+*Ingresa una opcion*+*" << endl;
		cout << "1-Agendar una cita" << endl;
		cout << "2-Modificar una cita" << endl;
		cout << "3-Eliminar cita" << endl;
		cout << "4-Lista de citas vigentes" << endl;
		cout << "5-Limpiar pantalla" << endl;
		cout << "6-Salir" << endl;
		cin >> operador;

		switch (operador) {

		case 1:

			while (cita < 3)
			{

				cout << "Ingrese su nombre" << endl;
				cin >> nombre;
				cout << "Ingrese hora del tratamiento" << endl;
				cin >> (hrs);
				cout << "Ingrese el nombre del tratamiento" << endl;
				getline(cin, nt);
				cout << "Ingrese la descripcion del tratamiento" << endl;
				getline(cin, desc);
				cout << "Ingrese el precio unitario del tratamiento" << endl;
				cin >> put;
				cout << "Cantidad del tratameinto" << endl;
				cin >> ct;
				cout << "Ingrese el precio unitario" << endl;
				cin >> pu;


				t = (put * ct) + pu;
				cout << "Su total es" << (t) << endl;
				system("pause");

				cout << "Seleccione 1- Para agregar otra cita" << endl;
				cout << "Seleccione 2- Para salir" << endl;
				cin >> opcion;

				if (opcion == 1)
				{
					cita + 1;
				}
				else (opcion == 2)
				{
					return main();
				}
				break;
			}

		case 2:
			cout << "Modificar una cita" << endl;
			system("pause");
			break;

		case 3:
			cout << "Eliminar cita" << endl;
			system("pause");
			break;

		case 4:
			cout << "Lista de citas vigentes" << endl;
			system("pause");
			break;

		case 5:
			cout << "Limpiar pantalla" << endl;
			system("pause");
			break;

		case 6:
			cout << "Saliendo..." << endl;
			system("pause");
			exit(1);




		}

	} while (operador < 6);
	system("pause");
	return 0;

	cout << "Su cita es " << endl;
	cout << "Saliendo del programa otra vez" << endl;
	cout << "Nombre de paciente: " << (nombre) << endl;
	cout << "Hora de tratamiento: " << (hrs) << endl;
	cout << "Tratamiento:  " << (nt) << endl;
	cout << "Descripcion del tratamiento" << (desc) << endl;
	cout << "Precio unitario del tratamiento" << (put) << endl;
	cout << "Cantidad de tratamiento" << (ct) << endl;
	cout << "Precio unitario de: " << (pu) << endl;
	cout << "Su total es de: " << (t) << endl;
	system("pause");






}