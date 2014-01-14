@echo off&color 1E
echo 正在处理%1
rmdir /s /q bookdir
rmdir /s /q bookdir_ok
rmdir /s /q %~n1
mkdir bookdir
mkdir bookdir_ok

echo unziping...

copy 7za.exe bookdir
copy %1 bookdir
rename %1 %~n1_1%~x1
cd bookdir
7za e %~n1%~x1>temp.txt
del 7za.exe
cd ..

echo working...


copy work.exe bookdir
cd bookdir
for %%i in (*.txt) do work %%i>temp.txt

del work.exe

cd ..

echo ziping

copy 7za.exe bookdir_ok
cd bookdir_ok
del temp*
7za a -tzip temp%~x1 *.txt>temp.txt
del 7za.exe
copy *%~x1 ..
cd ..
rename temp%~x1 %~n1%~x1
echo cleaning
rmdir /s /q bookdir
rmdir /s /q bookdir_ok