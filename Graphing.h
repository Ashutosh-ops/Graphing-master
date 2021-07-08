#ifndef Graphing_h
#define Graphing_h
#include "Arduino.h"
#include <cstring>
#include <MCUFRIEND_kbv.h>
#include "TouchScreen.h"
#include "SD.h"
#include <SPI.h>
#include <bits/stdc++.h>

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
/*_______Assigned______*/

/*____Calibrate TFT LCD_____*/
#define TS_MINX 125
#define TS_MINY 85
#define TS_MAXX 965
#define TS_MAXY 905
/*______End of Calibration______*/

/*______Assign names to colors and pressure_______*/
#define WHITE 0x0000  //Black->White
#define YELLOW 0x001F //Blue->Yellow
#define CYAN 0xF800   //Red->Cyan
#define PINK 0x07E0   //Green-> Pink
#define RED 0x07FF    //Cyan -> Red
#define GREEN 0xF81F  //Pink -> Green
#define BLUE 0xFFE0   //Yellow->Blue
#define BLACK 0xFFFF  //White-> Black
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
    char *Format(double , int, int);
    void DrawDial(MCUFRIEND_kbv &, int , int , int , double , double , double , double , double , int , int , unsigned int , unsigned int , unsigned int , char* , bool &);
    void DrawBarChartV(MCUFRIEND_kbv &, double , double , double , double , double , double , double , double , int , int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , char* , bool &);
    void DrawBarChartH(MCUFRIEND_kbv &, double , double , double , double , double , double , double , double , int , int , unsigned int , unsigned int , unsigned int , unsigned int , unsigned int , char* label, bool &);
    uint16_t read16(File&);
    uint32_t read32(File&);
    uint8_t showBMP(char *, int , int);
    ~Graphing();
};

#endif
