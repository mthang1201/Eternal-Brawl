if ($args.Count -eq 0) {
    $option = "-c"
} else {
    $option = $args[0]
}

switch ($option) {
    # FOR CMAKE
    # Build (When adding new files)
    "-b" {
        if ($exeFiles.Count -gt 0) {
            Remove-Item bin/Game.exe
        }

        & cd build
        & cmake -G "MinGW Makefiles" ..
        & cmake --build .

        if ($LASTEXITCODE -eq 0) {
            & ./../bin/Game
        }
        & cd ..
    }
    # Build from scratch
    "-s" {
        if ($exeFiles.Count -gt 0) {
            Remove-Item bin/Game.exe
        }

        & cd build
        & Remove-Item * -Recurse -Force
        & cmake -G "MinGW Makefiles" ..
        & cmake --build .

        if ($LASTEXITCODE -eq 0) {
            & ./../bin/Game
        }
        & cd ..
    }
    # Change
    "-c" {
        if ($exeFiles.Count -gt 0) {
            Remove-Item bin/Game.exe
        }

        & cd build
        & cmake --build .

        if ($LASTEXITCODE -eq 0) {
            & ./../bin/Game
        }
        & cd ..
    }

    # FOR MAKEFILE
    # make
    "-m" {
        make
        if ($LASTEXITCODE -eq 0) {
            & cd bin
            & ./Game
        }
    }
    default {
        Write-Host "Invalid option. Please use '-b', '-s', '-c', or '-m'."
    }
}