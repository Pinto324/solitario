//
// Created by branp on 2/03/2024.
//
#include <sstream>
#include "Carta.h"
Carta::Carta(int valor, std::string pre, char color) {
    Prefijo = pre;
    Valor = valor;
    Color = color;
    Ocultar = true;
}
// Método "getter" para el atributo Prefijo
std::string Carta::getPrefijo() const {
    return Prefijo;
}

// Método "getter" para el atributo Valor
int Carta::getValor() const {
    return Valor;
}

// Método "getter" para el atributo Color
char Carta::getColor() const {
    return Color;
}
// Método "getter" para el atributo Ocultar
bool Carta::getOcultar() const {
    return true;
}
//metodo get para buscar todos los datos para imprimir en consola
std::string Carta::getDatos() const{
    std::ostringstream ss;
    if(Ocultar){
        ss <<"  []  ";
    }else{
        if(Valor==11){
            ss <<" "<<"J"<<Prefijo << Color<<" ";
        }else if(Valor==12){
            ss <<" "<<"Q"<<Prefijo << Color<<" ";
        }else if(Valor==13){
            ss <<" "<<"K"<<Prefijo << Color<<" ";
        }else if(Valor==1){
            ss <<" "<<"A"<<Prefijo << Color<<" ";
        }else if(Valor==10){
            ss <<Valor<<Prefijo << Color<<" ";
        }else{
            ss<<" "<< Valor <<Prefijo << Color<<" ";
        }

    }
    return ss.str();
}
//metodos set
void Carta::setOcultar(bool siguiente) {
    Ocultar = siguiente;
}