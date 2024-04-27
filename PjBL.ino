#include "CTBot.h";
#include <DHT.h>

CTBot myBot;

// Pin WiFi
const char* ssid = "";
const char* pass = "";
const char* token = "";

// Pin Flame Sensor
#define flameSensor 34


// Pin DHT22
#define DHTPIN 5     // DHT PIN 4
#define DHTTYPE DHT22 

// Pin MQ2
int Gas_analog = 35;    
int Gas_digital = 32;

// Pin LED
int led = 26;

int aktif;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Memulai telegram bot. Koneksi ke WiFi");
  myBot.wifiConnect(ssid, pass);
  myBot.setTelegramToken(token);
  if (myBot.testConnection())
    Serial.println("Koneksi Berhasil");
  else 
    Serial.println("Gagal Terkoneksi");      
  pinMode(Gas_digital, INPUT);
  pinMode(led, OUTPUT);
  pinMode(flameSensor, INPUT); // Menggunakan pembacaan digital dengan pull-up resistor internal
  pinMode(DHTPIN, INPUT);
  dht.begin();
}

void loop() {
  TBMessage msg;

  // MQ2 sensor
  int gassensorAnalog = analogRead(Gas_analog);
  int gassensorDigital = digitalRead(Gas_digital);

  // DHT22 sensor
  float h  = dht.readHumidity();
  // read temperature in Celsius
  float t = dht.readTemperature();
  // read Heat Index
  float hic = dht.computeHeatIndex(t, h, false);

  // Read Flame Sensor
  int flameValue = analogRead(flameSensor);
  float flame = flameValue / 4;

  // Koneksi Telegram
  if (myBot.getNewMessage(msg)) {
    String pesan = msg.text;
    if (pesan.equals("ON")) {
        aktif = 1;
        myBot.sendMessage(msg.sender.id, "Sensor Kebakaran Sudah Menyala");
        Serial.println("Bot Terhubung");
    } else if (pesan.equals("OFF")) {
        aktif = 0;
        myBot.sendMessage(msg.sender.id, "Sensor Kebakaran Dimatikan");
        Serial.println("Bot Tidak Terhubung");
    }
  }
  
  if (aktif == 1) {
    if((gassensorAnalog > 1100 && flameValue < 200) || (t > 40 && h > 100)) {
      char message[100]; // Define a character array to hold the formatted message
      sprintf(message, "Terdeteksi Suhu: %.2f°C\nHeat Index: %.2f°C\nTerdeteksi Gas dan Api", t, h);
      myBot.sendMessage(msg.sender.id, message);
      digitalWrite (led, HIGH);
      Serial.print("Kelembapan: ");
      Serial.println(h);
      Serial.print("Temperature: ");
      Serial.println(t);
      Serial.print("GAS: ");
      Serial.println(gassensorAnalog);
      Serial.print("API: ");
      Serial.println(flameValue);      
    } else if (gassensorAnalog < 1100 || flameValue==4095 || (t < 40 && h < 100) ) {
      String message = "Tidak Terdeteksi Kebakaran, Aman!";
      myBot.sendMessage(msg.sender.id, message);
      Serial.println("No Gas");
      Serial.print("Kelembapan: ");
      Serial.println(h);
      Serial.print("Temperature: ");
      Serial.println(t);
      Serial.print("GAS: ");
      Serial.println(gassensorAnalog);
      Serial.print("API: ");
      Serial.println(flameValue);
      digitalWrite (led, LOW);
  } else if (aktif == 0) {
      Serial.println("Sensor Dimatikan");
    }
    delay(3000); 
    }
}
