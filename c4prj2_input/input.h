#ifndef INPUT_H
#define INPUT_H
#include <stdio.h>
#include "deck.h"
#include "future.h"

size_t strToInt(char *str);
void lineToStr(char *line);
int getLastIdx(const char *str, int fstIdx);
deck_t * hand_from_string(const char * str, future_cards_t * fc);
deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc);

#endif
