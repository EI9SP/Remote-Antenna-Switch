SET(SOURCES ui_Splash.c
    ui_MainScreen.c
    ui_Settings.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_events.cpp
    ui_img_logo_ei9spc_png.c
    ui_img_logo_ei9sp_png.c
    fonts/ui_font_Font1.c
    fonts/ui_font_Font2.c
    fonts/ui_font_Font23.c
    fonts/ui_font_Font80.c
    fonts/ui_font_Font801.c
    fonts/ui_font_LightsOut40.c
    fonts/ui_font_LightsOut60.c
    fonts/ui_font_LightsOut80.c)

add_library(ui ${SOURCES})
