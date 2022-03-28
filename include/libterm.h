#ifndef _LIBTERM_H_
#define _LIBTERM_H_
#include "../../list/src/list.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#undef TRUE
#define TRUE     1
#undef FALSE
#define FALSE    0

typedef struct TERMINAL_EVENT TERMINAL_EVENT;
struct TERMINAL_EVENT {
  int  id;
  char *name;
  bool *active;
  char *desc;
  char *arg_type;
};

TERMINAL_EVENT *terminal_events[] = {
  { 123, "t1" "desc", NULL, true },
  { NULL },
};

list_t         *terminal_events_list;
volatile int   LIBTERM_INITIALIZED = -1;
//*TERMINAL_EVENT get_terminal_events(){

//}

int t1();
void libterm_init();


/*  The callback is invoked by the library, it supplies 3 arguements...
 *  a pointer to the vterm object, the event (an integer id), and
 *  an 'anything' data pointer.  the contents of 'anything' are
 *  dictated by the type of event and described as following:
 *
 *  Event                               void *anything
 *  -----                               --------------
 *  TERM_EVENT_BUFFER_ACTIVATED        index of buffer as int*
 *  TERM_EVENT_BUFFER_DEACTIVATED      index of buffer as int*
 *  TERM_EVENT_BUFFER_PREFLIP          index of new buffer as int*
 *  TERM_EVENT_PIPE_READ               bytes read as ssize_t*
 *  TERM_EVENT_PIPE_WRITTEN            unused
 *  TERM_EVENT_TERM_PRESIZE            unused
 *  TERM_EVENT_TERM_RESIZED            size as struct winsize*
 *  TERM_EVENT_TERM_PRECLEAR           unused
 *  TERM_EVENT_TERM_SCROLLED           direction of scroll as int* (-1 or 1)*/

char *__term_event_names[] = {
  "TERM_EVENT_BUFFER_ACTIVATED",
  "TERM_EVENT_BUFFER_DEACTIVATED",
  "TERM_EVENT_BUFFER_PREFLIP",
  "TERM_EVENT_PIPE_READ",
  "TERM_EVENT_PIPE_WRITTEN",
  "TERM_EVENT_TERM_PRESIZE",
  "TERM_EVENT_TERM_RESIZED",
  "TERM_EVENT_TERM_PRECLEAR",
  "TERM_EVENT_TERM_SCROLLED",
  NULL
};

enum {
  TERM_EVENT_BUFFER_ACTIVATED = 0x10,
  TERM_EVENT_BUFFER_DEACTIVATED,
  TERM_EVENT_BUFFER_PREFLIP,
  TERM_EVENT_PIPE_READ,
  TERM_EVENT_PIPE_WRITTEN,
  TERM_EVENT_TERM_PRESIZE,
  TERM_EVENT_TERM_RESIZED,
  TERM_EVENT_TERM_PRECLEAR,
  TERM_EVENT_TERM_SCROLLED,
};

enum {
  VTERM_BUF_STANDARD = 0x00,            // normal / standard buffer
  VTERM_BUF_ALTERNATE,                  // typically used for lineart progs
  VTERM_BUF_HISTORY                     // the history buffer
};

#endif
