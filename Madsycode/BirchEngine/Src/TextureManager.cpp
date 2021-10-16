#include "TextureManager.h"
#include "Engine.h"

TextureManager* TextureManager::s_Instance = nullptr;

void TextureManager::Load(std::string id, std::string filename)
{
	SDL_Surface* tempSurface = IMG_Load(filename.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), tempSurface);
	SDL_FreeSurface(tempSurface);

	m_TextureMap[id] = texture;
}

void TextureManager::Drop(std::string id)
{
	SDL_DestroyTexture(m_TextureMap[id]);
	m_TextureMap.erase(id);
}

void TextureManager::Clean()
{
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
	{
		SDL_DestroyTexture(it->second);
	}

	m_TextureMap.clear();

	SDL_Log("Texture map cleaned!");
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = { 0, 0, width, height };
	SDL_Rect destRect = { x, y, width, height };
	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}