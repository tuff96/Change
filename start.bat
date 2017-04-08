@echo off
echo Searching for UE project file...
IF EXIST %~dp0\*.uproject (
	echo Staring Unreal Engine Project file...
	FOR /R %~dp0 %%a IN (*.uproject) DO start %%a
	echo Succes!
	echo Searching for VS project file...
		if exist %~dp0\*.sln (
			echo Staring Visual Studio Project file...
			FOR /R %~dp0 %%a IN (*.sln) DO start %%a
			echo Succes!
		)else goto VSnotfound
)else goto UEnotfound
goto Succesfulyexit
	
:UEnotfound
echo UE project file not found!
pause
exit

:VSnotfound
echo VS project file not found!
pause
exit

:Succesfulyexit
exit