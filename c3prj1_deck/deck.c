#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  for(int i = 0; i < hand->n_cards; i++) {
    print_card(*hand->cards[i]);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  card_t * curr = NULL;
  for(int i = 0; i < d->n_cards; i++) {
    curr = d->cards[i];
    if (c.value == curr->value && c.suit == curr->suit) {
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  card_t * swap = NULL;
  int r = 0;
  int cards = d->n_cards;
  for(int i = 0; i < cards; i++) {
    r = rand() % cards;
    swap = d->cards[i];
    d->cards[i] = d->cards[r];
    d->cards[r] = swap;
  }
}

void assert_full_deck(deck_t * d) {
  for(int i = 0; i < d->n_cards; i++) {
    assert(deck_contains(d, card_from_num(i)));
  }
}

void add_card_to(deck_t *deck, card_t c) {
  deck->n_cards++;
  deck->cards = realloc(deck->cards, (deck->n_cards) * sizeof(*(deck->cards)));
  deck->cards[deck->n_cards - 1] = NULL;
  deck->cards[deck->n_cards-1] = realloc(deck->cards[deck->n_cards - 1], sizeof(*(deck->cards[deck->n_cards - 1])));
  deck->cards[deck->n_cards - 1]->suit = c.suit;
  deck->cards[deck->n_cards - 1]->value = c.value;
}

card_t * add_empty_card(deck_t * deck) {
  card_t * temp_c = malloc(sizeof(*temp_c));
  temp_c->suit = 0;
  temp_c->value = 0;
  deck->n_cards++;
  deck->cards = realloc(deck->cards, (deck->n_cards) * sizeof(*(deck->cards)));
  deck->cards[deck->n_cards - 1] = temp_c;
  return temp_c;
}

deck_t * make_deck_exclude(deck_t * excluded_cards) {
  card_t temp_c;
  deck_t * ret_d = malloc(sizeof(*ret_d));
  ret_d->n_cards = 0;
  ret_d->cards = NULL;
  int cond;
  for(unsigned i=0; i<52; i++) {
    temp_c = card_from_num(i);
    cond = deck_contains(excluded_cards, temp_c);
    if(cond == 0) {
      add_card_to(ret_d, temp_c);
    }
  }
  return ret_d;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  deck_t *temp_h;
  deck_t *no_ret_d = malloc(sizeof(*no_ret_d));
  deck_t *ret_d;
  no_ret_d->n_cards = 0;
  no_ret_d->cards = NULL;
  card_t *temp_c;
  for(size_t i=0; i<n_hands; i++) {
    temp_h = hands[i];
    for(size_t j=0; j<temp_h->n_cards; j++) {
      temp_c = temp_h->cards[j];
      if(temp_c->value != 0) {
	if(deck_contains(no_ret_d, *temp_c) == 0) {
	  add_card_to(no_ret_d, *temp_c);
	}
      }
    }
  }
  ret_d = make_deck_exclude(no_ret_d);
  free_deck(no_ret_d);
  return ret_d;
}

void free_deck(deck_t *deck) {
  for(size_t i=0; i<deck->n_cards; i++) {
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}
      
