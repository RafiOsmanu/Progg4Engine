#pragma once
#include <memory>
#include "AudioNavigator.h"

namespace Engine
{
	class ServiceLocator final
	{
		static std::unique_ptr<BaseAudioNavigator> m_pSSInstance;
		static AudioNavigatorNull m_DefaultSS;

	public:
		static BaseAudioNavigator& GetSoundSystem() { return *m_pSSInstance.get(); }
		static void RegisterSoundSystem(BaseAudioNavigator* pSoundSystem)
		{
			m_pSSInstance.reset(pSoundSystem == nullptr ? &m_DefaultSS : pSoundSystem);
		}
	};

	inline std::unique_ptr<BaseAudioNavigator> ServiceLocator::m_pSSInstance{};
	inline AudioNavigatorNull ServiceLocator::m_DefaultSS;
}

