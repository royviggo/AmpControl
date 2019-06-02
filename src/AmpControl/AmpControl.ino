void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    // Blinky to confirm that the communication is Ok
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(700);
}
