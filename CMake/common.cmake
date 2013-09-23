# Must be included after PROJECT directive

SET (CMAKE_CXX_FLAGS_RELEASE
  "-pipe -W -Wall -Wextra -O2 -fomit-frame-pointer -fPIC -fvisibility-inlines-hidden -fvisibility=hidden"
)

SET (CMAKE_CXX_FLAGS_DEBUG
  "-pipe -W -Wall -Wextra -O0 -g -fPIC"
)


SET (CMAKE_EXE_LINKER_FLAGS
  "${CMAKE_EXE_LINKER_FLAGS} -lX11 -lxneur" )
