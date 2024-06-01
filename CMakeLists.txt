cmake_minimum_required(VERSION 3.10)
project(BIGASSIGNMENT)

# Thêm đường dẫn tới thư mục chứa các file header
include_directories(include)

set(SOURCES Bac_si.cpp Benh_nhan.cpp Bo_sung.cpp Dich_vu.cpp Thuoc.cpp)
# Tạo thư viện từ các file source
add_library(BIGASSIGNMENT STATIC ${SOURCES})

# Nếu bạn có file chính để kiểm thử, thêm đoạn này
add_executable(main main.cpp)
target_link_libraries(main BIGASSIGNMENT)
