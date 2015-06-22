#include <pebble.h>

#ifndef INDICATORS_H
  #define INDICATORS_H
    
  GRect batteryPos;
  GRect batteryIconSize;
  int batteryIcons;
  bool batterySubscribe;
  uint32_t batteryResourceId;
  BitmapLayer *s_battery_layer;
  GBitmap *s_battery_bitmap;
  GBitmap *s_battery_subbitmap;
  #ifdef PBL_BW
    uint32_t batteryResourceId2;
    BitmapLayer *s_battery_layer2;
    GBitmap *s_battery_bitmap2;
    GBitmap *s_battery_subbitmap2;
  #endif
  
  GRect bluetoothPos;
  GRect bluetoothIconSize;
  bool bluetoothSubscribe;
  uint32_t bluetoothResourceId;
  BitmapLayer *s_bluetooth_layer;
  GBitmap *s_bluetooth_bitmap;
  GBitmap *s_bluetooth_subbitmap;
  #ifdef PBL_BW
    uint32_t bluetoothResourceId2;
    BitmapLayer *s_bluetooth_layer2;
    GBitmap *s_bluetooth_bitmap2;
    GBitmap *s_bluetooth_subbitmap2;
  #endif
  
  
  void initBatterySettings();
  void initBluetoothSettings();
  void initIndicatorSettings();
  
  GBitmap* getIconFromSheet(const GBitmap * iconSheet, const int xIndex, const int yIndex, const GRect iconSize);
  void swapSubBitmap(GBitmap ** oldBitmapPtr, GBitmap * newBitmap, BitmapLayer * bitmapLayer);
  
  void checkBattery_(BatteryChargeState batState);
  void checkBattery();
  
  void checkBluetooth_(bool connected);
  void checkBluetooth();
  
  void initBatteryIcon(Window *window);
  void deinitBatteryIcon();
  
  void initBluetoothIcon(Window *window);
  void deinitBluetoothIcon();
#endif