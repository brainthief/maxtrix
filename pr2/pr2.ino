#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
byte _FLPArray123749899[8];
Max72xxPanel _max7219BusP112 = Max72xxPanel(12, 1, 1);
bool  _max7219BusP112_needUpdate = 1;
byte _gtv1 = 255;
bool _max4219b2_needUpdateDisp = 0;
byte _max4219b2_oldValueArraySingle[8];
void setup()
{
_max7219BusP112.shutdown( false);
_max7219BusP112.setIntensity(8);
}
void loop()
{




//Плата:1
for (int i=0; i<8; i++) {if ( ! (_FLPArray123749899[i] ==_max4219b2_oldValueArraySingle[i])){_max4219b2_oldValueArraySingle[i] = _FLPArray123749899[1]; 
_max4219b2_needUpdateDisp = 1;}}
if (_max7219BusP112_needUpdate) {
 _max7219PaintArray(_FLPArray123749899, 0, _max7219BusP112);
}
_FLPArray123749899[0] = (map((_gtv1), (0), (1023), (0), (255)));




if (_max7219BusP112_needUpdate) {_max7219BusP112.write(); 
_max7219BusP112_needUpdate = 0;} else {_max7219BusP112_needUpdate = (_max4219b2_needUpdateDisp);
_max4219b2_needUpdateDisp = 0;
}
}

void _max7219PaintArray(byte data[8], byte device,  Max72xxPanel bus)
{
  for (byte x = 0; x <= 7; x++)
  {
    for (byte y = 0; y <= 7; y++) {
      bus.drawPixel(((device * 8) + x), y, bitRead(data[x], y));
    }
  }

}
