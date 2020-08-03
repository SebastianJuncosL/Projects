#include <string>
#include <iostream>

using namespace std;
#pragma once

class Video
{
protected:
    string *nombre;      // Nombre de los videos
    float *duracion;     // Duracion del video
    string *genero;      // Genero del video
    float *calificacion; // Calificacion del video

public:
    Video(string, float, string, float);
    ~Video();
};