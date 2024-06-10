int light = 0; 

void setup() {
    
    Serial.begin(9600); 
    pinMode(13, OUTPUT); 
    pinMode(12, OUTPUT); 
}

void  loop() {
   
    light = analogRead(A0); 
    
    Serial.println(light); 
 
    if(light > 450) { 
        Serial.println("It  is quite light!");
        digitalWrite(13,LOW); 
        digitalWrite(12,LOW);  
    }
    else if(light > 229 && light < 451) { 
        Serial.println("It is average light!");
       digitalWrite(13, HIGH); 
       digitalWrite(12,LOW);  
    }
    else { 
        Serial.println("It  is pretty dark!");
        digitalWrite(13,HIGH); 
        digitalWrite(12,HIGH); 
    }
    delay(1000); 
}
