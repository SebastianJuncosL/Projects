#include "Pelicula.h"
#include "Serie.h"
#include <algorithm>
using namespace std;

#pragma once

class Streaming
{
private:
    // Nombre con el que podemos identificar el servicio de streaming en caso de que exista mas de uno
    string *nombre;
    // Estos vectores contienen las películas y series
    vector<Pelicula *> peliculas;
    vector<Serie *> series;
    friend class Admin; // Con esto permitimos que la clase de Admin pueda manejar las funciones de la
                        // clase Serie, sin tener que hacer los métodos públicos
    // Funciones para el manejo de películas, estas funciones serán explicadas en Streaming.cpp
    void agregarPelicula(string, float, string, float, string);
    void quitarPelicula(string);
    void quitarTodasLasPeliculas();
    // Funciones para el manejo de series y capítulos, estas funciones serán explicadas en Streaming.cpp
    void agregarSerie(string, string);
    void agregarCapitulos(string, string, int, float, float);
    void borrarSerie(string);

public:
    Streaming(string);
    ~Streaming();
    // Las siguientes funciones son a las que cualquier usuario puede acceder, estas
    // funciones serán explicadas en Streaming.cpp:
    // Información  sobre series y películas
    void getInfoPelicula(string);
    void getInfoSerie(string);
    void getCapitulosDeSerie(string);
    // Busquedas:
    // Por nombre
    void buscarPorNombre(string);
    // Por genero
    void buscarPorGenero(string);
};
