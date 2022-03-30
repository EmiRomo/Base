#include <iostream>
#include <string>

using namespace std;

struct Datos {
	string nombre, nt, descripcion;
	int hrs;
	int precio_ut = 0, precio_u = 0, t = 0, costo = 0;


}Citas [3];

int main() {

	int operador = 0, opcion = 0,i = 0;


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

			while (i < 3) {

				cout << "Ingrese su nombre" << endl;
				cin >> Citas[i].nombre;
				cout << "Ingrese hora del tratamiento" << endl;
				cin >> Citas[i].hrs;
				cout << "Ingrese el nombre del tratamiento" << endl;
				cin >> Citas[i].nt;
				cout << "Ingrese la descripcion del tratamiento" << endl;
				cin >> Citas[i].descripcion;
				cout << "Ingrese el precio unitario del tratamiento" << endl;
				cin >> Citas[i].precio_ut;
				cout << "Cantidad del tratamiento" << endl;
				cin >> Citas[i].costo;
				cout << "Ingrese el precio unitario" << endl;
				cin >> Citas[i].precio_u;

				Citas[i].t = (Citas[i].precio_ut * Citas[i].costo) + Citas[i].precio_u;

				system("cls");

				i++;
        	}
			cout << "Limite de citas alcanzado" << endl;
			system("pause");
			
			

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
			for (int i = 0; i < 3; i++) {

				cout << "ID" << i << endl;
				cout << "Nombre: " << Citas[i].nombre << endl;
				cout << "Hora del tratamiento " << Citas[i].hrs << endl;
				cout << "Nombre del tratamiento: " << Citas[i].nt << endl;
				cout << "Descripcion del tratamiento: " << Citas[i].descripcion << endl;
				cout << "Precio del tratamiento: $" << Citas[i].precio_ut << endl;
				cout << "Cantidad del tratamiento: " << Citas[i].costo << endl;
				cout << "Precio unitario: $" << Citas[i].precio_u << endl;
				cout << "Su total a pagar es: $" << Citas[i].t << endl;
				cout << "_______________________" << endl;

			} 

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






	} while (operador != 6);


		return 0;



}

