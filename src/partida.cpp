/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/partida.h>

Partida::Partida(DtPartida datos) {
    identificador = datos.getId();
    fecha = datos.getFecha();
    duracion = datos.getDuracion();
    activa = datos.getActiva();
    host = NULL;
    videogame = NULL;
}

int Partida::getId() { return identificador; }

DtFechaHora Partida::getDtFechaHora() { return fecha; }

void Partida::setDuracion(float f){duracion=f;}

void Partida::setActiva(bool act) { activa = act; }

bool Partida::esActiva() { return activa; }

void Partida::setHost(Jugador* player) {
    host = player;
}

Jugador* Partida::getHost() { return host; }

void Partida::remove(Jugador* player) { 
    if (player == host)
        host = NULL; 
}

void Partida::setVideojuego(Videojuego* vj) {
    videogame = vj;
}

Videojuego* Partida::getVideojuego() { return videogame; }

void Partida::finalizarPartida() {
    activa = false;
    this->asignarHoraFinalizacion();
}

Partida::~Partida() { }