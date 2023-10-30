/*
stepper.setMaxSpeed(1000); //최대속도
stepper.setCurrentPosition(0); //현재 스탭을 설정
stepper.currentPosition(); //현재 스탭을 반환
stepper.setSpeed(200); //스탭모터의 방향과 속도를 설정
stepper.runSpeed(); //스탭모터 작동(고정속도)
stepper.setAcceleration(2000); //가속량을 설정함
stepper.moveTo(1000); //목표스탭량을 설정함
stepper.runToPosition(); //가속도를 붙혀서 스탭모터제어
*/


#include <AccelStepper.h>

#define DIR1 5
#define STEP1 2
#define DIR2 6
#define STEP2 3 
#define DIR3 7
#define STEP3 4
#define STEP4 12
#define DIR4 13

AccelStepper stepper1 = AccelStepper(1, STEP3, DIR3); //z축
AccelStepper stepper2 = AccelStepper(1, STEP2, DIR2); //y축
AccelStepper stepper3 = AccelStepper(1, STEP1, DIR1); //x축
AccelStepper stepper4 = AccelStepper(1, STEP4, DIR4); //A축

int speed = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//결과를 시리얼모니터에서 볼거야~
  stepper1.setMaxSpeed(500); //초당 몇스탭이냐? 1000/s(초당5회전)
  stepper1.setAcceleration(500);
  stepper1.setCurrentPosition(0); //현재 스탭을 설정
  stepper2.setMaxSpeed(500); //초당 몇스탭이냐? 1000/s(초당5회전)
  stepper2.setAcceleration(500);
  stepper2.setCurrentPosition(0); //현재 스탭을 설정
  stepper3.setMaxSpeed(100); //초당 몇스탭이냐? 1000/s(초당5회전)
  stepper3.setAcceleration(100);
  stepper3.setCurrentPosition(0); //현재 스탭을 설정
  stepper4.setMaxSpeed(1500); //초당 몇스탭이냐? 1000/s(초당5회전)
  stepper4.setAcceleration(1500);
  stepper4.setCurrentPosition(0); //현재 스탭을 설정

}

//메인스레드
void loop() {
  // put your main code here, to run repeatedly:
  //스탭모터 1번이 시계방향으로 1회전한다
  
  stepper1.setCurrentPosition(0);//0점 조절 
  stepper1.moveTo(240);
  stepper1.runToPosition();
  Serial.print("step1");
  stepper1.stop();
  delay(2000);
  
  stepper2.setCurrentPosition(0);
  stepper2.moveTo(160);
  stepper2.runToPosition();
  Serial.print("step3");
  stepper2.stop();
  delay(2000);
  
  stepper4.setCurrentPosition(0);
  stepper4.moveTo(-120);
  stepper4.runToPosition();
  Serial.print("step2");
  stepper4.stop();
  delay(5000);

  stepper3.setCurrentPosition(0);
  stepper3.moveTo(30);
  stepper3.runToPosition();
  Serial.print("step2");
  stepper3.stop();
  delay(4000);

  stepper2.moveTo(-40);
  stepper2.runToPosition();
  Serial.print("step2");
  stepper2.stop();
  delay(2000);

  stepper1.moveTo(-80);
  stepper1.runToPosition();
  Serial.print("step1");
  stepper1.stop();
  delay(2000);

  stepper2.setCurrentPosition(0);
  stepper2.moveTo(30);
  stepper2.runToPosition();
  Serial.print("step3");
  stepper2.stop();
  delay(2000);

  stepper4.moveTo(120);
  stepper4.runToPosition();
  Serial.print("step2");
  stepper4.stop();
  delay(6000);
  
}
