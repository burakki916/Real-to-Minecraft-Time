set /A waittime = 30; 
timeout /t 30
goto checkPortLoop
:checkPortLoop
	netstat -o -n -a | findstr 25565

	if %ERRORLEVEL% equ 0 goto FOUND
	echo port not found!
	:fin
:FOUND
	echo port found
	start "time set" cmd /c timeset.bat
	goto fin
:fin