@echo off
for  %%i in (*) do (
  if not "%%i"=="%~nx0" (ffmpeg -i "%%i" -vn -codec copy "%%~ni.m4a"
  rem ffmpeg -i "%%i" -r 8 -s 640x480 -t 3 -ss 00:00:00 "%%i.gif"
  rem ���ķֱ��ʷ�����С
  )
)