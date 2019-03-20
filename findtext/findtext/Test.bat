@echo off
set PROGRAM="%~1"
set OUTFILE="out.txt"

:: Проверка на наличие подстроки и разницу регистров
%PROGRAM% weather.txt "weather" > %OUTFILE%
fc %OUTFILE% weather-out.txt || goto err

:: Проверка на наличие строки в пустом файле
%PROGRAM% empty.txt "weather" > %OUTFILE%  
fc %OUTFILE% empty-out.txt || goto err

:: Проверка на слово, которого нет в файлe
%PROGRAM% weather.txt "mom" > %OUTFILE%  
fc %OUTFILE% empty-out.txt || goto err

:: Проверка на пустую строку
::%PROGRAM% input2.txt "" > %OUTFILE%  
::fc %OUTFILE% empty-out.txt || goto err

:: Проверка на ввод файла без строки
%PROGRAM% weather.txt > %OUTFILE%  
fc %OUTFILE% error-elem-num.txt || goto err

:: Проверка на ввод строки без файла 
%PROGRAM% "mom" > %OUTFILE%  
fc %OUTFILE% error-elem-num.txt || goto err

:: Проверка на открытие несущесвующего файла
%PROGRAM% weaher.txt "weather" > %OUTFILE%  
fc %OUTFILE% err-file-open.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1