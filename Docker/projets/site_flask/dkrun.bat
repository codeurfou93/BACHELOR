::
::Lance une image pour execution en fonction de la version de l'image
::
@echo OFF
set VERSION=%1
set PORT=%2
if %VERSION%. == . (
    echo.
    
    echo Enter %0% ^[VERSION^] ^[PORT]
    echo %0% 1.0 8081
    echo  Or
    echo %0% 1.2 8082
    exit /B
) else (
    docker run -d --name site_flask_%VERSION% --rm -p%PORT%:8000 site_flask:%VERSION%
)