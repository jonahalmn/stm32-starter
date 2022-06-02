#include "musique.h"
#include "timer.h"

/* INITIALISATION DES MELODIES */

extern const Melodie gamme = { 8, {
    {DO,NOIRE}, {RE,NOIRE}, {MI,NOIRE}, {FA,NOIRE}, {SOL,NOIRE}, {LA,NOIRE}, {SI,NOIRE}, {DO*2,NOIRE}  } };

    
extern const Melodie morceau1 = { 18, {
     {SOL,NOIRE},{SOL,NOIRE},{SOL,NOIRE},{MI_BEMOL,CROCHE_POINTE},{SI_BEMOL,DOUBLE_CROCHE},
     {SOL,NOIRE},{MI_BEMOL,CROCHE_POINTE},{SI_BEMOL,DOUBLE_CROCHE},{SOL,NOIRE_POINTE},
     {RE*2,NOIRE},{RE*2,NOIRE},{RE*2,NOIRE},{MI_BEMOL*2,CROCHE_POINTE},{SI_BEMOL,DOUBLE_CROCHE},
     {FA_DIESE,NOIRE},{MI_BEMOL,CROCHE_POINTE},{SI_BEMOL,DOUBLE_CROCHE},{SOL,NOIRE_POINTE} } };


play_note(Note note, double intensity) {
   set_timer(&TIM2, note.frequence, intensity);
}