@echo off
cls
docker run -e keymap=joren -e keyboard=kc60 --rm -v %~dp0/../../../..:/qmk:rw edasque/qmk_firmware
timeout 10
