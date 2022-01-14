#pragma once

// NOTE: Due to a bug in the old version of Address Library, we do not have IDs for many of the
// virtual function tables for Scaleform objects. Instead, we use an offset from the closest ID
// for version 1.5.97, as a best guess for where the offset could be in a different game version.

namespace Offset
{
	namespace GASActionBufferData
	{
		// SkyrimSE 1.5.97.0: 0x17BC3F0
		inline static std::uintptr_t Vtbl =
			REL::Relocation<std::uintptr_t>(REL::ID(291566), 0x38).address();
	}

	namespace GASDoAction
	{

		// SkyrimSE 1.5.97.0: 0x17BC9C0
		inline constexpr REL::ID Vtbl(291613);
	}

	namespace GFxInitImportActions
	{
		// SkyrimSE 1.5.97.0: 0x17DC4C8
		inline static std::uintptr_t Vtbl =
			REL::Relocation<std::uintptr_t>(REL::ID(292202), 0x2C0).address();
	}

	namespace GFxPlaceObject2
	{
		// SkyrimSE 1.5.97.0: 0x17BE0E0
		inline static std::uintptr_t Vtbl =
			REL::Relocation<std::uintptr_t>(REL::ID(291775), 0x128).address();
	}

	namespace GFxPlaceObject3
	{
		// SkyrimSE 1.5.97.0: 0x17BE138
		inline static std::uintptr_t Vtbl =
			REL::Relocation<std::uintptr_t>(REL::ID(291775), 0x180).address();
	}

	namespace GFxRemoveObject
	{
		// SkyrimSE 1.5.97.0: 0x17DC408
		inline static std::uintptr_t Vtbl =
			REL::Relocation<std::uintptr_t>(REL::ID(292202), 0x200).address();
	}

	namespace GFxRemoveObject2
	{
		// SkyrimSE 1.5.97.0: 0x17DC448
		inline static std::uintptr_t Vtbl =
			REL::Relocation<std::uintptr_t>(REL::ID(292202), 0x240).address();
	}
}
