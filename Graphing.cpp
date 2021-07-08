#include "Graphing.h"
#include "Arduino.h"

Graphing::Graphing(/* args */)
{
  X = Y = k1 = l = 0;
}

Graphing::~Graphing()
{
}

void Graphing::Solid_Border(MCUFRIEND_kbv& tft)
{
  tft.fillRect(0, 0, 480, 5, GREEN);
  tft.fillRect(0, 0, 5, 480, GREEN);
  tft.fillRect(315, 0, 5, 480, GREEN);
  tft.fillRect(0, 475, 320, 5, GREEN);
}
void Graphing::nav_init(MCUFRIEND_kbv& tft)
{
  tft.setRotation(1);
  tft.setCursor(15, 30);
  tft.setTextSize(3);
  tft.setTextColor(RED);
  tft.println("<<");
  tft.setRotation(0);
}

/*___Prints the Interface for the CURRENT and its Graphics____*/
void Graphing::CURRENT_GRAPH(MCUFRIEND_kbv& tft)
{
        peak = 0;
        Serial.println("CURRENT_GRAPH");
        graph_7 = true;
        graph_1 = true;
        tft.fillScreen(WHITE);

        Solid_Border(tft);
        while (1)
        {
          Serial.println("before dial1");
          dial_print(0, 5000, 6,tft);
          Serial.println("after dial1");
          //          tft.setRotation(1);
          //          DrawBarChartV(tft, 80,  290, 30, 260, 0, 50 , 5, bvolts , 4 , 0, RED, YELLOW, BLUE, BLACK, WHITE, "Bits", graph_1);
          //          DrawDial(tft, 350, 120, 110, 0, 50 , 5, 240, volts,  1 , 2, RED, BLACK, WHITE, "Volts", graph_7);
          nav_init(tft);
          tft.setRotation(1);
          tft.setTextColor(BLUE);
          tft.setTextSize(3);
          tft.setCursor(20, 110);
          tft.println("C");
          tft.setCursor(20, 140);
          tft.println("U");
          tft.setCursor(20, 170);
          tft.print("R");
          tft.setCursor(20, 200);
          tft.print("R.");
          tft.setRotation(0);
          //          dial_reload();
          peak_view(peak,tft);
          //          TSPoint p1;
          /*cool it up*/
          X = 0;
          Y = 0;
          click_event();
          /*warm it up*/

          Serial.print(X);
          Serial.print(',');
          Serial.println(Y);

          if (Y > 40 && Y < 110)
          {
            if (X > 201 && X < 254)
            {
              return;
            }
          }
        }
}

/*___Prints the Interface for the 48v and its Graphics____*/
void Graphing::v48_GRAPH(MCUFRIEND_kbv& tft)
{
        peak = 0;
        Serial.println("v48_GRAPH");
        graph_7 = true;
        graph_1 = true;
        tft.fillScreen(WHITE);

        Solid_Border();
        while (1)
        {
          Serial.println("before dial1");
          dial_print(0, 50, 5,tft);
          Serial.println("after dial1");
          //          tft.setRotation(1);
          //          DrawBarChartV(tft, 80,  290, 30, 260, 0, 50 , 5, bvolts , 4 , 0, RED, YELLOW, BLUE, BLACK, WHITE, "Bits", graph_1);
          //          DrawDial(tft, 350, 120, 110, 0, 50 , 5, 240, volts,  1 , 2, RED, BLACK, WHITE, "Volts", graph_7);
          nav_init(tft);
          tft.setRotation(1);
          tft.setTextColor(BLUE);
          tft.setTextSize(3);
          tft.setCursor(20, 110);
          tft.println("48");
          tft.setCursor(20, 140);
          tft.println("v");
          tft.setRotation(0);
          //          dial_reload();
          peak_view(peak,tft);
          //          TSPoint p1;
          /*cool it up*/
          X = 0;
          Y = 0;
          click_event();
          /*warm it up*/

          Serial.print(X);
          Serial.print(',');
          Serial.println(Y);

          if (Y > 40 && Y < 100)
          {
            if (X > 201 && X < 254)
            {
              return;
            }
          }

          if (Y > 220 && Y < 255)
          {
            if (X > 40 && X < 90)
            {
              continue;
            }
          }
        }
}

/*___Prints the Interface for the 24v and its Graphics____*/


