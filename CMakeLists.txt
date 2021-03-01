# 指定cmake的最小版本
# 这行命令是可选的，我们可以不写这句话
# 但在有些情况下，如果CMakeLists.txt文件中使用了一些高版本cmake特有的一些命令的时候，
# 就需要加上这样一行，提醒用户升级到该版本之后再执行cmake
cmake_minimum_required(VERSION 3.17)

# 设置项目名称
# 该命令不是强制性的
# 它会引入两个变量DailyTraining_BINARY_DIR和DailyTraining_SOURCE_DIR
# 同时，cmake自动定义了两个等价的变量 PROJECT_BINARY_DIR和 PROJECT_SOURCE_DIR
project(DailyTraining)

set(CMAKE_CXX_STANDARD 14)

# 设置编译类型
add_executable(DailyTraining struct.cpp)# 生成可执行文件

# print project_name
message(${PROJECT_SOURCE_DIR})