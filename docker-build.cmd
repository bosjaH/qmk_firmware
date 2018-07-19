@echo off
cls
IF "%~1"=="" GOTO :showhelp
docker run -e keymap=%2 -e keyboard=%1 --rm -v %~dp0:/qmk:rw edasque/qmk_firmware
timeout 10
GOTO :end
:showhelp
echo Usage:
echo   docker-build keyboard keymap
echo Example:
echo   docker-build gh60 default
:end