void  Graphing::v24_GRAPH(MCUFRIEND_kbv& tft)
{
        peak = 0;
        Serial.println("v24_GRAPH");
        graph_7 = true;
        graph_1 = true;
        tft.fillScreen(WHITE);

        Solid_Border();
        while (1)
        {
          Serial.println("before dial1");
          dial_print(0, 50, 4,tft);
          Serial.println("after dial1");
          //          tft.setRotation(1);
          //          DrawBarChartV(tft, 80,  290, 30, 260, 0, 50 , 5, bvolts , 4 , 0, RED, YELLOW, BLUE, BLACK, WHITE, "Bits", graph_1);
          //          DrawDial(tft, 350, 120, 110, 0, 50 , 5, 240, volts,  1 , 2, RED, BLACK, WHITE, "Volts", graph_7);
          nav_init(tft);
          tft.setRotation(1);
          tft.setTextColor(BLUE);
          tft.setTextSize(3);
          tft.setCursor(20, 110);
          tft.println("24");
          tft.setCursor(20, 140);
          tft.println("v");
          tft.setRotation(0);
          //          dial_reload();
          peak_view(peak,tft);
          //          TSPoint p1;
          /*cool it up*/
          X = 0;
          Y = 0;
          click_event();
          /*warm it up*/

          Serial.print(X);
          Serial.print(',');
          Serial.println(Y);

          if (Y > 40 && Y < 100)
          {
            if (X > 201 && X < 254)
            {
             return;
            }
          }

          if (Y > 220 && Y < 255)
          {
            if (X > 40 && X < 90)
            {
              continue;
            }
          }
        }
}



/*___Prints the Interface for the main and its Graphics____*/
void Graphing::MAIN_GRAPH(MCUFRIEND_kbv& tft)
{
        peak = 0;
        Serial.println("Main");

        graph_7 = true;
        graph_1 = true;
        tft.fillScreen(WHITE);

        Solid_Border(tft);
        while (1)
        {
          Serial.println("before dial1");
          dial_print(0, 50, 1,tft);
          Serial.println("after dial1");
          
          nav_init(tft);    //Displaying navigation key/keys
          tft.setRotation(1);
          tft.setTextColor(BLUE);
          tft.setTextSize(3);
          tft.setCursor(20, 110);
          tft.println("M");
          tft.setCursor(20, 140);
          tft.println("A");
          tft.setCursor(20, 170);
          tft.print("I");
          tft.setCursor(20, 200);
          tft.print("N");
          tft.setRotation(0);
          
          peak_view(peak,tft);
          /*cool it up*/
          X = 0;
          Y = 0;
          click_event();
          
          /*warm it up*/

          Serial.print(X);
          Serial.print(',');
          Serial.println(Y);

          if (Y > 40 && Y < 100)
          {
            if (X > 201 && X < 254)
            {
              return;
            }
          }

          if (Y > 220 && Y < 255)
          {
            if (X > 40 && X < 90)
            {
              continue;
            }
          }
        }
}



/*___Prints the Interface for the JSD1 and its Graphics____*/
void Graphing::JSD1_GRAPH(MCUFRIEND_kbv& tft)
{
        peak = 0;
        Serial.println("JSD1");
        graph_7 = true;
        graph_1 = true;
        tft.fillScreen(WHITE);

        Solid_Border();
        while (1)
        {
          Serial.println("before dial1");
          dial_print(0, 50, 2,tft);
          Serial.println("after dial1");
          //          tft.setRotation(1);
          //          DrawBarChartV(tft, 80,  290, 30, 260, 0, 50 , 5, bvolts , 4 , 0, RED, YELLOW, BLUE, BLACK, WHITE, "Bits", graph_1);
          //          DrawDial(tft, 350, 120, 110, 0, 50 , 5, 240, volts,  1 , 2, RED, BLACK, WHITE, "Volts", graph_7);
          nav_init(tft);
          tft.setRotation(1);
          tft.setTextColor(BLUE);
          tft.setTextSize(3);
          tft.setCursor(20, 110);
          tft.println("J");
          tft.setCursor(20, 140);
          tft.println("S");
          tft.setCursor(20, 170);
          tft.print("D");
          tft.setCursor(20, 200);
          tft.print("1");
          tft.setRotation(0);
          //          dial_reload();
          peak_view(peak,tft);
          //          TSPoint p1;
          /*cool it up*/
          X = 0;
          Y = 0;
          click_event();
          /*warm it up*/

          Serial.print(X);
          Serial.print(',');
          Serial.println(Y);

          if (Y > 40 && Y < 100)
          {
            if (X > 201 && X < 254)
            {
              return;
            }
          }

          if (Y > 220 && Y < 255)
          {
            if (X > 40 && X < 90)
            {
              continue;
            }
          }
        }
}

