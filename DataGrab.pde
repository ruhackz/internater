import processing.serial.*;
import java.io.*;
Serial mySerial;

String myString = null;
float myVal;

BufferedWriter writer;

void setup()
{
  size (200, 400);
  
  String myPort = Serial.list()[0];
  mySerial = new Serial(this, myPort, 9600);
  try
  {
    writer = new BufferedWriter(new FileWriter("test.txt"));
  }
  catch (IOException e)
  {
    println (e.getMessage());
  }
  
}

void draw ()
{
  int counter = 0;
  
  while (counter < 5)
  {
    while (mySerial.available() > 0)
    {
      myString = mySerial.readStringUntil('\n');
      
      if (myString != null)
      {
        background(0);
        //String delimit[] = myString.split(",");
        try
        {
          writer.write(myString);
        }
        catch (IOException e)
        {
          println (e.getMessage());
        }
        
        //myVal = float(myString);
        //println (myVal);
        println (myString);
      }
    }
    counter++;
  }
  try
  {
    writer.close();
  }
  catch (IOException e)
  {
    println (e.getMessage());
  }
}
