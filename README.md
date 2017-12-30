# OneshotsGlowHack
GlowHack for CSGO
- core programming by [OneShot](https://github.com/OneshotGH)
- menu options by [gmastergreatee](https://github.com/gmastergreatee)

This project is created to help starters`(not pros & whoever comes in between)` to get up to speed with the high skill level required in online server matches against human players.

NOTE : The method used in this app is 100% VAC proof(tested myself on multiple servers). But still, use it at your own risk.

Release download __(Update 30 Dec, 2017)__ : click [here](https://github.com/gmastergreatee/OneshotsGlowHack/releases/download/20171230/OneshotsGlowHack.exe)

And no, __Aimbot__ will not be integrated as `wall-hack` must be enough for starters

## Steps to update the hack yourself

I'm assuming that you have already installed Visual Studio

- Clone/Download this repository
- Go to the repo's root folder & open __"OneshotsGlowHack.sln"__ file in visual studio
- In the solution explorer, open "Header Files/Offsets.h"
- There you will see the base offsets from __line 21__ to __line 25__
- Now go back to the repo's root folder & then go into __"HazeDumper"__ folder
- Run the updated game(csgo.exe) & join any team in an online server
- Now run __"hazedumper-rs-v0.2.1.exe"__ present in __"HazeDumper"__ folder as administrator
- All the required offsets will be dumped & displayed on the console
- Update the values in __"Offsets.h"__ file(__line 21__ to __line 25__) as displayed in the console
- Now build the visual studio project & done. Off you go playing. :smile:

For newbies in programming, let me tell you that the updated hack will be generated inside the root __"Release"__ folder

Enjoy, have a great day!
Cya
gmastergreatee

__Note :__ If you do update the project before me, please send a pull request. Thanks