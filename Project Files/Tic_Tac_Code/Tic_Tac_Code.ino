// C++ code
//
  //const int buttonPin1 = 2, buttonPin2 = 3;
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
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  //pinMode(buttonPin1, INPUT);
  //pinMode(buttonPin2, INPUT);
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
  int pos = 0;
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
  if ((greenwin == true)) {
    Serial.println ("Winner: Green Player\n");
    gwins++;
    Serial.print ("Green Win Total: ");
    Serial.println (gwins);
    Serial.print ("Red Win Total: ");
    Serial.println (rwins);
    //need to add other positions after
    redwin =  false;
  }
  if ((redwin == true)) {
    Serial.println ("Winner: Red Player\n");
    rwins++;
    Serial.print ("Green Win Total: ");
    Serial.println (gwins);
    Serial.print ("Red Win Total: ");
    Serial.println (rwins);
    //need to add other positions after
    greenwin = false;
  }

  //Outputs Current Player to Console, greenred false means current player is red
  if ((greenred == false) && (message == false) && (pos == 0)) {
    Serial.println (count_value);
    Serial.println (pos);
    Serial.println ("Current Player: Red");
    message = true;
  } 
  if ((greenred == true) && (message == false) && (pos == 0)) {
    Serial.println (count_value);
    Serial.println (pos);
    Serial.println ("Current Player: Green");
    message = true;
  }
  //computer input code below - replaced by button
  //if (Serial.available() > 0) {
  //  Serial.println ("Please Select a Valid Square");
  //  pos = Serial.read();
  //  Serial.println(pos);
  //}

  button1_State = digitalRead(2);
  button2_State = digitalRead(3);
  //push button 1 ++
  if (button1_State == HIGH && prestate == 0) {
    count_value++;
    if (count_value > 9) {
      count_value = 1;
    }
    // turn LED on
    if (message == true) {
      if (count_value == 1) {
        //if green is true, greenred false = red player
        if (g1 == true && greenred == false) {
          digitalWrite(11, HIGH);
          delay(200);
          digitalWrite(11, LOW);
        }
        else if (r1 == true && greenred == true) {
          digitalWrite(12, HIGH);
          delay(200);
          digitalWrite(12, LOW);
        }
        else if (r1 == false && g1 == false) {
          digitalWrite(11, HIGH);
          digitalWrite(12, HIGH);
          delay(200);
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
        }
        pos = count_value;
      }
      if (count_value == 2) {
        if (g2 == true && greenred == true) {
          digitalWrite(9, HIGH);
          delay(200);
          digitalWrite(9, LOW);
        }
        else if (r2 == true && greenred == false) {
          digitalWrite(8, LOW);
          delay(200);
          digitalWrite(8, LOW);
        }
        else if (r2 == false && g2 == false) {
          digitalWrite(9, HIGH);
          digitalWrite(8, HIGH);
          delay(200);
          digitalWrite(9, LOW);
          digitalWrite(8, LOW);
        }
        pos = count_value;
      }
      if (count_value == 3) {
        if (g3 == true && greenred == true) {
          digitalWrite(10, HIGH);
          delay(200);
          digitalWrite(10, LOW);
        }
        else if (r3 == true && greenred == false) {
          digitalWrite(13, HIGH);
          delay(200);
          digitalWrite(13, LOW);
        }
        else if (r3 == false && g3 == false) {
          digitalWrite(10, HIGH);
          digitalWrite(13, HIGH);
          delay(200);
          digitalWrite(10, LOW);
          digitalWrite(13, LOW);
        }
        pos = count_value;
      }
      if (count_value == 4) {
        if (g4 == true && greenred == true) {
          digitalWrite(5, HIGH);
          delay(200);
          digitalWrite(5, LOW);
        }
        if (r4 == true && greenred == false) {
          digitalWrite(7, HIGH);
          delay(200);
          digitalWrite(7, LOW);
        }   
        else if (r4 == false && g4 == false) {
          digitalWrite(5, HIGH);
          digitalWrite(7, HIGH);
          delay(200);
          digitalWrite(5, LOW);
          digitalWrite(7, LOW);
        }
        pos = count_value;
      }
      if (count_value == 5) {
        if (g5 == true) {
          digitalWrite(3, HIGH);
          delay(200);
          digitalWrite(3, LOW);
        }
        if (r5 == true) {
          digitalWrite(2, HIGH);
          delay(200);
          digitalWrite(2, LOW);
        }    
        else if (r5 == false && g5 == false) {
          digitalWrite(3, HIGH);
          digitalWrite(2, HIGH);
          delay(200);
          digitalWrite(3, LOW);
          digitalWrite(2, LOW);
        }
        pos = count_value;
      }
      if (count_value == 6) {
        if (g6 == true) {
          digitalWrite(4, HIGH);
          delay(200);
          digitalWrite(4, LOW);
        }
        if (r6 == true) {
          digitalWrite(6, HIGH);
          delay(200);
          digitalWrite(6, LOW);
        }  
        else if (r6 == false && g6 == false) {
          digitalWrite(4, HIGH);
          digitalWrite(6, HIGH);
          delay(200);
          digitalWrite(4, LOW);
          digitalWrite(6, LOW);
        }
        pos = count_value;
      }
      if (count_value == 7) {
        if (g7 == true) {
          digitalWrite(14, HIGH);
          delay(200);
          digitalWrite(14, LOW);
        }
        if (r7 == true) {
          digitalWrite(16, HIGH);
          delay(200);
          digitalWrite(16, LOW);
        }
        else if (r7 == false && g7 == false) {
          digitalWrite(14, HIGH);
          digitalWrite(16, HIGH);
          delay(200);
          digitalWrite(14, LOW);
          digitalWrite(16, LOW);
        }
        pos = count_value;
      }
      if (count_value == 8) {
        if (g8 == true) {
          digitalWrite(15, HIGH);
          delay(200);
          digitalWrite(15, LOW);
        }
        if (r8 == true) {
          digitalWrite(17, HIGH);
          delay(200);
          digitalWrite(17, LOW);
        } 
        else if (r8 == false && g8 == false) {
          digitalWrite(15, HIGH);
          digitalWrite(17, HIGH);
          delay(200);
          digitalWrite(15, LOW);
          digitalWrite(17, LOW);
        }
        pos = count_value;
      }
      if (count_value == 9) {
        if (g9 == true) {
          digitalWrite(18, HIGH);
          delay(200);
          digitalWrite(18, LOW);
        }
        if (r9 == true) {
          digitalWrite(19, HIGH);
          delay(200);
          digitalWrite(19, LOW);
        } 
        else if (r9 == false && g9 == false) {
          digitalWrite(18, HIGH);
          digitalWrite(18, HIGH);
          delay(200);
          digitalWrite(18, LOW);
          digitalWrite(18, LOW);
        }
        pos = count_value;
      }
    }
    Serial.print("Current Possition: ");
    Serial.println(count_value);
    prestate = 1;
  }
  //push button 2 --
  else if (button2_State == HIGH && prestate == 0) {
    if ((pos = 1) && (r1 == false) && (g1 == false)) {
    Serial.println("Posistion 1");
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
    pos = 0;
    count_value = 0;
  }
  else if ((pos = 2) && (r2 == false) && (g2 == false)) {
    Serial.println("Posistion 2");
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
    pos = 0;
    count_value = 0;
  }
  else if ((pos = 3) && (r3 == false) && (g3 == false)) {
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
    pos = 0;
    count_value = 0;
  }
  else if ((pos = 4) && (r4 == false) && (g4 == false)) {
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
    pos = 0;
    count_value = 0;
  }
  else if ((pos = 5) && (r5 == false) && (g5 == false)) {
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
    pos = 0;
    count_value = 0;
  }
  else if ((pos = 6) && (r6 == false) && (g6 == false)) {
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
    pos = 0;
    count_value = 0;
  }
  else if ((pos = 7) && (r7 == false) && (g7 == false)) {
    if ((greenred == false) && (g7 == false)) {
    digitalWrite(14, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = true;
    r7 = true;
    }
    if ((greenred == true) && (r7 == false)) {
    digitalWrite(16, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = false;
    g7 = true;
    }
    message = false;
    pos7 = false;
    pos = 0;
    count_value = 0;
  }
  else if ((pos = 8) && (r8 == false) && (g8 == false)) {
    if ((greenred == false) && (g8 == false)) {
    digitalWrite(15, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = true;
    r8 = true;
    }
    if ((greenred == true) && (r8 == false)) {
    digitalWrite(17, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = false;
    g8 = true;
    }
    message = false;
    pos8 = false;
    pos = 0;
    count_value = 0;
  }
  else if ((pos = 9) && (r9 == false) && (g9 == false)) {
    if ((greenred == false) && (g9 == false)) {
    digitalWrite(18, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = true;
    r9 = true;
    }
    if ((greenred == true) && (r9 == false)) {
    digitalWrite(19, HIGH);
    delay(10); // Delay a little bit to improve simulation performance
    greenred = false;
    g9 = true;
    }
    message = false;
    pos9 = false;
    pos = 0;
    count_value = 0;
  }
  prestate = 1;
  } 
  else if(button1_State == LOW && button2_State == LOW) {
    prestate = 0;
  //greenred true = green
  }
}
