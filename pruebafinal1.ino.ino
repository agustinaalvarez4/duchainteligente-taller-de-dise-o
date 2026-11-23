
const int SENSOR = 2;
const int BUZZER = 7;

const int LED_VERDE = 8;
const int LED_AMARILLO = 9;
const int LED_ROJO = 10;

volatile unsigned long pulsos = 0;

unsigned long inicioAgua = 0;
unsigned long ultimoPulso = 0;

bool aguaDetectada = false;

void contarPulso() {
  pulsos++;
}

void apagarTodo() {
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_ROJO, LOW);
  noTone(BUZZER);
}

void setup() {
  pinMode(SENSOR, INPUT_PULLUP);

  pinMode(BUZZER, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);

  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(SENSOR), contarPulso, RISING);

  apagarTodo();
}

void loop() {
  unsigned long ahora = millis();

  noInterrupts();
  unsigned long totalPulsos = pulsos;
  interrupts();

  // Esperar hasta que el sensor detecte agua
  if (!aguaDetectada && totalPulsos > 0) {
    aguaDetectada = true;
    inicioAgua = ahora;
    ultimoPulso = ahora;
  }

  // Si todavía no hay agua, mantener todo apagado
  if (!aguaDetectada) {
    apagarTodo();
    return;
  }

  // Actualizar el tiempo del último pulso
  static unsigned long pulsosAnteriores = 0;

  if (totalPulsos != pulsosAnteriores) {
    ultimoPulso = ahora;
    pulsosAnteriores = totalPulsos;
  }

  // Si pasan 15 segundos sin detectar pulsos, reiniciar
  if (ahora - ultimoPulso >= 15000) {
    aguaDetectada = false;

    noInterrupts();
    pulsos = 0;
    interrupts();

    pulsosAnteriores = 0;
    apagarTodo();
    return;
  }

  unsigned long tiempo = ahora - inicioAgua;

  // 0 a 5 segundos: verde
  if (tiempo < 5000) {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, LOW);
    noTone(BUZZER);
  }

  // 5 a 7 segundos: amarillo
  else if (tiempo < 7000) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, HIGH);
    digitalWrite(LED_ROJO, LOW);
    noTone(BUZZER);
  }

  // 7 a 10 segundos: rojo
  else if (tiempo < 10000) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, HIGH);
    noTone(BUZZER);
  }

  // 10 a 13 segundos: rojo y alarma
  else if (tiempo < 13000) {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, HIGH);
    tone(BUZZER, 2000);
  }

  // 13 a 15 segundos: rojo sin alarma
  else {
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, HIGH);
    noTone(BUZZER);
  }
}
