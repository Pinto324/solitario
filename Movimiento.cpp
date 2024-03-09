//
// Created by branp on 8/03/2024.
//

#include "Movimiento.h"
Movimiento::Movimiento() : NodoI(nullptr), NodoF(nullptr), NodoSig(nullptr), NodoAnt(nullptr), CartaM(nullptr) {}

// Métodos getter
NodoCarta* Movimiento::getNodoI() const {
    return NodoI;
}

NodoCarta* Movimiento::getNodoF() const {
    return NodoF;
}

Movimiento* Movimiento::getNodoSiguiente() const {
    return NodoSig;
}

Movimiento* Movimiento::getNodoAnterior() const {
    return NodoAnt;
}

Carta* Movimiento::getCartaMovida() const {
    return CartaM;
}

// Métodos setter
void Movimiento::setNodoI(NodoCarta* inicio) {
    NodoI = inicio;
}

void Movimiento::setNodoF(NodoCarta* fin) {
    NodoF = fin;
}

void Movimiento::setNodoSiguiente(Movimiento* sig) {
    NodoSig = sig;
}

void Movimiento::setNodoAnterior(Movimiento* final) {
    NodoAnt = final;
}

void Movimiento::setCartaMovida(Carta* carta) {
    CartaM = carta;
}