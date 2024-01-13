// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.3
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"
void ss_Animation( lv_obj_t *TargetObject, int delay);
// SCREEN: ui_Splash
void ui_Splash_screen_init(void);
void ui_event_Splash( lv_event_t * e);
extern lv_obj_t *ui_Splash;
void ui_event_Image2( lv_event_t * e);
extern lv_obj_t *ui_Image2;
extern lv_obj_t *ui_Label2;
// SCREEN: ui_MainScreen
void ui_MainScreen_screen_init(void);
void ui_event_MainScreen( lv_event_t * e);
extern lv_obj_t *ui_MainScreen;
void ui_event_Button2( lv_event_t * e);
extern lv_obj_t *ui_Button2;
extern lv_obj_t *ui_Label12;
extern lv_obj_t *ui_lblDateTime;
extern lv_obj_t *ui_Label17;
extern lv_obj_t *ui_Switch3;
void ui_event_Switch4( lv_event_t * e);
extern lv_obj_t *ui_Switch4;
extern lv_obj_t *ui_Label19;
extern lv_obj_t *ui_Label20;
extern lv_obj_t *ui_rollerActiveSwitchHOME;
extern lv_obj_t *ui_Panel18;
extern lv_obj_t *ui_Panel19;
extern lv_obj_t *ui_Panel20;
extern lv_obj_t *ui_lblTemperature;
extern lv_obj_t *ui_DateTime5;
void ui_event_Panel11( lv_event_t * e);
extern lv_obj_t *ui_Panel11;
extern lv_obj_t *ui_Label13;
void ui_event_Panel12( lv_event_t * e);
extern lv_obj_t *ui_Panel12;
extern lv_obj_t *ui_Label14;
void ui_event_Panel13( lv_event_t * e);
extern lv_obj_t *ui_Panel13;
extern lv_obj_t *ui_Label15;
void ui_event_Panel14( lv_event_t * e);
extern lv_obj_t *ui_Panel14;
extern lv_obj_t *ui_Label16;
// SCREEN: ui_Settings
void ui_Settings_screen_init(void);
void ui_event_Settings( lv_event_t * e);
extern lv_obj_t *ui_Settings;
extern lv_obj_t *ui_TabView1;
extern lv_obj_t *ui_General;
void ui_event_swClockEnabled( lv_event_t * e);
extern lv_obj_t *ui_swClockEnabled;
extern lv_obj_t *ui_Label18;
extern lv_obj_t *ui_Label22;
extern lv_obj_t *ui_rollerWifiList;
void ui_event_txtWifiPassword( lv_event_t * e);
extern lv_obj_t *ui_txtWifiPassword;
extern lv_obj_t *ui_Keyboard2;
extern lv_obj_t *ui_Label23;
void ui_event_Button5( lv_event_t * e);
extern lv_obj_t *ui_Button5;
extern lv_obj_t *ui_Label29;
extern lv_obj_t *ui_Switch_configuration;
extern lv_obj_t *ui_Label24;
extern lv_obj_t *ui_txtSwitchName;
extern lv_obj_t *ui_dropListOfSwitches;
extern lv_obj_t *ui_Label25;
extern lv_obj_t *ui_txtSwitchAddress;
extern lv_obj_t *ui_btnAddSwitch;
extern lv_obj_t *ui_Label28;
extern lv_obj_t *ui_Label26;
extern lv_obj_t *ui_btnRemoveSwitch;
extern lv_obj_t *ui_Label27;
void ui_event_Button6( lv_event_t * e);
extern lv_obj_t *ui_Button6;
extern lv_obj_t *ui_Label30;
extern lv_obj_t *ui_Antenna_Configuration;
extern lv_obj_t *ui_Roller3;
void ui_event_Button7( lv_event_t * e);
extern lv_obj_t *ui_Button7;
extern lv_obj_t *ui_Label31;
extern lv_obj_t *ui_lblAntenna1;
extern lv_obj_t *ui_lblAntenna2;
extern lv_obj_t *ui_lblAntenna3;
extern lv_obj_t *ui_lblAntenna4;
void ui_event_txtAntenaName1( lv_event_t * e);
extern lv_obj_t *ui_txtAntenaName1;
extern lv_obj_t *ui_KeyboardAntenna1;
void ui_event_txtAntenaName2( lv_event_t * e);
extern lv_obj_t *ui_txtAntenaName2;
extern lv_obj_t *ui_KeyboardAntenna2;
void ui_event_txtAntenaName3( lv_event_t * e);
extern lv_obj_t *ui_txtAntenaName3;
extern lv_obj_t *ui_KeyboardAntenna3;
void ui_event_txtAntenaName4( lv_event_t * e);
extern lv_obj_t *ui_txtAntenaName4;
extern lv_obj_t *ui_KeyboardAntenna4;
extern lv_obj_t *ui_lblSwitchSelector;
extern lv_obj_t *ui_Button3;
extern lv_obj_t *ui_Label32;
extern lv_obj_t *ui____initial_actions0;

LV_IMG_DECLARE( ui_img_logo_ei9spc_png);   // assets\logo_ei9spc.png
LV_IMG_DECLARE( ui_img_logo_ei9sp_png);   // assets\logo_ei9sp.png

LV_FONT_DECLARE( ui_font_Font1);
LV_FONT_DECLARE( ui_font_Font2);
LV_FONT_DECLARE( ui_font_Font23);
LV_FONT_DECLARE( ui_font_Font80);
LV_FONT_DECLARE( ui_font_Font801);
LV_FONT_DECLARE( ui_font_LightsOut40);
LV_FONT_DECLARE( ui_font_LightsOut60);
LV_FONT_DECLARE( ui_font_LightsOut80);

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif