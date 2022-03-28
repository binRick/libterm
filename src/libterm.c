#include "../../list/src/list.c"
#include "../../list/src/list_node.c"
#include "../../stp_print/stp_print.c"
#include "../include/libterm.h"


void get_term_event_names(){
  char **keys = list_keys(terminal_events_list);
}


int term_events_qty(){
  return(terminal_events_list->len);
}


int is_valid_term_event_name(char *n){
  if (LIBTERM_INITIALIZED == -1) {
    libterm_init();
  }
  list_node_t     *node;
  list_iterator_t *it = list_iterator_new(terminal_events_list, LIST_HEAD);
  int             cur = 0;

  while ((node = list_iterator_next(it))) {
    log_debug("key:%s", node->key);
  }

return 0;

  for (int cur = 1; cur <= terminal_events_list->len; cur++) {
      continue;
      log_debug("cur:%d", cur);

      list_node_t *found_item = list_find_key(terminal_events_list, __term_event_names[cur-1]);
      list_node_t *cur_item = list_at(terminal_events_list, cur);
      if(cur_item != NULL){
      TERMINAL_EVENT *cur_event = (cur_item->val);

    log_debug(" - #%d/%d: id:%d|"
            "",
            cur, terminal_events_list->len,
            123
            );
      }
  }

// list_node_t *f = list_find_key(terminal_events_list, n);
// int res = (f != NULL) ? 0 : -1;
  return(1);
  // return res;
}


//char * get_term_event_index_name(int i){


//    list_node_t *found1 = list_find_key(list, ui->name);


//}


void libterm_init(){
  if (LIBTERM_INITIALIZED == 1) {
    return;
  }
  LIBTERM_INITIALIZED = 1;


  terminal_events_list = list_new();

  char **n = __term_event_names;
  int  i   = 0;

  while (((*n) != NULL)) {
    char *cur_name = strdup(__term_event_names[i]);
    TERMINAL_EVENT *te = malloc(sizeof(TERMINAL_EVENT));
    te->id     = i*2;
    te->name   = strdup(cur_name);
    te->desc   = strdup("ok123");
    te->active = i < 5 ? true : false;
    list_node_t *item = list_node_key_new((void*)te, cur_name);
    log_info("adding %s -> %s / %s|active:%d|", cur_name, item->key, 
            ((TERMINAL_EVENT*)(item->val))->name,
            ((TERMINAL_EVENT*)(item->val))->active
            );

    list_rpush(terminal_events_list, item);

    log_debug(AC_GREEN "event #%d:" AC_RESETALL
              " "
              AC_BLUE AC_REVERSED "%s" AC_RESETALL
              "|"
              AC_MAGENTA AC_REVERSED "te->name:%s" AC_RESETALL
              "",
              i + 1, __term_event_names[i], te->name
              );
    free(item);
    i++;
    n++;
  }
  LIBTERM_INITIALIZED = 1;
}


int t1(){
  if (LIBTERM_INITIALIZED == -1) {
    libterm_init();
  }
  return(666);
}
