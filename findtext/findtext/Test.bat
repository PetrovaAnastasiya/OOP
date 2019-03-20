@echo off
set PROGRAM="%~1"
set OUTFILE="out.txt"

:: �������� �� ������� ��������� � ������� ���������
%PROGRAM% weather.txt "weather" > %OUTFILE%
fc %OUTFILE% weather-out.txt || goto err

:: �������� �� ������� ������ � ������ �����
%PROGRAM% empty.txt "weather" > %OUTFILE%  
fc %OUTFILE% empty-out.txt || goto err

:: �������� �� �����, �������� ��� � ����e
%PROGRAM% weather.txt "mom" > %OUTFILE%  
fc %OUTFILE% empty-out.txt || goto err

:: �������� �� ������ ������
::%PROGRAM% input2.txt "" > %OUTFILE%  
::fc %OUTFILE% empty-out.txt || goto err

:: �������� �� ���� ����� ��� ������
%PROGRAM% weather.txt > %OUTFILE%  
fc %OUTFILE% error-elem-num.txt || goto err

:: �������� �� ���� ������ ��� ����� 
%PROGRAM% "mom" > %OUTFILE%  
fc %OUTFILE% error-elem-num.txt || goto err

:: �������� �� �������� �������������� �����
%PROGRAM% weaher.txt "weather" > %OUTFILE%  
fc %OUTFILE% err-file-open.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1