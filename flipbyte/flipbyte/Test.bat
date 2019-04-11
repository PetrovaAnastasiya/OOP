@echo off
set PROGRAM="%~1"
set OUTFILE="out.txt"

:: Проверка на ввод только .exe
%PROGRAM% > %OUTFILE%  
fc %OUTFILE% error-elem-num.txt || goto err

:: Проверка на ввод большего кол-ва аргументов 
%PROGRAM% "-1" "-1"> %OUTFILE%  
fc %OUTFILE% error-elem-num.txt || goto err

:: Проверка на  число, которое не входит в [0;255] (<0)
%PROGRAM% "-1" > %OUTFILE%  
fc %OUTFILE% range-error.txt || goto err

:: Проверка на число, которое не входит в [0;255] (>255)
%PROGRAM% "256" > %OUTFILE%  
fc %OUTFILE% range-error.txt || goto err

:: Проверка на число, которое входит в диапазон 
%PROGRAM% "6" > %OUTFILE%  
fc %OUTFILE% output_6.txt || goto err

:: Проверка на 0
%PROGRAM% "0" > %OUTFILE%  
fc %OUTFILE% output_0.txt || goto err

:: Проверка на 255
%PROGRAM% "255" > %OUTFILE%  
fc %OUTFILE% output_255.txt || goto err
	
:: ввод не верного параметра 
%PROGRAM% "kgjlkdg" > %OUTFILE%  
fc %OUTFILE% parameter_error.txt || goto err

:: ввод не верного параметра 
%PROGRAM% "123dfks" > %OUTFILE%  
fc %OUTFILE% parameter_error.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
