#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstring>


using namespace std;

void Agregar(ofstream& citas);
void listacitas();
void Modificar(ifstream& Lis);
void Eliminar();
int Vcod(char codigo[10]);
int Vpre(char precio[10]);
int CodigoLocalizado(string auxcod);
bool New(int ubicacion);
bool Vco(char correo[20]);


struct Citas {
	char ID[10];
	char codigo[10];
	char nombre[20];
	char apellido [20];
	char correo[20];
	char hrs[5] , min[5];
	char nt [20];
	int cantr= 0;
	char precio[10];
	double precio_u = 0, Subtotal = 0, t = 0, IVA = 0;

}cita[100];

ofstream archivo;
ifstream Lis;
int numc = 0;
char codigo[10];
char correo[20];
char precio[10];

int main() {

	int operador = 0;


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
		    Agregar(archivo);
			break;
						

		case 2:
			Modificar(Lis);
			break;

		case 3:
		    Eliminar();
			break;

		case 4:
			listacitas();
			break;

		case 5:
			cout << "Limpiar pantalla" << endl;
			system("cls");
			break;

		case 6:
			cout << "Saliendo..." << endl;
			exit(1);


		}

	} while (operador != 6);


		return 0;

}




void Agregar(ofstream &archivo) {

	int longitud = 0, sw;
	bool repite = true, volver = true, recibido = true;
	double precio_u;

	archivo.open("Registro.txt", ios::out |  ios::app);

	cout << "Ingrese cuantas citas desea agendar" << endl;
	cin >> numc;

	for (int i = 1; i < numc + 1; i++) {

		do {
			cout << "Ingrese su codigo de cita" << endl;
			cin >> cita[i].codigo;

			longitud = strlen(cita[i].codigo);
			if (longitud < 6) {

				if (longitud < 5) {
					cout << "Su codigo debe ser de 5 digitos" << "\n";
				}
				else {
					sw = Vcod(cita[i].codigo);
					if (sw == 0) {
						repite = false;
					}
					else {
						cout << "Solo se permiten numeros" << "\n";
					}
				}
			}
			else {
				cout << "Su codigo no debe exceder los 5 digitos" << "\n";
			}

		} while (repite);

		cout << "Ingrese su nombre" << endl;
		cin.ignore();
		cin.getline(cita[i].nombre, 20);
		cout << "Ingrese sus apellidos" << endl;
		cin.getline(cita[i].apellido, 20);

		do {
			cout << "Ingrese su correo" << endl;
			cin >> cita[i].correo;
			longitud = strlen(cita[i].correo);
			if (Vco(cita[i].correo)) {
				
				recibido = false;
			}
			else {
				cout << ("El correo no debe llevar espacios") << endl;
			}
		} while (recibido);

		cout << "Ingrese hora del tratamiento" << endl;
		cin >> cita[i].hrs;
		cout << "Ingrese los minutos" << endl;
		cin >> cita[i].min;
		cout << "Ingrese el nombre del tratamiento" << endl;
		cin.ignore();
		cin.getline(cita[i].nt, 20);

		do {
			cout << "Ingrese el precio unitario" << endl;
			cin >> cita[i].precio;
			longitud = strlen(cita[i].precio);
			if (longitud < 6) {

				sw = Vpre(cita[i].precio);

				if (sw == 0) {
					precio_u = atof(cita[i].precio);
					volver = false;
				}
				else {
					cout << "Solo se permiten numeros" << "\n";
				}
			}
			else {
				cout << "El precio no exceder cantidad los 5 digitos" << endl;
			}

		} while (volver);

		cout << "Cantidad del tratamiento" << endl;
		cin >> cita[i].cantr;


		cita[i].Subtotal = (precio_u * cita[i].cantr);
		cita[i].IVA = cita[i].Subtotal * (0.16);
		cita[i].t = cita[i].Subtotal + cita[i].IVA;

		archivo << i << "ID ,";
		archivo << cita[i].codigo << " ,"; 
		archivo << cita[i].nombre << " ";
		archivo << cita[i].apellido << " ,"; 
		archivo << cita[i].correo << " ,";
		archivo << "Horas " << cita[i].hrs << ": " << cita[i].min << " , ";
		archivo << cita[i].nt << " ,";
		archivo << cita[i].cantr << ", ";
		archivo << cita[i].precio << ", ";
		archivo << cita[i].Subtotal << ", ";
		archivo << cita[i].IVA << ", ";
		archivo << cita[i].t << "\n";

		system("cls");

	}
	
	
	archivo.close();
}

