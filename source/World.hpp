#ifndef WORLD_HPP
#define WORLD_HPP

#include <string>
#include <vector>
#include <random>
#include <array>
#include <assets/scene/Scene.hpp>
#include <engine/env/ConfigFileParser.hpp>
#include <engine/env/Config.hpp>

namespace glPortal {

class Scene;
class Entity;
class Renderer;
class BoxCollider;
class Vector3f;
class SoundManager;

const float GRAVITY = 0.01;
const float FRICTION = 0.01;

const std::array<const std::string,3> MUSIC_PLAYLIST =
{
  "/audio/music/track1.ogg",
  "/audio/music/track2.ogg",
  "/audio/music/track3.ogg"
};

class Window;

class World {
public:
  World();
  void create();
  void setRendererWindow(Window*);
  void destroy();
  void update();
  void loadScene(const std::string &path);
  bool collidesWithWalls(const BoxCollider &collider) const;
  void shootPortal(int button);
  bool collides(const Vector3f &ro, const Vector3f &rd, const Entity &e, float *tNear, float *tFar);
  void render();
  Entity& getPlayer();
  EntityPair& getPortalPair(int n) const;

  static float gravity;
  static float friction;
private:
  bool wasF5Down;
  std::string currentScenePath;
  Renderer *renderer;
  Scene *scene;
  std::mt19937 generator;
  std::vector<std::string> mapList;
  unsigned int currentLevel = 0;
  ConfigFileParser *config;
};

} /* namespace glPortal */

#endif /* WORLD_HPP */
