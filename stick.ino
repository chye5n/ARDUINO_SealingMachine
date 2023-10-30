#

#define DIR1 5	//x축
#define STEP1 2	//x축
#define DIR2 6	//y축
#define STEP2 3	//y축
#define btn 4	//조이스틱 눌렀을 때
#define MS1 7	//마이크로 스텝
#define MS2 8	//마이크로 스텝
#define MS3 9	//마이크로 스텝

AccelStepper stepper2 = AccelStepper(1, STEP2, DIR2);	//y축
AccelStepper stepper3 = AccelStepper(1, STEP1, DIR1);	//x축

int xPosition = 0;
int yPosition = 0;
int xpin = A1;	//조이스틱 x 아날로그 받는 핀
int ypin = A0;	//조이스틱 y 아날로그 받는 핀
int speed = 1000;

void mprec(int div)	//motor precision: 0(full step) - 4(1/16 step)
{
	int trms[5][3] = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {1, 1, 0}, {1, 1, 1}};
	if(div > 4)
	{
		Serial.print("unknown");
		exit(1);
	}
	if(MS1 != 99){digitalWrite(MS1, trms[div][0];
	if(MS2 != 99){digitalWrite(MS2, trms[div][1];
	if(MS3 != 99){digitalWrite(MS3, trms[div][2];
}

void setup()
{
	Serial.begin(9600);	//결과를 시리얼모니터로 확인
	stepper2.setMaxSpeed(1000);	//초당 몇스텝? 1000/s(초당 5회전)
	stepper2.setAcceleration(50);
	stepper2.setCurrentPosition(0);	//현재 스탭을 설정
	stepper3.setMaxSpeed(1000);	//초당 몇스텝? 1000/s(초당 5회전)
	stepper3.setAcceleration(50);
	stepper3.setCurrentPosition(0);	//현재 스탭을 설정
	pinMode(DIR1, OUTPUT);	//x축 방향
	pinMode(STEP1, OUTPUT);	//x축 스텝
	pinMode(DIR2, OUTPUT);	//y축 방향
	pinMode(STEP2, OUTPUT);	//y축 스텝
	pinMode(xpin, INPUT);	//조이스틱 x
	pinMode(ypin, INPUT);	//조이스틱 y
	pinMode(MS1, OUTPUT);	//마이크로스텝핀
	pinMode(MS2, OUTPUT);	//마이크로스텝핀
	pinMode(MS3, OUTPUT);	//마이크로스텝핀
}

void loop()
{
	xPosition = analogRead(xpin);	//x위치 아날로그 신호
	yPosition = analogRead(ypin);	//y위치 아날로그 신호

	stepper2.setCurrentPosition(0);	//영점
	stepper3.setCurrentPosition(0);	//영점

	//조이스틱 위치값
	if(xPosition < 800)
	{
		mprec(3);	//motor precision: 0(full step) -4(1/16 step)
		digitalWrite(DIR2, HIGH);
		digitalWrite(STEP2, HIGH);
		delayMicroseconds(500);
		digitalWrite(STEP2, LOW);
		delayMicroseconds(500);
		Serial.print("X : ");
		delay(2);
		Serial.print(xPosition);
	}
	if(xPosition > 200)
	{
		digitalWrite(DIR2, LOW);
		digitalWrite(STEP2, HIGH);
		delayMicroseconds(500);
		digitalWrite(STEP2, LOW);
		delayMicroseconds(500);
		Serial.print("X : ");
		delay(2);
		Serial.print(xPosition);
	}
	if(yPosition < 800)
	{
		digitalWrite(DIR1, HIGH);
		digitalWrite(STEP1, HIGH);
		delayMicroseconds(500);
		digitalWrite(STEP1, LOW);
		delayMicroseconds(500);
		Serial.print("Y : ");
		delay(2);
		Serial.print(yPosition);
	}
	if(yPosition > 200)
	{
		digitalWrite(DIR1, LOW);
		digitalWrite(STEP1, HIGH);
		delayMicroseconds(500);
		digitalWrite(STEP1, LOW);
		delayMicroseconds(500);
		Serial.print("Y : ");
		delay(2);
		Serial.print(yPosition);
	}
}