/*
"----Command list:---"
"a?------------Get active antenna number"
"a0------------All off"
 "a1------------Antenna 1"
"a2------------Antenna 2"
"a3------------Antenna 3"
"a4------------Antenna 4"
"all-----------All ON!"

"address-(0-254)------Set new rs485 address"
"da?-----------Get Default antenna port"
"da (number)---Set Default antenna port"
"t?-------------Get Temperature"
"rs_term_on----BUS Termination Enabled"
"rs_term_off---BUS Termination Disabled"
"reboot -------System Restart"
"load----------Firmware update"
"?-------------Get command list"

Special commands
"255-<spacja> -?" - --------get command list
255 -<spacja> -reboot"--- reboot wszystkich switchy
255-<spacja> - a0" wyłącz wszytskie antenny na wszytkich switchach
*/
int ActiveAntennaPort;
int ActiveSwitchAddress;

String getActiveAntena = ActiveSwitchAddress + " a?";
String getActiveAntenaPort = ActiveSwitchAddress + " da?";
String setActiveAntenaPort = ActiveSwitchAddress + " da " + ActiveAntennaPort;

String switchAllAnntenasOFF = ActiveSwitchAddress + " a0";
String switchAllAnntenasON = ActiveSwitchAddress + " all";
String switchOnAntena1 = ActiveSwitchAddress + " a1";
String switchOnAntena2 = ActiveSwitchAddress + " a2";
String switchOnAntena3 = ActiveSwitchAddress + " a3";
String switchOnAntena4 = ActiveSwitchAddress + " a4";

String getSwitchTemp = ActiveSwitchAddress + " t?";
String rebootSwitch  = ActiveSwitchAddress + " reboot";
String enableTermination = ActiveSwitchAddress + " rs_term_on";
String disableTermination = ActiveSwitchAddress + " rs_term_off";

String rebootAllSwitches = "255 reboot";
String switchAllSwitchesAnntenasOFF = "255 a0";


void SendToSwitch(String command) // Send Command to switch
{
  for (int i = 0; i < command.length(); i++)
  {
    Serial2.write(command[i]);
  }
  Serial2.write("\r");
}

double GetTemperature() // Get temperature from controller - dummy value st the moment  [TBI]
{
  extern double currTemp;
  return currTemp;
}

void  GetDataFromSwitch() // Get data from switch
{
  String data_recievied;

  SendToSwitch(getActiveAntena);
  extern int currentAnt;
  if (Serial2.available())
  {
    data_recievied = Serial2.readStringUntil('\n');
    if ((data_recievied == "a1") or (data_recievied == "a2") or (data_recievied == "a3") or (data_recievied == "a4") or (data_recievied == "a0"))
    {
      currentAnt = 11; // data_recievied;
      data_recievied = "";
    }
    else
    {
      // placeholder to function returning issues with connectivity to switch
    }
  }
  SendToSwitch(getSwitchTemp);
  if (Serial2.available())
  {
    data_recievied = Serial2.readStringUntil('\n');
    if ((data_recievied.length() > 1) and (data_recievied.length() < 5))
    {
      double currTemp = 2.3; // data_recievied;
    }
    else
    {
      // placeholder to function returning issues with connectivity to switch
    }
  }
}