/*___Prints the Interface for the JSD2 and its Graphics____*/
void Graphing::JSD2_GRAPH(MCUFRIEND_kbv& tft)
{
        peak = 0;
        Serial.println("JSD2");
        graph_7 = true;
        graph_1 = true;
        tft.fillScreen(WHITE);

        Solid_Border(tft);
        while (1)
        {
          Serial.println("before dial1");
          dial_print(0, 50, 3, tft);
          Serial.println("after dial1");
          //          tft.setRotation(1);
          //          DrawBarChartV(tft, 80,  290, 30, 260, 0, 50 , 5, bvolts , 4 , 0, RED, YELLOW, BLUE, BLACK, WHITE, "Bits", graph_1);
          //          DrawDial(tft, 350, 120, 110, 0, 50 , 5, 240, volts,  1 , 2, RED, BLACK, WHITE, "Volts", graph_7);
          nav_init(tft);
          tft.setRotation(1);
          tft.setTextColor(BLUE);
          tft.setTextSize(3);
          tft.setCursor(20, 110);
          tft.println("J");
          tft.setCursor(20, 140);
          tft.println("S");
          tft.setCursor(20, 170);
          tft.print("D");
          tft.setCursor(20, 200);
          tft.print("2");
          tft.setRotation(0);
          //          dial_reload();
          peak_view(peak,tft);
          //          TSPoint p1;
          /*cool it up*/
          X = 0;
          Y = 0;
          click_event();
          /*warm it up*/

          Serial.print(X);
          Serial.print(',');
          Serial.println(Y);

          if (Y > 40 && Y < 100)
          {
            if (X > 201 && X < 254)
            {
              return;
            }
          }

          if (Y > 220 && Y < 255)
          {
            if (X > 40 && X < 90)
            {
              continue;
            }
          }
        }
}

/*___Prints the Help/User Manual____*/
void Graphing::HELP_MANUAL(MCUFRIEND_kbv& tft)
{
      tft.fillScreen(BLACK);
      Solid_Border(tft);
      tft.setTextColor(WHITE);
      tft.setCursor(80, 20);
      tft.setTextSize(3);
      tft.print("PROTECTION");
      tft.setTextColor(GREEN);
      tft.setCursor(20, 50);
      tft.setTextSize(2);
      tft.print("Write some Help manual here...");
      tft.setTextColor(BLUE);
      tft.setCursor(180, 440);
      tft.setTextSize(3);
      tft.print("(:Back ");
      while(1)
      {
        X = 0;
        Y = 0;
        click_event();
            /*warm it up*/
  
        Serial.print(X);
        Serial.print(',');
        Serial.println(Y);
  //      delay(300);
        if(X > 0 && X < 43)
        {
          if (Y > 0 && Y < 143)
          {
            Serial.println("Back: ");
            Serial.print(X);
            Serial.print(" , ");
            Serial.print(Y);
            Serial.println("");
            return;
          }
        }
        else{
          continue;
        }
      }  
}

