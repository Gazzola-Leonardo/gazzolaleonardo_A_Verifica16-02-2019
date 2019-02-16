int rosso = 11;
int giallo = 10;
int bianco = 9;
int verde = 8;
int DURATA = 0;
int i = 0;
int randNumber;
int cicli;
String serial;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Seriale attiva");
  pinMode(rosso, OUTPUT);
  pinMode(giallo, OUTPUT);
  pinMode(bianco, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(i == cicli){
    richiesta();
  }
  digitalWrite(rosso, HIGH);
  delay(DURATA);
  digitalWrite(rosso, LOW);
  digitalWrite(giallo, HIGH);
  delay(DURATA*2);
  digitalWrite(giallo, LOW);
  digitalWrite(bianco, HIGH);
  delay(DURATA);
  digitalWrite(bianco, LOW);
  digitalWrite(verde, HIGH);
  delay(DURATA*3);
  digitalWrite(verde, LOW);
  i++;
}

void richiesta(){
  Serial.println("Inserire dopo quanti dopo quanti CICLI il programma deve ricominciare dall’inizio:");
  while(Serial.available() == 0);
    if (Serial.available() > 0){
      serial = Serial.readString();
      Serial.println(serial.toInt());
      cicli = serial.toInt();
      i = 0;
  }
  Serial.println("Durata del led generata a random:");
  randNumber = random(1, 5);
  Serial.println(randNumber);
  DURATA = randNumber*1000;
}
