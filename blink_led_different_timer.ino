
#define ledPin1 7
#define ledPin2 6
#define ledPin3 5
#define ledPin4 4
int led_state1 = 0;
int led_state2 = 0;
int led_state3 = 0;
int led_state4 = 0;
float value = 0;
float value1 = 0;
float value2 = 0;
float value3 = 0;
int Led1 = 0;
int Led2 = 0;
int Led3 = 0;
int Led4 = 0;
String read_input;
int i = 0;
bool led1State = false;
bool led2State = false;
bool led3State = false;
bool led4State = false;
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  //initialize timer1
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A  = value;       // compare match register 16MHz/256/2Hz
  TCCR1B = TCCR1B | (1 << WGM12);  // CTC mode
  TCCR1B = TCCR1B | ((1 << CS12) | (1 << CS10)); // 256 prescaler
  TIMSK1 = TIMSK1 | (1 << OCIE1A); // enable timer compare interrupt

  // initialize timer3
  TCCR3A = 0;
  TCCR3B = 0;
  TCNT3  = 0;
  OCR3A  = value1;       // compare match register 16MHz/256/2Hz
  TCCR3B = TCCR3B | (1 << WGM32);  // CTC mode
  TCCR3B = TCCR3B | ((1 << CS32) | (1 << CS30)); // 256 prescaler
  TIMSK3 = TIMSK3 | (1 << OCIE3A); // enable timer compare interrupt  sei(); // enable all interrupts*/

  // initialize timer4
  TCCR4A = 0;
  TCCR4B = 0;
  TCNT4  = 0;
  OCR4A  = value2;       // compare match register 16MHz/256/2Hz
  TCCR4B = TCCR4B | (1 << WGM42);  // CTC mode
  TCCR4B = TCCR4B | ((1 << CS42) | (1 << CS40)); // 256 prescaler
  TIMSK4 = TIMSK4 | (1 << OCIE4A); // enable timer compare interrupt  sei(); // enable all interrupts*/

  // initialize timer5
  TCCR5A = 0;
  TCCR5B = 0;
  TCNT5  = 0;
  OCR5A  = value3;       // compare match register 16MHz/256/2Hz
  TCCR5B = TCCR5B | (1 << WGM52);  // CTC mode
  TCCR5B = TCCR5B | ((1 << CS52) | (1 << CS50)); // 256 prescaler
  TIMSK5 = TIMSK5 | (1 << OCIE5A); // enable timer compare interrupt  sei(); // enable all interrupts*/
  sei();
}
void loop()
{
  if (Serial.available() > 0)
  {
    read_input = Serial.readString();
    Serial.println(read_input);
    if (read_input == "1")
    {
      Led1 = read_input.toInt();
      led1State = true;
      led2State = false;
      led3State = false;
      led4State = false;

    }
    if (read_input == "2")
    {
      Led2 = read_input.toInt();
      led1State = false;
      led2State = true;
      led3State = false;
      led4State = false;
    }
    if (read_input == "3")
    {
      Led3 = read_input.toInt();
      led1State = false;
      led2State = false;
      led3State = true;
      led4State = false;
    }
    if (read_input == "4")
    {
      Led4 = read_input.toInt();
      led1State = false;
      led2State = false;
      led3State = false;
      led4State = true;
    }
    Serial.println("You entered : " + read_input);

  }
  if ( Led1 == 1 && led1State)
  {
    if ( read_input == "up")
    {
      value = read_timer_up();
      Serial.println("led1: " + (String)value);
      read_input = "";
    }
    if (read_input == "down")
    {
      value = read_timer_down();
      Serial.println("led1: " + (String)value);
      read_input = "";
    }
  }
  if (Led2 == 2 && led2State)
  {
    if ( read_input == "up")
    {
      value1 = read_timer_up();
      Serial.println("led2: " + (String)value1);
      read_input = "";
    }
    if (read_input == "down")
    {
      value1 = read_timer_down();
      Serial.println("led2: " + (String)value1);
      read_input = "";
    }
  }
  if ( Led3 == 3 && led3State)
  {
    if ( read_input == "up")
    {
      value2 = read_timer_up();
      Serial.println("led3: " + (String)value2);
      read_input = "";
    }
    if (read_input == "down")
    {
      value2 = read_timer_down();
      Serial.println("led3: " + (String)value2);
      read_input = "";
    }
  }
  if ( Led4 == 4 && led4State)
  {
    if ( read_input == "up")
    {
      value3 = read_timer_up();
      Serial.println("led4: " + (String)value3);
      read_input = "";
    }
    if (read_input == "down")
    {
      value3 = read_timer_down();
      Serial.println("led4: " + (String)value3);
      read_input = "";
    }
  }
  if ( read_input == "0")
  {
    if (led1State)
    {
      OCR1A = 0;
      digitalWrite(ledPin1, 0);
      Led1 = 0;
    }
    else if (led2State)
    {
      OCR3A = 0;
      digitalWrite(ledPin2, 0);
      Led2 = 0;
    }
    else if(led3State)
    {
      OCR4A = 0;
      digitalWrite(ledPin3, 0);
      Led3 = 0;
    }
    else if(led4State)
    {
      OCR5A = 0;
      digitalWrite(ledPin4, 0);
      Led4 = 0;
    }
  }
  if ( read_input == "delete")
  {
    OCR1A = 0;
    OCR3A = 0;
    OCR4A = 0;
    OCR5A = 0;
    Led1 = 0;
    Led2 = 0;
    Led3 = 0;
    Led4 = 0;
    digitalWrite(ledPin1, 0);
    digitalWrite(ledPin2, 0);
    digitalWrite(ledPin3, 0);
    digitalWrite(ledPin4, 0);
  }
}
float read_timer_up()
{
  i++;
  return ((16000000 / ( i * 1024)) - 1);

}
float read_timer_down()
{
  i--;
  if ( i <= 0)
  {
    float j = ((float)1 / (-i));
    return ((16000000 / (j * 1024) - 1));
  }
  else
  {
    return ((16000000 / ( i * 1024)) - 1);
  }

}

ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{ if (Led1 == 1)
  {
    OCR1A = value;
    led_state1 = !led_state1;
    digitalWrite(ledPin1, led_state1);
  }
}
ISR(TIMER3_COMPA_vect)
{
  if (Led2 == 2) {
    OCR3A = value1;
    led_state2 = !led_state2;
    digitalWrite(ledPin2, led_state2);
  }
}
ISR(TIMER4_COMPA_vect)
{
  if (Led3 == 3) {
    OCR4A = value2;
    led_state3 = !led_state3;
    digitalWrite(ledPin3, led_state3);
  }
}
ISR(TIMER5_COMPA_vect)
{
  if (Led4 == 4) {
    OCR5A = value3;
    led_state4 = !led_state4;
    digitalWrite(ledPin4, led_state4);
  }
}
