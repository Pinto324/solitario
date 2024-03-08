//
// Created by branp on 2/03/2024.
//

#include "Manejador.h"
#include "Carta.h"
#include "NodoCarta.h"
#include <cstdlib> // Para la función rand()
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>

Manejador::Manejador() {

};

//en ejecución el primer metodo utilizado, crea los arreglos con las cartas:
void Manejador::InsertarCartas(Carta* Baraja,Carta* Tablero) {
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    int cRepes = 1;
    int cArregloBaraja = 0;
    int cArregloTablero = 0;
    std::string pre = "";
    char color = 'n';
    while (cRepes <= 4) {
        if (cRepes == 1) {
            pre = "E3";
            color = 'n';
        } else if (cRepes == 2) {
            pre = "<>";
            color = 'r';
        } else if (cRepes == 3) {
            pre = "!!";
            color = 'n';
        } else if (cRepes == 4) {
            pre = "<3";
            color = 'r';
        }
        for (int i = 0; i < 13; ++i) {
            double opcion = static_cast<double>(std::rand()) / RAND_MAX;
            if(opcion <= 0.5){
                if(cArregloBaraja!=24){
                    Baraja[cArregloBaraja] = Carta(i+1, pre, color);
                    cArregloBaraja++;
                }else{
                    Tablero[cArregloTablero] = Carta(i+1, pre, color);
                    cArregloTablero++;
                }
            }else{
                if(cArregloTablero!=28){
                    Tablero[cArregloTablero] = Carta(i+1, pre, color);
                    cArregloTablero++;
                }else{
                    Baraja[cArregloBaraja] = Carta(i+1, pre, color);
                    cArregloBaraja++;
                }
            }
        }
        cRepes++;
    }
    //Revolver las cartas:
    std::shuffle(Baraja,Baraja+24,generator);
    std::shuffle(Tablero,Tablero+28,generator);
    bar = Baraja;
    tab = Tablero;
    PonerCartasTablero();
}
//segundo metodo utilizado:
void Manejador::PonerCartasTablero(){
    int EspacioMemoria =0;
    EspacioMemoria = asignarCol(&Col1, 1, EspacioMemoria, tab);
    EspacioMemoria = asignarCol(&Col2, 2, EspacioMemoria, tab);
    EspacioMemoria = asignarCol(&Col3, 3, EspacioMemoria, tab);
    EspacioMemoria = asignarCol(&Col4, 4, EspacioMemoria, tab);
    EspacioMemoria = asignarCol(&Col5, 5, EspacioMemoria, tab);
    EspacioMemoria = asignarCol(&Col6, 6, EspacioMemoria, tab);
    asignarCol(&Col7, 7, EspacioMemoria, tab);
    AsignarCola(&Cola1, bar);
    IniciarJuego();
}
//tercer metodo principal
void Manejador::IniciarJuego(){
    int opcion;
    bool Sigue = true;
    std::cout << "-------------------------------Bienvenido a Solitario---------------------" << std::endl;
    while (Sigue){
        ImprimirPantalla();
        std::cout << "1) cambiar carta del top" << std::endl;
        std::cout << "2) Mover alguna carta" << std::endl;
        std::cout << "3) Suicidarse :)" << std::endl;
        std::cout << "4) Adelantar Movimiento" << std::endl;
        std::cout << "5) Finalizar juego" << std::endl;
        std::cout << "Que desea hacer?";
        std::cin >> opcion;
        Jugar(opcion);
    }
}
//cuarto metodo principal
void Manejador::Jugar(int Opcion){
    switch (Opcion) {
        case 1:
            if(Cola1.getNodoSig() == nullptr){
                Cola1 = Cola2;
                Cola2 = *new NodoCarta();
            }else{
                if(Cola2.getCartaApuntada() == nullptr){
                    Cola2.setCartaApuntada(Cola1.getCartaApuntada());
                }else{
                    NodoCarta *Nuevo = new NodoCarta();;
                    Nuevo->setCartaApuntada(Cola1.getCartaApuntada());
                    AgregarNodo(RecorrerNodo(&Cola2),Nuevo);
                }
                Cola1 = *Cola1.getNodoSig();
            }
            break;
        case 2:
            int casilla;
            std::cout << "Escriba el numero de casilla donde se encuentra la carta";
            std::cin >> casilla;
            break;
        case 3:
            break;
        default:

            break;
    }
}
//metodo auxiliar del tercer principal para imprimir pantalla
void Manejador::ImprimirPantalla(){
    std::cout << "   1                      2     3     4     5" << std::endl;
    NodoCarta *Mc1 = &Col1, *Mc2 = &Col2, *Mc3 = &Col3, *Mc4 = &Col4, *Mc5 = &Col5, *Mc6 = &Col6, *Mc7 = &Col7;
    bool Sigue = true;

    std::cout <<Cola1.getCartaApuntada()->getDatos()<<" | |                "
            << (RecorrerNodo(&Ganar1)->getCartaApuntada() ? RecorrerNodo(&Ganar1)->getCartaApuntada()->getDatos() : "| |") << "   "
            << (RecorrerNodo(&Ganar2)->getCartaApuntada() ? RecorrerNodo(&Ganar2)->getCartaApuntada()->getDatos() : "| |") << "   "
            << (RecorrerNodo(&Ganar3)->getCartaApuntada() ? RecorrerNodo(&Ganar3)->getCartaApuntada()->getDatos() : "| |") << "   "
            << (RecorrerNodo(&Ganar4)->getCartaApuntada() ? RecorrerNodo(&Ganar4)->getCartaApuntada()->getDatos() : "| |") << std::endl;
    std::cout<<std::endl;
    while(Sigue){
        std::cout << (Mc1 && Mc1->getCartaApuntada() ? Mc1->getCartaApuntada()->getDatos() : "  ") << "     "
                  << (Mc2 && Mc2->getCartaApuntada() ? Mc2->getCartaApuntada()->getDatos() : "  ") << "     "
                  << (Mc3 && Mc3->getCartaApuntada() ? Mc3->getCartaApuntada()->getDatos() : "  ") << "     "
                  << (Mc4 && Mc4->getCartaApuntada() ? Mc4->getCartaApuntada()->getDatos() : "  ") << "     "
                  << (Mc5 && Mc5->getCartaApuntada() ? Mc5->getCartaApuntada()->getDatos() : "  ") << "     "
                  << (Mc6 && Mc6->getCartaApuntada() ? Mc6->getCartaApuntada()->getDatos() : "  ") << "     "
                  << (Mc7 && Mc7->getCartaApuntada() ? Mc7->getCartaApuntada()->getDatos() : "  ") << std::endl;

        if(Mc1 == nullptr && Mc2 == nullptr && Mc3 == nullptr&&Mc4 == nullptr&&Mc5 == nullptr&&Mc6 == nullptr&& Mc7 == nullptr){
            Sigue = false;
        }else{
            if(Mc1 != nullptr){
                Mc1 = Mc1->getNodoSig();
            }
            if(Mc2 != nullptr){
                Mc2 = Mc2->getNodoSig();
            }
            if(Mc3 != nullptr){
                Mc3 = Mc3->getNodoSig();
            }
            if(Mc4 != nullptr){
                Mc4 = Mc4->getNodoSig();
            }
            if(Mc5 != nullptr){
                Mc5 = Mc5->getNodoSig();
            }
            if(Mc6 != nullptr){
                Mc6 = Mc6->getNodoSig();
            }
            if(Mc7 != nullptr){
                Mc7 = Mc7->getNodoSig();
            }
        }
    }
    std::cout << " 6        7       8     9      10     11     12" << std::endl;
}
//metodo de apoyo del segundo metodo principal encargado de Asignar cola
void Manejador::AsignarCola(NodoCarta* Centinela, Carta* tab){
    for (int i = 0; i < 24; ++i) {
        if(i == 0){
            tab[i].setOcultar(false);
            Centinela->setCartaApuntada(&tab[i]);
        }else{
            NodoCarta* nuevo = new NodoCarta();
            tab[i].setOcultar(false);
            nuevo->setCartaApuntada(&tab[i]);
            NodoCarta* Final = RecorrerNodo(Centinela);
            AgregarNodo(Final,nuevo);
        }
    }
}

