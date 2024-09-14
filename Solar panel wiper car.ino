


//driver Wiper Motor
  int in11 =12;
  int in21 =11;
  int in31 =10;
  int in41 =9;
//driver Car Motor
  int in12= 8;
  int in22 =7;
  int in32 =6;
  int in42 =5;
  //water pump contror
  int rel =4;
  //IR sensor
  int infr1 =A1;
  int infr2 =A2;
  //push button
  int button=A0;
  
 int infr1state= LOW;
 int infr2state= LOW;
 int buttonstate=LOW;


void setup() {


    pinMode(in11, OUTPUT);
    pinMode(in21, OUTPUT);
    pinMode(in31, OUTPUT);
    pinMode(in41, OUTPUT);

    pinMode(in12, OUTPUT);
    pinMode(in22, OUTPUT);
    pinMode(in32, OUTPUT);
    pinMode(in42, OUTPUT);
    
    pinMode(rel, OUTPUT);
    
    pinMode(infr1, INPUT);
    pinMode(infr2, INPUT);
    
    pinMode(button, INPUT);
     
    digitalWrite(rel, HIGH);



}

void loop() {
buttonstate= digitalRead(button);

      if(buttonstate ==HIGH){
        
        water (in11, in21, in31, in41, in12, in22, in32, in42, rel, infr1);
        clean (in11, in21, in31, in41, in12, in22, in32, in42, infr2);
        
      }
  


}


void water (int in11,int in21,int in31,int in41, int in12,int in22, int in32, int in42, int rel,int infr1){
  
  int n=0;
  
  
  while(n<1){
    infr1state= digitalRead(infr1);
    delay(550);
       if(infr1state==HIGH){
          digitalWrite(in11, LOW);
          digitalWrite(in21, HIGH);
          digitalWrite(in31, LOW);
          digitalWrite(in41, HIGH);
          digitalWrite(in12, HIGH);
          digitalWrite(in22, LOW);
          digitalWrite(in32, HIGH);
          digitalWrite(in42, LOW);
          digitalWrite(rel, LOW);
      }
       if(infr1state==LOW){
          digitalWrite(in11, LOW);
          digitalWrite(in21, LOW);
          digitalWrite(in31, LOW);
          digitalWrite(in41, LOW);
          digitalWrite(in12, LOW);
          digitalWrite(in22, LOW);
          digitalWrite(in32, LOW);
          digitalWrite(in42, LOW);
          digitalWrite(rel, HIGH);
           n++;
      }  
    }
  }



void clean (int in11,int in21,int in31,int in41,int in12,int in22, int in32, int in42, int infr2){
  
    int n=0;
    
    
    while(n<1){
      infr2state= digitalRead(infr2);
          if(infr2state==HIGH){
            digitalWrite(in11, HIGH);
            digitalWrite(in21, LOW);
            digitalWrite(in31, HIGH);
            digitalWrite(in41, LOW);
            digitalWrite(in12, LOW);
            digitalWrite(in22, HIGH);
            digitalWrite(in32, LOW);
            digitalWrite(in42, HIGH);

       }
          if(infr2state==LOW){
             digitalWrite(in12, LOW);
             digitalWrite(in22, LOW);
             digitalWrite(in32, LOW);
             digitalWrite(in42, LOW);
             delay(5000);
             digitalWrite(in11, LOW);
             digitalWrite(in21, LOW);
             digitalWrite(in31, LOW);
             digitalWrite(in41, LOW);
             
             n++;
         }
      }
   }
