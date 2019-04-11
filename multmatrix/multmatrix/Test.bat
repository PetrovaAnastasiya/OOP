@echo off
set PROGRAM="%~1"
set OUTFILE="out.txt"

::�������� �� ���� ������ .exe
%PROGRAM% > %OUTFILE%
fc %OUTFILE% error-elem-num.txt || goto err

:: �������� �� ���� �������� ���-�� ���������� 
%PROGRAM% matrix1.txt matrix2.txt matrix1.txt > %OUTFILE%
fc %OUTFILE% error-elem-num.txt || goto err

:: �������� �� ���� �������� ���-�� ���������� 
%PROGRAM% matrix1.txt > %OUTFILE%
fc %OUTFILE% error-elem-num.txt || goto 

:: �������� �� �������������� ����
%PROGRAM% matrix1.txt matrix3.txt > %OUTFILE%
fc %OUTFILE% error-file-open.txt || goto err

%PROGRAM% matrix3.txt matrix1.txt > %OUTFILE%
fc %OUTFILE% error-file-open.txt || goto err

::�������� �� ��� �������������� �����
%PROGRAM% matrix3.txt matrix4.txt > %OUTFILE%
fc %OUTFILE% error-file-open.txt || goto err

::�������� �� A * B
%PROGRAM% matrix1.txt matrix2.txt > %OUTFILE%
fc %OUTFILE% result1.txt || goto err

::�������� �� B * A
%PROGRAM% matrix2.txt matrix1.txt > %OUTFILE%
fc %OUTFILE% result2.txt || goto err

::�������� �� A * ��������� �������
%PROGRAM% matrix1.txt matrixIdentity.txt > %OUTFILE%
fc %OUTFILE% result3.txt || goto err

::�������� �� ��������� ������� * A
%PROGRAM% matrixIdentity.txt matrix1.txt > %OUTFILE%
fc %OUTFILE% result3.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
