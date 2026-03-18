// Pin Tanımlamaları
const int ledPin = 4;
const int buzzerPin = 5;

// Notalar
#define NOTE_B4  494 // Açık tel (0)
#define NOTE_DS5 622 // 4. Perde
#define NOTE_E5  659 // 5. Perde
#define NOTE_FS5 740 // 7. Perde
#define NOTE_G5  784 // 8. Perde

// Riff Dizisi (0-4-0-7-0-5-0-8)
int thunderRiff1[] = {
  NOTE_B4, NOTE_DS5, NOTE_B4, NOTE_FS5
};

int thunderRiff2[] = {NOTE_B4, NOTE_E5,  NOTE_B4, NOTE_G5};

int tempo = 90; // Hız (ms)

void setup() {
  Serial.begin(115200);
  Serial.printf("Music starting...");
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
    int count1 = 0;
  while (count1 != 4) {
  for (int i = 0; i < 4; i++) {
    // Sadece perdeli notalarda (tekli indexler: 1, 3, 5, 7) LED yansın
    if (i % 2 != 0) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }

    tone(buzzerPin, thunderRiff1[i], tempo);
    delay(tempo);
    
    noTone(buzzerPin);
    delay(tempo / 2); // Notalar arası netlik için kısa boşluk
  }
  count1++;
  }

  int count2 = 0;
  while (count2 != 4) {
  for (int i = 0; i < 4; i++) {
    // Sadece perdeli notalarda (tekli indexler: 1, 3, 5, 7) LED yansın
    if (i % 2 != 0) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }

    tone(buzzerPin, thunderRiff2[i], tempo);
    delay(tempo);
    
    noTone(buzzerPin);
    delay(tempo / 2); // Notalar arası netlik için kısa boşluk
  }
  count2++;
  }
  
  // Riff bittiğinde LED'i söndür
  digitalWrite(ledPin, LOW);
}
