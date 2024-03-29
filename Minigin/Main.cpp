#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "Scene.h"
#include "GameObject.h"
#include "FPS.h"
#include "TextObject.h"
#include "TextureComponent.h"
#include "MoveComponent.h"
#include "Input.h"
#include "Commands.h"
#include "DeathObserver.h"
#include "ScoreObserver.h"
#include "HealthComponent.h"
#include "ScoreComponent.h"
#include "MapCreator.h"
#include "DataTypes.h"
#include "ColissionComponent.h"
#include "ServiceLocator.h"
#include "GameStateComponent.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto to = std::make_shared<dae::GameObject>();
	auto go = std::make_shared<dae::GameObject>();
	auto background = std::make_shared<dae::GameObject>();

	auto textureComponentGo = std::make_shared <dae::TextureComponent>(go);
	auto textureComponentBackground = std::make_shared <dae::TextureComponent>(background);


	
	//BACKGROUND
	/*background->AddComponent(textureComponentBackground);
	background->GetComponent<dae::TextureComponent>().get()->SetTexture("background.tga");
	background->SetLocalPosition({ 0, 0 });
	scene.Add(background);*/

	
	//LOGO
	/*go->AddComponent(textureComponentGo);
	go->GetComponent<dae::TextureComponent>().get()->SetTexture("logo.tga");
	go->SetLocalPosition({ 216, 180 });
	scene.Add(go);*/

	//fonts
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 30);
	auto fpsFont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);

	//text
	/*auto text = std::make_shared<dae::TextObject>("Programming 4 Assignment", font);
	to->AddComponent(text);
	to->GetComponent<dae::TextObject>()->SetPosition(125, 50);
	scene.Add(to);*/

	//MAP
	auto map = std::make_shared<dae::GameObject>();
	auto createMapComponent = std::make_shared<dae::MapCreator>(map, 7);
	map->AddComponent(createMapComponent);
	scene.Add(map);

	//FPS COUNTER
	auto fpsCounter = std::make_shared<dae::GameObject>();
	auto fpsCalc = std::make_shared<dae::FPS>(fpsCounter);
	fpsCounter->AddComponent(fpsCalc);
	
	auto fpsText = std::make_shared <dae::TextObject>("FPS: ", fpsFont);
	fpsCounter->AddComponent(fpsText);

	fpsCounter->GetComponent<dae::TextObject>()->SetPosition(20.f, 20.f);
	scene.Add(fpsCounter);

	//-------------sprite parent P1-------------//
	//auto qBert = std::make_shared<dae::GameObject>();
	//auto parentTexture = std::make_shared <dae::TextureComponent>(qBert);
	//auto parentHealth = std::make_shared <dae::HealthComponent>(spriteParent);
	//auto parentScore = std::make_shared <dae::ScoreComponent>(spriteParent);
	//auto liveTextP1 = std::make_shared <dae::TextObject>("Remaining Lives: " + std::to_string(parentHealth->GetCurrentHealth()), fpsFont);
	//auto scoreTextP1 = std::make_shared <dae::TextObject>("Score: " + std::to_string(parentScore->GetCurrentScore()), fpsFont);
	

	//qBert->AddComponent(parentTexture); 
	//spriteParent->AddComponent(parentHealth);
	//spriteParent->AddComponent(parentScore);
	//spriteParent->AddComponent(liveTextP1);
	//spriteParent->AddComponent(scoreTextP1);

	//liveTextP1->SetPosition(455.f, 450.f);
	//scoreTextP1->SetPosition(455.f, 420.f);

	//adding observer
	//std::shared_ptr<dae::DeathObserver> observerHealthP1 = std::make_shared<dae::DeathObserver>(parentHealth, liveTextP1);
	//spriteParent->GetComponent<dae::HealthComponent>()->GetSubject()->AddObserver(observerHealthP1);

	//std::shared_ptr<dae::ScoreObserver> observerScoreP1 = std::make_shared<dae::ScoreObserver>(parentScore, scoreTextP1);
	//spriteParent->GetComponent<dae::ScoreComponent>()->GetSubject()->AddObserver(observerScoreP1);




	//qBert->GetComponent<dae::TextureComponent>()->SetTexture("Qbert.png");
	//qBert->SetLocalPosition({ 160, 160 });

	//scene.Add(qBert);



	//-------------sprite child P2-------------//
	auto spriteChild = std::make_shared<dae::GameObject>();
	auto childTexture = std::make_shared <dae::TextureComponent>(spriteChild);
	auto collisionComponentP2 = std::make_shared <dae::ColissionComponent>(spriteChild, createMapComponent->GetCubes());

	//map extra component
	auto GameStateComponent = std::make_shared<dae::GameStateComponent>(map, spriteChild);
	map->AddComponent(GameStateComponent);



	//auto childHealth = std::make_shared <dae::HealthComponent>(spriteChild);
	//auto childScore = std::make_shared <dae::ScoreComponent>(spriteChild);
	//auto liveTextP2 = std::make_shared <dae::TextObject>("Remaining Lives: " + std::to_string(childHealth->GetCurrentHealth()), fpsFont);
	//auto scoreTextP2 = std::make_shared <dae::TextObject>("Score: " + std::to_string(childScore->GetCurrentScore()), fpsFont);


	spriteChild->AddComponent(childTexture);
	spriteChild->AddComponent(collisionComponentP2);
	//spriteChild->AddComponent(childHealth);
	//spriteChild->AddComponent(childScore);
	//spriteChild->AddComponent(liveTextP2);
	//spriteChild->AddComponent(scoreTextP2);
	
	//liveTextP2->SetPosition(5.f, 450.f);
	//scoreTextP2->SetPosition(5.f, 420.f);

	//adding observer
	//std::shared_ptr<dae::DeathObserver> observerHealthP2 = std::make_shared<dae::DeathObserver>(childHealth, liveTextP2);
	//spriteChild->GetComponent<dae::HealthComponent>()->GetSubject()->AddObserver(observerHealthP2);

	//std::shared_ptr<dae::ScoreObserver> observerScoreP2 = std::make_shared<dae::ScoreObserver>(childScore, scoreTextP2);
	//spriteChild->GetComponent<dae::ScoreComponent>()->GetSubject()->AddObserver(observerScoreP2);


	spriteChild->GetComponent<dae::TextureComponent>()->SetTexture("Qbert.png");
	spriteChild->SetLocalPosition({ 278, 245 });

	scene.Add(spriteChild);

	

	//spriteChild->SetParent(spriteParent);

	//CONTROLLER
	//int Controller1Index{ 0 };
	float speed{ 80.f };
	//dae::Input::GetInstance().AddController(std::make_shared<dae::Gamepad>(Controller1Index));

	////move left
	//auto moveComm = std::make_shared<dae::MoveCommand>(qBert, speed, dae::PlayerInput::Left);
	//dae::Input::GetInstance().AddCommand(std::make_pair(Controller1Index, dae::Gamepad::ControllerButton::DPadLeft), moveComm);

	////move right
	//moveComm = std::make_shared<dae::MoveCommand>(qBert, speed, dae::PlayerInput::Right);
	//dae::Input::GetInstance().AddCommand(std::make_pair(Controller1Index, dae::Gamepad::ControllerButton::DPadRight), moveComm);

	////move down
	//moveComm = std::make_shared<dae::MoveCommand>(qBert, speed, dae::PlayerInput::Down);
	//dae::Input::GetInstance().AddCommand(std::make_pair(Controller1Index, dae::Gamepad::ControllerButton::DPadDown), moveComm);

	////move up
	//moveComm = std::make_shared<dae::MoveCommand>(qBert, speed, dae::PlayerInput::Up);
	//dae::Input::GetInstance().AddCommand(std::make_pair(Controller1Index, dae::Gamepad::ControllerButton::DPadUp), moveComm);

	////Damage player1
	//auto damageComm = std::make_shared<dae::DamageCommand>(qBert);
	//dae::Input::GetInstance().AddCommand(std::make_pair(Controller1Index, dae::Gamepad::ControllerButton::ButtonSouth), damageComm);

	////add Score
	//// add a score command then bind to p1
	//auto addScoreComm = std::make_shared<dae::AddScoreCommand>(qBert);
	//dae::Input::GetInstance().AddCommand(std::make_pair(Controller1Index, dae::Gamepad::ControllerButton::ButtonWest), addScoreComm);
	//	



	//KEYBOARD

	//move left
	auto moveComm = std::make_shared<dae::MoveCommand>(spriteChild, speed * 2.f, dae::PlayerInput::Left);
	dae::Input::GetInstance().AddCommand(std::make_pair(SDL_SCANCODE_A, SDL_KEYUP), moveComm);
	
	//move right
	moveComm = std::make_shared<dae::MoveCommand>(spriteChild, speed * 2.f, dae::PlayerInput::Right);
	dae::Input::GetInstance().AddCommand((std::make_pair(SDL_SCANCODE_D, SDL_KEYUP)), moveComm);

	//move down
	moveComm = std::make_shared<dae::MoveCommand>(spriteChild, speed * 2.f, dae::PlayerInput::Down);
	dae::Input::GetInstance().AddCommand((std::make_pair(SDL_SCANCODE_S, SDL_KEYUP)), moveComm);

	//move up
	moveComm = std::make_shared<dae::MoveCommand>(spriteChild, speed * 2.f, dae::PlayerInput::Up);
	dae::Input::GetInstance().AddCommand((std::make_pair(SDL_SCANCODE_W, SDL_KEYUP)), moveComm);

	//Damage Player2
	// damageComm = std::make_shared<dae::DamageCommand>(spriteChild);
	//dae::Input::GetInstance().AddCommand((std::make_pair(SDL_SCANCODE_H, SDL_KEYDOWN)), damageComm);
	
	//add Score
	// add a score command then bind to p2
	//addScoreComm = std::make_shared<dae::AddScoreCommand>(spriteChild);
	//dae::Input::GetInstance().AddCommand((std::make_pair(SDL_SCANCODE_Y, SDL_KEYDOWN)), addScoreComm);

	//Sounds 
	Engine::ServiceLocator::RegisterAudioSystem(new Engine::Sdl_AudioNavigator());
	Engine::ServiceLocator::GetAudioSystem().AddSound("Swearing.wav", (unsigned short)Engine::Sound::QbertHit);
	Engine::ServiceLocator::GetAudioSystem().AddSound("QBertJump.wav", (unsigned short)Engine::Sound::QbertJump);
	Engine::ServiceLocator::GetAudioSystem().AddSound("QBertFall.wav", (unsigned short)Engine::Sound::QbertFall);
	Engine::ServiceLocator::GetAudioSystem().AddSound("RoundCompleteTune.wav", (unsigned short)Engine::Sound::QbertWin);

	
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}