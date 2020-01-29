echo "Building market proto test debug environment"
mkdir build_c_bin
cd build_c_bin
cmake -DWITH_testing=ON ..
msbuild ALL_BUILD.vcxproj
msbuild RUN_TESTS.vcxproj
echo "Stopping here for debugging"
