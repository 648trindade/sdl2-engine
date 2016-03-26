//==============================================================================
/*
	Texture class for wrapping SDL Textures

	3/13/2014
    SDLTutorials.com
    Tim Jones
*/
//==============================================================================
#ifndef __TEXTURE_H__
	#define __TEXTURE_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>

class Texture {
	private:
		std::string Filename;

		int Width = 0;
		int Height = 0;
		int pitch = 0;

		SDL_Renderer* Renderer = NULL;
		SDL_Texture* SDLTexture = NULL;
		SDL_Texture* MaskTexture = NULL;

	public:
		Texture();
		~Texture();

		bool Load(SDL_Renderer* Renderer, std::string Filename);

		void Render(int X, int Y);

		void Render(int X, int Y, int Width, int Height);

		void Render(int X, int Y, int Width, int Height, int SX, int SY, int SWidth, int SHeight);

		int GetWidth();
		int GetHeight();
		int GetPitch(); //To use with mask

		SDL_Texture* GetMaskTexture(){ return MaskTexture; };
		void DestroyMaskTexture(){ SDL_DestroyTexture(MaskTexture); };
};

#endif
