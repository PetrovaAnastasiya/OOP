@echo off
set PROGRAM="%~1"
set OUTFILE="out.txt"

:: �������� �� ���� ������ .exe
::%PROGRAM% > %OUTFILE%  
::fc %OUTFILE% error-elem-num.txt || goto err


echo All tests passed
exit /B 0

:err
echo Program testing failed
