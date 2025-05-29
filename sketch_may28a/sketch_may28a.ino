#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
//*******************************************************************************************************************************************************************************************************
const char* ssid = "ESP32";
const char* password = "hola1234";

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,4,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

uint8_t parqueo [8];

//ESCLAVOS
/*#define ESCLAVO1 0x55
#define ESCLAVO2 0x77

#define I2C_SDA 21
#define I2C_SCL 22

//uint8_t parqueoEstados[8];
uint8_t buffer[4];*/

//*******************************************************************************************************************************************************************************************************

void setup() {
  Serial.begin(115200);
  
  // Modo Access Point
  WiFi.softAP(ssid, password);
  Serial.println("ESP32 en modo Access Point");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);
  server.begin();

  //Wire.begin(I2C_SDA, I2C_SCL);
}

void loop() {
  delay(4000);
  server.handleClient();
//***********************************************ESCLAVO 2**********************************************************************
/*uint8_t PRIM1, PRIM2, PRIM3, PRIM4;

Wire.requestFrom(ESCLAVO2, 4);  // Solicita 4 bytes al esclavo

if (Wire.available() >= 4) {
    PRIM1 = Wire.read();  // Byte 1
    PRIM2 = Wire.read();  // Byte 2
    PRIM3 = Wire.read();  // Byte 3
    PRIM4 = Wire.read();  // Byte 4
}

// Ahora tienes cada valor individual en su variable correspondiente
Serial.print("PRIM1: "); Serial.println(PRIM1);
Serial.print("PRIM2: "); Serial.println(PRIM2);
Serial.print("PRIM3: "); Serial.println(PRIM3);
Serial.print("PRIM4: "); Serial.println(PRIM4);

  uint8_t error1 = Wire.endTransmission(true);
  Serial.printf("endTransmission2: %u\n", error1); //cum

//**************************************************ESCLAVO 1***************************************************************
uint8_t PRIM5, PRIM6, PRIM7, PRIM8;

Wire.requestFrom(ESCLAVO1, 4);  // Solicita 4 bytes al esclavo

if (Wire.available() >= 4) {
    PRIM5 = Wire.read();  // Byte 1
    PRIM6 = Wire.read();  // Byte 2
    PRIM7 = Wire.read();  // Byte 3
    PRIM8 = Wire.read();  // Byte 4
}

// Ahora tienes cada valor individual en su variable correspondiente
Serial.print("PRIM5: "); Serial.println(PRIM5);
Serial.print("PRIM6: "); Serial.println(PRIM6);
Serial.print("PRIM7: "); Serial.println(PRIM7);
Serial.print("PRIM8: "); Serial.println(PRIM8);

  uint8_t error3 = Wire.endTransmission(true);
  Serial.printf("endTransmission2: %u\n", error3); //cum*/
}

void handle_OnConnect () {
  server.send(404, "text/html", SendHTML(parqueo));
}
void handle_NotFound () {
  server.send(404, "text/plain", "Not Found");
}

