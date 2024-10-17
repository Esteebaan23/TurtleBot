#define LED 10
const int rgbazul = 4;
const int rgbverde = 3;
const int rgbrojo = 2;
int cont = 0;
//Esto porque estaba probando cada estado con un RGB
int mot1 = 5;
int mot2 = 6;
int izqA = 7;
int izqB = 8;
int derA = 9;
int derB = 10;
int vel = 255;
int python = 0;

void setup()
{
  pinMode(mot1, OUTPUT);
  pinMode(mot2, OUTPUT);
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
  Serial.begin(9600);
}

void loop()
{

  if (Serial.available() > 0)
  {
    python = Serial.read(); //leemos el serial

    if (python == 'w')
    {
      rojo();
      avanzar();
    }
    else if (python == 'z')
    {
      verde();
      reversa();
    }
    else if (python == 'a')
    {
      amarillo();
      izquierda();
    }
    else if (python == 'd')
    {
      blanco();
      derecha();
    }

    else if (python == 's')
    {
      apagado();
      detener();
    }
    else if (python == '+')
    {
      cafe();
      vel = vel * 2;
      
    if (vel > 255)
    {
      vel = 255;
    }S
      Serial.print(vel);

    }
    else if (python == '-')
    {
      tomate();
      vel = vel / 2;
      if (vel < 63)
    {
      vel = 63;
    }
      Serial.print(vel);

    }

  
}
}



void rojo()
{
  analogWrite(rgbazul, 0);
  analogWrite(rgbverde, 0);
  analogWrite(rgbrojo, 255);
}

void verde()
{

  analogWrite(rgbazul, 0);
  analogWrite(rgbverde, 255);
  analogWrite(rgbrojo, 0);
}
void azul()
{
  analogWrite(rgbazul, 255);
  analogWrite(rgbverde, 0);
  analogWrite(rgbrojo, 0);
}

void amarillo()
{
  analogWrite(rgbazul, 0);
  analogWrite(rgbverde, 255);
  analogWrite(rgbrojo, 255);
}

void blanco()
{
  analogWrite(rgbazul, 255);
  analogWrite(rgbverde, 255);
  analogWrite(rgbrojo, 255);
}

void cafe()
{
  analogWrite(rgbazul, 0);
  analogWrite(rgbverde, 0);
  analogWrite(rgbrojo, 128);
}

void tomate()
{
  analogWrite(rgbazul, 0);
  analogWrite(rgbverde, 125);
  analogWrite(rgbrojo, 255);
}

void apagado()
{
  analogWrite(rgbazul, 0);
  analogWrite(rgbverde, 0);
  analogWrite(rgbrojo, 0);
}


void detener() {
  analogWrite(derB, 0);  // Detiene los Motores
  analogWrite(izqB, 0);
}

void avanzar() {
  digitalWrite(derA, HIGH);  // Frente
  digitalWrite(izqA, HIGH);
  analogWrite(mot1, vel);
  digitalWrite(derB, LOW);
  digitalWrite(izqB, LOW);
  analogWrite(mot2, vel);


}

void derecha() {
  digitalWrite(derA, HIGH);  // Derecha
  digitalWrite(izqB, HIGH);
  digitalWrite(derB, LOW);  
  digitalWrite(izqA, LOW);
  analogWrite(mot1, vel);
  analogWrite(mot2, vel);
}

void izquierda() {
  digitalWrite(derB, HIGH);    // Izquierda
  digitalWrite(izqA, HIGH);
  digitalWrite(derA, LOW);  
  digitalWrite(izqB, LOW);
  analogWrite(mot1, vel);
  analogWrite(mot2, vel);
}

void reversa() {
  digitalWrite(derB, HIGH);  // Reversa
  digitalWrite(izqB, HIGH);
  digitalWrite(derA, LOW);  
  digitalWrite(izqA, LOW);
  analogWrite(mot1, vel);
  analogWrite(mot2, vel);

}
