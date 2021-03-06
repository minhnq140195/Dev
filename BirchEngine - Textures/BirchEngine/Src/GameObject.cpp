#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

void GameObject::Update() {

	xpos++;
	ypos++;

	srcRec.h = 32;
	srcRec.w = 32;
	srcRec.x = 0;
	srcRec.y = 0;

	destRec.x = xpos;
	destRec.y = ypos;
	destRec.w = srcRec.w * 2;
	destRec.h = srcRec.h * 2;
}

void GameObject::Render() {

	SDL_RenderCopy(Game::renderer, objTexture, &srcRec, &destRec);
}