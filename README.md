# Ducha Inteligente — TEI201

Sistema IoT diseñado para reducir el consumo excesivo de agua en duchas mediante monitoreo en tiempo real, alertas visuales y sonoras progresivas y registro de datos para promover duchas eficientes de 5 a 10 minutos[cite: 1].

## Integrantes del equipo
* Martina Couyoumdjian[cite: 1]
* Tomás Soto[cite: 1]
* Tomás Urzúa[cite: 1]
* Agustina Álvarez[cite: 1]

## Problema que resuelve (Avance 1)
En el contexto de crisis hídrica prolongada en Chile y la Región Metropolitana, cerca del 65–70% del consumo doméstico de agua ocurre en el baño y la ducha es el punto individual de mayor gasto (alrededor de 12 litros por minuto con la llave abierta)[cite: 1]. Las personas no cuentan con un indicador visible de tiempo o consumo mientras se duchan, lo que genera duchas prolongadas y desperdicio innecesario de agua potable[cite: 1].

## Componentes necesarios
* Microcontrolador (Arduino Uno / ESP32)[cite: 1]
* Sensor de flujo de agua YF-S201[cite: 1]
* Válvula solenoide[cite: 1]
* Indicadores visuales (LEDs verde, amarillo y rojo) y buzzer (zumbador)[cite: 1]
* Protoboard, resistencias, cables jumper y adaptador de corriente (5V o 7-12V)[cite: 1]
* Carcasa modular de protección diseñada en Fusion 360[cite: 1, 9]

## Estructura del repositorio
* `firmware/`: Código fuente del microcontrolador (`.ino`).
* `hardware/`: Esquemático eléctrico y lista de materiales (BOM)[cite: 11].
* `diseño-3d/`: Archivo Fusion 360 (`.f3d`), planos técnicos en PDF y renders[cite: 11].
* `testing/`: Protocolo de pruebas y resultados registrados[cite: 11].
* `docs/`: Presentación y documentación del proyecto[cite: 11].
* `FUENTES.md`: Declaración de librerías, código externo y uso de IA[cite: 14].

## Instrucciones de instalación y uso
1. **Hardware:** Armar el circuito conectando el sensor de flujo YF-S201, los LEDs (verde, amarillo y rojo), el buzzer y la válvula solenoide según el esquemático en `hardware/`[cite: 1, 11].
2. **Firmware:** Abrir el archivo `.ino` de la carpeta `firmware/` en Arduino IDE, seleccionar la placa y puerto correspondiente, y cargar el programa al microcontrolador[cite: 11, 18].
3. **Dashboard y operación:** Alimentar el sistema, abrir el dashboard de visualización (link/instrucciones del panel) y verificar la captura continua de flujo y alertas progresivas durante la ducha[cite: 1, 5, 11].
