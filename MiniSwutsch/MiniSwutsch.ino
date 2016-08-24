 #include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUMPIXELS 64
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 10;
bool state = false;

void setup(){
  Serial.begin(115200); //Hier evtl. auf 9600 Baud
  pixels.begin();
}

int getByte() {
  while (!Serial.available()) {}
  return Serial.read();
}

void loop() {
  byte r, g, b;
  
  if(getByte()=='1'){
    for(int i=0;i<NUMPIXELS;i++){
    
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(50,50,0)); // Moderately bright green color.
      
      //r = getByte();
      //g = getByte();
      //b = getByte();
      //pixels.setPixelColor(i, pixels.Color(r,g,b)); // serial colors
    
      pixels.show(); // This sends the updated pixel color to the hardware.
      state = true;
      delay(delayval); // Delay for a period of time (in milliseconds).
    }
  } else{
      if(state){
        for(int i=0;i<NUMPIXELS;i++){
        pixels.setPixelColor(i, pixels.Color(0,0,0));
        pixels.show(); // This sends the updated pixel color to the hardware.
        delay(delayval); // Delay for a period of time (in milliseconds).
        }
      state = false;
      }
  }
}