/****__________Dial printer by serial data-starts__________****/
void Graphing::dial_print(double l, double h, int choice,MCUFRIEND_kbv& tft)
{
  //          volts = main_var();
  double bvolts = 0.0, amps = 0.0;
  double pmvolts;
  tft.setRotation(1);
  switch (choice)
  {
  case 1:
    bvolts = main_var();
    pmvolts = bvolts;
    if (pmvolts < 0)
    {
      pmvolts = 0;
    }
    if (peak < bvolts)
    {
      peak = bvolts;
    }
    DrawDial(tft, 340, 120, 110, l, h, 10, 240, bvolts, 1, 2, BLUE, WHITE, BLACK, "Volts", graph_7);
    DrawBarChartV(tft, 80, 290, 30, 260, l, h, 10, pmvolts, 4, 0, PINK, YELLOW, BLUE, BLACK, WHITE, "Bits", graph_1);
    break;

  case 2:
    bvolts = jsd1();
    pmvolts = bvolts;
    if (pmvolts < 0)
    {
      pmvolts = 0;
    }
    if (peak < bvolts)
    {
      peak = bvolts;
    }
    DrawDial(tft, 340, 120, 110, l, h, 10, 240, bvolts, 1, 2, BLUE, WHITE, BLACK, "Volts", graph_7);
    DrawBarChartV(tft, 80, 290, 30, 260, l, h, 10, pmvolts, 4, 0, PINK, YELLOW, BLUE, BLACK, WHITE, "Bits", graph_1);
    break;

  case 3:
    bvolts = jsd2();
    pmvolts = bvolts;
    if (pmvolts < 0)
    {
      pmvolts = 0;
    }
    if (peak < bvolts)
    {
      peak = bvolts;
    }
    DrawDial(tft, 340, 120, 110, l, h, 10, 240, bvolts, 1, 2, BLUE, WHITE, BLACK, "Volts", graph_7);
    DrawBarChartV(tft, 80, 290, 30, 260, l, h, 10, pmvolts, 4, 0, PINK, YELLOW, BLUE, BLACK, WHITE, "Bits", graph_1);
    break;

  case 4:
    bvolts = v24op();
    pmvolts = bvolts;
    if (pmvolts < 0)
    {
      pmvolts = 0;
    }
    if (peak < bvolts)
    {
      peak = bvolts;
    }
    DrawDial(tft, 340, 120, 110, l, h, 10, 240, bvolts, 1, 2, BLUE, WHITE, BLACK, "Volts", graph_7);
    DrawBarChartV(tft, 80, 290, 30, 260, l, h, 10, pmvolts, 4, 0, PINK, YELLOW, BLUE, BLACK, WHITE, "Bits", graph_1);
    break;

  case 5:
    bvolts = v48op();
    pmvolts = bvolts;
    if (pmvolts < 0)
    {
      pmvolts = 0;
    }
    if (peak < bvolts)
    {
      peak = bvolts;
    }
    DrawDial(tft, 340, 120, 110, l, h, 10, 240, bvolts, 1, 2, BLUE, WHITE, BLACK, "Volts", graph_7);
    DrawBarChartV(tft, 80, 290, 30, 260, l, h, 10, pmvolts, 4, 0, PINK, YELLOW, BLUE, BLACK, WHITE, "Bits", graph_1);
    break;

  case 6:
    amps = current();
    pmvolts = bvolts;
    if (pmvolts < 0)
    {
      pmvolts = 0;
    }
    if (peak < amps)
    {
      peak = amps;
    }
    DrawDial(tft, 340, 120, 110, l, h, 1000, 240, amps, 1, 2, BLUE, WHITE, BLACK, "Amp.", graph_7);
    DrawBarChartV(tft, 80, 290, 30, 260, l, h, 500, amps, 4, 0, PINK, YELLOW, BLUE, BLACK, WHITE, "Bits", graph_1);
    break;

  default:

    break;
  }
  
  pmvolts = bvolts;
  if (pmvolts < 0)
  {
    pmvolts = 0;
  }
  if (peak < bvolts)
  {
    peak = bvolts;
  }
  DrawDial(tft, 340, 120, 110, l, h, 10, 240, bvolts, 1, 2, BLUE, WHITE, BLACK, "Volts", graph_7);
  DrawBarChartV(tft, 80, 290, 30, 260, l, h, 10, pmvolts, 4, 0, PINK, YELLOW, BLUE, BLACK, WHITE, "Bits", graph_1);
}
/****__________Dial printer by serial data-ends__________****/


/*_________peak_view()-starts___________*/
void Graphing::peak_view(double peak,MCUFRIEND_kbv& tft)
{
  tft.setRotation(1);
  tft.setTextSize(2);
  tft.setTextColor(BLACK);
  tft.setCursor(300, 275);
  tft.print("Peak: ");
  tft.fillRect(370, 275, 60, 30, WHITE);
  //  tft.setCursor(320, 275);
  tft.print(peak);
  tft.setRotation(0);
}
/*_______peak_view()-ends__________*/



/*_________Get Touchpoint object reference_________*/
void Graphing::click_event()
{
  tp = ts.getPoint(); //tp.x, tp.y are ADC values
  // if sharing pins, you'll need to fix the directions of the touchscreen pins
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(XP, OUTPUT);
  pinMode(YM, OUTPUT);

  if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE)
  {
    // is controller wiLTORANGE for Landscape ? or are we oriented in Landscape?
    //        if (SwapXY != (Orientation & 1)) SWAP(tp.x, tp.y);
    // scale from 0->1023 to tft.width  i.e. left = 0, rt = width
    // most mcufriend have touch (with icons) that extends below the TFT
    // screens without icons need to reserve a space for "erase"
    // scale the ADC values from ts.getPoint() to screen values e.g. 0-239
    Y = map(tp.x, TS_MINX, TS_MAXX, 0, 320);
    X = map(tp.y, TS_MINY, TS_MAXY, 0, 240);
  }
}

/*____________Get Touchpoint object reference - end_____________*/

TSPoint Graphing::waitTouch()
{
  TSPoint p;
  do
  {
//    Serial.println("TS Point");
    p = ts.getPoint();
    /******************/
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
  } while ((p.z < MINPRESSURE) || (p.z > MAXPRESSURE));
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 320);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 240);
  return p;
}





/*
  This method will draw a vertical bar graph for single input
  it has a rather large arguement list and is as follows
  &d = display object name
  x = position of bar graph (lower left of bar)
  y = position of bar (lower left of bar
  w = width of bar graph
  h =  height of bar graph (does not need to be the same as the max scale)
  loval = lower value of the scale (can be negative)
  hival = upper value of the scale
  inc = scale division between loval and hival
  curval = date to graph (must be between loval and hival)
  dig = format control to set number of digits to display (not includeing the decimal)
  dec = format control to set number of decimals to display (not includeing the decimal)
  barcolor = color of bar graph
  voidcolor = color of bar graph background
  bordercolor = color of the border of the graph
  textcolor = color of the text
  backcolor = color of the bar graph's background
  label = bottom lable text for the graph
  redraw = flag to redraw display only on first pass (to reduce flickering)
*/

