message(STATUS "utility")
include_directories(./)
add_executable(MyBase64_test base64.cpp ./test/base64_test.cpp)
add_executable(MyMd5_test md5.cpp ./test/md5_test.cpp)
add_executable(MySha1_test sha1.cpp ./test/sha1_test.cpp)
add_executable(MyStringHash_test stringhash.cpp ./test/stringhash_test.cpp)