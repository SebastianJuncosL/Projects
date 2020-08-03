#include <vector>
#include "Capitulo.h"

class Serie
{
private:
    vector<Capitulo *> capitulos; // Vector donde guardamos todos los capítulos
                                  // de una serie, estos capítulos se guardan en heap
    float ratingTotal;            // El rating de la serie se calcula como el promedio de la
                                  // calificación de todos sus capítulos
    string *nombre;               // Tenemos el nombre dde la serie
    string *genero;               // El género de la serie
    friend class Streaming;       // Con esto permitimos que la clase de Streaming pueda
                                  // manejar las funciones de la clase Serie, sin tener que hacer los métodos públicos
    // Las siguientes funciones se explican en el archivo de Serie.cpp
    void updateRating();
    string getNombreSerie();
    void agregarCapitulo(int, string, string, float, float);
    void borrarTodosLosCapitulos();
    void getInfoSerie();
    void listaDeCapitulos();
    string getGenero();

public:
    Serie(string, string);
    ~Serie();
};
