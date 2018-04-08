import processing.serial.*;
import processing.sound.*;
SoundFile file;
Serial connection;

String val;
int isPlaying = 0;
void setup () {
 String portName = Serial.list()[0];
 println(portName);
 connection = new Serial(this, portName, 9600);

 file = new SoundFile(this, "ravel.mp3");
}

void draw () {
 if (connection.available() > 0) {
    val = connection.readStringUntil('\n');
 }
 if (isPlaying == 0 && val != null && float(val) > 70 && float(val) < 100) {
   print(val);
   print("play!");
   isPlaying = 1;
   file.play();
   file.jump(250);
   delay(20000); // play for 20 s
   file.stop();
   println("stop");
 }
 
 if (isPlaying == 0) {
  println(val); 
 }
}
