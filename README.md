# Real-to-Minecraft-Time
The time in Minecraft is correlated to the time in the real world 

## setup
1.) Go to the server folder and put your own server.jar there. the one already there probably won't be on the update you would like

2.) set up the Minecraft server as you would usually, except in the property file turn on rcon and set a rcon password

3.) get out of the server folder and put your password in ReconPassword.txt  

4.) ideally with the server not running run rttmc.exe

5.) make sure to turn off the daylight cycle in Minecraft or things could get weird. 
## how it works 

the program gets the current time then converts it to the Minecraft time equivalent with proportions. 

then it uses [mcrcon](https://github.com/Tiiffi/mcrcon) to communicate with the Minecraft server and periodically sets the time in Minecraft to the time IRL.

ngl probably doesn't need to be done once a minute lol but I didn't want the sun and moon to be too jumpy. maybe later on ill set, it so where you can check it in a config file how long it takes to update. 

## other 
I got the idea from pokemon gold/silver. when I first played those games I thought it was amazing how the time in the game was similar to the time IRL so I decided to make it in Minecraft.  

also if you want to contact me my discord is rakki#6662

and if you got any ideas on how to improve the code, let me hear them. can't say ill implement it in the future but I still like hearing where I'm doing bad at. I'm not very experienced. 
