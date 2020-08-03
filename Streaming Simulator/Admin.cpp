#include "Admin.h"

Admin::Admin(string nombre) : Persona(nombre) {}

Admin::~Admin()
{
}

void Admin::agregarPelicula(Streaming *servicio, string nombrePelicula, float duracion, string genero, float calificacion, string director)
{
    servicio->agregarPelicula(nombrePelicula, duracion, genero, calificacion, director);
}

void Admin::agregarSerie(Streaming *servicio, string nombre, string genero)
{
    servicio->agregarSerie(nombre, genero);
}

void Admin::agregarCapitulos(Streaming *servicio, string nombreSerie, string nombreCapitulo, int numCap, float duracion, float calificacion)
{
    servicio->agregarCapitulos(nombreSerie, nombreCapitulo, numCap, duracion, calificacion);
}

void Admin::borrarSerie(Streaming* servicio, string nombre)
{
    servicio->borrarSerie(nombre);
}

void Admin::borrarPelicula(Streaming* servicio, string nombre)
{
    servicio->quitarPelicula(nombre);
}

void Admin::borrarTodasLasPeliculas(Streaming*servicio)
{
    servicio->quitarTodasLasPeliculas();
}