//
// Created by branp on 2/03/2024.
//

#ifndef SOLITARIO_MANEJADOR_H
#define SOLITARIO_MANEJADOR_H
#include "Carta.h"
#include "NodoCarta.h"
#include "Movimiento.h"

class Manejador {
    private:
        Carta* bar;
        Carta* tab;
        NodoCarta Col1, Col2, Col3, Col4, Col5, Col6, Col7, Cola1, Cola2, Ganar1, Ganar2, Ganar3, Ganar4;
        Movimiento Mov;
    public:
        Manejador();
        void InsertarCartas(Carta*,Carta*);
        void PonerCartasTablero();
        int asignarCol(NodoCarta* carta, int i, int memoria, Carta *pCarta);
        void RecorrerNodoImprimiendo(NodoCarta*);

    NodoCarta *RecorrerNodo(NodoCarta *pCarta);

    void AgregarNodo(NodoCarta *pCarta, NodoCarta *pCarta1);
    void AgregarNodoDoble(NodoCarta *pCarta, NodoCarta *pCarta1);
    void AsignarCola(NodoCarta *Centinela, Carta *tab);

    void IniciarJuego();

    void ImprimirPantalla();

    void Jugar(int Opcion);

    bool movimientoLegal();

    NodoCarta * obtenerNodo(int numero);
    Carta * obtenerCartaNodo(int numero);
    std::string movimientoLegal(int inicio, int final);

    void EliminarNodoDoble(NodoCarta *Eliminado);

    void limpiarPantalla();

    NodoCarta RecorrerNodoU(NodoCarta Centinela);

    NodoCarta GuardadorDeCambio(int numero);

    bool ComprobarVictory();

    void AgregarNodoDobleMov(Movimiento *temp, Movimiento *Nuevo);

    Movimiento *RecorrerNodoMov(Movimiento *Centinela);

    NodoCarta *obtenerNodoMov(int numero);

    void VerCartas(int casilla, int repes);
};


#endif //SOLITARIO_MANEJADOR_H
