//
// Created by branp on 5/03/2024.
//

#include "NodoCarta.h"
// Constructor
NodoCarta::NodoCarta(){
     NodoAnterior=nullptr;
     CartaApuntada=nullptr;
     NodoSig=nullptr;
}


// Métodos get

NodoCarta* NodoCarta::getNodoAnterior() const {
    return NodoAnterior;
}

Carta* NodoCarta::getCartaApuntada() const {
    return (CartaApuntada == nullptr) ? nullptr : CartaApuntada;
}

NodoCarta* NodoCarta::getNodoSig() const {
    return NodoSig;
}

// Métodos set

void NodoCarta::setNodoAnterior(NodoCarta* anterior) {
    NodoAnterior = anterior;
}

void NodoCarta::setCartaApuntada(Carta* carta) {
    CartaApuntada = carta;
}

void NodoCarta::setNodoSig(NodoCarta* siguiente) {
    NodoSig = siguiente;
}