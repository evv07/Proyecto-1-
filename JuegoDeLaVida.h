/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   JuegoDeLaVida.h
 * Author: laura
 *
 * Created on October 13, 2016, 9:06 AM
 */

#ifndef JUEGODELAVIDA_H
#define JUEGODELAVIDA_H
#include <iostream>

class JuegoDeLaVida{
public:
    ///Constructor vacío de JuegoDeLaVida
    JuegoDeLaVida();
    
    ///Constructor de JuegoDeLaVida
    JuegoDeLaVida(int dimensionTab, int** contenidoTab);
    
    ///Desctructor de JuegoDeLaVida
    virtual ~JuegoDeLaVida();
    
    ///Atributos de JuegoDeLaVida
    int dimensionTab;
    int** contenidoTab;
    
    ///Funciones de JuegoDeLaVida
    void Iniciar(JuegoDeLaVida&);
    void Iniciar(JuegoDeLaVida&,int NumGen);
    void Supervivencia(JuegoDeLaVida&,int** contTemporal);
    void Supervivencia(JuegoDeLaVida&,int** contTemporal, int NumGen);
    void Vaciar(JuegoDeLaVida&);
    void Imprimir(const JuegoDeLaVida&);



};


#endif /* JUEGODELAVIDA_H */