// Página HTML
String SendHTML(uint8_t *array) {
String ptr = "<!DOCTYPE html>\n";
ptr +="<html lang=es>\n";
ptr +="<head>\n";
ptr +="<meta charset=UTF-8 />\n";
ptr +="<title>Parqueo-matic</title>\n";
ptr += "<style>";
ptr += "body{background-color:black;font-family:Arial,sans-serif;color:white;";
ptr += "display:flex;justify-content:center;align-items:center;height:100vh;margin:0;";
ptr += "flex-direction:column}";
ptr += "h1{text-align:center;font-size:3em}";
ptr += "#contador-container{margin-bottom:20px;text-align:center}";
ptr += "#contador-container h2{margin:0}";
ptr += "#contador{font-size:36px;font-weight:bold;color:white}";
ptr += ".fila{display:flex;gap:10px;margin:0}";
ptr += ".parqueo{width:200px;height:300px;background-color:gray;border:2px solid yellow;";
ptr += "display:flex;align-items:center;justify-content:center;font-weight:bold;position:relative}";
ptr += ".parqueo img{position:absolute;width:80%;height:auto;top:50%;left:50%;";
ptr += "transform:translate(-50%,-50%);z-index:1}";
ptr += ".luces-fila{justify-content:center;gap:130px;margin:20px 0}";
ptr += ".luces{display:flex;gap:5px}";
ptr += ".luz{width:40px;height:40px;border-radius:50%}";
ptr += ".rojo-libre{background-color:#800000}";
ptr += ".rojo-ocupado{background-color:#ff4d4d}";
ptr += ".verde-libre{background-color:#0f0}";
ptr += ".verde-ocupado{background-color:#006400}";
ptr += ".mi-boton{padding:10px 20px;background-color:#28a745;color:white;";
ptr += "border:0;border-radius:8px;font-size:16px;cursor:pointer;";
ptr += "transition:background-color .3s;margin-top:30px}";
ptr += ".mi-boton:hover{background-color:#218838}";
ptr += "</style>\n";
ptr += "</head>\n";
ptr +="<body>\n";
ptr +="<h1>PARQUEOS</h1>\n";
ptr +="<div id=contador-container>\n";
ptr +="<h2>ESPACIOS DISPONIBLES</h2>\n";
ptr +="<span id=contador>8</span>\n";
ptr +="</div>\n";
ptr +="<div class=fila>\n";
ptr +="<div class=parqueo>1</div>\n";
ptr +="<div class=parqueo>2</div>\n";
ptr +="<div class=parqueo>3</div>\n";
ptr +="<div class=parqueo>4</div>\n";
ptr +="</div>\n";
ptr +="<div class=\"fila luces-fila\">\n";
ptr +="<div class=luces>\n";
ptr +="<div class=\"luz rojo-libre\"></div>\n";
ptr +="<div class=\"luz verde-libre\"></div>\n";
ptr +="</div>\n";
ptr +="<div class=luces>\n";
ptr +="<div class=\"luz rojo-libre\"></div>\n";
ptr +="<div class=\"luz verde-libre\"></div>\n";
ptr +="</div>\n";
ptr +="<div class=luces>\n";
ptr +="<div class=\"luz rojo-libre\"></div>\n";
ptr +="<div class=\"luz verde-libre\"></div>\n";
ptr +="</div>\n";
ptr +="<div class=luces>\n";
ptr +="<div class=\"luz rojo-libre\"></div>\n";
ptr +="<div class=\"luz verde-libre\"></div>\n";
ptr +="</div>\n";
ptr +="</div>\n";
ptr +="<div class=\"fila luces-fila\">\n";
ptr +="<div class=luces>\n";
ptr +="<div class=\"luz rojo-libre\"></div>\n";
ptr +="<div class=\"luz verde-libre\"></div>\n";
ptr +="</div>\n";
ptr +="<div class=luces>\n";
ptr +="<div class=\"luz rojo-libre\"></div>\n";
ptr +="<div class=\"luz verde-libre\"></div>\n";
ptr +="</div>\n";
ptr +="<div class=luces>\n";
ptr +="<div class=\"luz rojo-libre\"></div>\n";
ptr +="<div class=\"luz verde-libre\"></div>\n";
ptr +="</div>\n";
ptr +="<div class=luces>\n";
ptr +="<div class=\"luz rojo-libre\"></div>\n";
ptr +="<div class=\"luz verde-libre\"></div>\n";
ptr +="</div>\n";
ptr +="</div>\n";
ptr +="<div class=fila>\n";
ptr +="<div class=parqueo>5</div>\n";
ptr +="<div class=parqueo>6</div>\n";
ptr +="<div class=parqueo>7</div>\n";
ptr +="<div class=parqueo>8</div>\n";
ptr +="</div>\n";
ptr +="<button class=mi-boton onclick=ocuparParqueos()>Simular ocupación</button>\n";
ptr += "<script>";
ptr += "function ocuparParqueos(){";
ptr += "const luces=document.querySelectorAll('.luces');";
ptr += "const parqueos=document.querySelectorAll('.parqueo');";
ptr += "const totalEspacios=luces.length;";
ptr += "const cantidadOcupar=Math.floor(Math.random()*(totalEspacios+1));";
ptr += "const indices=[];";
ptr += "while(indices.length<cantidadOcupar){";
ptr += "const i=Math.floor(Math.random()*totalEspacios);";
ptr += "if(!indices.includes(i)){indices.push(i);}";
ptr += "}";
ptr += "indices.forEach(i=>{";
ptr += "const rojo=luces[i].children[0];";
ptr += "const verde=luces[i].children[1];";
ptr += "rojo.classList.remove('rojo-libre');";
ptr += "rojo.classList.add('rojo-ocupado');";
ptr += "verde.classList.remove('verde-libre');";
ptr += "verde.classList.add('verde-ocupado');";
ptr += "const img=document.createElement('img');";
ptr += "img.src='https://cdn-icons-png.flaticon.com/512/7436/7436375.png';";
ptr += "img.alt='Carro';";
ptr += "img.classList.add('carro-img');";
ptr += "parqueos[i].appendChild(img);";
ptr += "});";
ptr += "document.getElementById('contador').innerText=totalEspacios-cantidadOcupar;";
ptr += "setTimeout(()=>{";
ptr += "indices.forEach(i=>{";
ptr += "const rojo=luces[i].children[0];";
ptr += "const verde=luces[i].children[1];";
ptr += "rojo.classList.remove('rojo-ocupado');";
ptr += "rojo.classList.add('rojo-libre');";
ptr += "verde.classList.remove('verde-ocupado');";
ptr += "verde.classList.add('verde-libre');";
ptr += "const img=parqueos[i].querySelector('img');";
ptr += "if(img)parqueos[i].removeChild(img);";
ptr += "});";
ptr += "document.getElementById('contador').innerText=totalEspacios;";
ptr += "},3000);";
ptr += "}";
ptr += "</script>\n";

ptr +="</body>\n";
ptr +="</html>";

  return ptr;
}