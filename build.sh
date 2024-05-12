echo BUILD
cmake -B build -G Ninja

rm compile_commands.json
cp ./build/compile_commands.json .
