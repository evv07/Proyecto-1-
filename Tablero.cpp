/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Tablero.h"
using namespace std;

///Constructor vacío de Tablero
Tablero::Tablero(){
    
}

///Constructor de Tablero
Tablero::Tablero(int dimension, int** contenido){
    this->dimension = dimension;
    this->contenido = contenido;
}

///Destructor de Tablero
Tablero::~Tablero(){
}

Tablero* Tablero::imprimir(const Tablero&){
    for(int i = 0; i < dimension; i++){
        for(int j=0; j< dimension ;j++){
            cout << contenido[i][j] << " ";
            }
            cout << endl;
        }
    }

Tablero* Tablero::vaciar(const Tablero&){
    for(int i = 0; i < dimension; i++){
        for(int j=0; j< dimension ;j++){
            contenido[i][j]=0;
        }
}
}