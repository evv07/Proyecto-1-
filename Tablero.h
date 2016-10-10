/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.h
 * Author: esteban
 *
 * Created on October 7, 2016, 4:23 PM
 */

#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>

class Tablero{
public:
    ///Constructor vacío de Tablero
    Tablero();
    
    ///Constructor de Tablero
    Tablero(int dimension, int** contenido);
    
    ///Desctructor de Tablero
    virtual ~Tablero();
    
    ///Atributos de Tablero
    int dimension;
    int** contenido;
    
    ///Funciones de Tablero
    Tablero* vaciar(const Tablero&);
    Tablero* imprimir(const Tablero&);



};


#endif /* TABLERO_H */

