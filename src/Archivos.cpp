/**
	Nombres(s): Altamirnao Leal Jose ALfonso
	Nombres(s): Vázquez Jiménez Juan Manuel

	
*/

#include "Archivos.h"
char palabras[10];
ofstream archivo;
fstream archivoEntrada;
ifstream leerarchivo;
string nombre;
string renglon;
/**
creamos archivo
@params void
@result bool
*/
bool Archivos::Crea(){
	
	cout << "Dime el nombre del archivo: ";
    cin>>nombre;
    archivoEntrada.open(nombre.c_str(),ios::in);
    if(archivoEntrada.is_open()){
    	cout<<"Ya existe un archivo con ese nombre"<< endl;
        archivoEntrada.close();
        return false;
    }else{
   	 	archivo.open(nombre);
   		if(archivo.is_open()){
			archivo.close();
			cout <<"El archivo se creo con exito"<< endl;
			return true;
		}	
    }

}
/**
leemos archivo
@params void
@result bool
*/
bool Archivos::Leer(){
 
    cout << "Dime el nombre del archivo: ";
 	cin>>nombre;
    archivoEntrada.open(nombre.c_str(),ios::in);
    if (archivoEntrada.is_open()){
        while (! archivoEntrada.eof()){
            getline (archivoEntrada,renglon);
            cout<<renglon;
        }
        archivoEntrada.close();
        return true;
    }
    else cout << "archivo inexistente" << endl;  
    return false;

}
/**
editamos archivo
@params void
@result bool
*/
bool Archivos::Edita(){
	if(Leer()){	
		
		cin>>renglon;
    	archivo.open(nombre.c_str(),ios::app);
    	archivo<<renglon<< endl;
		archivo.close();
		return true;
	}else{
		return false;
	}
}
/**
Eliminamos archivo
@params void
@result bool
*/
bool Archivos::Elimina(){

    cout << "Dime el nombre del archivo: ";
    cin>>nombre;
    archivoEntrada.open(nombre.c_str(),ios::in);
    if (archivoEntrada.is_open()){
    	int aux=nombre.size();
		char Nombre[100];
		for (int a=0;a<=aux;a++){
            Nombre[a]=nombre[a];
        }
        remove(Nombre);
 		cout << "archivo Eliminado" << endl;
        return true;
    }
    else cout << "archivo inexistente" << endl;  
    return false;
}
/**
menu para las opciones del programa
@params void
@result void
*/
void Archivos::Menu(){
	int i=7;
	while(i){
	cout << "preciona 1 para crear un archivo" << endl;
	cout << "preciona 2 para editar un archivo" << endl;
	cout << "preciona 3 para imprimir un archivo" << endl; 
	cout << "preciona 4 eliminar un archivo" << endl; 
	cout << "preciona 5 parasalir " << endl;
	cin>>i;  
	if(i==1){
	Crea();	
	}if(i==2){
	Edita();
	}if(i==3){
	Leer();	
	}if(i==4){
	Elimina();	
	}if(i==5){
	i=0;
	}	
	}
	
}

