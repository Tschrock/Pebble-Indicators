#include <pebble.h>
#include "indicators.h"

static Window *s_main_window;



//
// Window functions
//

static void main_window_load(Window *window) {
  initIndicatorSettings();
  initBatteryIcon(window);
  initBluetoothIcon(window);
}

static void main_window_unload(Window *window) {
  deinitBatteryIcon();
  deinitBluetoothIcon();
}



//
// Main App Setup/Loop
//
  
static void init() {
  s_main_window = window_create();
  
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  window_stack_push(s_main_window, true);
}

static void deinit() {
  window_destroy(s_main_window);
}
  
int main(void) {
  init();
  app_event_loop();
  deinit();
}