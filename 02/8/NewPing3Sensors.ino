// ---------------------------------------------------------------------------
// Example NewPing library sketch that pings 3 sensors 20 times a second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
/////////////////////변수///////////////////////////
#define SONAR_NUM 3      // Number of sensors.
#define MAX_DISTANCE 100 // Maximum distance (in cm) to ping.

//초음파 센서 
#define FL_TRIG_ECHO 9
#define FR_TRIG_ECHO 10
#define R_TRIG_ECHO 11

//초음파 데이터
float  FL_distance = 0.0,FR_distance = 0.0,R_distance = 0.0,
    FL_distance_old = 0.0,FR_distance_old = 0.0,R_distance_old = 0.0,
    FL_distance_error = 0.0,LR_distance_error = 0.0,R_distance_error = 0.0, distance_error=0.0;

/////////////////////함수///////////////////////////
NewPing Sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(FL_TRIG_ECHO, FL_TRIG_ECHO, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
  NewPing(FR_TRIG_ECHO, FR_TRIG_ECHO, MAX_DISTANCE),
  NewPing(R_TRIG_ECHO, R_TRIG_ECHO, MAX_DISTANCE)
};

void read_sonar_sensor(){
  FL_distance = Sonar[0].ping_cm()*10;
  FR_distance = Sonar[1].ping_cm()*10;
  R_distance = Sonar[2].ping_cm()*10;
  if(FL_distance == 0) FL_distance = MAX_DISTANCE * 10.0;
  if(FR_distance == 0) FR_distance = MAX_DISTANCE * 10.0;
  if(R_distance == 0) R_distance = MAX_DISTANCE * 10.0;
  
  Serial.print("FL_distance : ");
  Serial.print(FL_distance);
  Serial.print("mm  ");
  
  Serial.print("FR_distance : ");
  Serial.print(FR_distance);
  Serial.print("mm  ");
  
  Serial.print("R_distance : ");
  Serial.print(R_distance);
  Serial.println("mm");
}

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
 read_sonar_sensor();
 delay(500);
}
