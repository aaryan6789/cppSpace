#ifndef _WHEEL_H
#define _WHEEL_H

/**
  * @author Owen Astrachan
  * @version $Id: wheel.h,v 1.2 1998/01/16 14:40:37 ola Exp ola $
  *
  * a Roulette Wheel
  *
  *  convention: 00 --> 37 (numbers are between 0 and 37)
  *  the color and number of the wheel are set
  *  by invoking the function spin()
  *
  * public enum Color has values Wheel::red, Wheel:black, Wheel::green
  * 
  *  Wheel()       -- construct a wheel, initialized to green 00
  *
  *  void spin()   -- spin the wheel and set color and number
  *
  *  int getNumber()         -- return the last spin: 0--37 (37==00)
  *  Wheel::Color getColor() -- return the color (green, black,red)
  */

class Wheel
{
  public:
    enum Color{red,black,green};
    
    Wheel();                  // initialize to green 00

    Color getColor() const;   // return color of last spin
    int getNumber()  const;   // return number of last spin (37 == 00)

    void spin();              // spin the wheel
    
  private:
    Color myColor;            // color from last spin
    int myNumber;             // number from last spin
};

#endif