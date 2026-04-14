rm -rf build
cmake -S . -B build
cmake --build build
sudo cmake --install build
echo "alias define=defines" >> ~/.bashrc
