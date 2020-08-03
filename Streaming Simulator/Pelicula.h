#include "Video.h"

#include <string>
using namespace std;
#pragma once

class Pelicula : private Video
{
private:
    string *director; // nombre del director de la pelicula

public:
    Pelicula(string, float, string, float, string);
    ~Pelicula();
    // Las siguientes funciones nos ayudan a regresar todos
    // los atributos heredados de la clase video, mas los atributos de la clase Película.
    string getNombre();
    string getDirector();
    string getGenero();
    float getCalificacion();
    void getInfoPelicula();
};
