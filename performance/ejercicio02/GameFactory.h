#pragma once

#include"VideoJuego.h"
#include<iostream>

using namespace std;

class GameFactory
{
protected:
    VideoJuego* v;
    void conception(){ cout << "en concepcion" << endl; }
    void disenio(){ cout << "en disenio" << endl; }
    void planificacion(){ cout << "en planificacion" << endl; }
    void produccion(){ cout << "en produccion" << endl; }
    void pruebasAceptacion(){ cout << "en pruebasAceptacion" << endl; }
public:
    void createGame(VideoJuego*& v, string categoria, VideoJuego::tipo tipo_juego, string nombre, int num_serie)
    {
        // conception();
        // disenio();
        // planificacion();
        // produccion();
        // pruebasAceptacion();
         if(categoria == "Estrategia")
         {
             int number_of_players = 3;
            //  cout << "Number of players" << endl;
            //  cin >> number_of_players;
             v = new Estrategia(nombre, num_serie, tipo_juego, number_of_players);
         }
         if(categoria == "Aventura")
         {
             string rate_category = "a";
            //  cout << "rate category" << endl;
            //  cin >> rate_category;
             v = new Aventura(nombre, num_serie,  tipo_juego, rate_category);
         }
         if(categoria == "Aprendizaje")
         {
             int num_niveles = 4;
            //  cout << "number of levels" << endl;
            //  cin >> num_niveles;
             v = new Aprendizaje(nombre, num_serie, tipo_juego, num_niveles);
         }
    }
};
