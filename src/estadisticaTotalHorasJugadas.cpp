/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/estadisticaTotalHorasJugadas.h"

EstadisticaTotalHorasJugadas::EstadisticaTotalHorasJugadas(string name,string desc):
    Estadistica(name,desc){}

DtEstadistica EstadisticaTotalHorasJugadas::procesarEstadistica(Videojuego * v){
    if(v==nullptr)
	return DtEstadistica(nombre,descripcion,0);
    else
	return DtEstadistica(nombre,descripcion,v->getTotalHorasJugadas());
}

