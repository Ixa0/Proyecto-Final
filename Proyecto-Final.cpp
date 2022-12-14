//012-22-8613	- Ixyamanik Rodriguez
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
using namespace std;

struct informacion{
	int codigo;
	char nombre [20];
	char apellido [20];
	int telefono;
	float IMCi;
	float IMCa;
	char* tIMCa;
	int edad;
	float altura;
	float peso;
};
typedef informacion ficha;

float IMC(float altura, float peso){
	float resultado;
	resultado = (peso/2.2)/(altura*altura);
	return(resultado);
}

char* estado (float IMC){
	char* resultado = new char[11];
	if (IMC<=18.5){
		strcpy(resultado, "Bajo peso");
	}
		else if(IMC>=18.5 && IMC<=24.99){
			strcpy(resultado, "Peso normal");
		}
			else if(IMC>25.00 && IMC<=30.00){
				strcpy(resultado, "Sobrepeso");
			}
			else if(IMC>30){
				strcpy(resultado, "Obesidad");
			}
	return (resultado);
}

main(){
	int op;
	system("color 70");
	ficha paciente;
	int llave, resultado, i;
	FILE *ptrcf;//puntero
	fstream newfile;
	do{
		system("cls");
		cout<<"Clinica de Nutricion\n\n";
		cout<<" 1. Ingreso de paciente nuevo\n";
		cout<<" 2. Actualizacion de datos\n";
		cout<<" 3. Eliminar Paciente\n";
		cout<<" 4. Reporte General\n";
		cout<<" 5. Consulta Paciente\n";
		cout<<" 6. Salir\n";
		cin>>op;
		switch (op){
			case 1:
				system("cls");
				cout<<"INGRESO DE PACIENTE NUEVO\n\n";
				if ((ptrcf = fopen("clinica.txt", "a+"))==NULL)//a+ es leer, escribir y añadir archivo 
					cout<<"El archivo no pudo abrirse\n";
				else{
					cout<<" - Codigo: "; 
					cin>>paciente.codigo;
					cout<<" - Nombre: ";
					cin>>paciente.nombre;
					cout<<" - Apellido: ";
					cin>>paciente.apellido;
					cout<<" - Telefono: ";
					cin>>paciente.telefono;
					cout<<" - Edad: ";
					cin>>paciente.edad;
					while (paciente.edad<20 || paciente.edad>65){
						cout<<"   La edad no esta en un rango posible (20-65). Intente nuevamente.\n   ";
						cin>>paciente.edad;
					}
					cout<<" - Altura: ";
					cin>>paciente.altura;
					cout<<" - Peso: ";
					cin>>paciente.peso;
					paciente.IMCi=IMC(paciente.altura, paciente.peso);
					paciente.IMCa=paciente.IMCi;
					cout<<" - IMC inicial: "<<paciente.IMCi<<endl;
					paciente.tIMCa=estado(paciente.IMCa);
					cout<<" - Estado de IMC: "<<paciente.tIMCa;
					cout<<"\nPulse Ctrl Z para guardar la informacion en la base de datos.\n";
					if(!feof(stdin)){
						fprintf(ptrcf, "%d %s %s %d %d %.2f %.2f %.2f %.2f %s\n", paciente.codigo, paciente.nombre, paciente.apellido, paciente.telefono, paciente.edad, paciente.altura, paciente.peso, paciente.IMCi, paciente.IMCa, paciente.tIMCa);
						//printf("Ingrese datos o Ctrl Z para finalizar: ");
						scanf("%d %s %s %d %d %.2f %.2f %.2f %.2f %s\n", &paciente.codigo, paciente.nombre, paciente.apellido, &paciente.telefono, &paciente.edad, &paciente.altura, &paciente.peso, &paciente.IMCi, &paciente.IMCa, paciente.tIMCa);
					}//fin if
				fclose(ptrcf);
				}//fin else
			break;
			case 2:
				system("cls");
				cout<<"ACTUALIZACION DE DATOS\n\n";
				cout<<"Ingrese el codigo del paciente: ";
				cin>>llave;
				if ((ptrcf = fopen("clinica.txt", "a+"))==NULL)//a+ es leer, escribir y añadir archivo 
					cout<<"El archivo no pudo abrirse\n";
				else{
				//	while(!feof(ptrcf)){
					if (paciente.codigo == llave){
						printf("%d %s %s %d %d %.2f %.2f %.2f %.2f %s\n", paciente.codigo, paciente.nombre, paciente.apellido, paciente.telefono, paciente.edad, paciente.altura, paciente.peso, paciente.IMCi, paciente.IMCa, paciente.tIMCa);
					}//fin if
					paciente.codigo==paciente.codigo;
					paciente.telefono==paciente.telefono;
					paciente.nombre==paciente.nombre;
					paciente.apellido==paciente.apellido;
					paciente.IMCi==paciente.IMCi;
					cout<<" - Edad: ";
					cin>>paciente.edad;
					cout<<" - Altura: ";
					cin>>paciente.altura;
					cout<<" - Peso: ";
					cin>>paciente.peso;
					paciente.IMCa=IMC(paciente.altura, paciente.peso);
					cout<<" - IMC actual: "<<paciente.IMCa;
					cout<<"\nPulse Ctrl Z para guardar la informacion en la base de datos.\n";
					if(!feof(stdin)){
						fprintf(ptrcf, "%d %s %s %d %d %.2f %.2f %.2f %.2f\n", paciente.codigo, paciente.nombre, paciente.apellido, paciente.telefono, paciente.edad, paciente.altura, paciente.peso, paciente.IMCi, paciente.IMCa);
						//printf("Ingrese datos o Ctrl Z para finalizar: ");
						scanf("%d %s %s %d %d %.2f %.2f %.2f %.2f\n", &paciente.codigo, paciente.nombre, paciente.apellido, &paciente.telefono, &paciente.edad, &paciente.altura, &paciente.peso, &paciente.IMCi, &paciente.IMCa);
					}//fin if
				fclose(ptrcf);
				//	}//fin while
				}//fin else
			break;
			case 3:
			break;
			case 4:
			break;
			case 5:
				system("cls");
				cout<<"CONSULTA DE PACIENTE\n\n";
				cout<<"Ingrese el codigo del paciente a buscar: ";
				cin>>llave;
				if ((ptrcf = fopen("clinica.txt", "r"))==NULL)
					cout<<"El archivo no pudo abrirse\n";
				else if (!feof(ptrcf)){
						if (paciente.codigo == llave){
							cout<<"Codigo - Nombre y Apellido - Telefono - Edad - Altura - Peso - IMC inicial - IMC actual - Estado\n";
							printf("%d - %s - %s - %d - %d - %.2f - %.2f - %.2f - %.2f - %S\n", paciente.codigo, paciente.nombre, paciente.apellido, paciente.telefono, paciente.edad, paciente.altura, paciente.peso, paciente.IMCi, paciente.IMCa, paciente.tIMCa);
							fclose(ptrcf);
						}//fin if
						fscanf(ptrcf, "%d %s %s %d %d %.2f %.2f %.2f %.2f %s\n", &paciente.codigo, paciente.nombre, paciente.apellido, &paciente.telefono, &paciente.edad, &paciente.altura, &paciente.peso, &paciente.IMCi, &paciente.IMCa);
					fclose(ptrcf);
				}//fin if
			break;
		}//fin switch
		cout << "\n\nIngrese un numero para regresar al menu o -6- para salir"<<endl;
		cin >> op;
	}//fin do
	while (op!=6);
	return 0;
}//fin main