/*****************************************************
Nom du fichier: musique.h

Auteurs : Lucas Besson
          Charles Blanchard
          Clement Deligeon
          Morad Bahassou
Date de création : 06/02/2018

Modifications : Frederic Rousseau
Dernière modification : 13/05/2018

*************************************************** */
#pragma once
#include <stdint.h>
#include "sys/devices.h"

//#ifndef MUSIC_H
//#define MUSIC_H

#define NB_MAX 100

/* DEFINITION DES NOTES EN FONCTION DE LEUR FREQUENCES */

#define DO 262
#define DO_DIESE 277
#define RE 294
#define RE_DIESE 311
#define MI 330
#define FA 349
#define FA_DIESE 370
#define SOL 392
#define SOL_DIESE 415
#define LA 440
#define LA_DIESE 466
#define SI 494

/*  Mais aussi par habitude */
#define SI_BEMOL 466
#define LA_BEMOL 415
#define MI_BEMOL 311

/* DEFINITION DES TEMPS */

#define RONDE 16
#define BLANCHE 8
#define NOIRE 4
#define DOUBLE_CROCHE 1
#define CROCHE 2
#define CROCHE_POINTE 3
#define BLANCHE_POINTE 12
#define NOIRE_POINTE 6


/* DEFINITION DES TYPES "Note" ET "Melodie" */

typedef struct Note Note;
struct Note{
    uint32_t frequence;         /* Frequence de la note */
    uint32_t duree;             /* Duree de la note (temps) */
};

typedef struct Melodie Melodie;
struct Melodie{
    uint32_t nb_note;           /* Nombre de note de la melodie */
    Note partition[NB_MAX];     /* Tableau contenant les notes */
};

play_note(Note note, double intensity);

