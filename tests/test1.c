#include <stdio.h>
#include <stdlib.h>
/*********************************/
#include "../../log/log.c"
/*********************************/
#include "../include/libterm.h"
/*********************************/
#include "../src/libterm.c"
/*********************************/


void test_bool(const char *s){
  fprintf(stderr, "TERM_EVENT_BUFFER_ACTIVATED:%d\n", TERM_EVENT_BUFFER_ACTIVATED);
  fprintf(stderr, "TERM_EVENT_BUFFER_DEACTIVATED:%d\n", TERM_EVENT_BUFFER_DEACTIVATED);
  fprintf(stderr, "TERM_EVENT_BUFFER_PREFLIP:%d\n", TERM_EVENT_BUFFER_PREFLIP);
  log_debug("t1:%d", t1());

  fprintf(stderr, "OK\n");
  tq_start(NULL);
  log_info(AC_RESETALL AC_BLUE "timestamp: %lu" AC_RESETALL, timestamp());
  log_debug("dur:%s", tq_stop(""));
  log_debug("term events qty: %d", term_events_qty());
  int r = -10;

  r = is_valid_term_event_name("TERM_EVENT_PIPE_WRITTEN");
//  r = is_valid_term_event_name("xxxxx");
//  log_debug("is_valid_term_event_name(xxxxx): %d", r);
//  log_debug("is_valid_term_event_name(TERM_EVENT_PIPE_WRITTEN): %d", r);
  log_debug("..........");
}


int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv) {
  test_bool("True");
}
