$exeFiles = Get-ChildItem -Path "bin" -Filter *.exe

if ($exeFiles.Count -gt 0) {
    rm bin/main.exe
}

& mingw32-make -f Makefile

if ($LASTEXITCODE -eq 0) {
    & ./bin/main
}

# cd "c:\Users\Minh Thang Bui\source\repos\Game\" ; if ($?) { g++ -Iinclude -Llib -o main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image } ; if ($?) { .\main }
