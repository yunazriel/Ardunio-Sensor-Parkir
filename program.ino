int trig = 7;
int echo = 6;
int merah = 2;
int kuning = 3;
int hijau = 4;
int buzzer = 5;
long durasi, jarak;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long durasi, jarak;
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  digitalWrite(trig, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  durasi = pulseIn(echo, HIGH);
  jarak = (durasi / 2) / 29.1;  //jarak satuan  "cm"

  if ((jarak < 50) && (jarak > 25)) {
    digitalWrite(hijau, HIGH);
  } else {
    digitalWrite(hijau, LOW);
  }

  if ((jarak > 6) && (jarak < 24)) {
    digitalWrite(kuning, HIGH);
  } else {
    digitalWrite(kuning, LOW);
  }

  if (jarak < 5) {
    digitalWrite(merah, HIGH);
    for (int i = 0; i < 5; i++) {
      tone(buzzer, 500); //frekuensi buzer
      delay(100);
      noTone(buzzer);
      delay(50);
    }
  } else {
    digitalWrite(merah, LOW);
    digitalWrite(buzzer, LOW);
  }

  Serial.print("Jarak object : ");
  Serial.print(jarak);
  Serial.println(" Cm");
  delay(1000);
}
