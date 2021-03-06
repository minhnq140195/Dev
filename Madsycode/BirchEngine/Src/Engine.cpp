#include "Engine.h"
#include "TextureManager.h"
#include "Warrior.h"

Engine* Engine::s_Instance = nullptr;
Warrior* player = nullptr;

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

	TextureManager::GetInstance()->Load("player", "assets/npc.png");
	player = new Warrior(new Properties("player", 100, 200, 16, 32));

	Vector2D v1(1, 1), v2;
	v1.Log("V1: ");

	Transform tf;
	tf.Log();

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
	player->Update(0);
}
void Engine::Render() {

	SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
	SDL_RenderClear(m_Renderer);

	//TextureManager::GetInstance()->Draw("tree", 100, 100, 32, 32);
	player->Draw();
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