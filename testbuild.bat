echo "Building the market proto C targets"
mkdir build_c_bin
cd build_c_bin
cmake -DWITH_testing=ON ..
msbuild ALL_BUILD.vcxproj
msbuild RUN_TESTS.vcxproj
cd ..
rmdir /s /q build_c_bin
