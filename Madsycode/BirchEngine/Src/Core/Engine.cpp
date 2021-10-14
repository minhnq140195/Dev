#include "Engine.h"
#include <iostream>

Engine* Engine::s_Instance = nullptr;

bool Engine::Init() {

	int flags = !SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_Window = SDL_CreateWindow("Soft Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);
		m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
		if (m_Renderer == nullptr)
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	return m_IsRunning = true;
}
bool Engine::Clean() {

	return true;
}
void Engine::Quit() {

	m_IsRunning = false;
}

void Engine::Update() {

}
void Engine::Render() {

	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderPresent(m_Renderer);
}
void Engine::Events() {

	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		Quit();
		break;
	default:
		break;
	}

}