touch test.txt
echo "TEST shannon entropy" > test.txt
touch result.txt
./bin/main.p
cat result.txt
rm test.txt
rm result.txt