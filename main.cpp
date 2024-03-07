#include <iostream>
#include "Carta.h"
#include "Manejador.h"

#include <random>    // Para std::default_random_engine y std::uniform_int_distribution
#include <chrono>
int main() {
    Carta* Baraja = new Carta[24];
    Carta* Tablero = new Carta[28];
    Manejador Mj;
    Mj.InsertarCartas(Baraja,Tablero);
    // Liberar memoria de los arreglos
    delete[] Baraja;
    delete[] Tablero;
    return 0;
}
