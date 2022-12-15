MyProject : project.o project.c
  gcc project.o -o project
  ./a.exe
MyProject : project.c
  gcc -c project.c -o project.o
installemsdk: 
  cd .. && git clone https://github.com/emscripten-core/emsdk.git
  cd ../emsdk && emsdk install latest && emsdk activate latest && emsdk_env.bat && emcc project.c -s WASM=1 -o project.html
  npm i http-server -g
runserver:
    cd ../emrun project.html