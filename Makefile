windows:
	@make winbuilddebug
	@make winbuildrelease
	@make winarchive
	@make linbuilddebug
	@make linbuildrelease
	@make linarchive
	@make git
winbuildrelease:
	@echo "**Building Vakhitest Release for WINDOWS x86"
	@cp -f src/header/tpl/depsrel.h src/header
	@mv src/header/depsrel.h src/header/deps.h
	i686-w64-mingw32-g++-win32 -DSFML_STATIC -DSFML_SHARED -I. src/*.cpp -o win/Release/Vakhitest.exe -static -mwindows -L./win/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lfreetype -lgdi32 -std=c++17 -O2 -s -DNDEBUG
	@echo "**Finished build with no errors"
	@cp -f src/header/tpl/depsbug.h src/header
	@mv src/header/depsbug.h src/header/deps.h
winbuilddebug:
	@echo "**Building Vakhitest Debug for WINDOWS x86"
	@cp -f src/header/tpl/depsbug.h src/header
	@mv src/header/depsbug.h src/header/deps.h
	i686-w64-mingw32-g++-win32 -DSFML_STATIC -DSFML_SHARED -I. src/*.cpp -o win/Debug/Vakhitest.exe -static -mwindows -L./win/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lfreetype -lgdi32 -std=c++17
	@echo "**Finished build with no errors"
winarchive:
	@echo "**Creating Windows 7z"
	cp -r -f assets/ win/Release
	cp -r -f assets/ win/Debug
	@rm -f lin/Vakhitest.7z
	7z a -mmt4 -mx=9 -wwin win/Vakhitest.7z win/Release/* bin/Debug/*
	@echo "##Created win/Vakhitest.7z for WINDOWS x86"
linbuildrelease:
	@echo "**Building Vakhitest Release for LINUX"
	@cp -f src/header/tpl/depsrel.h src/header
	@mv src/header/depsrel.h src/header/deps.h
	g++ -DSFML_STATIC -DSFML_SHARED -I. src/*.cpp -o bin/Release/Vakhitest -lsfml-graphics -lsfml-window -lsfml-system -lX11 -std=c++17 -O2 -s -DNDEBUG
	@echo "**Finished build with no errors"
	@cp -f src/header/tpl/depsbug.h src/header
	@mv src/header/depsbug.h src/header/deps.h
linbuilddebug:
	@echo "**Building Vakhitest Debug for LINUX"
	@cp -f src/header/tpl/depsbug.h src/header
	@mv src/header/depsbug.h src/header/deps.h
	g++ -DSFML_STATIC -DSFML_SHARED -I. src/*.cpp -o bin/Debug/Vakhitest -lsfml-graphics -lsfml-window -lsfml-system -lX11 -std=c++17
	@echo "**Finished build with no errors"
linarchive:
	@echo "**Creating Linux 7z"
	cp -r -f assets/ bin/Release
	cp -r -f assets/ bin/Debug
	@rm -f lin/Vakhitest.7z
	7z a -mmt4 -mx=9 -wbin bin/Vakhitest.7z bin/Release/* bin/Debug/*
	@echo "##Created bin/Vakhitest.7z for LINUX"
git:
	git add .
	git commit -m "$(te)"
	git pull
	git push