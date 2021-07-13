#ifndef Graphing_h
#define Graphing_h
#include "Arduino.h"
// #include <cstring>
#include "string.h"
#include <MCUFRIEND_kbv.h>
#include "TouchScreen.h"
#include "SD.h"
#include <SPI.h>
// #include <bits/stdc++.h>

/*______Define LCD pins (I have asigned the default values)_______*/
#define YP A1 // must be an analog pin, use "An" notation!
#define XM A2 // must be an analog pin, use "An" notation!
#define YM 7  // can be a digital pin
#define XP 6  // can be a digital pin

/*For mega*/
#define LCD_CS A4
#define LCD_CD A3
#define LCD_WR A2
#define LCD_RD A1
#define LCD_RESET A5
/*_______End of defanitions______*/

#define MINPRESSURE 10
#define MAXPRESSURE 1000
#define SWAP(a, b) {uint16_t tmp = a; a = b; b = tmp;}
#define gain 20
#define BMPIMAGEOFFSET 100
#define PALETTEDEPTH   8
#define BUFFPIXEL 20
/*_______Assigned______*/

/*____Calibrate TFT LCD_____*/
#define TS_MINX 125
#define TS_MINY 85
#define TS_MAXX 965
#define TS_MAXY 905
/*______End of Calibration______*/

/*______Assign names to colors and pressure_______*/
#define WHITE 0xFFFF  //Black->White
#define YELLOW 0xFFE0 //Blue->Yellow
#define CYAN 0x07FF   //Red->Cyan 
#define PINK 0xF81F   //Green-> Pink
#define RED 0xF800    //Cyan -> Red
#define GREEN 0x07E0  //Pink -> Green 
#define BLUE 0x001F   //Yellow->Blue 
#define BLACK 0x0000  //White-> Black
#define PURPLE 0x4A49
#define LTPURPLE 0x8200

/*________ENDS OF CALIBRATION CONFIGURATION_________*/

class Graphing
{
private:
    /* data */
protected:
    int X, Y, l, k1 = 0;                               //Stores the touch co-ordinates
    TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300); //300 is the sensitivity
    TSPoint tp;
    float refer = 4.789;
    float vdff  = 0.0;
    double peak = 0;
    bool graph_1 = true;
    bool graph_2 = true;
    bool graph_3 = true;
    bool graph_4 = true;
    bool graph_5 = true;
    bool graph_6 = true;
    bool graph_7 = true;

public:
    Graphing(/* args */);
    void Solid_Border(MCUFRIEND_kbv &);
    void nav_init(MCUFRIEND_kbv &);
    void CURRENT_GRAPH(MCUFRIEND_kbv &);
    void v48_GRAPH(MCUFRIEND_kbv &);
    void v24_GRAPH(MCUFRIEND_kbv &);
    void JSD1_GRAPH(MCUFRIEND_kbv &);
    void JSD2_GRAPH(MCUFRIEND_kbv &);
    void MAIN_GRAPH(MCUFRIEND_kbv &);
    void HELP_MANUAL(MCUFRIEND_kbv&);
    void dial_print(double , double , int ,MCUFRIEND_kbv&);
    void peak_view(double ,MCUFRIEND_kbv&);
    void click_event();
    TSPoint waitTouch();
    void Format(double , int, int, MCUFRIEND_kbv&);
    void DrawDial(MCUFRIEND_kbv &, int , int , int , double , double , double , double , double , int , int , unsigned int , unsigned int , unsigned int , char* , bool &);
    void DrawBarChartV(MCUFRIEND_kbv &, double , double , double , double , double , double , double , double , int , int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , char* , bool &);
    void DrawBarChartH(MCUFRIEND_kbv &, double , double , double , double , double , double , double , double , int , int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , char* label, bool &);
    uint16_t read16(File&);
    uint32_t read32(File&);
    uint8_t showBMP(char *, int , int, MCUFRIEND_kbv&);
    float main_var();
    float jsd1();
    float jsd2();
    float v24op();
    float v48op();
    float current();
    ~Graphing();
};

#endif

