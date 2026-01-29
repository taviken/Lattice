@echo off
REM --- Define the folder path you want to delete ---
SET FOLDER_PATH="build"

REM --- Check if the folder exists before attempting deletion ---
IF EXIST %FOLDER_PATH% (
    REM Use RD /S /Q to remove the directory and all its contents
    RD /S /Q %FOLDER_PATH%
    ECHO %FOLDER_PATH% has been deleted.
) ELSE (
    ECHO %FOLDER_PATH% not found.
)

