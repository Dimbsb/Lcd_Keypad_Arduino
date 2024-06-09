
#include <LiquidCrystal.h>
#include <Keypad.h>

const int rs = 13, en = 12, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

bool firstCharEntered = false;
char EnteredKey1 = 0;  
char EnteredKey2 = 0;  


const byte ROWS = 4;
const byte COLS = 3;

char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

byte rowPins[ROWS] = { 7, 6, 5, 4 };
byte colPins[COLS] = { 3, 2, 1 };

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("20..");
  lcd.setCursor(5, 0);
  lcd.print("NAME");
}

void loop() {

  if (!firstCharEntered) {               
   EnteredKey1 = customKeypad.getKey();  

    if (EnteredKey1 && (EnteredKey1 != '*' && EnteredKey1 != '#')) {
      firstCharEntered = true;  
      lcd.setCursor(0, 1);
      lcd.print(EnteredKey1);
    }
  } else {
    EnteredKey2 = customKeypad.getKey();  

    if (EnteredKey2 && (EnteredKey2 != '*' && EnteredKey2 != '#')) {  
      lcd.setCursor(1, 1);                                         
      lcd.print(EnteredKey2);

      int FirstNumber = EnteredKey1 - '0';  
      int SecondNumber = EnteredKey2 - '0';  
      
      lcd.setCursor(4, 1);    
      lcd.print(" ");
      lcd.setCursor(5, 1);
      lcd.print(" ");
      lcd.setCursor(6, 1);
      lcd.print(" ");
      lcd.setCursor(7, 1);
      lcd.print(" ");
      lcd.setCursor(4, 1);
      int TwoDigitsNumber = (FirstNumber*10 + SecondNumber);
      int SquareResult = TwoDigitsNumber * TwoDigitsNumber;
      lcd.print(SquareResult);

      firstCharEntered = false;
      EnteredKey1 = 0;  
      EnteredKey2 = 0;  

      
    }
  }
}
