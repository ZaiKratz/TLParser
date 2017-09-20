#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class ReadFeaturedStickers : public TLBaseObject
{
public:
	ReadFeaturedStickers();
	ReadFeaturedStickers(TArray<unsigned long long> id);

	~ReadFeaturedStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<unsigned long long> id;
	bool result;
};
} //end namespace block
