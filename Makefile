windows:
	@make winbuilddebug
	@make winbuildrelease
	@make winarchivedebug
	@make winarchiverelease
	@make git
winbuildrelease:
	@echo "**Building Vakhitest Release for WINDOWS x86"
	@cp -f src/header/tpl/depsrel.h src/header
	@mv src/header/depsrel.h src/header/deps.h
	i686-w64-mingw32-g++-win32 -DSFML_STATIC -DSFML_SHARED -I. src/*.cpp -o win/Release/Vakhitest.exe -static -mwindows  -L./win/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lfreetype -lgdi32 -std=c++17 -m32 -m32 -O2 -s -DNDEBUG
	@echo "**Finished build with no errors"
	@cp -f src/header/tpl/depsbug.h src/header
	@mv src/header/depsbug.h src/header/deps.h
winbuilddebug:
	@echo "**Building Vakhitest Debug for WINDOWS x86"
	@cp -f src/header/tpl/depsbug.h src/header
	@mv src/header/depsbug.h src/header/deps.h
	i686-w64-mingw32-g++-win32 -DSFML_STATIC -DSFML_SHARED -I. src/*.cpp -o win/Debug/Vakhitest.exe -static -mwindows  -L./win/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lfreetype -lgdi32 -std=c++17 -m32 -m32
	@echo "**Finished build with no errors"
winarchivedebug:
	@echo "**Creating Debug 7z"
	cp -r -f assets/ win/Debug
	cp -r -f assets/ bin/Debug
	@rm -f win/out/Vakhitest-Debug.7z
	7z a -mmt4 -mx=9 -wwin/Debug win/Vakhitest-Debug.7z win/Debug/*
	@echo "##Created win/out/Vakhitest-Debug.7z for WINDOWS x86"
winarchiverelease:
	@echo "**Creating Release 7z"
	cp -r -f assets/ win/Release
	cp -r -f assets/ bin/Release
	@rm -f win/out/Vakhitest-Release.7z
	7z a -mmt4 -mx=9 -wwin/Release win/Vakhitest-Release.7z win/Release/*
	@echo "##Created win/out/Vakhitest-Release.7z for WINDOWS x86"
git:
	git add .
	git commit -m "$(te)"
	git pull
	git push