#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/FeaturedStickers.h"

//begin namespace block
namespace MESSAGES
{
class GetFeaturedStickers : public TLBaseObject
{
public:
	GetFeaturedStickers();
	GetFeaturedStickers(int32 hash);

	~GetFeaturedStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Gethash() const
	{
		 return this->hash;
	}

	MESSAGES::FeaturedStickers* GetResult() const
	{
		 return this->result;
	}

private:
	int32 hash;
	MESSAGES::FeaturedStickers* result;
};
} //end namespace block
