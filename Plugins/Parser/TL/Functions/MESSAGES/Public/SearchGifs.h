#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/FoundGifs.h"

//begin namespace block
namespace MESSAGES
{
class SearchGifs : public TLBaseObject
{
public:
	SearchGifs();
	SearchGifs(FString q, int32 offset);

	~SearchGifs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getq() const
	{
		 return this->q;
	}

	int32 Getoffset() const
	{
		 return this->offset;
	}

	MESSAGES::FoundGifs* GetResult() const
	{
		 return this->result;
	}

private:
	FString q;
	 int32 offset;
	MESSAGES::FoundGifs* result;
};
} //end namespace block
