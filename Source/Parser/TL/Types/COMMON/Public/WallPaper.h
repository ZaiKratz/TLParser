#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PhotoSize.h"

//begin namespace block
namespace COMMON
{
class WallPaper : public TLBaseObject
{
public:
	WallPaper();
	WallPaper(int32 id, FString title, TArray<COMMON::PhotoSize*> sizes, int32 color);

	~WallPaper();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getid() const
	{
		 return this->id;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	TArray<COMMON::PhotoSize*>  Getsizes() const
	{
		 return this->sizes;
	}

	int32 Getcolor() const
	{
		 return this->color;
	}

private:
	int32 id;
	 FString title;
	 TArray<COMMON::PhotoSize*> sizes;
	 int32 color;
};
} //end namespace block
