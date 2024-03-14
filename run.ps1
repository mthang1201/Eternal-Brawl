if ($exeFiles.Count -gt 0) {
    rm bin/Game.exe
}

# FOR CMAKE
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .

if ($LASTEXITCODE -eq 0) {
    ./../bin/Game
}


# FOR MAKEFILE
# make

# if ($LASTEXITCODE -eq 0) {
#     cd bin
#     ./Game
# }
