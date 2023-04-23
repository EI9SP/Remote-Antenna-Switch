
void ProcessBT() // Process BT commands
{
  if (btCommand == "a0")
  {
    PrintMSG(btCommand);
    UpdateAntenaOnDisp(0);
    currentAnt = "a0";
  }
  if (btCommand == "a1")
  {
    PrintMSG(btCommand);
    UpdateAntenaOnDisp(1);
    currentAnt = "a1";
  }
  if (btCommand == "a2")
  {
    PrintMSG(btCommand);
    UpdateAntenaOnDisp(2);
    currentAnt = "a2";
  }
  if (btCommand == "a3")
  {
    PrintMSG(btCommand);
    UpdateAntenaOnDisp(3);
    currentAnt = "a3";
  }
  if (btCommand == "a4")
  {
    PrintMSG(btCommand);
    UpdateAntenaOnDisp(4);
    currentAnt = "a4";
  }
  if (btCommand == "rs_term_on")
  {
    PrintMSG(btCommand);
    PrintCMDOnDisp("Enable termination");
  }
  if (btCommand == "rs_term_off")
  {
    PrintMSG(btCommand);
    PrintCMDOnDisp("Disable termination");
  }
  if (btCommand == "reboot")
  {
    PrintMSG(btCommand);
    PrintCMDOnDisp("Rebooting remote unit");
  }
  if (btCommand == "load")
  {
    PrintMSG(btCommand);
    PrintCMDOnDisp("Connect unit for F/W update");
  }
}

String DirtyManualSwitch(String dir) // Process touch buttons
{
  if ((currentAnt == "a0") and (dir == "UP"))
  {
    currentAnt = "a1";
    UpdateAntenaOnDisp(1);
  }
  else if ((currentAnt == "a1") and (dir == "UP"))
  {
    currentAnt = "a2";
    UpdateAntenaOnDisp(2);
  }
  else if ((currentAnt == "a2") and (dir == "UP"))
  {
    currentAnt = "a3";
    UpdateAntenaOnDisp(3);
  }
  else if ((currentAnt == "a3") and (dir == "UP"))
  {
    currentAnt = "a4";
    UpdateAntenaOnDisp(4);
  }
  else if ((currentAnt == "a4") and (dir == "UP"))
  {
    currentAnt = "a0";
    UpdateAntenaOnDisp(0);
  }
  else if ((currentAnt == "a0") and (dir == "DOWN"))
  {
    currentAnt = "a4";
    UpdateAntenaOnDisp(4);
  }
  else if ((currentAnt == "a4") and (dir == "DOWN"))
  {
    currentAnt = "a3";
    UpdateAntenaOnDisp(3);
  }
  else if ((currentAnt == "a3") and (dir == "DOWN"))
  {
    currentAnt = "a2";
    UpdateAntenaOnDisp(2);
  }
  else if ((currentAnt == "a2") and (dir == "DOWN"))
  {
    currentAnt = "a1";
    UpdateAntenaOnDisp(1);
  }
  else if ((currentAnt == "a1") and (dir == "DOWN"))
  {
    currentAnt = "a0";
    UpdateAntenaOnDisp(0);
  }
  return currentAnt;
}


String ReturnAntenaToWWW() // Convert current antens too Integer for showing on WWW
{
  int webAnt;
  if (currentAnt == "a1")
  {
    webAnt = 1;
  }
  else if (currentAnt == "a2")
  {
    webAnt = 2;
  }
  else if (currentAnt == "a3")
  {
    webAnt = 3;
  }
  else if (currentAnt == "a4")
  {
    webAnt = 4;
  }
  else if (currentAnt == "a0")
  {
    webAnt = 0;
  }
  return String(webAnt);
}