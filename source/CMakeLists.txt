add_executable(source main.cpp)
target_compile_features(source PRIVATE cxx_std_23)
set_target_properties(source PROPERTIES CXX_EXTENSIONS off CXX_STANDARD_REQUIRED on)
