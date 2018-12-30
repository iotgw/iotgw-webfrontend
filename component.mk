#
# "main" pseudo-component makefile.
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)


COMPONENT_EMBED_FILES := build/index.html\
												 build/static/css/main.css\
												 build/static/js/main.js\
												 build/favicon.ico build/manifest.json

periph_web_files.o: build_web

check_npm: npm-is-not-exists
npm-is-not-exists: ; @which npm > /dev/null

check_node_modules:
	if [ ! -d "$(COMPONENT_PATH)/node_modules" ]; then\
	  	cd $(COMPONENT_PATH) && npm install && npm run build;\
	fi

check_build_directory:
	if [ ! -d "$(COMPONENT_PATH)/build" ]; then\
	    cd $(COMPONENT_PATH) && npm run build;\
	fi

build_web: check_npm check_node_modules check_build_directory

