//
// Created by branp on 5/03/2024.
//

#ifndef SOLITARIO_NODOCARTA_H
#define SOLITARIO_NODOCARTA_H
#include "Carta.h"

class NodoCarta {
private:
    NodoCarta* NodoAnterior;
    Carta* CartaApuntada;
    NodoCarta* NodoSig;
public:
    // Constructor
    NodoCarta();
    // Métodos "getter"
    NodoCarta* getNodoAnterior() const;
    Carta* getCartaApuntada() const;
    NodoCarta* getNodoSig() const;

    // Métodos "setter"
    void setNodoAnterior(NodoCarta* anterior);
    void setCartaApuntada(Carta* carta);
    void setNodoSig(NodoCarta* siguiente);
};


#endif //SOLITARIO_NODOCARTA_H
