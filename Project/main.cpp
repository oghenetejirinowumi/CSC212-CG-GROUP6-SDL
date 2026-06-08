#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL3 Test", 855, 800, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    // Background image
    SDL_Surface* bgSurface = IMG_Load("/Users/miraclechiji/CSC-212/Project/wood.png");
    SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
    SDL_FRect bgRect = { 0, 0, 855, 800 };
    SDL_DestroySurface(bgSurface);

    // Left image
    SDL_Surface* surface0 = IMG_Load("/Users/miraclechiji/CSC-212/Project/Flag.png");
    SDL_Texture* texture0 = SDL_CreateTextureFromSurface(renderer, surface0);
    SDL_FRect imgrect0 = { 80, 330, 280, 240 };
    SDL_DestroySurface(surface0);

    // Right image
    SDL_Surface* surface1 = IMG_Load("/Users/miraclechiji/CSC-212/Project/Fifa.png");
    SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
    SDL_FRect imgrect1 = { 525, 330, 280, 240 };
    SDL_DestroySurface(surface1);

    // Top image
    SDL_Surface* surface2 = IMG_Load("/Users/miraclechiji/CSC-212/Project/Star.png");
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
    SDL_FRect imgrect2 = { 260, 60, 280, 240 };
    SDL_DestroySurface(surface2);

    SDL_Event event;
    bool running = true;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                running = false;

            if (event.type == SDL_EVENT_KEY_DOWN &&
                event.key.key == SDLK_ESCAPE)
                running = false;
        }

        SDL_RenderClear(renderer);

        // Draw background first
        SDL_RenderTexture(renderer, bgTexture, NULL, &bgRect);

        // Draw images
        SDL_RenderTexture(renderer, texture0, NULL, &imgrect0);
        SDL_RenderTexture(renderer, texture1, NULL, &imgrect1);
        SDL_RenderTexture(renderer, texture2, NULL, &imgrect2);

        // Black frame color
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_FRect frame0 = {
            imgrect0.x - 5,
            imgrect0.y - 5,
            imgrect0.w + 10,
            imgrect0.h + 10
        };

        SDL_FRect frame1 = {
            imgrect1.x - 5,
            imgrect1.y - 5,
            imgrect1.w + 10,
            imgrect1.h + 10
        };

        SDL_FRect frame2 = {
            imgrect2.x - 5,
            imgrect2.y - 5,
            imgrect2.w + 10,
            imgrect2.h + 10
        };

        SDL_RenderRect(renderer, &frame0);
        SDL_RenderRect(renderer, &frame1);
        SDL_RenderRect(renderer, &frame2);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(bgTexture);
    SDL_DestroyTexture(texture0);
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}