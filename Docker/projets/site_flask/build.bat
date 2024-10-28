::
:: Construit une image en versionnant le tag de l'image
:: Le source .py est différent
::
@echo OFF
set VERSION=%1
if %VERSION%. == . (
    echo.
    echo Enter %0% ^[VERSION^]
    echo %0% 1.0
    echo  Or
    echo %0% 1.2
    exit /B
) else (
    docker build -f site_flask-%VERSION%.dockerfile -t site_flask:%VERSION% .
)