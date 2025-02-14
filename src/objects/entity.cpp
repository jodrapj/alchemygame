#include "entity.h"

Entity::Entity(int x, int y, SDL_Texture* texture) : x(x), y(y), texture(texture) {
}

Entity::Entity(int x, int y) : x(x), y(y) {
}

Entity::Entity() {
}
