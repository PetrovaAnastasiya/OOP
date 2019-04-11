@echo off
set PROGRAM="%~1"
set OUTFILE="out.txt"

:: �������� �� ���� ������ .exe
%PROGRAM% > %OUTFILE%  
fc %OUTFILE% error-elem-num.txt || goto err

:: �������� �� ���� �������� ���-�� ���������� 
%PROGRAM% "-1" "-1"> %OUTFILE%  
fc %OUTFILE% error-elem-num.txt || goto err

:: �������� ��  �����, ������� �� ������ � [0;255] (<0)
%PROGRAM% "-1" > %OUTFILE%  
fc %OUTFILE% range-error.txt || goto err

:: �������� �� �����, ������� �� ������ � [0;255] (>255)
%PROGRAM% "256" > %OUTFILE%  
fc %OUTFILE% range-error.txt || goto err

:: �������� �� �����, ������� ������ � �������� 
%PROGRAM% "6" > %OUTFILE%  
fc %OUTFILE% output_6.txt || goto err

:: �������� �� 0
%PROGRAM% "0" > %OUTFILE%  
fc %OUTFILE% output_0.txt || goto err

:: �������� �� 255
%PROGRAM% "255" > %OUTFILE%  
fc %OUTFILE% output_255.txt || goto err
	
:: ���� �� ������� ��������� 
%PROGRAM% "kgjlkdg" > %OUTFILE%  
fc %OUTFILE% parameter_error.txt || goto err

:: ���� �� ������� ��������� 
%PROGRAM% "123dfks" > %OUTFILE%  
fc %OUTFILE% parameter_error.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
