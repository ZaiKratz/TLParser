#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/WallPaper.h"

//begin namespace block
namespace ACCOUNT
{
class GetWallPapers : public TLBaseObject
{
public:
	GetWallPapers();
	~GetWallPapers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::WallPaper*> result;
};
} //end namespace block
