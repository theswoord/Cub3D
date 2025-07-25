NAME = game.html
SRC = main.c utils.c map_related.c drawing.c mlx_related.c math_helper.c map_checks.c parse.c free.c check_map.c errors.c cast_vertical.c cast_horizontal.c map_help.c texture_help.c parse_help2.c parse_help3.c parse_help4.c movements.c texture_help2.c get_next_line.c get_next_line_utils.c 

COMPILE = emcc

# CFLAGS for Emscripten. Removed native sdl2-config
CFLAGS = -O3

# EMCCFLAG with the correct flag for SDL2_image
EMCCFLAG = -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS="['png','jpg']" -s USE_WEBGL2=1 -s ALLOW_MEMORY_GROWTH=1 -s INITIAL_MEMORY=64MB

all: wasm

wasm:
	${COMPILE} ${CFLAGS} ${SRC} -o ${NAME} ${EMCCFLAG} --preload-file assets

fclean: 
	rm -f ${NAME} game.wasm game.js

wasme :
	emcc ${SRC}     -o ../react_wasm/sand-app/src/game/cub.js \
	-s USE_SDL=2 \
	-s WASM=1 \
	-O3 \
	-s MODULARIZE=1 \
	-s EXPORT_ES6=1 \
	-s INVOKE_RUN=0 \
	-s ALLOW_MEMORY_GROWTH=1 \
	-s EXPORTED_RUNTIME_METHODS="['callMain' , 'FS', 'ccall']" \
	-s INITIAL_MEMORY=64MB \
	-s USE_WEBGL2=1 \
	-s EXIT_RUNTIME=1 \
	-s USE_SDL_IMAGE=2 \
	--preload-file assets \
    --use-preload-plugins



re: fclean all

