/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>

//char imagen1 = "FINN_A~1.TXT";
//char imagen2 = "NUBE_A~1.TXT";
//char imagen3 = "UNICOR~1.TXT";
 
File root;
File myFile;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  SPI.setModule(0);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(10, OUTPUT);

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  root = SD.open("/ASCII_~1/");

  //printDirectory(root, 0);

  Serial.println("Se han cargado los archivos");

  String receivedData = Serial.readString();
  Serial.println(receivedData);
}
void loop()
{
  delay(500);

  Serial.println("\n\nMenu:\n1.  1\n2. Option 2\n3. Option 3");
  //Wait for response
  while (!Serial.available());    
  String readVal = Serial.readStringUntil('\n');
  delay(100);
  switch(readVal[0]){
    case '1':
      Serial.println("This is option 1");
      //printFile(myFile, "FINN_A~1.TXT");
      myFile = SD.open("FINN_A~1.TXT");
  if (myFile) {
    Serial.println("FINN_A~1.TXT");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening ");
    //Serial.print(file_name);
  }

      break;
    case '2':
      Serial.println("This is option 2");
      //printFile(myFile, "NUBE_A~1.TXT");
            myFile = SD.open("NUBE_A~1.TXT");
  if (myFile) {
    Serial.println("NUBE_A~1.TXT");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening ");
    //Serial.print(file_name);
  }
}
      break;
    case '3':
      Serial.println("This is option 3");
      //printFile(myFile, "UNICOR~1.TXT");

        myFile = SD.open("UNICOR~1.TXT");
  if (myFile) {
    Serial.println("UNICOR~1.TXT");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening ");
    //Serial.print(file_name);
  }
}
      break;
    default:
      Serial.print(readVal[0]);
      Serial.println(" invalid input");
      break;
  }
  


void printDirectory(File dir, int numTabs) {
   while(true) {
     
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}

/*void printFile(File dir, char *file_name){
  dir = SD.open(file_name);
  if (dir) {
    Serial.println(file_name);

    // read from the file until there's nothing else in it:
    while (dir.available()) {
      Serial.write(dir.read());
    }
    // close the file:
    dir.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening ");
    //Serial.print(file_name);
  }
}
*/
