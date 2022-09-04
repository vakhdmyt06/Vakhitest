windows:
	@make winbuild
	@make winarchive
	@make git
winbuild:
	@echo "**Building Vakhitest for WINDOWS x86"
	i686-w64-mingw32-g++-win32 -DSFML_STATIC -DSFML_SHARED -I. src/*.cpp -o win/out/Vakhitest.exe -static -mwindows  -L./win/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lfreetype -lgdi32 -std=c++17 -m32 -m32 -O2 -s -DNDEBUG
	@echo "**Finished build with no errors"
winarchive:
	@echo "**Creating Release 7z"
	@rm -f win/out/Vakhitest-Release.7z
	7z a -mmt4 -mx=9 -wwin/out win/out/Vakhitest-Release.7z win/out/*
	@echo "##Created win/out/Vakhitest-Release.7z for WINDOWS x86"
	cp -r -f assets/ win/out
	cp -r -f assets/ bin/Debug
	cp -r -f assets/ bin/Release
git:
	git add .
	git commit -m "$(te)"
	git pull
	git push