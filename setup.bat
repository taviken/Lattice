@echo off
set "DirectoryPath=build"

if not exist "%DirectoryPath%\" (
    mkdir "%DirectoryPath%"
    echo Folder created: %DirectoryPath%
) else (
    echo Folder already exists: %DirectoryPath%
)
