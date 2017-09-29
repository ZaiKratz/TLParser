#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class ReorderStickerSets : public TLBaseObject
{
public:
	ReorderStickerSets();
	ReorderStickerSets(bool masks, TArray<unsigned long long> order);

	~ReorderStickerSets();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getmasks() const
	{
		 return this->masks;
	}

	TArray<unsigned long long>  Getorder() const
	{
		 return this->order;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	bool masks;
	 TArray<unsigned long long> order;
	bool result;
};
} //end namespace block