void Graphing::DrawBarChartV(MCUFRIEND_kbv &d, double x, double y, double w, double h, double loval, double hival, double inc, double curval, int dig, int dec, unsigned int barcolor, unsigned int voidcolor, unsigned int bordercolor, unsigned int textcolor, unsigned int backcolor, char* label, bool &redraw)
{

  double stepval, range;
  double my, level;
  double i, data;
  
  int addpad = 0;
  char sbuf2[40];
  char sbuf[40];
  char msg_out[3] = " ";
  unsigned slen;
  
  // draw the border, scale, and label once
  // avoid doing this on every update to minimize flicker
  if (redraw == true)
  {
    redraw = false;

    d.drawRect(x - 1, y - h - 1, w + 2, h + 2, bordercolor);
    d.setTextColor(textcolor, backcolor);
    d.setTextSize(2);
    d.setCursor(x, y + 10);
    d.println(label);
    // step val basically scales the hival and low val to the  height
    // deducting a small value to eliminate round off errors
    // this val may need to be adjusted
    stepval = (inc) * (double(h) / (double(hival - loval))) - .001;
    for (i = 0; i <= h; i += stepval)
    {
      my = y - h + i;
      d.drawFastHLine(x + w + 1, my, 5, textcolor);
      // draw lables
      d.setTextSize(1);
      d.setTextColor(textcolor, backcolor);
      d.setCursor(x + w + 12, my - 3);
      data = hival - (i * (inc / stepval));

      
      (dtostrf(data, dec, dig, sbuf));
      slen = (unsigned)strlen(sbuf);
      for (addpad = 1; addpad <= dec + dig - slen; addpad++)
      {
    //    condata = " " + condata;
        strcat(sbuf,msg_out);
      }
      d.println(sbuf);
    }
  }
  // compute level of bar graph that is scaled to the  height and the hi and low vals
  // this is needed to accompdate for +/- range
  level = (h * (((curval - loval) / (hival - loval))));
  // draw the bar graph
  // write a upper and lower bar to minimize flicker cause by blanking out bar and redraw on update
  d.fillRect(x, y - h, w, h - level, voidcolor);
  d.fillRect(x, y - level, w, level, barcolor);
  // write the current value
  d.setTextColor(textcolor, backcolor);
  d.setTextSize(2);
  d.setCursor(x, y - h - 23);

  addpad = 0;
//  char sbuf[40];
//  char msg_out[3] = " ";
  
  (dtostrf(curval, dec, dig, sbuf2));

  slen = (unsigned)strlen(sbuf2);
  for (addpad = 1; addpad <= dec + dig - slen; addpad++)
  {
//    condata = " " + condata;
    strcat(sbuf2,msg_out);
  }
  d.println(sbuf2);
}

/*
  This method will draw a dial-type graph for single input
  it has a rather large arguement list and is as follows
  &d = display object name
  cx = center position of dial
  cy = center position of dial
  r = radius of the dial
  loval = lower value of the scale (can be negative)
  hival = upper value of the scale
  inc = scale division between loval and hival
  sa = sweep angle for the dials scale
  curval = date to graph (must be between loval and hival)
  dig = format control to set number of digits to display (not includeing the decimal)
  dec = format control to set number of decimals to display (not includeing the decimal)
  needlecolor = color of the needle
  dialcolor = color of the dial
  textcolor = color of all text (background is dialcolor)
  label = bottom lable text for the graph
  redraw = flag to redraw display only on first pass (to reduce flickering)
*/

