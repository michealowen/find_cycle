![alt sss](find_cycle.jpg)

![alt sss](find_cycle.jpg)
## 寻找有向图中指定长度的简单环

- 目前工作,实现所有的找环算法

`
├── CMakeLists.txt
├── README.md
├── cmake-build-debug
│	├── CMakeCache.txt
│	├── CMakeFiles
│	│	├── 3.17.5
│	│	│	├── CMakeCCompiler.cmake
│	│	│	├── CMakeCXXCompiler.cmake
│	│	│	├── CMakeDetermineCompilerABI_C.bin
│	│	│	├── CMakeDetermineCompilerABI_CXX.bin
│	│	│	├── CMakeRCCompiler.cmake
│	│	│	├── CMakeSystem.cmake
│	│	│	├── CompilerIdC
│	│	│	│	├── CMakeCCompilerId.c
│	│	│	│	├── a.exe
│	│	│	│	└── tmp
│	│	│	└── CompilerIdCXX
│	│	│	    ├── CMakeCXXCompilerId.cpp
│	│	│	    ├── a.exe
│	│	│	    └── tmp
│	│	├── ALGORITHM_OBJ.dir
│	│	│	├── ALGORITHM_OBJ.objlib
│	│	│	├── DependInfo.cmake
│	│	│	├── build.make
│	│	│	├── cmake_clean.cmake
│	│	│	├── depend.make
│	│	│	├── flags.make
│	│	│	├── progress.make
│	│	│	└── src
│	│	│	    └── algorithm
│	│	├── CMakeDirectoryInformation.cmake
│	│	├── CMakeOutput.log
│	│	├── CMakeTmp
│	│	├── IO_OBJ.dir
│	│	│	├── DependInfo.cmake
│	│	│	├── IO_OBJ.objlib
│	│	│	├── build.make
│	│	│	├── cmake_clean.cmake
│	│	│	├── depend.make
│	│	│	├── flags.make
│	│	│	├── progress.make
│	│	│	└── src
│	│	│	    └── io
│	│	├── Makefile.cmake
│	│	├── Makefile2
│	│	├── NETWORK_OBJ.dir
│	│	│	├── DependInfo.cmake
│	│	│	├── NETWORK_OBJ.objlib
│	│	│	├── build.make
│	│	│	├── cmake_clean.cmake
│	│	│	├── depend.make
│	│	│	├── flags.make
│	│	│	├── progress.make
│	│	│	└── src
│	│	│	    └── network
│	│	├── TEST_OBJ.dir
│	│	│	├── DependInfo.cmake
│	│	│	├── TEST_OBJ.objlib
│	│	│	├── build.make
│	│	│	├── cmake_clean.cmake
│	│	│	├── depend.make
│	│	│	├── flags.make
│	│	│	├── progress.make
│	│	│	└── src
│	│	│	    └── test
│	│	├── TargetDirectories.txt
│	│	├── UTIL_GOBJ.dir
│	│	│	├── DependInfo.cmake
│	│	│	├── UTIL_GOBJ.objlib
│	│	│	├── build.make
│	│	│	├── cmake_clean.cmake
│	│	│	├── depend.make
│	│	│	├── flags.make
│	│	│	├── progress.make
│	│	│	└── src
│	│	│	    └── util
│	│	├── clion-environment.txt
│	│	├── clion-log.txt
│	│	├── cmake.check_cache
│	│	├── find_cycle.dir
│	│	│	├── DependInfo.cmake
│	│	│	├── build.make
│	│	│	├── cmake_clean.cmake
│	│	│	├── depend.make
│	│	│	├── flags.make
│	│	│	├── link.txt
│	│	│	├── progress.make
│	│	│	└── src
│	│	│	    └── app
│	│	├── generate.dir
│	│	│	├── DependInfo.cmake
│	│	│	├── build.make
│	│	│	├── cmake_clean.cmake
│	│	│	├── depend.make
│	│	│	├── flags.make
│	│	│	├── link.txt
│	│	│	├── progress.make
│	│	│	└── src
│	│	│	    └── app
│	│	├── progress.marks
│	│	└── test.dir
│	│	    ├── DependInfo.cmake
│	│	    ├── build.make
│	│	    ├── cmake_clean.cmake
│	│	    ├── depend.make
│	│	    ├── flags.make
│	│	    ├── link.txt
│	│	    ├── progress.make
│	│	    └── src
│	│	        └── app
│	├── Makefile
│	├── Testing
│	│	└── Temporary
│	│	    └── LastTest.log
│	├── cmake_install.cmake
│	└── find_cycle.cbp
├── data
│	├── n100_e120
│	│	└── n100_e120.txt
│	├── n100_e500
│	│	└── n100_e500.txt
│	├── n10_e50
│	│	└── n10_e50.txt
│	├── n10_e90
│	│	└── n10_e90.txt
│	├── n20_e200
│	│	└── n20_e200.txt
│	├── n20_e50
│	│	└── n20_e50.txt
│	├── n20_e70
│	│	└── n20_e70.txt
│	├── n20_e80
│	│	└── n20_e80.txt
│	├── n30_e50
│	│	└── n30_e50.txt
│	├── n3_e5
│	│	└── n3_e5.txt
│	├── n4_e5
│	│	└── n4_e5.txt
│	├── n50_e1000
│	│	└── n50_e1000.txt
│	├── n50_e200
│	│	└── n50_e200.txt
│	├── n50_e500
│	│	└── n50_e500.txt
│	├── n5_e20
│	│	└── n5_e20.txt
│	└── n6_e15
│	    └── n6_e15.txt
├── find_cycle.jpg
├── src
│	├── algorithm
│	│	├── Johnson.cpp
│	│	├── Johnson.h
│	│	├── Tiernan.cpp
│	│	└── Tiernan.h
│	├── app
│	│	├── generate.cpp
│	│	├── main.cpp
│	│	└── test.cpp
│	├── io
│	│	├── reader.cpp
│	│	├── reader.h
│	│	├── writer.cpp
│	│	└── writer.h
│	├── network
│	│	├── graph.cpp
│	│	├── graph.h
│	│	└── mtype.h
│	├── test
│	│	├── boost_graph_test.cpp
│	│	└── boost_graph_test.h
│	└── util
│	    ├── debug.h
│	    ├── util.cpp
│	    └── util.h
└── third_party
└── spdlog
├── async.h
├── async_logger-inl.h
├── async_logger.h
├── common-inl.h
├── common.h
├── details
│	├── backtracer.h
│	├── circular_q.h
│	├── console_globals.h
│	├── file_helper-inl.h
│	├── file_helper.h
│	├── fmt_helper.h
│	├── log_msg-inl.h
│	├── log_msg.h
│	├── log_msg_buffer.h
│	├── mpmc_blocking_q.h
│	├── null_mutex.h
│	├── os-inl.h
│	├── os.h
│	├── pattern_formatter-inl.h
│	├── pattern_formatter.h
│	├── periodic_worker-inl.h
│	├── periodic_worker.h
│	├── registry-inl.h
│	├── registry.h
│	├── synchronous_factory.h
│	├── thread_pool-inl.h
│	└── thread_pool.h
├── fmt
│	├── bin_to_hex.h
│	├── bundled
│	│	├── LICENSE.rst
│	│	├── chrono.h
│	│	├── color.h
│	│	├── core.h
│	│	├── format-inl.h
│	│	├── format.h
│	│	├── locale.h
│	│	├── ostream.h
│	│	├── posix.h
│	│	├── printf.h
│	│	├── ranges.h
│	│	└── time.h
│	├── fmt.h
│	└── ostr.h
├── formatter.h
├── logger-inl.h
├── logger.h
├── sinks
│	├── android_sink.h
│	├── ansicolor_sink-inl.h
│	├── ansicolor_sink.h
│	├── base_sink-inl.h
│	├── base_sink.h
│	├── basic_file_sink-inl.h
│	├── basic_file_sink.h
│	├── daily_file_sink.h
│	├── dist_sink.h
│	├── dup_filter_sink.h
│	├── msvc_sink.h
│	├── null_sink.h
│	├── ostream_sink.h
│	├── rotating_file_sink-inl.h
│	├── rotating_file_sink.h
│	├── sink-inl.h
│	├── sink.h
│	├── stdout_color_sinks-inl.h
│	├── stdout_color_sinks.h
│	├── stdout_sinks-inl.h
│	├── stdout_sinks.h
│	├── syslog_sink.h
│	├── systemd_sink.h
│	├── wincolor_sink-inl.h
│	└── wincolor_sink.h
├── spdlog-inl.h
├── spdlog.h
├── tweakme.h
└── version.h
`

