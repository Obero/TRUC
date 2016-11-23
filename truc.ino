/*
 * Very basic Arduino sketch for TRUC
 * All values are totally arbitrary
 * Have to change it manually according to your measures
 */

// Pins
#define PHOTOR 0
#define LEDRED 5
#define LEDGRE 4
#define LEDBLU 3
#define BUZZER 11

// Color indexes for range tabs
#define RED 0
#define GRE 1
#define BLU 2

// Ranges definition - hand made
//                RED, GRE, BLU

// RED
int red_min[3] = {510, 70 , 140};
int red_max[3] = {570, 100, 170};

// WHITE
int tab_min[3] = {600, 160, 370};
int tab_max[3] = {640, 220, 420};

// BLUE
int blu_min[3] = {200, 40 , 200};
int blu_max[3] = {250, 80 , 250};

// VIOLET
int tpu_min[3] = {210, 30 , 120};
int tpu_max[3] = {260, 80 , 180};

// BLACK
int tbl_min[3] = {130 ,20 , 70};
int tbl_max[3] = {170, 60 , 90};


void setup() {
  // Leds pins init
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDBLU, OUTPUT);
  pinMode(LEDGRE, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  // For debug purposes only
  Serial.begin(9600);
}

void loop() {
  // Make RBG probing
  int red, green, blue = 0;

  digitalWrite(LEDRED, HIGH);
  delay(150);
  red = analogRead(PHOTOR);
  digitalWrite(LEDRED, LOW);

  digitalWrite(LEDGRE, HIGH);
  delay(150);
  green = analogRead(PHOTOR);
  digitalWrite(LEDGRE, LOW);

  digitalWrite(LEDBLU, HIGH);
  delay(150);
  blue = analogRead(PHOTOR);
  digitalWrite(LEDBLU, LOW);

  // Test if white
  if (red >= tab_min[RED] && green >= tab_min[GRE] && blue >= tab_min[BLU])
  {
    if (red <= tab_max[RED] && green <= tab_max[GRE] && blue <= tab_max[BLU])
    {
      tone(BUZZER, 3000, 500);
      Serial.print("red");
    }
  }

  // Test if red
  if (red >= red_min[RED] && green >= red_min[GRE] && blue >= red_min[BLU])
  {
    if (red <= red_max[RED] && green <= red_max[GRE] && blue <= red_max[BLU])
    {
      tone(BUZZER, 1500, 500);
      Serial.print("red");
    }
  }

  // Test if blue
  if (red >= blu_min[RED] && green >= blu_min[GRE] && blue >= blu_min[BLU])
  {
    if (red <= blu_max[RED] && green <= blu_max[GRE] && blue <= blu_max[BLU])
    {
      tone(BUZZER, 2000, 500);
      Serial.print("blue");
    }
  }

  // Test if purple
  if (red >= tpu_min[RED] && green >= tpu_min[GRE] && blue >= tpu_min[BLU])
  {
    if (red <= tpu_max[RED] && green <= tpu_max[GRE] && blue <= tpu_max[BLU])
    {
      tone(BUZZER, 800, 500);
      Serial.print("table - purple");
    }
  }


  // Test if black
  if (red >= tbl_min[RED] && green >= tbl_min[GRE] && blue >= tbl_min[BLU])
  {
    if (red <= tbl_max[RED] && green <= tbl_max[GRE] && blue <= tbl_max[BLU])
    {
      tone(BUZZER, 200, 500);
      Serial.print("table - black");
    }
  }

  // Currently your only way of getting init values
  Serial.print(String(red) + ',' + String(green) + ',' + String(blue) + '\n');

  // Probe and beep every second
  delay(1000);
}
