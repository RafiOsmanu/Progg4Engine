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

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto to = std::make_shared<dae::GameObject>();
	auto go = std::make_shared<dae::GameObject>();
	auto background = std::make_shared<dae::GameObject>();

	auto textureComponentGo = std::make_shared <dae::TextureComponent>(go);
	auto textureComponentBackground = std::make_shared <dae::TextureComponent>(background);

	
	//BACKGROUND
	background->AddComponent(textureComponentBackground);
	background->GetComponent<dae::TextureComponent>().get()->SetTexture("background.tga");
	background->SetLocalPosition({ 0, 0 });
	scene.Add(background);

	
	//LOGO
	go->AddComponent(textureComponentGo);
	go->GetComponent<dae::TextureComponent>().get()->SetTexture("logo.tga");
	go->SetLocalPosition({ 216, 180 });
	scene.Add(go);

	//fonts
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 30);
	auto fpsFont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);

	//text
	auto text = std::make_shared<dae::TextObject>("Programming 4 Assignment", font);
	to->AddComponent(text);
	to->GetComponent<dae::TextObject>()->SetPosition(125, 50);
	scene.Add(to);

	//FPS COUNTER
	auto fpsCounter = std::make_shared<dae::GameObject>();
	auto fpsCalc = std::make_shared<dae::FPS>(fpsCounter);
	fpsCounter->AddComponent(fpsCalc);
	
	auto fpsText = std::make_shared <dae::TextObject>("FPS: ", fpsFont);
	fpsCounter->AddComponent(fpsText);

	fpsCounter->GetComponent<dae::TextObject>()->SetPosition(20.f, 20.f);
	scene.Add(fpsCounter);

	////sprite parent
	//auto spriteParent = std::make_shared<dae::GameObject>();
	//auto parentTexture = std::make_shared <dae::TextureComponent>(spriteParent);
	//auto moveComponentP = std::make_shared <dae::MoveComponent>(spriteParent);

	//spriteParent->AddComponent(parentTexture); 
	//spriteParent->AddComponent(moveComponentP);

	//spriteParent->GetComponent<dae::TextureComponent>()->SetTexture("yoshi.png");
	//

	//spriteParent->SetLocalPosition({ 160, 160 });

	//scene.Add(spriteParent);

	////sprite Child
	//auto spriteChild = std::make_shared<dae::GameObject>();
	//auto childTexture = std::make_shared <dae::TextureComponent>(spriteChild);
	//auto moveComponentC = std::make_shared <dae::MoveComponent>(spriteChild);
	//

	//spriteChild->AddComponent(childTexture);
	//spriteChild->AddComponent(moveComponentC);


	//spriteChild->GetComponent<dae::TextureComponent>()->SetTexture("yoshiEgg.png");

	//scene.Add(spriteChild);

	//spriteChild->SetParent(spriteParent);

}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}