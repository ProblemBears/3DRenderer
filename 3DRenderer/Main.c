#include <stdio.h>
#include <SDL3/SDL.h>

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_GAMEPAD | SDL_INIT_EVENTS | SDL_INIT_SENSOR | SDL_INIT_CAMERA);
	printf("Hello, world!");
	return 0;
}