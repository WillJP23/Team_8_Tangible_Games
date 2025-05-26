// C++ code
//
  const int buttonPin1 = 1;
  const int buttonPin2 = 0;
  const int ledPin = 5;

void setup()
{
  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);
}
  //put outside loop?
  bool r1 = false; 
  bool r2 = false; 
  bool r3 = false; 
  bool r4 = false; 
  bool r5 = false; 
  bool r6 = false; 
  bool r7 = false; 
  bool r8 = false; 
  bool r9 = false; 
  //green
  bool g1 = false;
  bool g2 = false;
  bool g3 = false;
  bool g4 = false;
  bool g5 = false;
  bool g6 = false;
  bool g7 = false;
  bool g8 = false;
  bool g9 = false;
  bool pos1 = false;
  bool pos2 = false;
  bool pos3 = false; 
  bool pos4 = false; 
  bool pos5 = false; 
  bool pos6 = false; 
  bool pos7 = false; 
  bool pos8 = false; 
  bool pos9 = false; 
  bool greenred = false;
  //variables for tracking greenred posisitions, used for calculating winner
  bool redwin = false;
  bool greenwin = false;
  bool message = false;
  int gwins = 0;
  int rwins = 0;
  char pos = 0;
  int button1_State = 0;
  int button2_State = 0;
  int count_value =0;
  int prestate =0;

void loop()
{
  //sequence determining if a winner is here
  //Green Win Conditions
  // - Horizontals
  if ((g1 == true) && (g2 == true) && (g3 == true)) {
    greenwin = true;
  }
  if ((g4 == true) && (g5 == true) && (g6 == true)){
    greenwin = true;
  }
  if ((g7 == true) && (g8 == true) && (g9 == true)) {
    greenwin = true;
  }
  // - Verticals
  if ((g1 == true) && (g4 == true) && (g7 == true)) {
    greenwin = true;
  }
  if ((g2 == true) && (g5 == true) && (g8 == true)) {
    greenwin = true;
  }
  if ((g3 == true) && (g6 == true) && (g9 == true)) {
    greenwin = true;
  }
  // - Diagonals
  if ((g1 == true) && (g5 == true) && (g9 == true)) {
    greenwin = true;
  }
  if ((g3 == true) && (g5 == true) && (g7 == true)) {
    greenwin = true;
  }
  //Red Win Conditions
  if ((r1 == true) && (r2 == true) && (r3 == true)) {
    redwin = true;
  }
  if ((r4 == true) && (r5 == true) && (r6 == true)) {
    redwin = true;
  }
  if ((r7 == true) && (r8 == true) && (r9 == true)) {
    redwin = true;
  }
  if ((r1 == true) && (r4 == true) && (r7 == true)) {
    redwin = true;
  }
  if ((r2 == true) && (r5 == true) && (r8 == true)) {
    redwin = true;
  }
  if ((r3 == true) && (r6 == true) && (r9 == true)) {
    redwin = true;
  }
  if ((r1 == true) && (r5 == true) && (r9 == true)) {
    redwin = true;
  }
  if ((r3 == true) && (r5 == true) && (r7 == true)) {
    redwin = true;
  }

  //winner script
  if (greenwin == true) {
    Serial.println ("Winner: Green Player\n");
    gwins++;
    Serial.print ("Green Win Total: ");
    Serial.println (gwins);
    Serial.print ("Red Win Total: ");
    Serial.println (rwins);
    //need to add other positions after
    digitalWrite(12, HIGH);
  }
  if (redwin == true) {
    Serial.println ("Winner: Red Player\n");
    rwins++;
    Serial.print ("Green Win Total: ");
    Serial.println (gwins);
    Serial.print ("Red Win Total: ");
    Serial.println (rwins);
    //need to add other positions after
    digitalWrite(13, HIGH);
  }

  //Outputs Current Player to Console, greenred false means current player is red
  if ((greenred == false) && (message == false)) {
    Serial.println ("Current Player: Red");
    message = true;
  } 
  if ((greenred == true) && (message == false)) {
    Serial.println ("Current Player: Green");
    message = true;
  }

  //computer input code below - replaced by button
  if (Serial.available() > 0) {
    Serial.println ("Please Select a Valid Square");
    pos = Serial.read();
    Serial.println(pos);
  }
  //determines which square is chosen
  //greenred true = green
  if ((pos == '1') && (r1 == false) && (g1 == false)) {
    if ((greenred == false) && (g1 == false)) {
    digitalWrite(11, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = true;
    r1 = true;
    }
    if ((greenred == true) && (r1 == false)) {
    digitalWrite(12, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = false;
    g1 = true;
    }
    message = false;
    pos1 = false;
  }
  else if ((pos == '2') && (r2 == false) && (g2 == false)) {
    if ((greenred == false) && (g2 == false)) {
    digitalWrite(9, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = true;
    r2 = true;
    }
    if ((greenred == true) && (r2 == false)) {
    digitalWrite(8, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = false;
    g2 = true;
    }
    message = false;
    pos2 = false;
  }
  else if ((pos == '3') && (r3 == false) && (g3 == false)) {
    if ((greenred == false) && (g3 == false)) {
    digitalWrite(10, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = true;
    r3 = true;
    }
    if ((greenred == true) && (r3 == false)) {
    digitalWrite(13, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = false;
    g3 = true;
    }
    message = false;
    pos3 = false;
  }
  else if ((pos == '4') && (r4 == false) && (g4 == false)) {
    if ((greenred == false) && (g4 == false)) {
    digitalWrite(5, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = true;
    r4 = true;
    }
    if ((greenred == true) && (r4 == false)) {
    digitalWrite(7, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = false;
    g4 = true;
    }
    message = false;
    pos4 = false;
  }
  else if ((pos == '5') && (r5 == false) && (g5 == false)) {
    if ((greenred == false) && (g5 == false)) {
    digitalWrite(3, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = true;
    r5 = true;
    }
    if ((greenred == true) && (r5 == false)) {
    digitalWrite(2, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = false;
    g5 = true;
    }
    message = false;
    pos5 = false;
  }
  else if ((pos == '6') && (r6 == false) && (g6 == false)) {
    if ((greenred == false) && (g6 == false)) {
    digitalWrite(4, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = true;
    r6 = true;
    }
    if ((greenred == true) && (r6 == false)) {
    digitalWrite(6, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = false;
    g6 = true;
    }
    message = false;
    pos6 = false;
  }
  else if ((pos == '7') && (r7 == false) && (g7 == false)) {
    if ((greenred == false) && (g7 == false)) {
    digitalWrite(A0, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = true;
    r7 = true;
    }
    if ((greenred == true) && (r7 == false)) {
    digitalWrite(A2, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = false;
    g7 = true;
    }
    message = false;
    pos7 = false;
  }
  else if ((pos == '8') && (r8 == false) && (g8 == false)) {
    if ((greenred == false) && (g8 == false)) {
    digitalWrite(A1, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = true;
    r8 = true;
    }
    if ((greenred == true) && (r8 == false)) {
    digitalWrite(A3, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = false;
    g8 = true;
    }
    message = false;
    pos8 = false;
  }
  else if ((pos == '9') && (r9 == false) && (g9 == false)) {
    if ((greenred == false) && (g9 == false)) {
    digitalWrite(A4, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = true;
    r9 = true;
    }
    if ((greenred == true) && (r9 == false)) {
    digitalWrite(A5, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = false;
    g9 = true;
    }
    message = false;

    pos9 = false;
  }
}