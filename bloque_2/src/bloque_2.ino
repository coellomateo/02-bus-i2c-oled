// ============================================================================
// UETS SOPORTE TÉCNICO — SEMANA 02 — BLOQUE 2: INICIALIZACIÓN OLED & CABECERA
// 3° Bachillerato Técnico en Informática (2026–2027)
// ============================================================================

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Dimensiones de la pantalla OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Reset de la pantalla (-1 si comparte el pin de reset del ESP32)
#define OLED_RESET_PIN -1
#define OLED_I2C_ADDR 0x3C
#define SERIAL_BAUD 115200

// Instanciación del objeto display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET_PIN);

void setup() {
  Serial.begin(SERIAL_BAUD);
  delay(1000);
  Serial.println("\n[BLOQUE 2] Inicializando Pantalla OLED SSD1306...");

  // Inicialización del bus I2C (SDA = 21, SCL = 22)
  Wire.begin(21, 22);

  // Inicialización de la pantalla OLED con bomba de carga interna
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR)) {
    Serial.println("[OLED] X ERROR: Pantalla no detectada en 0x3C");
    while (true); // Detiene la ejecución si falla el hardware
  }

  Serial.println("[OLED] Pantalla detectada correctamente.");

  // Configuración inicial de pantalla
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  // Dibujar marco decorativo exterior
  display.drawRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);

  // Encabezado principal
  display.setTextSize(1);
  display.setCursor(10, 8);
  display.print(">> ESP32 SISTEMA <<");

  // Línea divisoria
  display.drawLine(5, 20, 122, 20, SSD1306_WHITE);

  // Texto de estado
  display.setCursor(15, 28);
  display.print("Estado: ONLINE");

  display.setCursor(15, 42);
  display.print("OLED I2C: OK (0x3C)");

  // Enviar buffer a la pantalla física
  display.display();
}

void loop() {
  // Mantener el estado en el bucle principal
  delay(1000);
}