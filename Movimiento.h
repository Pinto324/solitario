//
// Created by branp on 8/03/2024.
//

#ifndef SOLITARIO_MOVIMIENTO_H
#define SOLITARIO_MOVIMIENTO_H


#include "NodoCarta.h"

class Movimiento {
    private:
    NodoCarta *NodoI,*NodoF;
    Movimiento *NodoSig, *NodoAnt;
    Carta* CartaM;
public:
    Movimiento();
    Movimiento(NodoCarta* inicio, NodoCarta* fin, NodoCarta* sig, NodoCarta* final, Carta* carta);

    // Métodos getter
    NodoCarta *getNodoI() const;
    NodoCarta* getNodoF() const;
    Movimiento* getNodoSiguiente() const;
    Movimiento* getNodoAnterior() const;
    Carta* getCartaMovida() const;

    // Métodos setter
    void setNodoI(NodoCarta* inicio);
    void setNodoF(NodoCarta* fin);
    void setNodoSiguiente(Movimiento* sig);
    void setNodoAnterior(Movimiento* final);
    void setCartaMovida(Carta* carta);


};


#endif //SOLITARIO_MOVIMIENTO_H
