#ifdef GAME2D_EXPORTS
#define GAME2D_API __declspec(dllexport)
#else
#define GAME2D_API __declspec(dllimport)
#endif