void Graphing::DrawDial(MCUFRIEND_kbv &d, int cx, int cy, int r, double loval, double hival, double inc, double sa, double curval, int dig, int dec, unsigned int needlecolor, unsigned int dialcolor, unsigned int textcolor, char* label, bool &redraw)
{

  double ix, iy, ox, oy, tx, ty, lx, rx, ly, ry, i, offset, stepval, data, angle;
  double degtorad = .0174532778;
  static double px = cx, py = cy, pix = cx, piy = cy, plx = cx, ply = cy, prx = cx, pry = cy;

  // draw the dial only one time--this will minimize flicker
  if (redraw == true)
  {
    redraw = false;
    d.fillCircle(cx, cy, r - 2, dialcolor);
    d.drawCircle(cx, cy, r, needlecolor);
    d.drawCircle(cx, cy, r - 1, needlecolor);
    d.setTextColor(textcolor, dialcolor);
    d.setTextSize(2);
    d.setCursor(cx - 25, cy + 40);
    d.println(label);
  }
  // draw the current value
  d.setTextSize(2);
  d.setTextColor(textcolor, dialcolor);
  d.setCursor(cx - 25, cy + 20);
  d.println(Format(curval, dig, dec));
  // center the scale about the vertical axis--and use this to offset the needle, and scale text
  offset = (270 + sa / 2) * degtorad;
  // find hte scale step value based on the hival low val and the scale sweep angle
  // deducting a small value to eliminate round off errors
  // this val may need to be adjusted
  stepval = (inc) * (double(sa) / (double(hival - loval))) + .00;
  // draw the scale and numbers
  // note draw this each time to repaint where the needle was
  for (i = 0; i <= sa; i += stepval)
  {
    angle = (i * degtorad);
    angle = offset - angle;
    ox = (r - 2) * cos(angle) + cx;
    oy = (r - 2) * sin(angle) + cy;
    ix = (r - 10) * cos(angle) + cx;
    iy = (r - 10) * sin(angle) + cy;
    tx = (r - 30) * cos(angle) + cx;
    ty = (r - 30) * sin(angle) + cy;
    d.drawLine(ox, oy, ix, iy, textcolor);
    d.setTextSize(1.5);
    d.setTextColor(textcolor, dialcolor);
    d.setCursor(tx - 10, ty);
    data = hival - (i * (inc / stepval));
    d.println(Format(data, dig, dec));
  }
  // compute and draw the needle
  angle = (sa * (1 - (((curval - loval) / (hival - loval)))));
  angle = angle * degtorad;
  angle = offset - angle;
  ix = (r - 10) * cos(angle) + cx;
  iy = (r - 10) * sin(angle) + cy;
  // draw a triangle for the needle (compute and store 3 vertiticies)
  lx = 5 * cos(angle - 90 * degtorad) + cx;
  ly = 5 * sin(angle - 90 * degtorad) + cy;
  rx = 5 * cos(angle + 90 * degtorad) + cx;
  ry = 5 * sin(angle + 90 * degtorad) + cy;
  // first draw the previous needle in dial color to hide it
  // note draw performance for triangle is pretty bad...

  //d.fillTriangle (pix, piy, plx, ply, prx, pry, dialcolor);
  //d.fillTriangle (pix, piy, plx, ply, prx, pry, dialcolor);

  //d.fillTriangle (pix, piy, plx, ply, prx - 20, pry - 20, dialcolor);
  //d.fillTriangle (pix, piy, prx, pry, prx + 20, pry + 20, dialcolor);

  d.fillTriangle(pix, piy, plx, ply, prx, pry, dialcolor);
  d.drawTriangle(pix, piy, plx, ply, prx, pry, dialcolor);

  // then draw the old needle in need color to display it
  d.fillTriangle(ix, iy, lx, ly, rx, ry, needlecolor);
  d.drawTriangle(ix, iy, lx, ly, rx, ry, textcolor);

  // draw a cute little dial center
  d.fillCircle(cx, cy, 8, textcolor);
  //save all current to old so the previous dial can be hidden
  pix = ix;
  piy = iy;
  plx = lx;
  ply = ly;
  prx = rx;
  pry = ry;
}

/*
  This method will draw a horizontal bar graph for single input
  it has a rather large arguement list and is as follows
  &d = display object name
  x = position of bar graph (upper left of bar)
  y = position of bar (upper left of bar (add some vale to leave room for label)
  w = width of bar graph (does not need to be the same as the max scale)
  h =  height of bar graph
  loval = lower value of the scale (can be negative)
  hival = upper value of the scale
  inc = scale division between loval and hival
  curval = date to graph (must be between loval and hival)
  dig = format control to set number of digits to display (not includeing the decimal)
  dec = format control to set number of decimals to display (not includeing the decimal)
  barcolor = color of bar graph
  voidcolor = color of bar graph background
  bordercolor = color of the border of the graph
  textcolor = color of the text
  back color = color of the bar graph's background
  label = bottom lable text for the graph
  redraw = flag to redraw display only on first pass (to reduce flickering)
*/

