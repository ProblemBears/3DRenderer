#include <stdio.h>
#include <stdbool.h>
#include <SDL3/SDL.h>

bool is_running = false;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool initialize_window(void) {
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		fprintf(stderr, "Error initializing SDL .\n");
		return false;
	}

	// Create the window and renderer using SDL_CreateWindowAndRenderer
	if (SDL_CreateWindowAndRenderer(NULL, 800, 600, SDL_WINDOW_BORDERLESS, &window, &renderer) == 0) {
		fprintf(stderr, "Error creating SDL window and renderer: %s\n", SDL_GetError());
		return false;
	}

	return true;
}

void setup(void)
{

}

void process_input(void)
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_EVENT_QUIT:
		is_running = false;
		break;
	case SDL_EVENT_KEY_DOWN:
		if (event.key.key == SDLK_ESCAPE)
			is_running = false;
		break;
	}
}

void update(void)
{

}

void render(void)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

int main(int argc, char* args[]) {

	is_running = initialize_window();

	setup();

	while (is_running)
	{
		process_input();
		update();
		render();
	}

	return 0;
}