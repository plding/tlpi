DIRS = lib \
	fileio

all:
	@for dir in ${DIRS}; do ${MAKE} -C $${dir}; done

allgen:
	@for dir in ${DIRS}; do ${MAKE} -C $${dir} allgen; done

clean:
	@for dir in ${DIRS}; do ${MAKE} -C $${dir} clean; done