void Graphing::DrawBarChartH(MCUFRIEND_kbv &d, double x, double y, double w, double h, double loval, double hival, double inc, double curval, int dig, int dec, unsigned int barcolor, unsigned int voidcolor, unsigned int bordercolor, unsigned int textcolor, unsigned int backcolor, char* label, bool &redraw)
{
  double stepval, range;
  double mx, level;
  double i, data;

  int addpad = 0;
  char sbuf2[40];
  char sbuf[40];
  char msg_out[3] = " ";
  unsigned slen;

  // draw the border, scale, and label once
  // avoid doing this on every update to minimize flicker
  // draw the border and scale
  if (redraw == true)
  {
    redraw = false;
    d.drawRect(x, y, w, h, bordercolor);
    d.setTextColor(textcolor, backcolor);
    d.setTextSize(2);
    d.setCursor(x, y - 20);
    d.println(label);
    // step val basically scales the hival and low val to the width
    stepval = inc * (double(w) / (double(hival - loval))) - .00001;
    // draw the text
    for (i = 0; i <= w; i += stepval)
    {
      d.drawFastVLine(i + x, y + h + 1, 5, textcolor);
      // draw lables
      d.setTextSize(1);
      d.setTextColor(textcolor, backcolor);
      d.setCursor(i + x, y + h + 10);
      // addling a small value to eliminate round off errors
      // this val may need to be adjusted
      data = (i * (inc / stepval)) + loval + 0.00001;

      (dtostrf(data, dec, dig, sbuf));

      slen = (unsigned)strlen(sbuf);
      for (addpad = 1; addpad <= dec + dig - slen; addpad++)
      {
    //    condata = " " + condata;
        strcat(sbuf,msg_out);
      }
      d.println(sbuf);
    }
  }
  // compute level of bar graph that is scaled to the width and the hi and low vals
  // this is needed to accompdate for +/- range capability
  // draw the bar graph
  // write a upper and lower bar to minimize flicker cause by blanking out bar and redraw on update
  level = (w * (((curval - loval) / (hival - loval))));
  d.fillRect(x + level + 1, y + 1, w - level - 2, h - 2, voidcolor);
  d.fillRect(x + 1, y + 1, level - 1, h - 2, barcolor);
  // write the current value
  d.setTextColor(textcolor, backcolor);
  d.setTextSize(2);
  d.setCursor(x + w + 10, y + 5);
  
  addpad = 0;
//  char sbuf[40];
//  char msg_out[3] = " ";
  
  (dtostrf(curval, dec, dig, sbuf2));

  slen = (unsigned)strlen(sbuf2);
  for (addpad = 1; addpad <= dec + dig - slen; addpad++)
  {
//    condata = " " + condata;
    strcat(sbuf2,msg_out);
  }
  d.println(sbuf2);
}

char *Graphing::Format(double val, int dec, int dig)
{
  int addpad = 0;
  char sbuf[40];
  char msg_out[3] = " ";
  
  (dtostrf(val, dec, dig, sbuf));

  unsigned slen = (unsigned)strlen(sbuf);
  for (addpad = 1; addpad <= dec + dig - slen; addpad++)
  {
//    condata = " " + condata;
    strcat(sbuf,msg_out);
  }
  return (sbuf);
}
/*___________End barV_________*/

/*_______bmpprint function -- starts_________*/


uint16_t Graphing::read16(File& f) {
    uint16_t result;         // read little-endian
    result = f.read();       // LSB
    result |= f.read() << 8; // MSB
    return result;
}

uint32_t Graphing::read32(File& f) {
    uint32_t result;
    result = f.read(); // LSB
    result |= f.read() << 8;
    result |= f.read() << 16;
    result |= f.read() << 24; // MSB
    return result;
}

