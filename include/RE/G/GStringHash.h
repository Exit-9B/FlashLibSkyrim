#pragma once

#include "RE/G/GAllocator.h"
#include "RE/G/GHash.h"
#include "RE/G/GString.h"

namespace RE
{
	// should be GString::BernsteinHashFunctionCIS
	static UPInt BernsteinHashFunctionCIS(const void* a_dataIn, UPInt a_size, UPInt a_seed = 5381)
	{
		assert(a_dataIn);
		auto         dataIn = static_cast<const std::uint8_t*>(a_dataIn);
		UPInt        hash;
		std::uint8_t byte = 0;
		for (hash = a_seed; a_size; hash = byte ^ 33 * hash) {
			byte = *(dataIn + a_size-- - 1);
			if (byte - 65 <= 25) {
				byte += 32;
			}
		}
		return hash;
	}

	// should be GString::NoCaseHashFunctor
	class NoCaseHashFunctor
	{
	public:
		UPInt operator()(const GString& a_data) const
		{
			return BernsteinHashFunctionCIS(a_data.data(), a_data.size());
		}
	};

	template <class U, class Allocator = GAllocatorGH<U>>
	class GStringHash : public GHash<GString, U, NoCaseHashFunctor, Allocator>
	{
	public:
		using BaseType = GHash<GString, U, NoCaseHashFunctor, Allocator>;
		using SelfType = GStringHash<U, Allocator>;
	};
}
