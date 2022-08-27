windows:
	@make winbuild
	@make winarchive
winbuild:
	@echo "**Building Vakhitest for WINDOWS x86"
	x86_64-w64-mingw32-g++ ./*.cpp -o ./win/out/Vakhitest.exe -I. -L./win/lib -lsfml-window -lsfml-graphics -lsfml-system -std=c++20
	@echo "**Finished build with no errors"
winarchive:
	@echo "**Creating Release 7z"
	@rm -f win/out/Vakhitest-Release.7z
	7z a -mmt4 -mx=9 -wwin/out win/out/Vakhitest-Release.7z win/out/*
	@echo "##Created win/out/Vakhitest-Release.7z for WINDOWS x86"