#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/WallPaper.h"

//begin namespace block
namespace COMMON
{
class WallPaperSolid : public TLBaseObject
{
public:
	WallPaperSolid();
	WallPaperSolid(int32 id, FString title, int32 bg_color, int32 color);

	~WallPaperSolid();
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

	int32 GetBgColor() const
	{
		 return this->bg_color;
	}

	int32 Getcolor() const
	{
		 return this->color;
	}

private:
	int32 id;
	 FString title;
	 int32 bg_color;
	 int32 color;
};
} //end namespace block
