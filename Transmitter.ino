
int GNDPin0 = A4; //Set Analog pin 4 as GND
int VccPin  = A5; //Set Analog pin 5 as VCC
int GNDPin1 = A0;

int xAxisInputPin =  A3; //X axis input
int yAxisInputPin = A2; //Y axis input

int Q1  = 7;
int Q2  = 8;
int Q3  = 9;

const int f = A1;
int valAnalog(0);
const int t = 2;

long x_coordinate(0); //Variabe for storing X coordinates
long y_coordinate(0); //Variabe for storing Y coordinates
long z_coordinate(0); //Variabe for storing Z coordinates


// These values need to be calibrated first and then used in the code
int forward_limit = 370;
int backward_limit = 294;
int right_limit = 400;
int left_limit = 300;

void setup()
{
  Serial.begin(9600);   
  
  pinMode(GNDPin0, OUTPUT);
  pinMode(VccPin, OUTPUT);
  pinMode(GNDPin1, OUTPUT);
  pinMode(Q1,OUTPUT);
  pinMode(Q2,OUTPUT);
  pinMode(Q3,OUTPUT);
  pinMode(f, INPUT);
  pinMode(t, OUTPUT);
  digitalWrite(GNDPin0, LOW); //Set A4 pin LOW
  digitalWrite(VccPin, HIGH); //Set A5 pin HIGH
  digitalWrite(GNDPin1, LOW); 
}
void loop()
{
  x_coordinate = analogRead(xAxisInputPin); //Reads X coordinates
  y_coordinate = analogRead(yAxisInputPin); //Reads Y coordinates
 
     if ( y_coordinate>forward_limit)// Change the value for adjusting sensitivity
      move_forward();
      else if  (y_coordinate<backward_limit)
      move_backward();
    else if(x_coordinate>right_limit)  // Change the value for adjusting sensitivity
      move_right();
    else if(x_coordinate<left_limit)  // Change the value for adjusting sensitivity
      move_left();
    else
      stop_();    
}

void move_forward()
{
  valAnalog = analogRead(f);

  if(valAnalog<550)
  {
    Serial.println("");
    Serial.println("Forward Close");
    digitalWrite(Q1,HIGH);
    digitalWrite(Q2,HIGH);
    digitalWrite(Q3,HIGH);
    digitalWrite(t, HIGH);
  }
  else if(valAnalog>551)
  {
    Serial.println("");
    Serial.println("Forward Open");
    digitalWrite(Q1,HIGH);
    digitalWrite(Q2,HIGH);
    digitalWrite(Q3,HIGH);
    digitalWrite(t, LOW);
  }
}

void move_backward()
{
  valAnalog=analogRead(f);
  if(valAnalog<550)
  {
    Serial.println("");
    Serial.println("Backward Close");
    digitalWrite(Q1,LOW);
    digitalWrite(Q2,HIGH);
    digitalWrite(Q3,LOW);
    digitalWrite(t, HIGH);
  }
  if(valAnalog>551)
  {
    Serial.println("");
    Serial.println("Backward Open");
    digitalWrite(Q1,LOW);
    digitalWrite(Q2,HIGH);
    digitalWrite(Q3,LOW);
    digitalWrite(t, LOW);
  }
  
}

void move_left()
{
  valAnalog=analogRead(f);
  if(valAnalog<550)
  {
    Serial.println("");
    Serial.println("Left Close");
    digitalWrite(Q1,LOW);
    digitalWrite(Q2,LOW);
    digitalWrite(Q3,HIGH);
    digitalWrite(t, HIGH);
  }
  if(valAnalog>551)
  {
    Serial.println("");
    Serial.println("Left Open");
    digitalWrite(Q1,LOW);
    digitalWrite(Q2,LOW);
    digitalWrite(Q3,HIGH);
    digitalWrite(t, LOW);
  }
}

void move_right()
{
  valAnalog=analogRead(f);
  if(valAnalog<550)
  {
    Serial.println("");
    Serial.println("Right Close");
    digitalWrite(Q1,HIGH);
    digitalWrite(Q2,LOW);
    digitalWrite(Q3,LOW);
    digitalWrite(t, HIGH);
  }
  if(valAnalog>551)
  {
    Serial.println("");
    Serial.println("Right Open");
    digitalWrite(Q1,HIGH);
    digitalWrite(Q2,LOW);
    digitalWrite(Q3,LOW);
    digitalWrite(t, LOW);
  }
}

void stop_()
{
  valAnalog=analogRead(f);
  if(valAnalog<550)
  {
    Serial.println("");
    Serial.println("stop Close");
    digitalWrite(Q1,LOW);
    digitalWrite(Q2,LOW);
    digitalWrite(Q3,LOW);
    digitalWrite(t, HIGH);
  }
   if(valAnalog>551)
  {
    Serial.println("");
    Serial.println("stop Open");
    digitalWrite(Q1,LOW);
    digitalWrite(Q2,LOW);
    digitalWrite(Q3,LOW);
    digitalWrite(t, LOW);
  }
}

