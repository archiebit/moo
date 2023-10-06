incdirs := inc
libdirs :=
libs    :=

include makefile-config

resources := $(shell dir res /B | findstr /R .rc$)
sources   := $(shell dir src /B | findstr /R .cc$)
objects   := ${sources:.cc=.o} ${resources:.rc=.o}


${tmp}/%.o: src/%.cc
	clang++ -o $(call path,$@) $(call pathpack,$^) ${incdirs} -c ${flags}

${tmp}/%.o: res/%.rc
	windres -o $(call path,$@) $(call pathpack,$^)



${bin}/program.exe: $(addprefix ${tmp}/,${objects})
	clang++ -o $(call path,$@) $(call pathpack,$^) ${libdirs} ${libs}