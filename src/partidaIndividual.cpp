/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Integrantes:
 *      Alexis Baladon (5.574.612-4) - alexis.baladon@fing.edu.uy
 *      Guillermo Toyos (5.139.879-9) - guillermo.toyos@fing.edu.uy
 *      Jorge Machado (4.876.616-9) - jorge.machado.ottonelli@fing.edu.uy
 *      Juan Jose Mangado (5.535.227-0) - juan.mangado@fing.edu.uy
 *      Mathias Ramilo (5.665.788-5) - mathias.ramilo@fing.edu.uy
 */

#include <../include/partidaIndividual.h>

PartidaIndividual::PartidaIndividual(DtPartidaIndividual datos) : Partida(DtPartida(datos.getId(), datos.getFecha(),
        datos.getDuracion(), datos.esActiva())) { 
    partidaAnterior = NULL;
}

float PartidaIndividual::getDuracion() { 
    if (this->esActiva()) {
        return this->getDtFechaHora().diffHoras(fechaSistema::fecha);
    } else {
        return duracion;
    }
}

void PartidaIndividual::setPartidaAnterior(PartidaIndividual* pAnt) {
    partidaAnterior = pAnt;
}

PartidaIndividual* PartidaIndividual::getPartidaAnterior() { return partidaAnterior; }

void PartidaIndividual::asignarHoraFinalizacion() {
    this->setDuracion(this->getDtFechaHora().diffHoras(fechaSistema::fecha));
}

PartidaIndividual::~PartidaIndividual() { }
