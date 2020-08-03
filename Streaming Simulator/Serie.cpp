#include "Serie.h"

Serie::Serie(string nombre, string genero) : nombre(new string(nombre)), genero(new string(genero))
{
    // Iniciamos el valor del rating de la serie como 0, ya que al crearla esta no tiene capítulos
    ratingTotal = 0.0;
}

Serie::~Serie()
{
    // Borramos todos los atributos de una serie que se encutran en heap
    delete nombre;
    delete genero;
}

void Serie::updateRating()
{
    // Reiniciamos el rating total para que no se repitan los valores y el rating no sea constante
    ratingTotal = 0.0;
    // Iteramos en todos los capítulos
    for (int i = 0; i < capitulos.size(); i++)
    {
        // Y obteneos la calificación de estos, ls cuales se van acumulando en el rating total de la serie
        ratingTotal += capitulos[i]->getCalificacionCapitulo();
    }
    // Despues de obtener la suma de las calificaciones, lo dividimos entre el número de capítulos para otener
    // la calificacion total de la serie
    ratingTotal = ratingTotal / capitulos.size();
}

string Serie::getNombreSerie()
{
    // Regresamos el nombre de la serie para poder utilizarlo en funciones fuera de la clase
    return *nombre;
}

void Serie::agregarCapitulo(int numCap, string nombre, string genero, float duracion, float calificacion)
{
    // Agregamos capítulos a la serie, pasandole todos los atributos de un video y de un capítulo, para
    // poder crear el capítulo en heap y guardar su direccion en el vector de capítulos
    capitulos.push_back(new Capitulo(nombre, duracion, genero, calificacion, numCap));
}

void Serie::borrarTodosLosCapitulos()
{
    // Creamos un loop que itere dentro del vector que contiene todos los capítulos
    for (int i = 0; i < capitulos.size(); i++)
    {
        // Borramos todos los capítulos con el delete, ya que se encuentran en hepa
        delete capitulos[i];
    }
}

void Serie::getInfoSerie()
{
    // Generamos la parte de arriba de la caja que contiene el nombre de la serie
    // IMPORTANTE: todos los capítulos deben de guardarse en orden numérico, si
    // esto no se hace, al momento de imprimirlos, los capítulos salen desordenados
    for (int i = 0; i < nombre->size(); i++)
    {
        cout << "-";
    }
    cout << "----\n";
    // mostramos el nombre de la serie
    std::cout << "¦ " << *nombre << " ¦" << std::endl;
    // Generamos la parte de abajo de la caja que contene en nombre de la serie
    for (int i = 0; i < nombre->size(); i++)
    {
        cout << "-";
    }
    std::cout << "----" << std::endl;
    // Imprimimos informacion reelevante para el usuario sobre la serie
    std::cout << "Rating: " << ratingTotal << std::endl;
    // Mostramos el número de capítulos que contiene la serie
    std::cout << capitulos.size() << " Capitulos" << std::endl;
}

void Serie::listaDeCapitulos()
{
    std::cout << "Lista de Capitulos de " << *nombre << std::endl;
    // Generamos un loop para poder entrar en los métodos públicos de cada capítulo
    for (int i = 0; i < capitulos.size(); i++)
    {
        // Imprimimos el número y nombre de cada capítulo.
        std::cout << capitulos[i]->getNumeroCapitulo() << ". " << capitulos[i]->getNombre() << std::endl;
    }
}

string Serie::getGenero()
{
    // Regresamos el género de la serie para poder utilizarlo en funciones fuera de la clase
    return *genero;
}