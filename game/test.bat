@echo off
del /q Log.txt
rd /s /q Game\x64\Debug
rd /s /q Game\x64\Release
rd /s /q .vs\Game\v17\ipch