//metodo de apoyo del segundo metodo principal
int Manejador::asignarCol(NodoCarta* Centinela, int repes, int contador, Carta* tab){
    for (int i = 0; i < repes; ++i) {
        if(repes == 1){
            tab[contador].setOcultar(false);
            Centinela->setCartaApuntada(&tab[contador]);
        }else{
            if(i==0){
                Centinela->setCartaApuntada(&tab[contador]);
            }else{
                if(i==repes-1){tab[contador].setOcultar(false);}
                NodoCarta* nuevo = new NodoCarta();;
                nuevo->setCartaApuntada(&tab[contador]);
                NodoCarta* Final = RecorrerNodo(Centinela);
                AgregarNodoDoble(Final,nuevo);
            }
        }
        contador++;
    }
    return contador;
}

//metodos de apoyo para el manejo de los nodos
void Manejador::AgregarNodoDoble(NodoCarta* temp, NodoCarta* Nuevo){
    temp->setNodoSig(Nuevo);
    Nuevo->setNodoAnterior(temp);
}
void Manejador::AgregarNodo(NodoCarta* temp, NodoCarta* Nuevo){
    temp->setNodoSig(Nuevo);
}
NodoCarta* Manejador::RecorrerNodo(NodoCarta* Centinela){

    while (Centinela->getNodoSig() != nullptr) {
        Centinela = Centinela->getNodoSig();
    }

    return Centinela;
}

void Manejador::RecorrerNodoImprimiendo(NodoCarta* Centinela){
    int i = 1;
    while (Centinela->getNodoSig() != nullptr) {
        Carta *a = Centinela->getCartaApuntada();
        Centinela = Centinela->getNodoSig();
        std::cout << "Cartas en fila[" << i << "]: " << a->getValor()<< " | " << a->getPrefijo() << std::endl;
        i++;
    }
    Carta *a = Centinela->getCartaApuntada();
    std::cout << "Cartas en fila[" << i << "]: " << a->getValor()<< " | " << a->getPrefijo() << std::endl;
}
