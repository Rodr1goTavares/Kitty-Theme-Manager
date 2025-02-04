script_dir=$(dirname "$0")
cd "$script_dir"

cd ../
mkdir build
cd build

echo "Staring Cmake..."

cmake ..
cmake --build .
