#include <FastLED.h>
#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1015 ads1115;

#define LED_PIN 2
#define NUM_LEDS 59
CRGB leds[NUM_LEDS];

// Gradient palette "snodraegon_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/snodraegon.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.


// Gradient palette "tashangel_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/tashangel.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( snodraegon_gp ) {
  0, 133, 68, 197,
  51,   2,  1, 33,
  101,  50, 35, 130,
  153, 199, 225, 237,
  204,  41, 187, 228,
  255, 133, 68, 197
};

// Gradient palette "trove_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/trove.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 84 bytes of program space.

DEFINE_GRADIENT_PALETTE( trove_gp ) {
  0,  12, 23, 11,
  12,   8, 52, 27,
  25,  32, 142, 64,
  38,  55, 68, 30,
  51, 190, 135, 45,
  63, 201, 175, 59,
  76, 186, 80, 20,
  89, 220, 79, 32,
  101, 184, 33, 14,
  114, 137, 16, 15,
  127, 118, 20, 27,
  140,  79, 16, 35,
  153,  67,  8, 26,
  165,  22,  9, 42,
  178,  11,  3, 34,
  191,  58, 31, 109,
  204, 186, 49, 83,
  216, 182, 25, 55,
  229,  39, 90, 100,
  242,  15, 81, 132,
  255,  68, 135, 52
};

// Gradient palette "bluefly_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/bluefly.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( bluefly_gp ) {
  0,   0,  0,  0,
  63,   0, 39, 64,
  191, 175, 215, 235,
  255,   0,  0,  0
};
// Gradient palette "butterflytalker_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/butterflytalker.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 28 bytes of program space.

DEFINE_GRADIENT_PALETTE( butterflytalker_gp ) {
  0,   1,  1,  6,
  51,   6, 11, 52,
  89, 107, 107, 192,
  127, 101, 161, 192,
  165, 107, 107, 192,
  204,   6, 11, 52,
  255,   0,  0,  0
};
// Gradient palette "daisyfae_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/daisyfae.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( daisyfae_gp ) {
  0,   4,  8,  0,
  86,  74, 91,  1,
  178, 161, 175, 41,
  255, 237, 139,  0
};

// Gradient palette "fairygarden_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/fairygarden.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

// Gradient palette "halloween_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/halloween.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( halloween_gp ) {
  0, 173, 53,  1,
  127,   0,  0,  0,
  191, 173, 53,  1,
  255, 173, 53,  1
};


DEFINE_GRADIENT_PALETTE( fairygarden_gp ) {
  0,  55, 19, 103,
  51,  95, 32, 133,
  101, 167, 44, 162,
  153, 125, 182, 237,
  204,  84, 127, 207,
  255,  19, 40, 114
};

// Gradient palette "girlcat_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/girlcat.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 20 bytes of program space.

DEFINE_GRADIENT_PALETTE( girlcat_gp ) {
  0, 173, 229, 51,
  73, 139, 199, 45,
  140,  46, 176, 37,
  204,   7, 88,  5,
  255,   0, 24,  0
};
// Gradient palette "hangonfatboy_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/hangonfatboy.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 40 bytes of program space.

DEFINE_GRADIENT_PALETTE( hangonfatboy_gp ) {
  0, 215, 74,  6,
  30,  74, 22, 53,
  61,  18,  6, 27,
  96,   5, 36, 85,
  114,   1,  8, 30,
  140,   1,  8, 30,
  158,   5, 36, 85,
  193,  18,  6, 27,
  224,  74, 22, 53,
  255, 215, 74,  6
};
// Gradient palette "lailah1_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/lailah1.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 48 bytes of program space.

DEFINE_GRADIENT_PALETTE( lailah1_gp ) {
  0,  13,  1,  4,
  28,  34,  5, 19,
  56,   1,  1,  3,
  79,   1,  1, 75,
  101,  31, 15,  4,
  127,  80, 43,  7,
  150,   1, 45, 27,
  173,  64, 252, 205,
  196,  20, 23,  2,
  216, 234, 252, 89,
  237,   8,  2,  6,
  255, 175, 70, 88
};
// Gradient palette "liahlah2_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/liahlah2.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 40 bytes of program space.

DEFINE_GRADIENT_PALETTE( liahlah2_gp ) {
  0,  38, 73, 145,
  30,   7, 19, 51,
  56,  73, 40, 230,
  86,  55, 49, 182,
  112,  15, 135, 250,
  140, 125, 122, 212,
  170,  13, 55, 228,
  198, 123, 65, 228,
  229,   7, 19, 51,
  255,  38, 73, 145
};
// Gradient palette "otis_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/otis.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( otis_gp ) {
  0,  26,  1, 89,
  127,  17, 193,  0,
  216,   0, 34, 98,
  255,   0, 34, 98
};

// Gradient palette "purplefly_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/purplefly.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 16 bytes of program space.

DEFINE_GRADIENT_PALETTE( purplefly_gp ) {
  0,   0,  0,  0,
  63, 239,  0, 122,
  191, 252, 255, 78,
  255,   0,  0,  0
};
// Gradient palette "quagga_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/quagga.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 24 bytes of program space.

DEFINE_GRADIENT_PALETTE( quagga_gp ) {
  0,   1,  9, 84,
  40,  42, 24, 72,
  84,   6, 58,  2,
  168,  88, 169, 24,
  211,  42, 24, 72,
  255,   1,  9, 84
};
// Gradient palette "sunlitwave_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/rc/tn/sunlitwave.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( sunlitwave_gp ) {
  0,   5,  9, 84,
  45,  37, 24, 111,
  81,  16,  5, 59,
  112,  24,  1, 20,
  150,  34,  1,  2,
  198, 175, 36,  7,
  237, 208, 104, 16,
  255, 239, 211, 158
};

void setup() {
  Serial.begin(115200);
  ads1115.begin();  // Initialize ads1115

  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, 2, GRB>(leds, NUM_LEDS);//.setCorrection(TypicalLEDStrip);
  //FastLED.setBrightness(127);
}

void loop() {
    int16_t adc0, adc1, adc2, adc3;
 
  adc0 = ads1115.readADC_SingleEnded(0);
  adc1 = ads1115.readADC_SingleEnded(1);
  adc2 = ads1115.readADC_SingleEnded(2);
  adc3 = ads1115.readADC_SingleEnded(3);
  Serial.print("AIN0: "); Serial.println(adc0);
  Serial.print("AIN1: "); Serial.println(adc1);
  Serial.print("AIN2: "); Serial.println(adc2);
  Serial.print("AIN3: "); Serial.println(adc3);
  Serial.println(" ");
  
  // put your main code here, to run repeatedly:
  CRGBPalette16 myPal = otis_gp;

  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* higher = faster motion */

  fill_palette( leds, NUM_LEDS,
                startIndex, 16, /* higher = narrower stripes */
                myPal, 255, LINEARBLEND);

  FastLED.show();
  FastLED.delay(1000 / 240);
}
