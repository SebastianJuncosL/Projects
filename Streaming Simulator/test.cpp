#include <string>
#include <iostream>
using namespace std;
#include "Streaming.h"
#include "Admin.h"

int main(int argc, char const *argv[])
{
    Admin *juncos = new Admin("Admin Juncos");
    Streaming *netflix = new Streaming("Netflix");
    // Peliculas:
    juncos->agregarPelicula(netflix, "Kimi No Na Wa", 1.46, "Romance", 4.9, "Makoto Shinkai");
    juncos->agregarPelicula(netflix, "Tenki no Ko", 1.51, "Romance", 4.8, "Makoto Shinkai");
    juncos->agregarPelicula(netflix, "Star Wars", 2.20, "Sci-Fi", 4.0, "George Lucas");
    juncos->agregarPelicula(netflix, "Star Trek", 2.13, "Sci-Fi", 4.2, "J.J Abrams");
    juncos->agregarPelicula(netflix, "The Maze Runner", 1.53, "Sci-Fi", 2.7, "Wes Ball");
    juncos->agregarPelicula(netflix, "Sen to Chihiro no Kamikakushi", 2.05, "Fantasy", 4.9, "Hayao Miyazaki");
    juncos->agregarPelicula(netflix, "Mononoke-hime", 2.14, "Fantasia", 4.9, "Hayao Miyazaki");
    juncos->agregarPelicula(netflix, "Kurenai no buta", 1.42, "Fantasia", 4.2, "Hayao Miyazaki");
    juncos->agregarPelicula(netflix, "Suicide Squad", 2.17, "Accion", 2.4, "David Ayer");
    juncos->agregarPelicula(netflix, "Batman", 2.20, "Accion", 3.5, "Christopher Nolan");

    // Series:
    //    Mirai Nikki:
    juncos->agregarSerie(netflix, "Mirai Nikki", "Romance");
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Sign Up", 1, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Contract Terms", 2, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Initial Failure", 3, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Hand-Written", 4, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Voice Message", 5, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Silent Mode", 6, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Answering Machine", 7, .24, 4.9);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "New Model", 8, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Blocking Calls", 9, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Family Plan", 10, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Service Terminated", 11, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "No Service Area", 12, .24, 4.9);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Number Withheld", 13, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Memory Erased", 14, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Double Holder", 15, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Reapir", 16, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Family Discount", 17, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Crossed Lines", 18, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Clearing Data", 19, .24, 4.9);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Transfer Data", 20, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Security Code", 21, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Disconnect", 22, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Unulfilled Contract", 23, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Searching", 24, .24, 4.9);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Reset", 25, .24, 5);
    juncos->agregarCapitulos(netflix, "Mirai Nikki", "Format", 26, .24, 5);
    //    One Punch:
    juncos->agregarSerie(netflix, "One Punch Man", "Accion");
    juncos->agregarCapitulos(netflix, "One Punch Man", "The Strongest Man", 1, .22, 4.7);
    juncos->agregarCapitulos(netflix, "One Punch Man", "The Lone Cyborg", 2, .22, 4.8);
    juncos->agregarCapitulos(netflix, "One Punch Man", "The Obsessive Scientist", 3, .22, 4.7);
    juncos->agregarCapitulos(netflix, "One Punch Man", "The Modern Ninja", 4, .22, 4.6);
    juncos->agregarCapitulos(netflix, "One Punch Man", "The Ultimate Master", 5, .22, 4);
    juncos->agregarCapitulos(netflix, "One Punch Man", "The Terrifying City", 6, .22, 4.2);
    juncos->agregarCapitulos(netflix, "One Punch Man", "The Ultimate Disciple", 7, .22, 4.9);
    juncos->agregarCapitulos(netflix, "One Punch Man", "The Deep Sea King", 8, .22, 4.7);
    juncos->agregarCapitulos(netflix, "One Punch Man", "Unyielding Justice", 9, .22, 4.4);
    juncos->agregarCapitulos(netflix, "One Punch Man", "Unparalleled Peril", 10, .22, 4.3);
    juncos->agregarCapitulos(netflix, "One Punch Man", "The Dominator of the Universe", 11, .22, 4.5);
    juncos->agregarCapitulos(netflix, "One Punch Man", "The Strongest Hero", 12, .22, 4.9);
    //    Control Z
    juncos->agregarSerie(netflix, "Control Z", "Drama");
    juncos->agregarCapitulos(netflix, "Control Z", "Birthday Girl", 1, .40, 4.7);
    juncos->agregarCapitulos(netflix, "Control Z", "Victims", 2, .40, 4.8);
    juncos->agregarCapitulos(netflix, "Control Z", "Idiots", 3, .40, 4.7);
    juncos->agregarCapitulos(netflix, "Control Z", "Night School", 4, .40, 4.6);
    juncos->agregarCapitulos(netflix, "Control Z", "Face to Face", 5, .40, 4);
    juncos->agregarCapitulos(netflix, "Control Z", "How Well Do You Really Know Javier?", 6, .40, 4.2);
    juncos->agregarCapitulos(netflix, "Control Z", "Control Z", 7, .40, 4.9);
    juncos->agregarCapitulos(netflix, "Control Z", "Public Enemy", 8, .40, 4.7);
    //    BoJack Horseman
    juncos->agregarSerie(netflix, "BoJack Horseman", "Drama");
    juncos->agregarCapitulos(netflix, "BoJack Horseman", "The NoJack Horseman Story", 1, .25, 3.5);
    juncos->agregarCapitulos(netflix, "BoJack Horseman", "BoJack Hates the Troops", 2, .25, 4.8);
    juncos->agregarCapitulos(netflix, "BoJack Horseman", "Prickly-Muffin", 3, .25, 4.7);
    juncos->agregarCapitulos(netflix, "BoJack Horseman", "Zoes and Zeldas", 4, .25, 4.2);
    juncos->agregarCapitulos(netflix, "BoJack Horseman", "Live Fast, Diane Nguyen", 5, .25, 4.7);
    juncos->agregarCapitulos(netflix, "BoJack Horseman", "Our A-Story is a 'D' Story", 6, .25, 5);
    juncos->agregarCapitulos(netflix, "BoJack Horseman", "Say Anything", 7, .25, 4.9);
    juncos->agregarCapitulos(netflix, "BoJack Horseman", "The Telescope", 8, .25, 4.7);
    juncos->agregarCapitulos(netflix, "BoJack Horseman", "Horse Majeure", 9, .25, 4.2);
    juncos->agregarCapitulos(netflix, "BoJack Horseman", "One Trick Pony", 10, .25, 4.8);
    juncos->agregarCapitulos(netflix, "BoJack Horseman", "Downer Ending", 11, .25, 5);
    juncos->agregarCapitulos(netflix, "BoJack Horseman", "Later", 12, .25, 5);

    // Busquedas e informacion:
    netflix->buscarPorNombre("w");
    netflix->getInfoPelicula("Star Wars");
    netflix->buscarPorGenero("drama");
    netflix->getInfoSerie("Mirai Nikki");
    cout << "\n";
    netflix->getCapitulosDeSerie("Mirai Nikki");
    cout << "\n";
    netflix->buscarPorGenero("roman");
    netflix->getInfoPelicula("Tenki no Ko");
    cout << "\n";

    // Borramos todo
    juncos->borrarSerie(netflix, "Mirai Nikki");
    juncos->borrarSerie(netflix, "One Punch Man");
    juncos->borrarSerie(netflix, "Control Z");
    juncos->borrarSerie(netflix, "BoJack Horseman");

    juncos->borrarTodasLasPeliculas(netflix);
    delete netflix;
    delete juncos;

    return 0;
}
