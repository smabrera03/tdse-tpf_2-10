Porpuesta #1:
typedef enum {Basto, Copa, Oro, Espada} palot_t
typedef enum {NO_SE_CANTO_T (NSCT), TRUCO, RETRUCO, QV4} truco_t
typedef enum {NO_SE_CANTO_ENV(NSCE), E, EE, RE, FE} envido_t
typedef enum {CJ1, CJ2, NINGUNO} canto_t
typedef enum {TJ1, TJ2} turno_t (turno j1 o turno j2)
typedef enum {MJ1, MJ2} mano_t

typedef struct{
    int valor;
    palo_t palo;
}carta_t


typedef struct{
    carta_t carta1;
    carta_t carta2;
    carta_t carta3;
    int puntos;
}jugador_t

typedef struct{
    int mano = 0; //(0, 1 ó 2) por qué mano vamos
    mano_t mano = MJ1; //(en principio) qué jugador es mano"
    turno_t turno = TJ1; //(en principio) de quién es el siguiente turno
    jugador_t jugador1;
    jugador_t jugador2;

    truco_t truco;
    canto_t canto_truco = ninguno; // (en principio) quién cantó truco (si alguien cantó)

    envido_t envido;
    canto_t canto_envido = ninguno; //(en principio) quién cantó envido (si alguien cantó)"
}ronda_t;

//para cargar la primer carta:
//etapa de validación, digamos que la carta está bien
if(ronda->turno == TJI){
    ronda->jugador1->carta1->palo = 
    ronda->jugador1->carta1->valor = 
    ronda->turno = TJ2;
}else{
    //cargar la carta para el otro jugador
}

//segunda opción: en lugar de tener los 2 jugadores separados ponerlos en una lista

ronda->jugadores[ronda->turno]->carta = //etc

//sin bloque if. Choclazo si me preguntan

//RESOLUCIÓN: priorizamos legibilidad, el bloque if es el que va

//este bloque x6 veces
if(ronda->turno == TJI){
    ronda->jugador1->carta1->palo = 
    ronda->jugador1->carta1->valor = 
}else{
    //cargar la carta para el otro jugador
}

//problema: quiero ir cargando las cartas de forma sucesiva
int cartas_cargadas
if(turno == TJ1){
    if(cartas_cargadas = 0){
        //cargo carta 1
    }
    if(cartas_cargadas = 2){
        //cargo carta 2
    }
    if(cartas_cargadas = 4){
        //cargo carta 2
    }
}//una cagada no

//Si en cambio

typedef struct{
    carta_t cartas[3];
    int mganadas;
    int puntos;
}jugador_t

if(turno == TJ1){
    ronda->jugador1->cartas[mano] = carta_a_cargar;
}

if(turno == TJ2){
    ronda->jugador2->cartas[mano] = carta_a_cargar;
    mano++;
}

//NUEVA PROPUESTA:
typedef enum {Basto, Copa, Oro, Espada} palot_t;
typedef enum {NO_SE_CANTO_T (NSCT), TRUCO, RETRUCO, QV4} truco_t;
typedef enum {NO_SE_CANTO_ENV(NSCE), E, EE, RE, FE} envido_t;
typedef enum {J1, J2} jenum_t;

//borrar esto?
typedef enum {CJ1, CJ2, NINGUNO} canto_t;
typedef enum {TJ1, TJ2} turno_t;// (turno j1 o turno j2)
typedef enum {MJ1, MJ2} mano_t;


typedef struct{
    int valor;
    palo_t palo;
    jenum_t jugador;
}carta_t;

typedef struct{
    int mano = 0; //(0, 1 ó 2) por qué mano vamos
    mano_t mano = MJ1; //(en principio) qué jugador es mano"
    turno_t turno = TJ1; //(en principio) de quién es el siguiente turno
    carta_t cartas[6]; //array con las 6 cartas a jugar
    int cartas_cargadas = 0;
    truco_t truco;
    canto_t canto_truco = ninguno; // (en principio) quién cantó truco (si alguien cantó)

    envido_t envido;
    canto_t canto_envido = ninguno; //(en principio) quién cantó envido (si alguien cantó)"
}ronda_t;

//llega la carta

cartas[cartas_cargadas]->palo = palo;
cartas[cartas_cargadas]->valor = valor;
cartas[cartas_cargadas]->jugador = ronda->turno; //comprimir los 3 enum´s en uno solo
cartas_cargadas++;
if(ronda-turno == J1)
    ronda->turno = J2;
else{
    ronda->turno = J1;
}
switch(cartas_cargadas){
    case 2:
        jenum_t ganador = comparar_cartas(cartas[0], cartas[1]);
        ronda->turno = ganador;
        if(ganador==jugador1){
            jugador1->mganadas++;
        }
        else if(ganador==jugador2){
            jugador2->mganadas++;
        }
        else{
            //fue parda, no sé que hacer
        }
    case 4:
        jenum_t ganador = comparar_cartas(cartas[2], cartas[3]);
        ronda->turno = ganador;
        if(ganador==jugador1){
            jugador1->mganadas++;
        }
        else if(ganador==jugador2){
            jugador2->mganadas++;
        }
        else{
            //fue parda, no sé que hacer
        }
    case 6:
        jenum_t ganador = comparar_cartas(cartas[4], cartas[5]);
        ronda->turno = ganador;
        if(ganador==jugador1){
            jugador1->mganadas++;
        }
        else if(ganador==jugador2){
            jugador2->mganadas++;
        }
        else{
            //fue parda, no sé que hacer
        }
}

//llega otra carta
cartas[cartas_cargadas]->palo = palo;
cartas[cartas_cargadas]->valor = valor;
cartas[cartas_cargadas]->jugador = ronda->turno; //comprimir los 3 enum´s en uno solo
cartas_cargadas++;
if(ronda-turno == J1)
    ronda->turno = J2;
else{
    ronda->turno = J1;
}
cartas_cargadas++;
if(cartas_cargadas == 2){
    jenum_t ganador = comparar_cartas(cartas[0], cartas[1]);
}

