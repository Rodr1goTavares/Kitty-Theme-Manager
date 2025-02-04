script_dir=$(dirname "$0")
cd "$script_dir"

cd ../
rm -rf ./build
mkdir build
cd build

echo "Staring Cmake..."

cmake ..
cmake --build .

echo "Staring..."

./ktm