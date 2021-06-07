typedef struct {
	SDL_Joystick *joysticks[MAX_NUM_JOYSTICKS];
	SDL_Haptic *haptics[MAX_NUM_JOYSTICKS];
	int rumble[MAX_NUM_JOYSTICKS]; // 2 -> play rumble
	int connected; // connected joysticks number
} App;
