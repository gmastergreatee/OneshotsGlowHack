
/* @'   @+          @;         @@@@@         @@@@@,                  @
   @@  ;@+          @;         @,  @         @'  @,                  @           @
   @@, @@+ +@@@: @@@@; @@@@    @,  @ @; '@   @'  @, @@@@  @@@@ :@@@' @@@@, @@@@:@@@#
   @,@.@#+ ,. ## @  @; @  @    @@@@@ ,@ @:   @'  @, @` @` @  @ +@ :; @, @; @  @' @.
   @ @@:#+ '@@@# @  @; @@@@    @,  @  @ @    @'  @, @  @` @@@@  @@@  @  @; @  @' @.
   @ '@ #+ @. @# @  @; @  .    @,  @  '@     @;  @, @  @` @  . `` +@ @  @; @  @' @.
   @    #+ @@@@# @@@@; @@@@    @@@@@ :@:     @@@@@. @  @. @@@@ '@@@@ @` @; @@@@' @@+ */
#include "OneshotsGlowHack.h"
CHackProcess fProcess; // Object made so we can use the class functions
Offsets O;
Glow G; // GlowClass Object 
int main() // our start this code runs first.
{
	system("title CSGO GlowHack by OneShot and gmastergreatee");
	try {
		loadOffsets();
	}
	catch (char* error) {
		std::cout << error << std::endl << "Hit \"Enter\" key to exit...";
		getchar();
		return 1;
	}

	bool gloActive = false;
	bool gloAll = false;
	bool gloBothTeam = false;
	int maxPlayersAllowed = 50;

	std::cout << "Please run this file with Admin-priviledges for it to work correctly" << std::endl << "Searching for the running game, csgo.exe..." << std::endl;
	fProcess.RunProcess();
	displayStat(gloActive, maxPlayersAllowed, gloAll, gloBothTeam);
	while (true) // a while loop that we have to run our code over and over until we shut it down.
	{
		//toggle glow hack
		if (GetAsyncKeyState(VK_F12)) {
			gloActive = !gloActive;
			if (gloActive) {
				Beep((DWORD)5000, (DWORD)100);
			}
			else {
				Beep((DWORD)2500, (DWORD)100);
			}
			displayStat(gloActive, maxPlayersAllowed, gloAll, gloBothTeam);
		}
		//decrement max glow players
		if (GetAsyncKeyState(VK_F6)) {
			if (maxPlayersAllowed > 1) {
				maxPlayersAllowed -= 1;
				displayStat(gloActive, maxPlayersAllowed, gloAll, gloBothTeam);
			}
		}
		//increment max glow players
		if (GetAsyncKeyState(VK_F7)) {
			if (maxPlayersAllowed < 64) {
				maxPlayersAllowed += 1;
				displayStat(gloActive, maxPlayersAllowed, gloAll, gloBothTeam);
			}
		}
		//glow all or players only
		if (GetAsyncKeyState(VK_F8)) {
			gloAll = !gloAll;
			displayStat(gloActive, maxPlayersAllowed, gloAll, gloBothTeam);
			Beep((DWORD)2000, (DWORD)100);
		}
		//glow player team or both team
		if (GetAsyncKeyState(VK_F9)) {
			gloBothTeam = !gloBothTeam;
			displayStat(gloActive, maxPlayersAllowed, gloAll, gloBothTeam);
			Beep((DWORD)2000, (DWORD)100);
		}
		//Reset to defaults
		if (GetAsyncKeyState(VK_F10)) {
			gloAll = false;
			gloBothTeam = false;
			maxPlayersAllowed = 50;
			Beep((DWORD)5000, (DWORD)100);
			displayStat(gloActive, maxPlayersAllowed, gloAll, gloBothTeam);
		}

		if (gloActive) {
			G.Run(maxPlayersAllowed, gloAll, gloBothTeam);
		}
		Sleep(1); // Sleep of 1ms so we dont eat too much cpu power.
	}

	return 0;
}

void displayStat(bool& isActivated, int& maxPlayers, bool& gloAll, bool& gloBothTeam) {
	system("cls");
	std::cout << "GlowHack 2018-01-11 (non-steam tested)" << std::endl
		<< "[OneshotGH & gmastergreatee]" << std::endl
		<< "=======================================================================================" << std::endl << std::endl
		<< "Activation Status(F12)      : " << (isActivated == true ? "Activated" : "De-Activated") << std::endl
		<< "Max PlayerCount(F6/F7)      : " << maxPlayers << std::endl
		<< "Player/Weapon Glow Mode(F8) : " << (gloAll == true ? "Glow All Players + Weapons" : "Glow Selected Team Players Only") << std::endl
		<< "Team Glow Mode(F9)          : " << (gloBothTeam == true ? "Glow Both Teams" : "Glow Enemy Team") << std::endl << std::endl
		<< "=======================================================================================" << std::endl << std::endl
		<< "F12   : Toggle GlowHack (deactivate while changing maps to avoid unnecessary crashes)" << std::endl
		<< "F1    : Toggle Team Colors" << std::endl
		<< "F6/F7 : Decrease/Increase MaxPlayerCount to Highlight" << std::endl
		<< "F8    : Toggle glow (selected team players)/(all players & weapons)" << std::endl
		<< "F9    : Toggle glow (enemy team)/(both teams)" << std::endl
		<< "F10   : Reset all settings to defaults" << std::endl << std::endl
		<< "=======================================================================================" << std::endl << std::endl
		<< "Note : Need to run this app again to attach to a new csgo.exe instance" << std::endl
		<< "Keep settings to default for optimum performance" << std::endl;
	Sleep(100); // Sleep of 100ms so that the values don't change rapidly
}

void loadOffsets() {
	std::ifstream inFile;

	std::string inputFileName = "csgo.toml";

	inFile.open(inputFileName);

	if (inFile.is_open()) {
		int netvarIndex = 0;
		int signatureIndex = 0;
		bool start = false;

		while (!inFile.eof()) {
			std::string line;

			std::getline(inFile, line);

			if (netvarIndex < 2) {
				int index = line.find("m_");
				if (index >= 0 && index < 1000) {
					setOffset(line);
					netvarIndex++;
				}
			}
			else if (signatureIndex < 4) {
				int index = line.find("dw");
				if (index >= 0 && index < 1000) {
					setOffset(line);
					signatureIndex++;
				}
			}
		}
	}
	else {
		throw "Unable to find file \"csgo.toml\".\n\nFollow below steps to generate the file(also to update the hack) :-\n\n1. Run \"csgo.exe\", connect to an online server & join a team.\n2. Run \"HazeDumper.exe\" with admin priviledges.\n3. After you see some offsets in the console, close the HazeDumper console.\n\nDone, the file(csgo.toml) has been successfully generated. Enjoy, the hack";
	}
}

void setOffset(std::string line) {
	int splitOffset = line.find(" = ");
	int realOffset = std::stoi(line.substr(splitOffset + 3));
	std::string offsetType = line.substr(0, splitOffset);

	if (offsetType == "m_iHealth") {
		O.m_iHealth = realOffset;
	}
	else if (offsetType == "m_iTeamNum") {
		O.m_iTeamNum = realOffset;
	}
	else if (offsetType == "dwEntityList") {
		O.m_dwEntityList = realOffset;
	}
	else if (offsetType == "dwGlowObjectManager") {
		O.m_dwGlowObject = realOffset;
	}
	else if (offsetType == "dwLocalPlayer") {
		O.m_dwLocalPlayer = realOffset;
	}
}