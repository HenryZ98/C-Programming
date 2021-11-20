#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

counts_t * createCounts(void) {
  //WRITE ME
  counts_t * counts = malloc(sizeof(*counts));
  counts->counts = NULL;
  counts->nCounts = 0;
  return counts;
}

one_count_t * createCount(const char * name) {
  one_count_t * answer = malloc(sizeof(*answer));
  if (name != NULL) {
    answer->name = strdup(name);
    assert(strcmp(name, answer->name) == 0);
  }
  else {
    answer->name = NULL;
  }
  answer->count = 1;
  return answer;
}
    
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  for(int i=0; i<c->nCounts; i++) {
    if (name == NULL) {
      if (c->counts[i]->name == NULL) {
	c->counts[i]->count++;
	return;
      }
    }
    else if (c->counts[i]->name != NULL && strcmp(name, c->counts[i]->name) == 0) {
      c->counts[i]->count++;
      return;
    }
  }
  c->nCounts++;
  c->counts = realloc(c->counts, c->nCounts * sizeof(*c->counts));
  c->counts[c->nCounts - 1] = createCount(name);
}
      
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  int unknownIdx = -1;
  for(int i=0; i<c->nCounts; i++) {
    if(c->counts[i]->name == NULL) {
      unknownIdx = i;
    }
    else {
      fprintf(outFile, "%s: %d\n", c->counts[i]->name, c->counts[i]->count);
    }
  }
  if(unknownIdx != -1) {
    fprintf(outFile, "<unknown>: %d\n", c->counts[unknownIdx]->count);
  }
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for(int i=0; i<c->nCounts; i++) {
    free(c->counts[i]->name);
    free(c->counts[i]);
  }
  free(c->counts);
  free(c);
}
