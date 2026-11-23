# Declaración de Fuentes e Inteligencia Artificial — Ducha Inteligente

## Librerías utilizadas
| Librería | Versión | Uso en el proyecto | Fuente |
| :--- | :--- | :--- | :--- |
| Ninguna librería externa | N/A | El código utiliza únicamente funciones nativas de Arduino (`pinMode`, `digitalWrite`, `millis`, `attachInterrupt`, `tone`, `noTone`, `Serial`). | Documentación oficial de Arduino |

## Código externo adaptado
### Conteo de pulsos por interrupción y temporización no bloqueante con `millis()` (`pruebafinal1.ino`)[cite: 20, 22]
* **Fuente:** Patrón estándar de interrupciones (`attachInterrupt` en pin 2) y control de tiempo con `millis()` de la documentación y ejemplos de Arduino[cite: 22].
* **Adaptación:** Se configuró la interrupción `RISING` en el pin `SENSOR` (pin 2) para incrementar `pulsos` con `contarPulso()`, se protegió la lectura/reinicio de `pulsos` con `noInterrupts()` / `interrupts()`, y se programó la secuencia de estados con LEDs (`8`, `9`, `10`) y `BUZZER` (`7`) en ventanas de `5000 ms`, `7000 ms`, `10000 ms`, `13000 ms` y reinicio tras `15000 ms` sin pulsos[cite: 22].

## Uso de Inteligencia Artificial
### Asistencia en estructura, redacción y revisión del código / documentación[cite: 16, 17]
* **Herramienta:** Gemini (noviembre 2026)[cite: 17]
* **Uso / Prompt:** Apoyo para estructurar el código de control de luces/buzzer según detección de flujo y preparar la documentación del repositorio (`README.md` y `FUENTES.md`)[cite: 1, 11, 14, 22].
* **Adaptación:** Se definieron y verificaron los pines (`2`, `7`, `8`, `9`, `10`), los tiempos de prueba en milisegundos y el comportamiento del prototipo con el hardware armado[cite: 1, 22].
* **Comprensión:** El equipo comprende cómo `contarPulso()` suma pulsos en cada flanco de subida del sensor, cómo `millis()` mide el tiempo transcurrido desde `inicioAgua` sin detener el loop, y cómo se reinician las variables tras 15 segundos sin actividad[cite: 22].