void listacitas() {
	
	cout << "<--------Lista de citas generadas-------->" << endl;
		
	for (int i = 1; i < numc + 1; i++) {

	  cout << i << "Id: " << cita[i].codigo << endl;
	  cout << "Nombre: " << cita[i].nombre << endl;
	  cout << "Apellido ;" << cita[i].apellido << endl;
	  cout << "Correo" << cita[i].correo << endl;
	  cout << "Hora del tratamiento: " << cita[i].hrs << ":" << cita[i].min << endl;
	  cout << "Nombre del tratamiento: " << cita[i].nt << endl;
	  cout << "Cantidad:   " << cita[i].cantr << endl;
	  cout << "Precio unitario:      $" << cita[i].precio << endl;
	  cout << "Subtotal:             $" << cita[i].Subtotal << endl;
	  cout << "Iva 16%              :" << cita[i].IVA << endl;
	  cout << "Total:                $" << cita[i].t << endl;
 	  cout << "-------------------------------------\n" << endl;

	}	
	system("pause");
}
	


void Modificar(ifstream &Lis) {

	char auxcod[10];
	bool encontrado = false;
	int ubicacion = 0;
	

	cout << "Ingrese el ID de la cita" << endl;
	cin.getline(auxcod, 10);

	ubicacion = CodigoLocalizado(auxcod);

	if (ubicacion) {
		if (New(ubicacion)) {

			cout << "Cambio realizado con exito" << endl;
		}

		cout << "Cambios sin exito" << endl;
	}
	system("pause");

}

void Eliminar() {

	int ib = 0;
	cout << "Ingrese el ID de la cita que quiera eliminar" << endl;
	cin >> ib;

	

	cout << "Eliminando cita" << ib + 1 << endl;

	

}

int CodigoLocalizado(string auxcod) {
	struct Citas cita;
	int contador = 0;
	string bufferCod;
	ifstream Lis("Registro.txt");

	Lis.read((char*)&cita, sizeof(cita));

	while (Lis && !Lis.eof()) {

		contador++;
		bufferCod = cita.codigo;
		if (auxcod == bufferCod) {

			cout << "Cita encontrada" << endl;
			return contador;
		}

		Lis.read((char*)&cita, sizeof(cita));

	}
	Lis.close();
	return 0;

}


int Vcod(char codigo[10]) {
	int a = 0,sw=0, j;
	
	j = strlen(codigo);

	while (a < j && sw == 0) {

		if (isdigit(codigo[a]) != 0) {

			a++;

			}
		else{
			
		    sw = 1;
		}

	}
	return sw;	

}

int Vpre(char precio[10]) {
	int a = 0, sw = 0, j;

		j = strlen(precio);

		while (a < j && sw == 0) {

			if (isdigit(precio[a]) != 0) {

				a++;
			}
			else
			{
				sw = 1;
			}

		}
		return sw;
}

bool Vco(char correo[20]) {

	for (int i = 1; i < numc + 1; i++) {

		bool isValid = true;
		int strlength = strlen(correo);
		for (int i = 0; i < strlength; i++) {

			if (correo[i] == ' ') {
				isValid = false;
				i = strlength;
			}
		}
		return isValid;

	}
}
bool New(int ubicacion) {

	bool re = true;
	int longitud = 0;

	try {
		struct Citas cita;
		cin.ignore();

		cout << "Ingrese el nuevo nombre" << endl;
		cin.getline(cita.nombre, 20);

		cout << "Ingrese el nuevo apellido " << endl;
		cin.getline(cita.apellido, 20);

		do {
			cout << "Ingrese su correo" << endl;
			cin.getline(cita.correo, 20);
			longitud = strlen(cita.correo);
			if (Vco(cita.correo)) {

				re= false;
			}
			else {
				cout << ("El correo no debe llevar espacios") << endl;
			}
		} while (re);

		cout << "Ingrese la nueva hora" << endl;
		cin >> cita.hrs;

		cout << "Ingrese los nuevos minutos" << endl;
		cin >> cita.min;

		cout << "Ingrese el nuevo nombre de tratamiento" << endl;
		cin.getline(cita.nt, 20);

		ofstream New("Registro.txt");
		New.seekp((ubicacion - 1) * sizeof(cita), ios::beg);

		New.write((char*)&cita, sizeof(cita));
		New.close();
		return true;

	}
	catch (exception e) {
		cout << "Ha ocurrido un error" << e.what();
		return false;
	}



}
