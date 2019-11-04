// Arduino adapation of  Samoylov Eugene aka Helius microrl lib (ghelius@gmail.com)
// GNU licence
// E.Droz 1.11.2019

#include <microrl.h>

// create microrl object and pointer on it
microrl_t rl;


void setup()
{
   Serial.begin(115200);

   Serial.print ("\n________________ microrl for Arduino _______________\n");
   
   
   microrl_init (&rl,Serial);
   microrl_set_execute_callback (&rl, command);
}

void loop()
{

   microrl_run(&rl);

  // delay(10); 
}


#define HELP() if (strcmp(argv[0], "help")==0)


int command (int argc, const char * const * argv)
{
      HELP(){//                 : 
         Serial.print("hello          : Return world !\n");
      }; 
      if  (strcmp (argv[0], "hello") == 0) 
      {
            Serial.print("World ! \n"); 
         return 0;
      }
     
     
            
      HELP(){ return 0;}
      
      //error message if command was not used
      //for (int i=0; i<argc;i++)printf("%s ",argv[i]);
      Serial.print ("command not found or arguments error\n");
}



 
