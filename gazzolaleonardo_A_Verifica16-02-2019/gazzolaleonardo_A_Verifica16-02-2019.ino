int rosso = 11;
int giallo = 10;
int bianco = 9;
int verde = 8;
int DURATA = 0;
int i = 0;
int randNumero;
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
  richiesta();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(i == cicli){
    genera();
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
  genera();
}
void genera(){
  Serial.println("Durata del led generata a random in secondi:");
  randNumero = random(0, 5);
  Serial.println(randNumero);
  DURATA = randNumero*1000;
}
