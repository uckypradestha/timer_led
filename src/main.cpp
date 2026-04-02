#include <Arduino.h>
#include <TimerOne.h>   // Library untuk menggunakan Timer1 (16-bit hardware timer)

const int ledPin = 5; // Pin untuk LED yang akan berkedip setiap 500 ms
const int timerLedPin = 11; // Pin untuk LED yang akan berkedip setiap 5 detik (dengan interrupt)

// Fungsi ISR (Interrupt Service Routine)
// Fungsi ini akan dipanggil otomatis setiap interval timer tercapai
void longBlink() {
  // Toggle LED pada pin 11 (HIGH jadi LOW, LOW jadi HIGH)
  digitalWrite(timerLedPin, !digitalRead(timerLedPin));
}

void setup() {
  // Set pin 11 sebagai output (LED yang dikontrol oleh interrupt)
  pinMode(timerLedPin, OUTPUT);

  // Set pin 5 sebagai output (LED yang dikontrol oleh loop biasa)
  pinMode(ledPin, OUTPUT);
  
  // Inisialisasi Timer1
  // Nilai dalam mikrodetik → 5.000.000 µs = 5 detik
  Timer1.initialize(5000000);    

  // Menghubungkan fungsi ISR (longBlink) ke Timer1
  // Artinya: setiap 5 detik, fungsi longBlink akan dijalankan otomatis
  Timer1.attachInterrupt(longBlink);  
}

void loop() {
  // LED pada pin 5 dinyalakan
  digitalWrite(ledPin, HIGH);

  // Delay 500 ms (blocking)
  delay(500);

  // LED pada pin 5 dimatikan
  digitalWrite(ledPin, LOW);

  // Delay 500 ms
  delay(500);
}