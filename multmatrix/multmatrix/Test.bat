@echo off
set PROGRAM="%~1"
set OUTFILE="out.txt"

::Проверка на ввод только .exe
%PROGRAM% > %OUTFILE%
fc %OUTFILE% error-elem-num.txt || goto err

:: Проверка на ввод большего кол-ва аргументов 
%PROGRAM% matrix1.txt matrix2.txt matrix1.txt > %OUTFILE%
fc %OUTFILE% error-elem-num.txt || goto err

:: Проверка на ввод меньшего кол-ва аргументов 
%PROGRAM% matrix1.txt > %OUTFILE%
fc %OUTFILE% error-elem-num.txt || goto 

:: Проверка на несуществующий файл
%PROGRAM% matrix1.txt matrix3.txt > %OUTFILE%
fc %OUTFILE% error-file-open.txt || goto err

%PROGRAM% matrix3.txt matrix1.txt > %OUTFILE%
fc %OUTFILE% error-file-open.txt || goto err

::Проверка на два несуществующих файла
%PROGRAM% matrix3.txt matrix4.txt > %OUTFILE%
fc %OUTFILE% error-file-open.txt || goto err

::Проверка на A * B
%PROGRAM% matrix1.txt matrix2.txt > %OUTFILE%
fc %OUTFILE% result1.txt || goto err

::Проверка на B * A
%PROGRAM% matrix2.txt matrix1.txt > %OUTFILE%
fc %OUTFILE% result2.txt || goto err

::Проверка на A * единичная матрица
%PROGRAM% matrix1.txt matrixIdentity.txt > %OUTFILE%
fc %OUTFILE% result3.txt || goto err

::Проверка на единичная матрица * A
%PROGRAM% matrixIdentity.txt matrix1.txt > %OUTFILE%
fc %OUTFILE% result3.txt || goto err

echo All tests passed
exit /B 0

:err
echo Program testing failed
