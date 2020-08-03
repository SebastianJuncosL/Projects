#include "Capitulo.h"

Capitulo::Capitulo(string nombre, float duracion, string genero, float calificacion, int numCap) : Video(nombre, duracion, genero, calificacion), numeroCapitulo(new int(numCap)) {}

Capitulo::~Capitulo()
{
    // Borramos todos los atributos que se encuentran en heap de la clase Capitulo
    delete numeroCapitulo;
}

string Capitulo::getNombre()
{
    return *nombre;
}

int Capitulo::getNumeroCapitulo()
{
    return *numeroCapitulo;
}

float Capitulo::getCalificacionCapitulo()
{
    return *calificacion;
}