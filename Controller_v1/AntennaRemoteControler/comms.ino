void PrintMSG(String command) // Send command to controller and debuging info to console & OLED - partially dummy [TBI]
{

  DEBUG_PRINT("Command: " + command);
  SendToSwitch(command);
  command = "";
}

String GetDataFromSwitch() // Get data from switch
{
  String data_recievied;
  SendToSwitch("ax");
  if (Serial2.available())
  {
    data_recievied = Serial2.readStringUntil('\n');
    if ((data_recievied == "a1") or (data_recievied == "a2") or (data_recievied == "a3") or (data_recievied == "a4") or (data_recievied == "a0"))
    {
      currentAnt = data_recievied;
      data_recievied = "";
    }
    else
    {
      //placeholder to function returning issues with connectivity to switch
    }
  }
  SendToSwitch("t");
  if (Serial2.available())
  {
    data_recievied = Serial2.readStringUntil('\n');
    if ((data_recievied.length() > 1) and (data_recievied.length() < 5))
    {
      currTemp = data_recievied;
    }
    else
    {
      //placeholder to function returning issues with connectivity to switch
    }
  }
}

void SendToSwitch(String command) // Send Command to switch
{
  for (int i = 0; i < command.length(); i++)
  {
    Serial2.write(command[i]);
  }
  Serial2.write("\r");
}

String GetTemperature() // Get temperature from controller - dummy value st the moment  [TBI]
{
  return currTemp;
}
