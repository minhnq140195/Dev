#include "Engine.h"
#include <iostream>
#include "TextureManager.h"

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

	TextureManager::GetInstance()->Load("tree", "assets/grass.png");
	return m_IsRunning = true;
}
void Engine::Clean() {

	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();
}
void Engine::Quit() {

	m_IsRunning = false;
}

void Engine::Update() {

}
void Engine::Render() {

	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderClear(m_Renderer);

	TextureManager::GetInstance()->Draw("tree", 100, 100, 32, 32);
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