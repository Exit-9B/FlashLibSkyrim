#pragma once

namespace SWF
{
	namespace TagFactory
	{
		auto MakePlaceObject(
			RE::GFxMovieDataDef*          a_movieData,
			const RE::GFxPlaceObjectData& a_data) -> RE::GFxPlaceObjectBase*;

		auto MakeRemoveObject(RE::GFxMovieDataDef* a_movieData, std::uint16_t a_depth)
			-> RE::GFxRemoveObject2*;

		auto MakeRemoveObject(
			RE::GFxMovieDataDef* a_movieData,
			std::uint16_t        a_characterId,
			std::uint16_t        a_depth) -> RE::GFxRemoveObject*;

		auto MakeInitImportActions(
			RE::GFxMovieDataDef* a_movieData,
			std::uint32_t        a_movieIndex) -> RE::GFxInitImportActions*;

		auto MakeDoAction(RE::GFxMovieDataDef* a_movieData, RE::GASActionBufferData* a_data)
			-> RE::GASDoAction*;
	}
}
