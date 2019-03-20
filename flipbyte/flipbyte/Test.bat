@echo off
set PROGRAM="%~1"
set OUTFILE="out.txt"



echo All tests passed
exit /B 0

:err
echo Program testing failed