uint8_t Graphing::showBMP(char* nm, int x, int y)
{
    File bmpFile;
    int bmpWidth, bmpHeight;    // W+H in pixels
    uint8_t bmpDepth;           // Bit depth (currently must be 24, 16, 8, 4, 1)
    uint32_t bmpImageoffset;    // Start of image data in file
    uint32_t rowSize;           // Not always = bmpWidth; may have padding
    uint8_t sdbuffer[3 * BUFFPIXEL];    // pixel in buffer (R+G+B per pixel)
    uint16_t lcdbuffer[(1 << PALETTEDEPTH) + BUFFPIXEL], *palette = NULL;
    uint8_t bitmask, bitshift;
    boolean flip = true;        // BMP is stored bottom-to-top
    int w, h, row, col, lcdbufsiz = (1 << PALETTEDEPTH) + BUFFPIXEL, buffidx;
    uint32_t pos;               // seek position
    boolean is565 = false;      //

    uint16_t bmpID;
    uint16_t n;                 // blocks read
    uint8_t ret;

    if ((x >= tft.width()) || (y >= tft.height()))
        return 1;               // off screen

    bmpFile = SD.open(nm);      // Parse BMP header
    bmpID = read16(bmpFile);    // BMP signature
    (void) read32(bmpFile);     // Read & ignore file size
    (void) read32(bmpFile);     // Read & ignore creator bytes
    bmpImageoffset = read32(bmpFile);       // Start of image data
    (void) read32(bmpFile);     // Read & ignore DIB header size
    bmpWidth = read32(bmpFile);
    bmpHeight = read32(bmpFile);
    n = read16(bmpFile);        // # planes -- must be '1'
    bmpDepth = read16(bmpFile); // bits per pixel
    pos = read32(bmpFile);      // format
    if (bmpID != 0x4D42) ret = 2; // bad ID
    else if (n != 1) ret = 3;   // too many planes
    else if (pos != 0 && pos != 3) ret = 4; // format: 0 = uncompressed, 3 = 565
    else {
        bool first = true;
        is565 = (pos == 3);               // ?already in 16-bit format
        // BMP rows are padded (if needed) to 4-byte boundary
        rowSize = (bmpWidth * bmpDepth / 8 + 3) & ~3;
        if (bmpHeight < 0) {              // If negative, image is in top-down order.
            bmpHeight = -bmpHeight;
            flip = false;
        }

        w = bmpWidth;
        h = bmpHeight;
        if ((x + w) >= tft.width())       // Crop area to be loaded
            w = tft.width() - x;
        if ((y + h) >= tft.height())      //
            h = tft.height() - y;

        if (bmpDepth <= PALETTEDEPTH) {   // these modes have separate palette
            bmpFile.seek(BMPIMAGEOFFSET); //palette is always @ 54
            bitmask = 0xFF;
            if (bmpDepth < 8)
                bitmask >>= bmpDepth;
            bitshift = 8 - bmpDepth;
            n = 1 << bmpDepth;
            lcdbufsiz -= n;
            palette = lcdbuffer + lcdbufsiz;
            for (col = 0; col < n; col++) {
                pos = read32(bmpFile);    //map palette to 5-6-5
                palette[col] = ((pos & 0x0000F8) >> 3) | ((pos & 0x00FC00) >> 5) | ((pos & 0xF80000) >> 8);
            }
        }

        // Set TFT address window to clipped image bounds
        tft.setAddrWindow(x, y, x + w - 1, y + h - 1);
        for (row = 0; row < h; row++) { // For each scanline...
            // Seek to start of scan line.  It might seem labor-
            // intensive to be doing this on every line, but this
            // method covers a lot of gritty details like cropping
            // and scanline padding.  Also, the seek only takes
            // place if the file position actually needs to change
            // (avoids a lot of cluster math in SD library).
            uint8_t r, g, b, *sdptr;
            int lcdidx, lcdleft;
            if (flip)   // Bitmap is stored bottom-to-top order (normal BMP)
                pos = bmpImageoffset + (bmpHeight - 1 - row) * rowSize;
            else        // Bitmap is stored top-to-bottom
                pos = bmpImageoffset + row * rowSize;
            if (bmpFile.position() != pos) { // Need seek?
                bmpFile.seek(pos);
                buffidx = sizeof(sdbuffer); // Force buffer reload
            }

            for (col = 0; col < w; ) {  //pixels in row
                lcdleft = w - col;
                if (lcdleft > lcdbufsiz) lcdleft = lcdbufsiz;
                for (lcdidx = 0; lcdidx < lcdleft; lcdidx++) { // buffer at a time
                    uint16_t color;
                    // Time to read more pixel data?
                    if (buffidx >= sizeof(sdbuffer)) { // Indeed
                        bmpFile.read(sdbuffer, sizeof(sdbuffer));
                        buffidx = 0; // Set index to beginning
                        r = 0;
                    }
                    switch (bmpDepth) {          // Convert pixel from BMP to TFT format
                        case 24:
                            b = sdbuffer[buffidx++];
                            g = sdbuffer[buffidx++];
                            r = sdbuffer[buffidx++];
                            color = tft.color565(r, g, b);
                            break;
                        case 16:
                            b = sdbuffer[buffidx++];
                            r = sdbuffer[buffidx++];
                            if (is565)
                                color = (r << 8) | (b);
                            else
                                color = (r << 9) | ((b & 0xE0) << 1) | (b & 0x1F);
                            break;
                        case 1:
                        case 4:
                        case 8:
                            if (r == 0)
                                b = sdbuffer[buffidx++], r = 8;
                            color = palette[(b >> bitshift) & bitmask];
                            r -= bmpDepth;
                            b <<= bmpDepth;
                            break;
                    }
                    lcdbuffer[lcdidx] = color;

                }
                tft.pushColors(lcdbuffer, lcdidx, first);
                first = false;
                col += lcdidx;
            }           // end cols
        }               // end rows
        tft.setAddrWindow(0, 0, tft.width() - 1, tft.height() - 1); //restore full screen
        ret = 0;        // good render
    }
    bmpFile.close();
    return (ret);
}

/*_______BMP printfunction --ends_______*/

